/******************************************************************************/
/*Files to Include                                                            */
/******************************************************************************/

#if defined(__XC)
#include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
#include <htc.h>        /* HiTech General Include File */
#endif

#include <stdint.h>         /* For uint8_t definition */
#include <stdbool.h>        /* For true/false definition */
#include "system.h"        /* System funct/params, like osc/peripheral config */
#include "user.h"          /* User funct/params, such as InitApp */


/******************************************************************************/
/* Interrupt Routines                                                         */

/******************************************************************************/

void interrupt isr(void) {
    extern volatile long timer;
    extern volatile long sub_timer;
    extern volatile long tap_timer;
    extern volatile long mod_timer;
    extern volatile long baseline_delay_time;
    extern volatile long delay_time;
    extern volatile int top_push_state;
       
    if (INTCONbits.TMR0IF == 1) {
        timer = timer + 1;
        sub_timer = sub_timer + 1;
        tap_timer = tap_timer + 1;
        mod_timer = mod_timer + 1;
        INTCONbits.TMR0IF = 0;
    }

    if (timer >= baseline_delay_time) { //delay_time
        LATFbits.LATF5 = 1;
        timer = 0;
    }

    if (timer >= 20) { //delay_time
        LATFbits.LATF5 = 0;
    }
    
    if (sub_timer >= delay_time) { //sub_delay_time
        set_leds_top(top_push_state, 1);
        sub_timer = 0;
    }

    if (sub_timer >= 20) { //delay_time
        set_leds_top(top_push_state, 0);
    }


}

