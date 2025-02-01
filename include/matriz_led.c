#include <stdio.h>
#include "matriz_led.h"
#include <hardware/pio.h>
#include "hardware/clocks.h"

// Biblioteca gerada pelo arquivo .pio durante compilação.
#include "ws2818b.pio.h"

PIO pio;
uint sm;

// FUNÇÕES

// função que inicializa a matriz de LEDs
uint matrix_init(uint pin_out)
{

  uint offset = pio_add_program(pio0, &ws2818b_program);
  pio = pio0;

  sm = pio_claim_unused_sm(pio, false);
  if (sm < 0)
  {
    pio = pio1;
    sm = pio_claim_unused_sm(pio, true);
  }

  ws2818b_program_init(pio, sm, offset, pin_out); // tive que mudar a .pio

  return sm;
}

// função que procura um LED específico na matriz de LEDs, de acordo com suas coordenadas x e y
int matrix_get_index(int aux)
{
  int x = aux % 5; // Coluna
  int y = aux / 5; // Linha
  // Se a linha for par (0, 2, 4), percorremos da esquerda para a direita.
  // Se a linha for ímpar (1, 3), percorremos da direita para a esquerda.
  if (y % 2 == 0)
  {
    return y * 5 + (4 - x); // Linha par (direita para esquerda).
  }
  else
  {
    return y * 5 + x; // Linha ímpar (esquerda para direita).
  }
}

void matrix_draw_number(const uint32_t matriz[10][25], uint8_t numero) {
  for (uint8_t aux = 0; aux < NUM_PIXELS; aux++)
  {
    uint8_t led = matrix_get_index(aux);
    pio_sm_put_blocking(pio0, sm, matriz[numero][led]);
  }
}