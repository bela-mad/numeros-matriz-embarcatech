#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "./include/animation.h"
#include "./include/button.h"
#include "./include/led-rgb.h"
#include "./include/matriz_led.h"

// Cabeçalho da função de callback dos botões
void gpio_irq_handler(uint gpio, uint32_t events);

// Declaração de variáveis
uint8_t cont = 0;                        // Variável auxiliar para exibir o número na matriz de LEDs
static volatile uint32_t last_time = 0;  // Variável que recebe o último tempo registrado

int main() {
    
    // Inicialização e configuração dos componentes a serem utilizados
    stdio_init_all();
    led_init(RED_LED_PIN);
    led_init(GREEN_LED_PIN);
    led_init(BLUE_LED_PIN);
    button_init(BUTTON_A_PIN);
    button_init(BUTTON_B_PIN);
    matrix_init(LED_MATRIZ_PIN);

    // Configuração das interrupções nos botões A e B
    gpio_set_irq_enabled_with_callback(BUTTON_A_PIN, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);
    gpio_set_irq_enabled_with_callback(BUTTON_B_PIN, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);

    // Desenho do número 0 para inicializar a contagem
    matrix_draw_number(numeros_low, cont);

    // Esta estrutura armazenará informações sobre o temporizador configurado
    struct repeating_timer timer;    

    // Configura o temporizador para chamar a função de callback a cada 0,1 segundo (5 vezes por segundo, contando com o LED aceso e apagado)
    add_repeating_timer_ms(100, repeating_timer_callback, NULL, &timer);

    while (true){
        sleep_ms(100);
    }
}

// Função callback que verifica o tempo para que o debouncing ocorra, atualiza esse tempo, verifica o botão que 
// foi pressionado, atualiza o valor de cont para exibir o número correto na tela e imprime o valor na matriz
void gpio_irq_handler(uint gpio, uint32_t events) {
    uint32_t current_time = to_us_since_boot(get_absolute_time());
    if (current_time - last_time > 200000) { // 200 ms de debouncing

        last_time = current_time;
        if (gpio == BUTTON_A_PIN) {
            cont++;

            if (cont > 9) {
                cont = 9;
            }
        } else if (gpio == BUTTON_B_PIN) {
            cont--;

            if (cont > 9) {
                cont = 0;
            }
        }
        matrix_draw_number(numeros_low, cont);
    }
}