/*
	Student Name: Italo Peirano

	Program Description: This program is a small calculator that adds, multiplies, 
	squares a number. It is important to know that this program  uses command line
	arguments as input, and process those inputs to produce the result of the 
	calculator.
	
	Affirmation of Originality: "I affirm that I wrote this program myself without
	any help from any other people or sources from the internet."	 
*/

#include <stdio.h>
#include <stdlib.h>

int debug = 0;

int main(int argc, char **argv)
{
	extern char *optarg; /* special variable that gets the argument of a flag */
	extern int optind; /* number of arguments not counting argv[0] */
	int c, err = 0; 
	int aflag = 0, mflag = 0, xflag = 0; /* control flags for processing */
	double value = 0;
	static char usage[] = "usage: minicalc [-a num] [-m num] [-x] value between 1 and 50\n";
	double num1 = 0;
	double num2 = 0;	
/*	
"a:m:x" means: "a" we have an a_flag, ":" with its corresponding argument
"m" we have an m_flag, ":" with its corresponding argument
"x" we have an X_flag with no argument
*/
	while ((c = getopt(argc, argv, "a:m:x")) != -1)
		switch (c) {
		case 'a':

			aflag = 1;
			num1 = atof(optarg); /* optarg gets the argument of -a flag */
			if(num1 <1 || num1 >500){
				fprintf(stderr, usage, argv[0]);
				exit(1);
			}
			break;
		case 'm':
			mflag = 1;
			num2 = atof(optarg); /* optarg gets the argument of -m flag */
			if(num2 <1 || num2 > 10){
				fprintf(stderr,usage,argv[0]);
				exit(1);
			}
			break;
		case 'x':
			xflag = 1;
			break;
		case '?':
			err = 1;
			break;
		}
 
	 if ((optind+1) > argc) {	
		/* 
 		need at least one argument (change +1 to +2 for two, etc. as needeed).
		if a flag is missing its corresponding argument an error message prints.
		*/
		printf("optind = %d, argc=%d\n", optind, argc);
		fprintf(stderr, "%s: missing name\n", argv[0]);
		fprintf(stderr, usage, argv[0]);
		exit(1);
	} else if (err) {
		fprintf(stderr, usage, argv[0]);
		exit(1);
	}
	
	if (optind < argc)
	/* these are the arguments, after the flags with their arguments */
		for ( ; optind < argc; optind++){
			printf("argument: \"%s\"\n", argv[optind]);
			value = atof(argv[optind]);
			if(value < 1 || value >50){
				fprintf(stderr,usage,argv[0]);
				exit(1);
			}
		}
	else {
		printf("no arguments left to process\n");
	}
	/* Processing of the command argument */
	if(xflag == 1){
		value  = value * value;
		 
	}
	if(mflag ==1 ){
		value = value * num2;
	}	
	if(aflag == 1){
		value = value + num1;
	}
	
	/* Prints result */
	printf("the result is : %.2f\n",value);

		
	exit(0);
}
