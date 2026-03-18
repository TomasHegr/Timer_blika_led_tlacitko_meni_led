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

    GPIO_Init(SB_LED1_PORT, SB_LED1_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(SB_LED2_PORT, SB_LED2_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(SB_LED3_PORT, SB_LED3_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);

    GPIO_Init(SB_S4_PORT, SB_S4_PIN, GPIO_MODE_IN_PU_NO_IT);

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
            if(PUSH(SB_S4) && !btn_press){
                
                led_pointer1+=1;
                if(led_pointer1 > 2){
                    led_pointer1=0;
                }
                
            }
            
            btn_press= PUSH(SB_S4);
            time= milis();

        }
    };

  

   
}

/*-------------------------------  Assert -----------------------------------*/
#include "__assert__.h"
