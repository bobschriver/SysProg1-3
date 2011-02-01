#include "c_io.h"

#define TRUE 1
#define FALSE 0

#define CRYPTO_LENGTH 12


//For use with crypto input
char * crypto_input;
char * next_input_char;
int buffer_remaining;

void process_input(char input);

//Used to store the current input state
enum INPUT_STATE
{
	NONE,
	CRYPTO,
	GUESS
} curr_state;
