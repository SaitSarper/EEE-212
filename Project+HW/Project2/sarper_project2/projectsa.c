#include <MKL25Z4.H>
#include <stdio.H>
#include "utils.h"

void ADC0_init(void);
void DAC0_init(void);
void SysTick_Handler(void);
volatile int k = 0;
static int n = 12;
void PORTA_IRQHandler(void) ;
int main (void) 
{	
	LCD_init();
	int samplenum;
	
	int saw_tooth;
	int square;
	int sine;

	float coef = 0;
		
	const static int sinewave[67] =
	
	{39,70,120,156,345,600,910,1264,1648,2048,2448,2832,3186,3496,3751,3940,4057,
	4096,4057,3940,3751,3496,3186,2832,2448,2048,1648,1264,910,600,345,156,120,70,39,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			
	;
	
	const static int sawtooth [61] = {68, 136, 205, 273, 341, 409, 478, 546, 614, 682, 751, 819, 887, 955, 1023, 1092, 1160, 1228, 
		1296, 1365, 1433, 1501, 1569, 1638, 1706, 1774, 1842, 1911, 1979, 2047, 2115, 2184, 2252, 2320, 2388, 2457, 
		2525, 2593, 2661, 2730, 2798, 2866, 2934, 3003, 3071, 3139, 3207, 3276, 3344, 3412, 3480, 3549, 3617, 3685, 
	3753, 3822, 3890, 3958, 4026,4062, 4095};
	
	 	
	const static int squarewave [65] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0,0, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 
		4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095, 4095};
	
		
	__disable_irq(); /* disable all IRQs */
	
	SIM->SCGC5 |= 0x400;  /*enable port B for output*/
	PORTB->PCR[1] = 0X100; /* make PTB1 GPIO*/
	PORTB->PCR[2] = 0X100; /* make PTB2 GPIO*/
	PORTB->PCR[3] = 0X100; /* make PTB3 GPIO*/
	PTB->PDDR |= 0x0E ;/*make PTB1,2,3 outputs*/

	
	SIM->SCGC5 |= 0x200; /* enable clock to Port A */
	/* configure PTA1 for interrupt */
	PORTA->PCR[1] |= 0x00100;  
	PORTA->PCR[1] |= 0x00003; /*activate resistance */
	PTA->PDDR &= ~0x0002; /* make pin input */
	PORTA->PCR[1] &= ~0xF0000; /* clear interrupt selection */
	PORTA->PCR[1] |= 0xA0000; /* enable falling edge interrupt */

	SysTick->LOAD = (41940000/16) - 1; /*to make 2 second delay*/
	SysTick->CTRL = 3;			/*clock is divided by 16 make such a long delay*/
	NVIC_EnableIRQ(PORTA_IRQn);
//	NVIC->ISER[0] |= 0x40000000; /* enable INT30 (bit 30 of ISER[0]) */
	__enable_irq(); /* global enable IRQs */
	
	DAC0_init(); /* Configure DAC0 */
	ADC0_init(); /* Configure ADC0 */
	uint32_t result = 0;

	
	while (1) {
			ADC0->SC1[0] = 0; /* start conversion on channel 0 */
			while(!(ADC0->SC1[0] & 0x80)){}
				if (k == 0){for (samplenum = 0; samplenum < 65; samplenum++){ 
					/* write on DAC0 */
					square = squarewave[samplenum]* coef;
					DAC0->DAT[0].DATL = (square) & 0xff; /* write low byte */
					DAC0->DAT[0].DATH = ((square) >> 8) & 0x0f;/* write high byte */
					Delay(n+17);}
				}
				if (k == 1){for (samplenum = 0; samplenum < 67; samplenum++){ 
					/* write on DAC0 */
					sine=sinewave[samplenum]*coef;
					DAC0->DAT[0].DATL = (sine) & 0xff; /* write low byte */
					DAC0->DAT[0].DATH = ((sine) >> 8) & 0x0f;/* write high byte */
					Delay(n+16);}
				}
				if (k == 2){for (samplenum = 0; samplenum < 61; samplenum++){ 
					/* write on DAC0 */
					saw_tooth = sawtooth[samplenum] * coef;
					DAC0->DAT[0].DATL = (saw_tooth) & 0xff;
					DAC0->DAT[0].DATH = ((saw_tooth) >> 8) & 0x0f;

					Delay(n+17);}
				}
			result = ADC0->R[0]; /* read conversion result and clear COCO flag */
			coef = result / 4096.0;
		}
}

void DAC0_init(void) 
{
	SIM->SCGC6 |= 0x80000000; /* clock to DAC module */
	DAC0->C1 = 0; /* disable the use of buffer */
	DAC0->C0 = 0x80 | 0x20; /* enable DAC and use software trigger */
}

void SysTick_Handler(void){

	uint32_t result = 0;
	char list[4];
	ADC0->SC1[0] = 0; /* start conversion on channel 0 */
	result = ADC0->R[0]; /* read conversion result and clear COCO flag */
	result = ((result + 1)*3.3)*1000/4096;
	
	int p= 0;
	int kalan;
	kalan =result;
	for(p=0;p<4;p++)
		{kalan= result %10;
		result = result/10;
		list[p]= kalan + '0';}
	
	
			LCD_command(0x01);
			print_fnc("Freq: 610Hz");
			LCD_command(0xC0);
			print_fnc("Voltage: ");

			LCD_data(list[3]);
			LCD_data('.');
			LCD_data(list[2]);
			LCD_data(list[1]);
		  LCD_data(list[0]);
			LCD_data('V');
	
}
void ADC0_init(void)
{
	SIM->SCGC5 |= 0x2000; /* clock to PORTE */
	PORTE->PCR[20] = 0; /* PTE20 analog input */
	SIM->SCGC6 |= 0x8000000; /* clock to ADC0 */
	ADC0->SC2 &= ~0x40; /* software trigger */
	/* clock div by 4, long sample time, single ended 12 bit, bus clock */
	ADC0->CFG1 = 0x40 | 0x10 | 0x04 | 0x00;
}


void PORTA_IRQHandler(void) 
{	Delay(300000);
	k = (k + 1) % 3;  
	PORTA->ISFR = 0x00000002; /* clear interrupt flag  001 sended */
}
