/*
 * Main Program for Project 3
 * Author: Robert Schriver
 * Author: Alex Crawford
 */

int main(void)
{
	curr_input_state = INPUT_STATE.CRYPTO;
	
}

void process_input(char * input)
{
	if(curr_input_state == INPUT_STATE.CRYPTO)
	{
		crypto_input(char * input);
		curr_input_state = INPUT_STATE.GUESS;
	}
	else if(curr_input_state == INPUT_STATE.GUESS)
	{
	}
}

long crypto_input(char * input)
{
	long * long_input = (long *) input;

	long seed;

	for(int i = 0; i < CRYPTO_LENGTH / 4; i ++)
	{
		seed ^= long_input + i;
	}

	return seed;
}
