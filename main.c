/*
 * Main Program for Project 3
 * Author: Robert Schriver
 */

#include "main.h"

int main(void)
{
	curr_input_state = INPUT_STATE.CRYPTO;

	__install_isr( INT_VEC_TIMER , clock_isr);
	
	c_puts("Enter Crypto Input");

	get_crypto_input();

	c_puts("Done Crypto Input");

	curr_input_state = INPUT_STATE.GUESS;

	get_guess_input();
}

void get_crypto_input()
{
	while(crypto_buffer_remaining > 0)
	{
		char input = c_getchar();
		process_input(input);
		c_putchar(input);
	}

	process_crypto_input(crypto_buffer);
}

void get_guess_input()
{
}

void process_input(char input)
{
	if(curr_input_state == INPUT_STATE.CRYPTO)
	{
		if(crypto_buffer_remaining-- > 0)
		{
			next_input_char = input;
			next_input_char++;
		}
		else
		{
			curr_state = INPUT_STATE.BEEP;
		}
	}
	else if(curr_input_state == INPUT_STATE.GUESS)
	{
	}
	else if(curr_state == INPUT_STATE.BEEP)
	{
		c_putchar("\a");	
	}
}

void process_crypto_input(char * input)
{
	long * long_input = (long *) input;

	long seed;

	for(int i = 0; i < CRYPTO_LENGTH / 4; i ++)
	{
		seed ^= *(long_input + i);
	}

	PutSeed(crypto_seed);
}

void input_output_isr(int vector , int code)
{
}

void increment_clock_counter()
{
	if(curr_input_state == INPUT_STATE.GUESS)
	{
		clock_counter++;
		c_puts("clock interrupt");
	}
}

void clock_isr(int vector, int code)
{
	increment_clock_counter();
}


