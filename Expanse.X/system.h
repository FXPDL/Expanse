/******************************************************************************/
/* System Level #define Macros                                                */
/******************************************************************************/

/* TODO Define system operating frequency */

/* Microcontroller MIPs (FCY) */
#define SYS_FREQ        500000L
#define FCY             SYS_FREQ/4

/******************************************************************************/
/* System Function Prototypes                                                 */
/******************************************************************************/

/* Custom oscillator configuration funtions, reset source evaluation
functions, and other non-peripheral microcontroller initialization functions
go here. */

void ConfigureOscillator(void); /* Handles clock switching/osc initialization */
void wait_ms(uint16_t);
void set_leds_bottom(int);
void set_leds_top(int, int);
uint16_t adc_convert(uint8_t);
float map(float, float, float, float, float);
int set_subdivision(int,int);
int modulation(signed int, signed int);
//int covert_BPM(int);