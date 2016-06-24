/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#if defined(__XC)
#include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
#include <htc.h>        /* HiTech General Include File */
#endif

#include <stdint.h>         /* For uint8_t definition */
#include <stdbool.h>        /* For true/false definition */
#include "user.h"

/******************************************************************************/
/* User Functions                                                             */
/******************************************************************************/

/* <Initialize variables in user.h and insert code for user algorithms.> */

void InitApp(void) {
    TRISBbits.TRISB0 = 1; //set as INPUT
    TRISBbits.TRISB1 = 0; //set as OUTPUT
    TRISBbits.TRISB2 = 1; //set as INPUT
    TRISBbits.TRISB3 = 1; //set as INPUT
    TRISBbits.TRISB4 = 0; //set as OUTPUT
    TRISBbits.TRISB5 = 0; //set as OUTPUT
    ANSELBbits.ANSB0 = 0; //set as DIGITAL
    ANSELBbits.ANSB2 = 0; //set as DIGITAL
    ANSELBbits.ANSB3 = 0; //set as DIGITAL

    TRISCbits.TRISC6 = 0; //set as OUTPUT
    TRISCbits.TRISC7 = 0; //set as OUTPUT

    TRISDbits.TRISD0 = 0; //set as OUTPUT
    TRISDbits.TRISD1 = 0; //set as OUTPUT
    TRISDbits.TRISD2 = 0; //set as OUTPUT
    TRISDbits.TRISD3 = 0; //set as OUTPUT
    TRISDbits.TRISD4 = 0; //set as OUTPUT
    TRISDbits.TRISD5 = 1; //set as INPUT
    TRISDbits.TRISD5 = 1; //set as INPUT

    TRISEbits.TRISE0 = 1; //set as INPUT
    TRISEbits.TRISE1 = 1; //set as INPUT
    ANSELEbits.ANSE0 = 0; //set as DIGITAL
    ANSELEbits.ANSE1 = 0; //set as DIGITAL
    PORTEbits.RE0 = 0; //set as ViL
    PORTEbits.RE1 = 0; //set as ViL

    TRISFbits.TRISF0 = 0; //set as OUTPUT
    TRISFbits.TRISF1 = 0; //set as OUTPUT
    TRISFbits.TRISF2 = 0; //set as OUTPUT
    TRISFbits.TRISF3 = 0; //set as OUTPUT
    TRISFbits.TRISF4 = 0; //set as OUTPUT
    TRISFbits.TRISF5 = 0; //set as OUTPUT
    TRISFbits.TRISF6 = 0; //set as OUTPUT

    TRISGbits.TRISG1 = 0; //set as OUTPUT
    TRISGbits.TRISG2 = 0; //set as OUTPUT

    init_adc();
    init_pwm();

    INTCONbits.GIE = 0b1; //enable interrupt
    INTCONbits.TMR0IE = 0b1;
    INTCONbits.TMR0IF = 0b0;
}

int set_leds_bottom(int x) {
    switch (x) {
        case 1:
            LATDbits.LATD0 = 1;
            LATDbits.LATD1 = 0;
            LATDbits.LATD2 = 0;
            LATDbits.LATD3 = 0;
            LATDbits.LATD4 = 0;
            break;
        case 2:
            LATDbits.LATD0 = 0;
            LATDbits.LATD1 = 1;
            LATDbits.LATD2 = 0;
            LATDbits.LATD3 = 0;
            LATDbits.LATD4 = 0;
            break;
        case 3:
            LATDbits.LATD0 = 0;
            LATDbits.LATD1 = 0;
            LATDbits.LATD2 = 1;
            LATDbits.LATD3 = 0;
            LATDbits.LATD4 = 0;
            break;
        case 4:
            LATDbits.LATD0 = 0;
            LATDbits.LATD1 = 0;
            LATDbits.LATD2 = 0;
            LATDbits.LATD3 = 1;
            LATDbits.LATD4 = 0;
            break;
        case 5:
            LATDbits.LATD0 = 0;
            LATDbits.LATD1 = 0;
            LATDbits.LATD2 = 0;
            LATDbits.LATD3 = 0;
            LATDbits.LATD4 = 1;
            break;
        case 6:
            LATDbits.LATD0 = 0;
            LATDbits.LATD1 = 0;
            LATDbits.LATD2 = 0;
            LATDbits.LATD3 = 0;
            LATDbits.LATD4 = 0;
            break;
    }
}

int set_subdivision(int x, int y) {
    //x = delay time
    //y = state
    switch (y) {
        case 1:
            x = x * .75; // dotted eight
            break;
        case 2:
            x = x * .66666; //quarter triplet
            break;
        case 3:
            x = x * .5; //eight 
            break;
        case 4:
            x = x * .3333; //eight triplet
            break;
        case 5:
            x = x * .25; //16th
            break;
        case 6:
            x = x; // 1:1 ratio
            break;
    }
    return x;
}

int set_leds_top(int x, int ledState) {
    switch (x) {
        case 1:
            LATFbits.LATF0 = ledState;
            LATFbits.LATF1 = 0;
            LATFbits.LATF2 = 0;
            LATFbits.LATF3 = 0;
            LATFbits.LATF4 = 0;
            break;
        case 2:
            LATFbits.LATF0 = 0;
            LATFbits.LATF1 = ledState;
            LATFbits.LATF2 = 0;
            LATFbits.LATF3 = 0;
            LATFbits.LATF4 = 0;
            break;
        case 3:
            LATFbits.LATF0 = 0;
            LATFbits.LATF1 = 0;
            LATFbits.LATF2 = ledState;
            LATFbits.LATF3 = 0;
            LATFbits.LATF4 = 0;
            break;
        case 4:
            LATFbits.LATF0 = 0;
            LATFbits.LATF1 = 0;
            LATFbits.LATF2 = 0;
            LATFbits.LATF3 = ledState;
            LATFbits.LATF4 = 0;
            break;
        case 5:
            LATFbits.LATF0 = 0;
            LATFbits.LATF1 = 0;
            LATFbits.LATF2 = 0;
            LATFbits.LATF3 = 0;
            LATFbits.LATF4 = ledState;
            break;
        case 6:
            LATFbits.LATF0 = 0;
            LATFbits.LATF1 = 0;
            LATFbits.LATF2 = 0;
            LATFbits.LATF3 = 0;
            LATFbits.LATF4 = 0;
            break;
    }
}

void init_adc(void) {
    ADCON1bits.ADFM = 0b1; // right justify the output
    ADCON1bits.ADCS = 0b110; // use Fosc/64 for clock source
    ADCON1bits.ADPREF = 0b00; // Vref = Vdd
    ADCON0bits.ADON = 0b1; // turn on the ADC
}

uint16_t adc_convert(uint8_t channel) {
    ADCON0bits.CHS = channel; // select the given channel
    ADCON0bits.GO = 0b1; // start the conversion
    while (ADCON0bits.GO_nDONE); // wait for the conversion to finish
    return (ADRESH << 8) | ADRESL; // return the result
}

void init_pwm(void) {
    APFCONbits.CCP2SEL = 0; //CCP2 is on RC1
    TRISCbits.TRISC2 = 0; //CCP1 pin to output
    TRISCbits.TRISC1 = 0; //CCP2 pin to output
    TRISGbits.TRISG0 = 0; //CCP3 pin to output
    TRISGbits.TRISG3 = 0; //CCP4 pin to output
    TRISGbits.TRISG4 = 0; //CCP5 pin to output
    TRISEbits.TRISE6 = 0; //CCP6 pin to output
    TRISEbits.TRISE5 = 0; //CCP7 pin to output
    TRISEbits.TRISE4 = 0; //CCP8 pin to output
    TRISEbits.TRISE3 = 0; //CCP9 pin to output
    TRISEbits.TRISE2 = 0; //CCP10 pin to output
    CCP1CONbits.CCP1M = 0b1111; // set CCP1 as PWM mode
    CCP2CONbits.CCP2M = 0b1111; // set CCP2 as PWM mode
    CCP3CONbits.CCP3M = 0b1111; // set CCP3 as PWM mode
    CCP4CONbits.CCP4M = 0b1111; // set CCP4 as PWM mode
    CCP5CONbits.CCP5M = 0b1111; // set CCP5 as PWM mode
    CCP6CONbits.CCP6M = 0b1111; // set CCP6 as PWM mode
    CCP7CONbits.CCP7M = 0b1111; // set CCP7 as PWM mode
    CCP8CONbits.CCP8M = 0b1111; // set CCP8 as PWM mode
    CCP9CONbits.CCP9M = 0b1111; // set CCP9 as PWM mode
    CCP10CONbits.CCP10M = 0b1111; // set CCP10 as PWM mode
    CCPTMRS0 = 0b00000000; //set CCP4, CCP3, CCP2, CCP1 to reference Timer2
    CCPTMRS1 = 0b00000000; //set CCP8, CCP7, CCP6, CCP5 to reference Timer2
    CCPTMRS2 = 0b00000000; //set CCP10, CCP9 to reference Timer2
    CCPR1 = 50; //set CCP1 Duty Cycle to 50%
    CCPR2 = 100; //set CCP1 Duty Cycle to 50%
    CCPR3 = 150; //set CCP1 Duty Cycle to 50%
    CCPR4 = 200; //set CCP1 Duty Cycle to 50%
    init_timer2();
    init_timer0();
}

void init_timer2(void) {
    T2CONbits.T2OUTPS = 0b0000;
    T2CONbits.T2CKPS = 0b00;
    PR2 = 0xFF; //set Timer2 max value (16Mhz/4*1*15.67khz)
    T2CONbits.TMR2ON = 1;
}

void init_timer0(void) {
    OPTION_REGbits.TMR0CS = 0b0;
    OPTION_REGbits.PSA = 0b0;
    OPTION_REGbits.PS0 = 0b0;
    OPTION_REGbits.PS1 = 0b1;
    OPTION_REGbits.PS2 = 0b0;
}

float map(float x, float in_min, float in_max, float out_min, float out_max) {
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

int modulation(signed int x, signed int y) {
    //modulation(mod_value, adjusted_pot_value);
    x = (127500 + (y * x)) / 1000;
    return x;
}