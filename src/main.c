#include "main.h"
#include "daughterboard.h"
#include "milis.h"
#include <stdbool.h>
#include <stm8s.h>
// #include "delay.h"
// #include "uart1.h"
#include "sonboard.h"
#include <stdio.h>

extern uint8_t led_pointer1 ;

void init(void)
{
    

    CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1); // taktovani MCU na 16MHz
    init_milis();
    // init_uart1();

    GPIO_Init(DB_LED6_PORT, DB_LED6_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(DB_LED5_PORT, DB_LED5_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(DB_LED4_PORT, DB_LED4_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);

    GPIO_Init(DB_S1_PORT, DB_S1_PIN, GPIO_MODE_IN_PU_NO_IT);

    TIM3_TimeBaseInit(TIM3_PRESCALER_128,50000-1);      // nastavení časovače na 400 ms
    TIM3_Cmd(ENABLE);                                //POVOLÍ/SPUSTÍ TIM 3
    TIM3_ITConfig(TIM3_IT_UPDATE,ENABLE);             //Událost update UPDATE je zdrojem/způsobí IRQ
    enableInterrupts();   
}


int main(void)
{

    uint32_t time = 0;
    uint8_t btn_press = 0;
    

    init();
    
    while(1){

        if(milis() - time > 33){
            if(PUSH(DB_S1) && !btn_press){
                
                led_pointer1+=1;
                if(led_pointer1 > 2){
                    led_pointer1=0;
                }
                
            }
            
            btn_press= PUSH(DB_S1);
            time= milis();

        }
    };

  

   
}

/*-------------------------------  Assert -----------------------------------*/
#include "__assert__.h"
