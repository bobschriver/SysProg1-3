#include "c_io.h"
#include "rngs.h"
#include "support.h"
#include "x86arch.h"
#include "startup.h"

#define TRUE 1
#define FALSE 0

#define CRYPTO_LENGTH 12


//For use with crypto input
char crypto_buffer [ CRYPTO_LENGTH ];
char * next_input_char;
int crypto_buffer_remaining;

long clock_counter;


void get_crypto_input(void);
void get_guess_input(void);


void process_input(char input);
void process_crypto_input(char * input);
void increment_clock_counter(void);


void input_output_isr(int vector , int code);
void clock_isr(int vector, int code);



//Used to store the current input state
enum INPUT_STATE
{
	NONE,
	BEEP,
	CRYPTO,
	GUESS
};

enum INPUT_STATE curr_input_state;
