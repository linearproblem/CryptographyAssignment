/******************************************************************************
INCLUDE LIBRARIES
******************************************************************************/
#include <stdio.h>

// test upload from app

/******************************************************************************
DECLARE FUNCTIONS
******************************************************************************/
void printHeader();
void mainMenu();
void helloWorld(); // Prints the text "Hello World into the console"
void encryptString();
// ADD ZERO ARRAYS

void guessNum();


/******************************************************************************
MAIN
******************************************************************************/
int main(){
   // guessNum();

    // Prints application header
          printHeader();
    // Opens user menu
         mainMenu();
    // Runs hello world function
        helloWorld();

    // Runs text encryption function
        //encryptString();
        int x;
    scanf("%d",&x); // temp delay
    return 0;
}


/******************************************************************************
EXTERNAL FUNCTIONS
******************************************************************************/

void printHeader(){
    // Prints splash back
    printf("+-----------------------------------------------------------------------------------+\n");
    printf("|                                                                                   |\n");
    printf("|     XXXXXXXXX  XXXXXXXXX  XXXXXXXXXXXXX    X         X  XXXXXXXXXXX  XXXXXXXXXXX  |\n");
    printf("|   XXX              X      X           X    X         X  X            X         XX |\n");
    printf("|  XX                X      X           XX   X         X  X            X          X |\n");
    printf("| XX                 X      X           XX   X         X  X            X          X |\n");
    printf("| X                  X      X           X    X         X  X            X          X |\n");
    printf("| X                  X      XXXXXXXXXXXX     XXXXXXXXXXX  XXXXXXXX     XXXXXXXXXXXX |\n");
    printf("| X                  X      XX               X         X  X            X   XX       |\n");
    printf("| X                  X      X                X         X  X            X    XXX     |\n");
    printf("| XX                 X      X                X         X  X            X      XXX   |\n");
    printf("|  XXX               X      X                X         X  X            X        XX  |\n");
    printf("|    XXXXXXXXXX  XXXXXXXXX  X                X         X  XXXXXXXXXXX  X         XX |\n");
    printf("|                                                                                   |\n");
    printf("+-----------------------------------------------------------------------------------+\n");
}

void mainMenu() {
    // Run Hello World Function
    printf("\t Press 1 for Hello World\n");
    printf("\t Press 2 for Rotation Cipher\n");
    printf("\t Press 3 for Substitution Cipher\n");

    int userInput;
    scanf("%d",&userInput); // Record User Input
    printf("%d",userInput);
    switch (userInput) {

        case 1:
            helloWorld();
            break;

        case 2:

        case 3:


        default:
            printf("\nYou have Not Made A Selection");
            break;
    }
}

void helloWorld(){

// Silly ACII Art printed to console, as displayed below
    printf("+--------------------------------------------+\n");
    printf("|  X                  X    X                 |\n");
    printf("|  X                  X    X                 |\n");
    printf("|  X                  X    X                 |\n");
    printf("|  X                  X    X                 |\n");
    printf("|  X                  X    X                 |\n");
    printf("|  XXXXXX   XXXXXXXX  X    X      XXXX       |\n");
    printf("|  XX   XX  XX     X  X    X    XX    XX     |\n");
    printf("|  X     XX XXXXXXX   X    X   XX      XX    |\n");
    printf("|  X      X X         X    X    XX    XX     |\n");
    printf("|  X      X  XXXXX    X    X      XXXX       |\n");
    printf("|                                            |\n");
    printf("|                                            |\n");
    printf("|  X         X                           XX  |\n");
    printf("|  X        XXX             XX  X        XX  |\n");
    printf("|  X   XX     X          XXX XX X        XXX |\n");
    printf("|  X   XX     X  XXXXXX  X    X X         XX |\n");
    printf("|  X XXXX    X  XX    XX X      X  XXXXX XXX |\n");
    printf("|   X   X   XX  X    XX  X      X  XX  XXXXX |\n");
    printf("|       XXXXX   XXXXX    X      X   XXX    X |\n");
    printf("|                                            |\n");
    printf("+--------------------------------------------+\n");


/* Prints the text "Hello World" into the console*/
  printf("\n\tHello World\n\n\n\n\n");
  mainMenu();
};


void encryptString(){
/* Collects text from user input and runs encryption function */
	int MAXCHAR = 300; // Sets maximum characters that can be typed in
	
	// Collects and stores user entered characters
	char textString[MAXCHAR];
	int textInteger[MAXCHAR];

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
	if(textString[index]>=65&&textString[index]<=90){ // Makes sure input is only capital letters
		textInteger[index]=(int)textString[index]-65; 	// Converts string into text Integers (and then makes them between 0 and 99)
		printf("works\n"); //FIX WAS JUST FOR TEST
	}else{
	// Array entered doesn't include only capital letters
		printf("ERROR: only enter text in capital letters\n\n");
        encryptString(); // Restarts Function
	};
	
	printf("%d\n",textInteger[index]); // prints current value of integer
	break;
/* 10 for quiz, 12.5 for assignment
LOWERCASE STUFF FOR LATER
97<= numberval <=122
*/
}
};
