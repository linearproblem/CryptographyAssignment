/******************************************************************************
TODO:
 - Setup menu structure
 - Connect random seed with the rotation cipher
    - Add in sections/todos with information bout other key entry options

******************************************************************************/
/******************************************************************************
LAYOUT

 Rotation Cipher
    - Encrypt
        - Provide Key
        - Generate Random Key
    - Decrypt
        - With Key
        - Without Key (automatic)
 Substitution Cipher
    - Encrypt
        - Give table of values in csv
    - Decrypt
        - Using csv key file
        - Automatic Decryption
******************************************************************************/


/******************************************************************************
INCLUDE LIBRARIES
******************************************************************************/
#include <stdio.h>
#include <stdlib.h> // Used for the random function
#include <time.h>   // Used to get seed for random number generator


/******************************************************************************
DECLARE FUNCTIONS
******************************************************************************/
// User Interface
void printHeader();
void mainMenu();
    // Sub-Menu
        // Rotation Cipher
            // User key
            // Generate Key
            // Please enter key
                // Encrypt
                    // key = key, pass onto function
                // Decrypt
                    // key = -key, pass onto function
        // Substitution Cipher

// Encryption/Decryption Functions
void encryptString(); // ENCRYPT rotation Cipher String
int generateKey(); // Generates a key (1 to 25) for rotation and substitution cipher

// Zeroing Functions
void zeroCharArray(char arrayName[], int arraySize); // Sets all values in a char type array to zero
void zeroIntegerArray(int arrayName[], int arraySize); // Sets all values in an integer type array to zero


/******************************************************************************
MAIN
******************************************************************************/
int main(){
        // Prints application header
         printHeader();
    // Opens user menu
       mainMenu();

    // Runs text encryption function
     // encryptString();
    int tmp = generateKey();
   scanf("%d",&tmp); // temp delay
    printf("print test");

    return 0;
}

/******************************************************************************
EXTERNAL FUNCTIONS
******************************************************************************/

void printHeader(){
    // Prints splash back
    printf(" _____              _       ___  _         _                 \n");
    printf("/__   \\  ___ __  __| |_    / __\\(_) _ __  | |__    ___  _ __ \n");
    printf("  / /\\/ / _ \\ \\/ /| __|   / /   | || '_ \\ | '_ \\  / _ \\| '__|\n");
    printf(" / /   |  __/ >  < | |_  / /___ | || |_) || | | ||  __/| |   \n");
    printf(" \\/     \\___|/_/\\_\\ \\__| \\____/ |_|| .__/ |_| |_| \\___||_|   \n");
    printf("                                   |_|                       \n");
    printf("+----------------------------------------------------+\n");

/******************************************************************************
TODO:
- Use cleaner looking header

******************************************************************************/
}

void mainMenu() {
    printf("\n-- Main Menu --\n");
    // Display menu options
    printf("\tRotation Cipher\n");
        printf("\t\t 1: Encrypt text\n");
        printf("\t\t 2: Decrypt text with key\n");
        printf("\t\t 3: Decrypt text without key\n");
    printf("\n\tSubstitution Cipher\n");
         printf("\t\t 4: Encrypt text\n");
         printf("\t\t 5: Decrypt text with key\n");
        printf("\t\t 3: Decrypt text without key\n");

    // Collect user selection
    int userInput;
    printf("\nPlease Select an Option:");
    scanf("%d",&userInput); // Record User Input
    printf("%d",userInput);
    switch (userInput) {

        case 1:
       //     Rotation Cipher function FIX
            break;

        case 2:
        //
        case 3:


        default:
            printf("\nYou have Not Made A Selection");
            break;
    }
}



void encryptString(){
    /* Collects text from user input and runs encryption function */
	int MAXCHAR = 300; // Sets maximum characters that can be typed in

	
	// Collects and stores user entered characters
	char textString[MAXCHAR];
	int textInteger[MAXCHAR]; // Stores encrypted text as in values
    for(int index = 0; index<MAXCHAR; index++){
        textInteger[index] = textString[index];
    }

    // Initialise both arrays using function
    zeroCharArray(textString, MAXCHAR);
    zeroIntegerArray(textInteger, MAXCHAR);


    // Collects input string from console
	printf("\nPlease Enter Text to Encrypt\n"); 
	fgets(textString,MAXCHAR,stdin); //stores user input into a string
        //TODO: Collect text input from user specified file

    // User selects where key is to come from
        int key;
         key = -19;           // HARDCODED KEY
         printf("Please Enter Key:");
         scanf("%d",&key);                      // USER INPUT KEY
         printf("\tYou Entered: %d",key);
        //key = generateKey();    //GENERATED KEY
                                // KEY FROM FILE
    // prints both versions of generated key, do not use when using user provided key
        printf("\nKEY IS:%d (or %d)\n",key,-(26-key));


	// Convert char values into integer equivalents
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
/* Converts key to a number from 0 to 25
 *
 * For example, if  key = -2    (For E=5: [5+-2]%26 = 3 or C)
 *          same as key =  24   (For E=5: [5+24]%26 = 3 or C)
 *
 * */
    int userInput;
    printf("1(encrypt)\n2(decrypt)\n");
    scanf("%d",&userInput); // Record User Input
    printf("%d",userInput);
    switch (userInput) {

        case 1: // Leave key as is
            break;
        case 2:
            key = -key;
            break;
        default:
            printf("\nYou have Not Made A Selection");
            break;
    }
    if(key>=-26&&key<=26){
        if(key<0){
            key = 26+key;
        }

    }else{
        // Gives user an error when key value is not between -26 and 26
        printf("The provided key is invalid\n");
    }

// Encrypt key = key
// Decrypt key = 26-key


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
    
    for(int index = 0; index<MAXCHAR; index++){
	
    	// Convert capitals letters into numbers A = 0, B = 1, C = 2... e.c.t.
    	if(textInteger[index]>=65&&textInteger[index]<=90){ // Makes sure it only converts capital letters
    	
    	   // Converts string into text Integers (and then makes them between 0 and 99)
    	   textInteger[index]=textInteger[index]-65; 	
        
    		
    	// TODO: key from 0 to 26 which adds a value onto the characters (-24 = +2)
    	   // Adds key value onto code
    	   textInteger[index] = (textInteger[index]+key)%26;
    	   
//    	   // Loops some letters around if a -ve key is given (only for required letters)
//    	   if(textInteger[index]<0){
//    	       textInteger[index] = textInteger[index] + 26;
//    	   }
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

//printf("%d",textInteger);

};

/* Initialises random number generator the first time it is run
 * Uses current system time to generate random-ish number between 0-25
 *
 *
 *
 * */
int generateKey(){
    static int count = 0; // Records whether or not the function has been run 0 = never run, 1 = has run before
    int key;          // Initialises key

    /* Initialises random number generator the first time it is run*/
    if (count ==0) {
        time_t seed; // Gets current system time to use as seed
        srand((unsigned) time(&seed)); // Gives time in seconds as seed
        count++; // Sets count to 1, so key is not regenerated each time function is called
    }

    key = rand() % 25 + 1 ; // Gives key from 1 to 25 (because 0 and 26 are unencrypted)
    return key;
}


void zeroCharArray(char arrayName[], int arraySize){
// in above line can use *arrayName or arrayName[]
/* Sets all values in an array to 0;
 * */
    for (int index = 0; index<arraySize; index++){
        arrayName[index] = 0;
    }
};
void zeroIntegerArray(int arrayName[], int arraySize){
// in above line can use *arrayName or arrayName[]
/* Sets all values in an array to 0;
 * */
    for (int index = 0; index<arraySize; index++){
        arrayName[index] = 0;
    }
};