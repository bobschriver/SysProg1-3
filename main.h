#include "c_io.h"
#include "rngs.h"
#include "support.h"

#define TRUE 1
#define FALSE 0

#define CRYPTO_LENGTH 12


//For use with crypto input
char crypto_buffer [ CRYPTO_LENGTH ];
char * next_input_char;
int crypto_buffer_remaining;

long clock_counter;

void process_input(char input);

//Used to store the current input state
enum INPUT_STATE
{
	NONE,
	BEEP,
	CRYPTO,
	GUESS
} curr_state;
