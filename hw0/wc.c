#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int lines = 0;
int words = 0;
int chars = 0;

int ignoreSpace = 1; // handle space at the beggining
int ignoreLine = 1; // handle blank line at the beggining
int c;

int main(int argc, char *argv[]) {
    
	if (argc == 2) {
		FILE *fp = fopen(argv[1],"r");
		if (!fp) {
			fprintf(stderr, "Unable to open file %s. Exiting.\n", argv[1]);
			exit(1);
		}
		doIt(fp);
	}	
}

int doIt(FILE *fp) {
	while ((c = getc(fp)) != EOF) {
		if( c == '\t' || c == ' ') {
			if(!ignoreSpace) {
				words++;
				ignoreSpace = 1;
			}
		} else {
			ignoreSpace = 0;
		}
		
		if(c == '\n') {
			if(!ignoreLine) {
				lines++;
				words++;
				ignoreLine = 1;
			} else {
				lines++;
				ignoreLine = 0;
			}
		}

		chars++;
	}
	printf (" %d  %d %d \n", lines, words, chars);
	return 0;
}