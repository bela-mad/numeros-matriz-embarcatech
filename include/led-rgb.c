#include "led-rgb.h"

// Funções

// Função que inicializa o pino do LED e configura como saída
void led_init(uint gpio) {
    gpio_init(gpio);
    gpio_set_dir(gpio, GPIO_OUT);
}

// Função callback, usada na estrutura de repetição, que muda o estado do LED vermelho
bool repeating_timer_callback(struct repeating_timer *t) {
    gpio_put(RED_LED_PIN, !gpio_get(RED_LED_PIN));

    // se o retorno for verdadeiro, cria-se um loop na temporização
    return true;
}