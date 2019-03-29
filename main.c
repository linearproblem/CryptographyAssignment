/******************************************************************************
INCLUDE LIBRARIES
******************************************************************************/
#include <stdio.h>


/******************************************************************************
DECLARE FUNCTIONS
******************************************************************************/
void helloWorld(); // Prints the text "Hello World into the console"
void encryptString();
// ADD ZERO ARRAYS


/******************************************************************************
MAIN
******************************************************************************/
int main(){
  // Runs hello world function
    void helloWorld();

  // Runs text encrytion function
    encryptString();

    return 0;
}


/******************************************************************************
EXTERNAL FUNCTIONS
******************************************************************************/

void helloWorld(){
/* Prints the text "Hello World" into the console*/
  printf("Hello World");    
};


void encryptString(){
/* Collects text from user input and runs encryption function */
	int MAXCHAR = 300; // Sets maximum characters that can be typed in
	
	// Collects and stores user entered characters
	char textString[MAXCHAR];
	char textInteger[MAXCHAR];

		// Initialise both arrays (FIX - External Function)
		for(int index = 0; index<MAXCHAR; index++){
			textString[index] = 0;
			textInteger[index] = 0;
		}
		
	// Collects and stores user entered characters
	printf("\nPlease Enter Text to Encrypt\n"); 
	fgets(textString,MAXCHAR,stdin); //stores user input into a string
  

	



/*
	0 = A, B = 1 e.c.t.
	letterValue[]%27
*/

// Prints output
  for(int index = 0; index<5 ; index++){
	printf("%d\n",(int)textString[index]);  
	
	// Convert capitals letters into numbers A = 0, B = 1, C = 2... e.c.t.
	if(textInteger[index]>=65||textInteger[index]<=90){ // Makes sure input is only capital letters
		textInteger[index]=(int)textString[index]-65; 	// Converts string into textIntegerbers (and then makes them between 0 and 99)
		printf("works\n"); \\FIX WAS JUST FOR TEST
	}else{
	// Array entered doesn't include only capital letters
		printf("ERROR: only enter in text");
	};
	
	printf("%d\n",textInteger[index]);
	break;
/* 10 for quiz, 12.5 for assignment
LOWERCASE STUFF FOR LATER
97<= numberval <=122
*/
}
};
