#include <stdio.h>
#include <stdlib.h>

#include <editline/readline.h>
#ifndef __APPLE__
/* Apple includes add_history in the main readline header */
#include <editline/history.h>
#endif /*__APPLE__*/

int main(int argc, char **argv) {
    /* Print version and exit information */
    puts("Lispy Version 0.0.0.0.1");
    puts("Press Ctrl+C to Exit\n");

    /* in a never ending loop */
    while (1) {
        /* Output our prompt and get input */
        char *input = readline("lispy> ");

	/* add input to history */
	add_history(input);

	/*Echo input back to user */
	printf("No you're a %s\n", input);

	/* free retrieved input */
	free(input);
    }
    
    return 0;
}
