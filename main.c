/******************************************************************************
TODO:
 - PUT MENU IN MAIN FUNCTION
 x Connect random seed with the rotation cipher
 Substitution Cipher
     x Random key with sub cipher
    - Use key to encrypt
    - Use key to decrypt

Auto Decrypt
    - Rotation Cipher
    - Substitution Cipher

    - Add in sections/todos with information bout other key entry options


- Fix application exit
- Test encrypt vs decrypt

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

// Changes console text colour
#define GREEN   "\x1b[32m"   // Green for header
#define CYAN    "\x1b[36m"   // Cyan for user entered text
#define RED     "\x1b[31m"   // Red for errors
#define YELLOW "\x1b[33m"    // Yellow for console output
#define RESET   "\x1b[0m"    // Default (white) for menu and other text
    // USAGE:     printf(RED "This is an error\n" RESET); 

/******************************************************************************
DECLARE FUNCTIONS (Function Prototypes)
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
void rotationCipher(int direction); // ENCRYPT and DECRYPT using rotation Cipher String
void substitutionCipher();
int generateKey(); // Generates a key (1 to 25) for rotation and substitution cipher
void analyseText();

// Zeroing Functions
void zeroCharArray(char arrayName[], int arraySize); // Sets all values in a char type array to zero
void zeroIntegerArray(int arrayName[], int arraySize); // Sets all values in an integer type array to zero

void clearStdin(); // clears standard input (resolves fgets error)


/******************************************************************************
MAIN
******************************************************************************/
int main(){
    analyseText();
        //substitutionCipher();
    // Prints application header
        //printHeader();
    // Opens user menu
     //   mainMenu();

    // Runs text encryption function
      //rotationCipher();
    int tmp = generateKey();
    scanf("%d",&tmp); // temp delay
    getchar();
    printf("print test");

    return 0;
}

/******************************************************************************
EXTERNAL FUNCTIONS
******************************************************************************/
void printHeader(){
    // Prints splash back
    printf(GREEN); // Sets header colour to green
    printf(" _____              _       ___  _         _                 \n");
    printf("/__   \\  ___ __  __| |_    / __\\(_) _ __  | |__    ___  _ __ \n");
    printf("  / /\\/ / _ \\ \\/ /| __|   / /   | || '_ \\ | '_ \\  / _ \\| '__|\n");
    printf(" / /   |  __/ >  < | |_  / /___ | || |_) || | | ||  __/| |   \n");
    printf(" \\/     \\___|/_/\\_\\ \\__| \\____/ |_|| .__/ |_| |_| \\___||_|   \n");
    printf("                                   |_|                       \n");
    printf(RESET); // Resets back to white
    printf("+------------------------------------------------------------+\n");
}
void mainMenu() {
    printf("\n-- Main Menu --\n");
    // Display menu options
    printf("\tRotation Cipher\n");
        printf("\t\t 1: Encrypt text with key\n");
        printf("\t\t 2: Encrypt text with random key\n");
        printf("\t\t 3: Decrypt text with key\n");
        printf("\t\t 4: Decrypt text without key\n");
    printf("\n\tSubstitution Cipher\n");
        printf("\t\t 5: Encrypt text\n");
        printf("\t\t 6: Decrypt text with key\n");
        printf("\t\t 7: Decrypt text without key\n");
    printf("\n\tOther\n");
        printf("\t\t 0: Exit Application\n");

    // Collect user selection
    int userInput = 0; // Initialises the user input selection to make sure it is not equal to 7
    
    while (userInput != 7){ // Repeats menu selection until user decides to exit
        printf("\nPlease select an option:"CYAN);
        scanf("%d",&userInput); // Record User Input
        printf(RESET);// Changes console text back to white
      //  printf("%d" RESET,userInput);
        switch (userInput) {
    
            case 1:
             // Rotation Cipher function encrypt
                rotationCipher(userInput); // Sends direction
                break;
            case 2:
            // Generate random key
                rotationCipher(userInput); // Sends direction
                break;
            case 3:
                // Rotation Cipher function decrypt with key
                rotationCipher(userInput);
                break;
            case 4:
                // Rotation Cipher function decrypt without key
                break;
            case 6:
            //
                break;
            case 0: 
                // Exit application
                printf("You have chosen to leave");//TEMP FIX
                break;
                //return 0; // use when in main control
            default:
                printf(RED"Selection invalid\n"RESET);
                break;
        }
        
    }

}

void rotationCipher(int direction){
    // direction specifies whether the function is meant to decrypt or encrypt the text
    // it is used later on in the function in a switch case argument
            // 1 = encrypt using given key
            // 2 = decrypt using given key
            // 3 = decrpyt automatically
            // 4 = encrypt using random key
        
    /********************************
    Collect Encyption Key from User
    *********************************/
    // User selects where key is to come from
     int key = 0;
     //key = -19;           // HARDCODED KEY FIX(remove)
                                // KEY FROM FILE

    switch (direction){
        case 1: // Encrypt with given key
           printf("Please Enter Key:"CYAN);
           scanf("%d",&key);          // USER INPUT KEY
           printf(RESET"You entered:"YELLOW"%d\n"RESET,key);
           break;
        case 2:// Encrypt with random key
            while(key == 0) { // Makes sure key is not zero
                key = generateKey(); // Gets generated key from function (returns 0 to 25)
            }
            // prints both versions of generated key
            printf("Generated key is:"YELLOW"%d (or %d)\n"RESET,key,-(26-key));
            break;
        case 3: // Decrypt with given key
           printf("Please Enter Key:"CYAN);
           scanf("%d",&key); // USER INPUT KEY
           printf(RESET"You entered:"YELLOW"%d\n"RESET,key);
            // Encrypt key = key
            // Decrypt key = 26-key (Changes key so it reverses encryption)
            key = -key;
            break;
        case 4:
        default:
            printf(RED"Fatal error, this should never happen"RESET);
            break;
    }
    
    if(key>=-26&&key<=26){ // Checks key is valid
        if(key<0){
            /* Converts key to a number from 0 to 25
            *
            * For example, if  key = -2    (For E=5: [5+-2]%26 = 3 or C)
            *          same as key =  24   (For E=5: [5+24]%26 = 3 or C)
            *
            * */
            key = 26+key;
        }
    }else{
        // Gives user an error when key value is not between -26 and 26
        printf("The provided key is invalid\n");
    }
    
    /********************************
    Collect Input Text
    *********************************/

    /* Collects text from user input and runs encryption function */
	int MAXCHAR = 300; // Sets maximum characters that can be typed in
	// Collects and stores user entered characters
	char textString[MAXCHAR];
	int textInteger[MAXCHAR]; // Stores text as integer values


    // Initialise both arrays using function
    zeroCharArray(textString, MAXCHAR);
    zeroIntegerArray(textInteger, MAXCHAR);

    // Collects input string from console
	printf("\nPlease Enter Text to Encrypt\n "); 
	getchar(); // Clears console (input stream - https://stackoverflow.com/questions/26318275/fgets-skipping-inputs)
	fgets(textString,MAXCHAR,stdin); //stores user input into a string
        //TODO: Collect text input from user specified file
        
    /********************************
    Perform Encryption/Decryption Using key
    *********************************/

	// Convert char values into integer equivalents
	for(int index = 0; index<MAXCHAR; index++){
        textInteger[index] = textString[index];
	}

	// Convert lowercase characters to uppercase
	for(int index = 0; index<MAXCHAR; index++){
	    if (textInteger[index]>=97&&textInteger[index]<=122){ // Checks if the ACII letter is in the lowercase range i.e [97(a) to 122(z)]
            textInteger[index] = textInteger[index] - 32;   // 97(letter a) - 32 = 65(letter A)         
	    }
	}
    
    for(int index = 0; index<MAXCHAR; index++){
	
    	// Convert capitals letters into numbers A = 0, B = 1, C = 2... e.c.t.
    	if(textInteger[index]>=65&&textInteger[index]<=90){ // Makes sure it only converts capital letters (leaves spaces)
    	   textInteger[index]=textInteger[index]-65; 	
        
    	   // Adds key value onto code
    	   textInteger[index] = (textInteger[index]+key)%26;

            // Convert text back to capital letters
            textInteger[index]=textInteger[index]+65; 
        }//END IF
    }
    
// PRINT STRING
    printf("\nINPUT STRING:\n");
	for(int index = 0; index<MAXCHAR; index++){
	printf(YELLOW"%c"RESET,textString[index]);
	}
	printf("\nOUTPUT STRING:\n");
	for(int index = 0; index<MAXCHAR; index++){
	printf(YELLOW"%c"RESET,textInteger[index]);
	}

//printf("%d",textInteger);

};
void substitutionCipher(){
/********************************
 Setup Encryption key
*********************************/
                //   A, B, C,D,E,F, G,H, I, J, K, L, M, N, O, P, Q, R, S,T,U,V, W, X,Y,Z
    int subKey[26]= {5,14,19,0,1,4,25,6,22,11,13,10,15,12,20,18,24,21,16,9,7,2,17,23,8,3}; // Hard coded Array
                //   F, O, T,A,B,E, Z,G, W, L, N, K, P, M, U, S, Y, V, Q,J,H,C, R, X,I,D

        //zeroIntegerArray(subKey,26); // zeros substitution key array




//    // Generate substitution key
//        for (int index = 0; index < 26; index++) {
//            subKey[index] = generateKey(); // Generates key using function
//
//            // Checks to ensure each letter is unique (checks all previously assigned values)
//            for (int prevIndex = 0; prevIndex<index;prevIndex++){
//                if (subKey[index] == subKey[prevIndex]) {
//                    index--; // Gets the function to generate a new key for the key at that index
//                    break;   // Breaks loop that checks for uniqueness as soon as it is found the key is not unique
//                }
//            }
//        }

//    // print substitution key
//    for (int index = 0; index <26 ; index++){
//        printf("%c,%c\n",index+65,subKey[index]+65);
//    }

/********************************
 Get input text
*********************************/
    /* Collects text from user input and runs encryption function */
    int MAXCHAR = 30; // Sets maximum characters that can be typed in
    // Collects and stores user entered characters
    char textString[MAXCHAR];
    int textInteger[MAXCHAR]; // Stores text as integer values

    // Initialise both arrays using function
    zeroCharArray(textString, MAXCHAR);
    zeroIntegerArray(textInteger, MAXCHAR);

    // Collects input string from console
    printf("\nPlease Enter Text to Encrypt\n");
   // getchar(); // Clears console (input stream - https://stackoverflow.com/questions/26318275/fgets-skipping-inputs)
   // clearStdin();

    fgets(textString,MAXCHAR,stdin); //stores user input into a string

    //TODO: Collect text input from user specified file

/********************************
 Encrypt/Decrypt text using key
*********************************/

    // Convert char values into integer equivalents before performing mathematical operation
    for(int index = 0; index<MAXCHAR; index++){
        textInteger[index] = textString[index];
    }

    // Convert lowercase characters to uppercase
    for(int index = 0; index<MAXCHAR; index++){
        if (textInteger[index]>=97&&textInteger[index]<=122){ // Checks if the ACII letter is in the lowercase range i.e [97(a) to 122(z)]
            textInteger[index] = textInteger[index] - 32;   // 97(letter a) - 32 = 65(letter A)
        }
    }
    printf("sub%d\n",subKey[0]);

    for(int index = 0; index<MAXCHAR; index++){

        // Convert capitals letters into numbers A = 0, B = 1, C = 2... e.c.t. (not required for substitution but makes it simpler)
        if(textInteger[index]>=65&&textInteger[index]<=90){ // Makes sure it only converts capital letters (leaves spaces)
            textInteger[index]=textInteger[index]-65;

            // Encrypt using substitution
            for(int subIndex = 0 ;subIndex<26; subIndex++){
                if (textInteger[index] == subIndex){ //if letter == 0, 1, 2, 3 e.c.t substitute (swap) with key value
                  printf("%d becomes %d\n",textInteger[index],subKey[subIndex]); //remove FIX used for test
                  printf("%c becomes %c\n",textInteger[index]+65,subKey[subIndex]+65); //remove FIX used for text
                   textInteger[index] = subKey[subIndex];
                   break; // Breaks the loop as soon as the letter is swapped
                }
            }

            // Decrypt using substitution //GBKKH RHCKA = hello world
            for (int keyIndex = 0; keyIndex<26; keyIndex++){
                if (textInteger[index] == subKey[keyIndex]){ //if letter == 0,1,2,3 e.c.t substitute (swap) with key value
                    textInteger[index] = keyIndex;
                    printf("\nTextInteger[%d]=%d",textInteger[index],keyIndex); // change to check letter
                    printf("\nTextInteger[%c]=%c",textInteger[index]+65,keyIndex+65); // change to check letter FIX
                    break; // Breaks the loop as soon as the letter is swapped back
                }
            }



        // Convert text back to capital letters
           textInteger[index] = textInteger[index]+65;

        }//END IF
    }


// PRINT STRING
    printf("\nINPUT STRING:\n");
    for(int index = 0; index<MAXCHAR; index++){
        printf("%c",textString[index]);
    }


    // Convert integer values back to char values
    for(int index = 0; index<MAXCHAR; index++){
        if (textString[index]>=0&&textString[index]<26){ // Ensures only upper case letters are converted back
            textString[index] = textInteger[index];
        }
    }
    printf("\nOUTPUT STRING:\n");
    for(int index = 0; index<MAXCHAR; index++){
        printf("%c",textInteger[index]);
    }


}
void analyseText(){
    char letters[]= {65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90};
                    //A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
    int stats[26];
    zeroIntegerArray(stats,26);
    int MAXCHAR = 500;
    char inputText[MAXCHAR];
    zeroCharArray(inputText,MAXCHAR);
    // Record user input
    printf("\nPlease Enter Text to Encrypt:\n");


    fgets(inputText,MAXCHAR,stdin); //stores user input into a string


    // Perform analysis
    for (int i = 0; i<MAXCHAR; i++){ // For each letter in the input
        for(int index = 0; index<26;index++){ // Check against letters
            if(inputText[i]==letters[index]){
               stats[index]++; // add one to the letter count
                break;
            }
        }
    }
    for (int i =0; i<26;i++)
        printf("%c occurs %d times\n",i+65,stats[i]);

}

int generateKey(){
/* Initialises random number generator the first time it is run
 * Uses current system time to generate random-ish number between 0-25
 * */
    static int count = 0; // Records whether or not the function has been run 0 = never run, 1 = has run before
    int key;          // Initialises key

    /* Initialises random number generator the first time it is run*/
    if (count ==0) {
        time_t seed; // Gets current system time to use as seed
        srand((unsigned) time(&seed)); // Gives time in seconds as seed
        count++; // Sets count to 1, so seed is not regenerated each time function is called
    }

    key = rand() % 26; // Gives key from 0 to 25 (because 0 and 26 are unencrypted)
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


void clearStdin(){
    // Probably not required while: can be used but left just in case
    // getchar(); // Clears console input (ensures fgets works)
    int consoleInput;
    do{
        consoleInput = getchar();
    }while(consoleInput != EOF && consoleInput != '\n');
}

/*  PRINT COMMANDS USED FIX
    printf("ORIG LETR VALUE: %c\n",textString[index]);
	printf("UNENCRYPT VALUE: %d\n",(int)textString[index]);  // Prints output (TEMP)
	printf("ZRO-TWENT VALUE: %d\n",textInteger[index]);
	printf("ENCRYPTED VALUE :%c\n\n",textInteger[index]); // prints current value of integer
*/

// CONSOLE COLOUR
// https://stackoverflow.com/questions/3219393/stdlib-and-colored-output-in-c