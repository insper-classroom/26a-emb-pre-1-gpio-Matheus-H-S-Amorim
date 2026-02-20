#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>




// constantes de numeros dos pinos onde tem leds e o botao
const int BTN_1 = 28;

const int LED_V = 5;
const int LED_R = 8;
const int LED_Az = 11;
const int LED_Am = 15;


int main() {
  // inicia td
  stdio_init_all();

  //inicia pinos (botao e led)
  gpio_init(BTN_1);

  gpio_init(LED_V);
  gpio_init(LED_R);
  gpio_init(LED_Az);
  gpio_init(LED_Am);


  //define se é entrada  ou saida (botao e led)
  gpio_set_dir(BTN_1,GPIO_IN);

  gpio_set_dir(LED_V,GPIO_OUT);
  gpio_set_dir(LED_R,GPIO_OUT);
  gpio_set_dir(LED_Az,GPIO_OUT);
  gpio_set_dir(LED_Am,GPIO_OUT);

  //inicia c o botao levantadoo
  gpio_pull_up(BTN_1);

  while (true) {
    // Use delay de 300 ms entre os estados!

    
    if (!gpio_get(BTN_1)) {

      gpio_put(LED_V, 1);
      sleep_ms(300);
      gpio_put(LED_V, 0);


      gpio_put(LED_R, 1);
      sleep_ms(300);
      gpio_put(LED_R, 0);

      gpio_put(LED_Az, 1);
      sleep_ms(300);
      gpio_put(LED_Az, 0);

      gpio_put(LED_Am, 1);
      sleep_ms(300);
      gpio_put(LED_Am, 0);





      while (!gpio_get(BTN_1)) {
      };
    }

}
}
