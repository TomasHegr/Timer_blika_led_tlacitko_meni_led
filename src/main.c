#include "main.h"
#include "daughterboard.h"
#include "milis.h"
#include <stdbool.h>
#include <stm8s.h>
// #include "delay.h"
// #include "uart1.h"
#include <stdio.h>




void init(void)
{
    CLK_HSIPrescalerConfig(CLK_PRESCALER_HSIDIV1); // taktovani MCU na 16MHz
    init_milis();
    // init_uart1();

    GPIO_Init(DB_LED6_PORT, DB_LED6_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(DB_LED5_PORT, DB_LED5_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);
    GPIO_Init(DB_S1_PORT, DB_S1_PIN, GPIO_MODE_IN_PU_NO_IT);
}


int main(void)
{

    uint32_t time = 0;

    init();

    while (1) {
        if (milis() - time > 333) {
            REVERSE(DB_LED6);
            time = milis();
            // printf("%ld\n", time);
        }
        // delay_ms(333);
    }
}

/*-------------------------------  Assert -----------------------------------*/
#include "__assert__.h"
