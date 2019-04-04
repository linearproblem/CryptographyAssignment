/******************************************************************************
TODO:

******************************************************************************/



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
void encryptString(); // ENCRYPT rotation Cipher String
encryptString();



/******************************************************************************
MAIN
******************************************************************************/
int main(){
    // Prints application header
         //printHeader();
    // Opens user menu
       //  mainMenu();

    // Runs text encryption function
        encryptString();
        
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
/******************************************************************************
TODO:
- Use cleaner looking header

******************************************************************************/
}

void mainMenu() {
    // Display menu options
    printf("\t Press 1 for Rotation Cipher\n");
    printf("\t Press 2 for Substitution Cipher\n");
    // Collect user selection
    int userInput;
    scanf("%d",&userInput); // Record User Input
    printf("%d",userInput);
    switch (userInput) {

        case 1:
       //     Rotation Ciper function FIX
            break;

        case 2:

        case 3:


        default:
            printf("\nYou have Not Made A Selection");
            break;
    }
}


void encryptString(){
    /* Collects text from user input and runs encryption function */
	int MAXCHAR = 300; // Sets maximum characters that can be typed in
	int key = -1;
	
	// Collects and stores user entered characters
	char textString[MAXCHAR];
	int textInteger[MAXCHAR]; // Stores encrypted text as in values

		// Initialise both arrays (FIX - External Function)
		for(int index = 0; index<MAXCHAR; index++){
			textString[index] = 0;
			textInteger[index] = 0;
			/*
            TODO:
            - Add zero'ing function here to clean up code         
            **/
		}
		
    // Collects input string from console
	printf("\nPlease Enter Text to Encrypt\n"); 
	fgets(textString,MAXCHAR,stdin); //stores user input into a string
	
	// Convert sring values into integer equvilants
	for(int index = 0; index<MAXCHAR; index++){
        textInteger[index] = textString[index];
	}

 
/******************************************************************************
TODO:
x Collect input data
x Convert string (char) to integer
x Convert any lowercase characters to uppercase
x Convert all characters to a replacement number from 0-25
- Add key variable from -25 to 25
    - Collect key from user (later)
- 

******************************************************************************/
	

// TODO: convert lowercase to uppercase (TEST!!!)

	// Convert lowercase characters to uppercase
	for(int index = 0; index<MAXCHAR; index++){
	    if (textInteger[index]>=97&&textInteger[index]<=122){ // Checks if the ACII letter is in the lowercase range i.e [97(a) to 122(z)]
            textInteger[index] = textInteger[index] - 32;   // 97(letter a) - 32 = 65(letter A)         
	    }
	}




/*
 * 
 *  Convert uppercase letters (ONLY) from ACII letters to num(0-25 equiv)
 *  Applies the key
 * 
 * 
 */

/*  PRINT COMMANDS USED FIX
    printf("ORIG LETR VALUE: %c\n",textString[index]);
	printf("UNENCRYPT VALUE: %d\n",(int)textString[index]);  // Prints output (TEMP)
	printf("ZRO-TWENT VALUE: %d\n",textInteger[index]);
	printf("ENCRYPTED VALUE :%c\n\n",textInteger[index]); // prints current value of integer
*/
    
    for(int index = 0; index<MAXCHAR; index++){ // FIX MAKE MAX VALUE 
	
    	// Convert capitals letters into numbers A = 0, B = 1, C = 2... e.c.t.
    	if(textInteger[index]>=65&&textInteger[index]<=90){ // Makes sure it only converts capital letters
    	
    	   // Converts string into text Integers (and then makes them between 0 and 99)
    	   textInteger[index]=textInteger[index]-65; 	
        
    		
    	// TODO: key from -25 to 26 which adds a value onto the characters (-24 = 24?) where 26 - 0	
    	   // Adds key value onto code
    	   textInteger[index] = (textInteger[index]+key)%26;
    	   
    	   // Loops some letters around if a -ve key is given (only for required letters)
    	   if(textInteger[index]<0){
    	       textInteger[index] = textInteger[index] + 26; 
    	   }
        // TODO: CONVERT BACK TO FULLCAPS
            textInteger[index]=textInteger[index]+65; 
        }//END IF
    }
// PRINT STRING
    printf("INPUT STRING:\n");
	for(int index = 0; index<MAXCHAR; index++){
	printf("%c",textString[index]);
	}
	printf("\n\nOUTPUT STRING:\n");
	for(int index = 0; index<MAXCHAR; index++){
	printf("%c",textInteger[index]);
	}



};


/* 10 for quiz, 12.5 for assignment
LOWERCASE STUFF FOR LATER
97<= numberval <=122
*/

// test update