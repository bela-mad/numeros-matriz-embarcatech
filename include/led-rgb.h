#ifndef LED_RGB_H
#define LED_RGB_H

#include <stdio.h>
#include "pico/stdlib.h"

// Defines
#define GREEN_LED_PIN 11
#define BLUE_LED_PIN 12
#define RED_LED_PIN 13

// Cabeçalhos das funções
void led_init(uint gpio);
bool repeating_timer_callback(struct repeating_timer *t);

#endif