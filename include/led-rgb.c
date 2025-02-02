#include "led-rgb.h"

// Funções

// função que inicializa o pino do LED e configura como saída
void led_init(uint gpio) {
    gpio_init(gpio);
    gpio_set_dir(gpio, GPIO_OUT);
}

// callback que será usada na estrutura de repetição
bool repeating_timer_callback(struct repeating_timer *t)
{
    gpio_put(RED_LED_PIN, !gpio_get(RED_LED_PIN));

    // se o retorno for verdadeiro, cria-se um loop na temporização
    return true;
}