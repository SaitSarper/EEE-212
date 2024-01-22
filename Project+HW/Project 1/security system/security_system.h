#include <MKL25Z4.H>
#include <stdio.h>

typedef struct database{
	// This struct represents a user
	uint32_t id;
	uint32_t pw;
	uint16_t valid;
}database;

void Delay(volatile unsigned int time_del);
void LCD_command(unsigned char command);
void LCD_data(unsigned char data);
void LCD_init(void);
void LCD_ready(void);
void keypad_init(void);
void print_fnc(char* text);
int user_check(database* user_list);
void user_add(uint32_t id, uint32_t pw, database* user_list);
void user_delete(uint32_t id, database* user_list);
uint32_t keypad_getkey(void);
uint32_t get_number_from_keypad(void);
char get_command_from_keypad(void);
void database_init(database* user_list);

