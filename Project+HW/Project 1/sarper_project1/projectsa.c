/* module3.c: Based on Mazidi etal book. 
 *Sait Sarper Ozaslan
 22002861
 
 */

#include <MKL25Z4.H>
#include <stdio.h>


#define RS 0x04     /* PTA2 mask */ 
#define RW 0x10     /* PTA4 mask */ 
#define EN 0x20     /* PTA5 mask */

void Delay(volatile unsigned int time_del);
void LCD_command(unsigned char command);
void LCD_data(unsigned char data);
void LCD_init(void);
void LCD_ready(void);
void keypad_init(void);
void Derivative(void);
uint32_t keypad_getkey(void);

int main(void)
{
  uint32_t seloperation;
	uint32_t key;
	uint32_t num = 6;		/*added*/
	uint32_t addnum = 0;	/*added*/
 
	char lookup[]= {'1','2','3','+','4','5','6','B','7','8','9','C','*','0','#','D'};
	uint32_t c[6];		/*added*/
  char replist[12]; /* list to try if it is showing the right value*/
	
	uint32_t nlist[5];
	
	uint32_t kalan = 0; /*ne oldugunu biliyon aq*/
uint32_t m = 0;
uint32_t	n = 0;
uint32_t total = 0;
uint32_t x = 0;
	uint32_t k = 0;
	
	int disp = 0;
	int fi = 0;
	uint32_t final=0;
uint32_t dernum = 0;

	
	uint32_t l, trial;
	LCD_init();
	LCD_command(0x80);      /* set cursor at first line */
				LCD_data('c');
				LCD_data('=');
		keypad_init();
				
				
   
    
		
		while(1)
		{
		Delay(300000);	
		key=keypad_getkey();
			
				
			if (num != 0){
			if(key != 0)
			{c[addnum] = (lookup[key-1]- '0');
				addnum++;
				num= num -1;
		  LCD_data(lookup[key-1])
				;
				Delay(300000);
				
				}
			if (num == 0)
				break;
	}

}
		while (1)
		{Delay(300000);	
		key=keypad_getkey();
			if (key == 15)
				break;
		}
			
LCD_command(0x01);
LCD_data('S');
LCD_data('E');
LCD_data('L');
LCD_data('E');
LCD_data('C');
LCD_data('T');
LCD_data(' ');
LCD_data('O');
LCD_data('P');
LCD_data('E');
LCD_data('R');
LCD_data('A');
LCD_data('T');
LCD_data('I');
LCD_data('O');
LCD_data('N');

while (1)
	{Delay(300000);	
		key=keypad_getkey();
			if (key == 15){
			
			
		
	seloperation = key;
		LCD_command(0x01);
		LCD_data('E');          
	LCD_data('N');
	LCD_data('T');
	LCD_data('E');
	LCD_data('R');
	LCD_data(' ');
	LCD_data('A');		
	LCD_data(' ');
	LCD_data('P');          
	LCD_data('T');
	




while (1){
		/* now we get the pt*/
Delay(300000);	
	key=keypad_getkey();
	if (lookup[key-1]=='#')
		goto fin;
	if(key != 0){
	nlist[n] = (lookup[key-1]-'0');
				n++;
	dernum = dernum + 1;
	LCD_data(lookup[key-1]);
		Delay(300000);
	}
	}
/* we need to turn the data into one int*/

	
	fin:	LCD_command(0xC0);
while (1){x= nlist[k];
	for (m=dernum-1;m!=0;m--){
	x=x*10;}
	total= x+total;
	k++;
	dernum--;
	if (dernum==0)
		goto calc;
	
}
calc:{total= 5*c[0]*total*total*total*total+4*c[1]*total*total*total+
	3*c[2]*total*total+2*c[3]*total+c[4];


}

final = total;
while (1){
	kalan= final %10;
final = final/10;
	replist[disp]= kalan + '0';
	if ((final== 0)%(kalan==0))
	goto next;

	
	
disp++;

}

next:fi=disp;
while (1) {
	LCD_data(replist[fi]);
	fi--;
	
	
	Delay(300000);
	if (fi==1-2)
		break;
}

	}
	if (key==13){
		LCD_command(0x01);
	LCD_command(0x80);
	LCD_data('S');
LCD_data('T');
LCD_data('A');
LCD_data('R');
LCD_data('T');
LCD_data('T');


	n=0;
		dernum=0;
		k=0;
	while (1){
		/* now we get the pt*/
	
Delay(300000);	
	key=keypad_getkey();
	if (lookup[key-1]=='#')
		goto fin1;
	if(key != 0){
	nlist[n] = (lookup[key-1]-'0');
				n++;
	dernum = dernum + 1;
	LCD_data(lookup[key-1]);
		Delay(300000);
	}
	}
/* we need to turn the data into one int*/

	
	fin1:
while (1){x= nlist[k];
	for (m=dernum-1;m!=0;m--){
	x=x*10;}
	total= x+total;
	k++;
	dernum--;
	if (dernum==0)
		goto calc1;
	
}
calc1:{total= 167*c[0]*total*total*total*total*total*total+200*c[1]*total*total*total*total*total+
	250*c[2]*total*total*total*total+333*c[3]*total*total*total+500*c[4]*total*total+1000*c[5]*total;
	l=total;
	}
	LCD_command(0xC0);
	LCD_data('E');
LCD_data('N');
	LCD_data('D');
	n=0;
		dernum=0;
		k=0;
	while (1){
		/* now we get the pt*/
		
Delay(300000);	
	key=keypad_getkey();
	if (lookup[key-1]=='#')
		goto fin2;
	if(key != 0){
	nlist[n] = (lookup[key-1]-'0');
				n++;
	dernum = dernum + 1;
	LCD_data(lookup[key-1]);
		Delay(300000);
	}
	}
/* we need to turn the data into one int*/

	
	fin2:
	total=0;
while (1){x= nlist[k];
	for (m=dernum-1;m!=0;m--){
	x=x*10;}
	total= x+total;
	k++;
	dernum--;
	if (dernum==0)
		goto calc2;
	
}
calc2:{total= 167*c[0]*total*total*total*total*total*total+200*c[1]*total*total*total*total*total+
	250*c[2]*total*total*total*total+333*c[3]*total*total*total+500*c[4]*total*total+1000*c[5]*total;
	trial=total;}
	
final = trial-l;
	LCD_command(0x01);
while (1){
	kalan= final %10;
final = final/10;
	replist[disp]= kalan + '0';
	if ((final== 0)%(kalan==0))
	goto next1;

	
	
disp++;

}

next1:fi=disp;
while (1) 
		{if(fi==2)
			{LCD_data('.');}
	LCD_data(replist[fi]);
	fi--;
	
	
	Delay(300000);
	if (fi==1-2)
		break;
}	

	
	}}
	
}
void LCD_init(void)
{
    SIM->SCGC5 |= 0x1000;       /* enable clock to Port D */ 
    PORTD->PCR[0] = 0x100;      /* make PTD0 pin as GPIO */
    PORTD->PCR[1] = 0x100;      /* make PTD1 pin as GPIO */
    PORTD->PCR[2] = 0x100;      /* make PTD2 pin as GPIO */
    PORTD->PCR[3] = 0x100;      /* make PTD3 pin as GPIO */
    PORTD->PCR[4] = 0x100;      /* make PTD4 pin as GPIO */
    PORTD->PCR[5] = 0x100;      /* make PTD5 pin as GPIO */
    PORTD->PCR[6] = 0x100;      /* make PTD6 pin as GPIO */
    PORTD->PCR[7] = 0x100;      /* make PTD7 pin as GPIO */
    PTD->PDDR = 0xFF;           /* make PTD7-0 as output pins */
    
    SIM->SCGC5 |= 0x0200;       /* enable clock to Port A */ 
    PORTA->PCR[2] = 0x100;      /* make PTA2 pin as GPIO */
    PORTA->PCR[4] = 0x100;      /* make PTA4 pin as GPIO */
    PORTA->PCR[5] = 0x100;      /* make PTA5 pin as GPIO */
    PTA->PDDR |= 0x34;          /* make PTA5, 4, 2 as output pins */
    
    LCD_command(0x38);      /* set 8-bit data, 2-line, 5x7 font */
    LCD_command(0x01);      /* clear screen, move cursor to home */
    LCD_command(0x0F);      /* turn on display, cursor blinking */
}

/* This function waits until LCD controller is ready to
 * accept a new command/data before returns.
 */
void LCD_ready(void)
{
    uint32_t status;
    
    PTD->PDDR = 0x00;          /* PortD input */
    PTA->PCOR = RS;         /* RS = 0 for status */
    PTA->PSOR = RW;         /* R/W = 1, LCD output */
    
    do {    /* stay in the loop until it is not busy */
			  PTA->PCOR = EN;
			  Delay(500);
        PTA->PSOR = EN;     /* raise E */
        Delay(500);
        status = PTD->PDIR; /* read status register */
        PTA->PCOR = EN;
        Delay(500);			/* clear E */
    } while (status & 0x80UL);    /* check busy bit */
    
    PTA->PCOR = RW;         /* R/W = 0, LCD input */
    PTD->PDDR = 0xFF;       /* PortD output */
}

void LCD_command(unsigned char command)
{
    LCD_ready();			/* wait until LCD is ready */
    PTA->PCOR = RS | RW;    /* RS = 0, R/W = 0 */
    PTD->PDOR = command;
    PTA->PSOR = EN;         /* pulse E */
    Delay(500);
    PTA->PCOR = EN;
}

void LCD_data(unsigned char data)
{
    LCD_ready();			/* wait until LCD is ready */
    PTA->PSOR = RS;         /* RS = 1, R/W = 0 */
    PTA->PCOR = RW;
    PTD->PDOR = data;
    PTA->PSOR = EN;         /* pulse E */
    Delay(500);
    PTA->PCOR = EN;
}

/* Delay n milliseconds
 * The CPU core clock is set to MCGFLLCLK at 41.94 MHz in SystemInit().
 */

/* delay n microseconds
 * The CPU core clock is set to MCGFLLCLK at 41.94 MHz in SystemInit().
 */


void Delay(volatile unsigned int time_del) {
  while (time_del--) 
		{
  }
}


void keypad_init(void)
{
    SIM->SCGC5 |= 0x0800;       /* enable clock to Port C */ 
    PORTC->PCR[0] = 0x103;      /* make PTC0 pin as GPIO and enable pullup*/
    PORTC->PCR[1] = 0x103;      /* make PTC1 pin as GPIO and enable pullup*/
    PORTC->PCR[2] = 0x103;      /* make PTC2 pin as GPIO and enable pullup*/
    PORTC->PCR[3] = 0x103;      /* make PTC3 pin as GPIO and enable pullup*/
    PORTC->PCR[4] = 0x103;      /* make PTC4 pin as GPIO and enable pullup*/
    PORTC->PCR[5] = 0x103;      /* make PTC5 pin as GPIO and enable pullup*/
    PORTC->PCR[6] = 0x103;      /* make PTC6 pin as GPIO and enable pullup*/
    PORTC->PCR[7] = 0x103;      /* make PTC7 pin as GPIO and enable pullup*/
    PTC->PDDR = 0x00;         /* make PTC7-0 as input pins */
}




uint32_t keypad_getkey(void)
{
    uint32_t row, col;
    const char row_select[] = {0x01, 0x02, 0x04, 0x08}; /* one row is active */

    /* check to see any key pressed */
    PTC->PDDR |= 0x0F;          /* rows output */
    PTC->PCOR = 0x0F;               /* ground rows */
    Delay(500);                 /* wait for signal return */
    col =  PTC->PDIR & 0xF0UL;     /* read all columns */
    PTC->PDDR = 0;              /*  rows input */
    if (col == 0xF0UL)
        return 0;               /* no key pressed */

    /* If a key is pressed, it gets here to find out which key.
     * It activates one row at a time and read the input to see
     * which column is active. */
    for (row = 0; row < 4; row++)
    {
        PTC->PDDR = 0;                  /* disable all rows */
        PTC->PDDR |= row_select[row];   /* enable one row */
        PTC->PCOR = row_select[row];    /* drive the active row low */
        Delay(500);                     /* wait for signal to settle */
        col = PTC->PDIR & 0xF0UL;         /* read all columns */
        if (col != 0xF0UL) break;         /* if one of the input is low, some key is pressed. */
    }
    PTC->PDDR = 0;                      /* disable all rows */
    if (row == 4) 
        return 0;                       /* if we get here, no key is pressed */
 
    /* gets here when one of the rows has key pressed, check which column it is */
    if (col == 0xE0UL) return row * 4 + 1;    /* key in column 0 */
    if (col == 0xD0UL) return row * 4 + 2;    /* key in column 1 */
    if (col == 0xB0UL) return row * 4 + 3;    /* key in column 2 */
    if (col == 0x70UL) return row * 4 + 4;    /* key in column 3 */

    return 0;   /* just to be safe */
}


