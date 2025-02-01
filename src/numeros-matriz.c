#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h" // temporização via hardware
#include "./include/animation.h"
#include "./include/button.h"
#include "./include/led_rgb.h"
#include "./include/matriz_led.h"

// void gpio_irq_handler(uint gpio, uint32_t events);

uint8_t cont = 0;
static volatile uint32_t last_time = 0;

int main() {
    
    stdio_init_all;
    // inicialização e configuração dos componentes a serem utilizados
    led_init(RED_LED_PIN);
    button_init(BUTTON_A_PIN);
    button_init(BUTTON_B_PIN);
    matrix_init(LED_MATRIZ_PIN);

    // gpio_set_irq_enabled_with_callback(BUTTON_A_PIN, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);
    // gpio_set_irq_enabled_with_callback(BUTTON_B_PIN, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);

    matrix_draw_number(numeros, cont);

    // Esta estrutura armazenará informações sobre o temporizador configurado.
    struct repeating_timer timer;

    // Configura o temporizador para chamar a função de callback a cada 0,2 segundo (5 vezes por segundo).
    add_repeating_timer_ms(200, repeating_timer_callback, NULL, &timer);

    while (true) {
        sleep_ms(100);
    }
}

// void gpio_irq_handler(uint gpio, uint32_t events)
// {
//     uint32_t current_time = to_us_since_boot(get_absolute_time());
//     if (current_time - last_time > 200000)
//     { // 200 ms de debouncing

//         last_time = current_time;
//         if (gpio == BUTTON_A_PIN)
//         {
//             cont++;

//             if (cont > 9)
//             {
//                 cont = 9;
//             }
//         }
//         else if (gpio == BUTTON_B_PIN)
//         {
//             cont--;

//             if (cont < 0)
//             {
//                 cont = 0;
//             }
//         }
//         matrix_draw_number(numeros, cont);
//     }
// }