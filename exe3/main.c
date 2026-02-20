#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

// constantes de numeros dos pinos onde tem led e os botao
const int BTN_1 = 28;
const int LED_1 = 4;

const int BTN_2 = 26; 
const int LED_2 = 6;



int main() {
  // inicia td
  stdio_init_all();

  //inicia pinos (botao e led)
  gpio_init(BTN_1);
  gpio_init(BTN_2);  

  gpio_init(LED_1);
  gpio_init(LED_2);

  //define se é entrada  ou saida (botao e led)
  gpio_set_dir(BTN_1,GPIO_IN);
  gpio_set_dir(BTN_2,GPIO_IN);  

  gpio_set_dir(LED_1,GPIO_OUT);
  gpio_set_dir(LED_2,GPIO_OUT);

  //inicia c botoes levantados
  gpio_pull_up(BTN_1);
  gpio_pull_up(BTN_2);


  // estado de ligado (ou n ) dos botao
  int b1_on = 0;
  int b2_on = 0; 

  while (true) {
    
    if (!gpio_get(BTN_1)) {
      printf("Botao 1\n");

      if (b1_on){
        gpio_put(LED_1, 0);
        b1_on = 0;
        
      }
      else{
        gpio_put(LED_1, 1);
        b1_on = 1; 
      }
      
      while (!gpio_get(BTN_1)) {
      };
    }




    if (!gpio_get(BTN_2)) {
      printf("Botao 2\n"); 
      
      if (b2_on){
        gpio_put(LED_2, 0);
        b2_on = 0;
        
      }
      else{
        gpio_put(LED_2, 1);
        b2_on = 1; 
      }
           

      while (!gpio_get(BTN_2)) {

      };

    }


  }
}
