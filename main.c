/*
 * Main Program for Project 3
 * Author: Robert Schriver
 */

#include "main.h"

int main(void)
{
	curr_input_state = CRYPTO;
	crypto_buffer_remaining = CRYPTO_LENGTH;	

	__install_isr( INT_VEC_TIMER , clock_isr);

	asm("sti");
	
	c_puts("Enter Crypto Input\n");

	//get_crypto_input();

	c_puts("Done Crypto Input\n");

	curr_input_state = GUESS;

	get_guess_input();
}

void get_crypto_input(void)
{
	while(crypto_buffer_remaining > 0)
	{
		c_puts("before enter character\n");
		char input = c_getchar();
		c_puts("after enter character\n");
		
		//c_putchar(input);
		process_input(input);
	}

	process_crypto_input(crypto_buffer);
}

void get_guess_input(void)
{
	while(1)
	{
		//c_puts("waiting for interrupts\n");
	}
}

void process_input(char input)
{
	if(curr_input_state == CRYPTO)
	{
		if(crypto_buffer_remaining > 0)
		{
			crypto_buffer_remaining--;
			*next_input_char = input;
			next_input_char++;
		}
		else
		{
			curr_input_state = BEEP;
		}
	}
	else if(curr_input_state == GUESS)
	{
	}
	else if(curr_input_state == BEEP)
	{
		c_putchar('\a');	
	}
}

void process_crypto_input(char * input)
{
	long * long_input = (long *) input;

	long seed;

	int i;

	for(i = 0; i < CRYPTO_LENGTH / 4; i ++)
	{
		seed ^= *(long_input + i);
	}

	c_printf("%o" , seed);
	
	PutSeed(seed);
}

void input_output_isr(int vector , int code)
{
}

void increment_clock_counter(void)
{
	if(curr_input_state == GUESS)
	{
		clock_counter++;
		c_puts("clock interrupt\n");
	}
}

void clock_isr(int vector, int code)
{
	increment_clock_counter();
	__outb( PIC_SLAVE_CMD_PORT , PIC_EOI );
	c_printf("%o %o\n" , vector , code);
}


