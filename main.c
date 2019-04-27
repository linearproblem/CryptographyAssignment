/******************************************************************************


******************************************************************************/
/******************************************************************************
LAYOUT (menu tree):

// Rotation Cipher
    //Encrypt
        // Get Key
            // From console
            // From file
            // Randomly generate
        // Get text
            // From console
            // From file
    // Decrypt
        // Get Key
            // From console
            // From file
            // Randomly generate
        // Get text
            // From console
            // From file
// Substitution Cipher
        // Get Key
            // From console
            // From file
            // Randomly generate
        // Get text
            // From console
            // From file
    // Decrypt
        // Get Key
            // From console
            // From file
            // Randomly generate
        // Get text
            // From console
            // From file

******************************************************************************/


/******************************************************************************
INCLUDE LIBRARIES
******************************************************************************/
#include <stdio.h>
#include <stdlib.h> // Used for the random function
#include <time.h>   // Used to get seed for random number generator


/******************************************************************************
DECLARE FUNCTIONS (Function Prototypes)
******************************************************************************/
// User Interface
void printHeader(); // Menu header

/*******Separate Function for each task created*******/
// Rotation Cipher only functions
void encryptRotation(); // Encrypts text using rotation cipher
void decryptRotation(); // Decrypts text using rotation cipher
int getRotationKey(); // Gets rotation key from user specified location
void rotationCipher(char inputText[],int key,int letterCount); // ENCRYPT and DECRYPT using rotation Cipher

// Substitution Cipher only functions
void encryptSubstitution(); // Encrypts text using substitution cipher
void decryptSubstitution(); // Decrypts text using substitution cipher
void getSubstitutionKey(int subKey[]); // Gets substitution key from user specified location
void generateSubKey(int subKey[]); // Generates substitution key and prints it to console
void substitutionCipher(char inputText[],int subKey[],int letterCount, int direction); // ENCRYPT and DECRYPT using substitution Cipher

// Common functions (used both cipher types functions)
void getInputText(char textInput[], int *letterCount); // Collects input text from user specified location
int generateKey(); // Generates a key (0 to 25) for rotation and substitution cipher
void printArray(char arrayName[],int arraySize); // Used to print input and output text


// Zeroing Functions
void zeroCharArray(char arrayName[], int arraySize); // Sets all values in a char type array to zero
void zeroIntegerArray(int arrayName[], int arraySize); // Sets all values in an integer type array to zero


// Automatic Decryption
    // Not fully functioning, sometimes works
void crackRotation(); // Function used to crack rotation cipher
float findChiScore(int inputText[],int letterCount); // Finds goodness of fit of a rotation


/******************************************************************************
MAIN
******************************************************************************/
int main(){
    // Prints application header
        printHeader();

    // Main Menu
    int userInput = 0; // Initialises the user input selection to make sure it is not equal to 7
    while (userInput != 7){ // Repeats menu selection until user decides to exit
    printf("\n-- Main Menu --\n");
    // Display menu options
    printf("\tRotation Cipher\n");
    printf("\t\t 1: Encrypt text with key\n");
    printf("\t\t 2: Decrypt text with key\n");
    printf("\n\tSubstitution Cipher\n");
    printf("\t\t 3: Encrypt text\n");
    printf("\t\t 4: Decrypt text with key\n");
    printf("\n\tOther\n");
    printf("\t\t 5: Crack Rotation Cipher (beta)\n");
    printf("\t\t 0: Exit Application\n");

    // Collect user selection
    printf("\nPlease select an option: ");
        scanf("%d",&userInput); // Record User Input
        switch (userInput) {

            case 1:
                // Rotation Cipher function encrypt
                encryptRotation();
                break;
            case 2:
                // Rotation Cipher function decrypt with key
                decryptRotation();
                break;
            case 3:
                // Substitution cipher encrypt with key
                encryptSubstitution();
                break;
            case 4:
                // Substitution cipher decrypt with key
                decryptSubstitution();
                break;
            case 5:
                crackRotation();
                break;
            case 0:
                // Exit application
                printf("You have chosen to leave");
                return 0; // Exit Application
            default:
                printf("\nERROR: Invalid selection, please try again: ");
                break;
        }
    }
}

/******************************************************************************
EXTERNAL FUNCTIONS (function definitions)
******************************************************************************/

/* NAME:
 *  printHeader
 * USAGE:
 *  Prints ACII art header to console upon application start
 *
 * INPUT:
 *  (none)
 *
 * RETURN:
 *  (none)
 *
 * LIMITATIONS:
 *  Does not resize well on small monitors
 * */
void printHeader(){
    // Prints splash back
    printf("\n");
    printf(" _____              _       ___  _         _                 \n");
    printf("/__   \\  ___ __  __| |_    / __\\(_) _ __  | |__    ___  _ __ \n");
    printf("  / /\\/ / _ \\ \\/ /| __|   / /   | || '_ \\ | '_ \\  / _ \\| '__|\n");
    printf(" / /   |  __/ >  < | |_  / /___ | || |_) || | | ||  __/| |   \n");
    printf(" \\/     \\___|/_/\\_\\ \\__| \\____/ |_|| .__/ |_| |_| \\___||_|   \n");
    printf("                                   |_|                       \n");
    printf("+------------------------------------------------------------+\n");
}

/******************************************************************************
Rotation Cipher Functions
******************************************************************************/
/* NAME:
 *  encryptRotation
 * USAGE:
 *  Encrypts text using rotation cipher
 *
 * INPUT:
 *  (none)
 *
 * RETURN:
 *  (none)
 *
 * LIMITATIONS:
 *  Only converts English A-Z characters
 *  Only allows 2000 letters unless changed
 * */
void encryptRotation(){
    printf("\n*****************************\nROTATION CIPHER: ENCRYPT TEXT\n*****************************");
    int key;
    int letterCount = 2000; // Stores letter count for use later (to improve encryption/decryption efficiency)
    char inputText[letterCount]; // // Used to store text to convert
    zeroCharArray(inputText, letterCount);  // Initialise all array values to 0 using function

    key = getRotationKey(); // Get key from user specified location

    getInputText(inputText, &letterCount); // Get input text using function

    // Print input text to console
    printf("\nINPUT TEXT:\n");
    printArray(inputText,letterCount);

    rotationCipher(inputText,key,letterCount); // Modify text with key using rotation cipher function

    // Print output text to the console
    printf("\nOUTPUT TEXT:\n");
    printArray(inputText,letterCount);
}

/* NAME:
 *  decryptRotation
 * USAGE:
 *  Decrypts text using rotation cipher
 *
 * INPUT:
 *  (none)
 *
 * RETURN:
 *  (none)
 *
 * LIMITATIONS:
 *  Only converts English A-Z characters
 *  Only allows 2000 letters unless changed
 * */
void decryptRotation(){
    printf("\n*****************************\nROTATION CIPHER: DECRYPT TEXT\n*****************************");
    int key;
    int letterCount = 2000; // Stores letter count for use later (to improve encryption/decryption efficiency)
    char inputText[letterCount]; // Used to store text to convert
    zeroCharArray(inputText, letterCount);  // Initialise all array values to 0 using function

    key = getRotationKey(); // Get key from user specified location
    key = 26 - key;  // Change key so it reverses encryption

    getInputText(inputText, &letterCount); // Get input text using function

    // Print input text to console
    printf("\nINPUT TEXT:\n");
    printArray(inputText,letterCount);

    rotationCipher(inputText,key,letterCount); // Modify text with key using rotation cipher function

    // Print output text to the console
    printf("\nOUTPUT TEXT:\n");
    printArray(inputText,letterCount);
}

/* NAME:
 *  getRotationKey
 * USAGE:
 *  Get rotation key from user specified area such as:
 *      - Standard input (the console)
 *      - From a file
 *      - Randomly generated key function
 *
 * INPUT:
 *  (none)
 *
 * RETURN:
 *  Key to use for the rotation cipher
 *
 *
 * LIMITATIONS:
 *  Only accepts user input key values between -26 and 26 (as originally specified)
 *  file path can only be 100 characters long (including extension)
 * */
int getRotationKey(){
    int key = 0;   // Key zeroed to allow random generation to run
    int userInput; // Stores user menu selection

    // Initialise key from file
    FILE *keyInput; // Declares key input from file
    char filePath[100]; // Initialise user entered file path
    zeroCharArray(filePath,100); // Initialise char array (zero's all values)


    // Rotation Key Sub Menu
    printf("\n-- Rotation Cipher Key Selection --\n");

    printf("\t Key Location\n");
        // Display menu options
        printf("\t\t 1: Enter key into console\n"); // Collects key from standard input (console)
        printf("\t\t 2: Get key from file\n");      // Collects key from file
        printf("\t\t 3: Randomly Generate Key\n");  // Collects key from random number generation

    printf("\nKey Location: ");

    // Get user selection
    scanf("%d",&userInput); // Record User Input

    switch (userInput) {    // User selects where key is to come from
        // Act depending on what the user selects
        case 1:
            // Prompts user to enter key into console and sets key value
            printf("Please Enter Key:");
            scanf("%d",&key); // Get key from console
            printf("You entered:""%d\n",key); // Print key to console for user confirmation
            break;
        case 2:
            // Prompts user to enter location of file with key and sets file value as key
            printf("Please enter file path of key (e.g. key.txt)\n");
            printf("File Path: ./");
            scanf("%s",filePath); // Get key file path from user
            keyInput = fopen(filePath,"r"); // Open file from user specified location
            
            // Error Check
            if (keyInput == NULL){
                perror("fopen()");
                printf("\nERROR: Invalid location, please try again.\n");
                encryptRotation(); // Restart rotation encryption function
            }

            fscanf(keyInput,"%d",&key); // Get key from file
            printf("\nThe key is: ""%d\n",key); // Print key to screen
            break;
        case 3:
            // Gets key value from random key function
            while(key == 0) { // Makes sure key is not zero
                key = generateKey(); // Gets generated key from function (returns 0 to 25)
            }
            // prints both versions of generated key
            printf("Generated key is: ""%d (or %d)\n",key,-(26-key));
            break;
        default:
            // Notifies user of invalid selection and prompts them to try again
            printf("\nERROR: Invalid Selection, please try again.\n");
            encryptRotation(); // Restart rotation encryption function
    }

    // Error check and convert key value
    if(key>=-26&&key<=26){ // Checks key is valid
        if(key<0){
            /* Converts key to a number from 0 to 25
            *
            * For example, if  key = -2    (For E=5: [5+-2]%26 = 3 or C)
            *          same as key =  24   (For E=5: [5+24]%26 = 3 or C)
            *
            * */
            key = 26 + key;
        }
    }else{
        // Gives user an error when key value is not between -26 and 26
        printf("\nERROR: The provided key is invalid\n");
        encryptRotation(); // Restart function to ask user for key again
    }
    return key; // Returns key to rotation encryption/decryption function
}

/* NAME:
 *  rotationCipher
 * USAGE:
 *  Encrypt and decrypt text using given key by acting
 *  as the rotation cipher codec
 *
 * INPUT:
 *  Char array to encrypt
 *  Key to encrypt the text with
 *  letterCount so function knows how many letters to convert
 *
 * RETURN: (but will modify input text)
 *  (none)
 *
 *
 * LIMITATIONS:
 *  Key must be a value between 0 - 26
 *  Function only converts in one direction, so must have key modified to decrypt properly
 * */
void rotationCipher(char inputText[],int key,int letterCount){
    int textInteger[letterCount]; // Stores text as integer values
    zeroIntegerArray(textInteger, letterCount);

	// Convert char values into integer equivalents
	for(int index = 0; index<letterCount; index++){
        textInteger[index] = inputText[index];
	}

	// Convert lowercase characters to uppercase
	for(int index = 0; index<letterCount; index++){
	    if (textInteger[index]>=97&&textInteger[index]<=122){ // Checks if the ACII letter is in the lowercase range i.e [97(a) to 122(z)]
            textInteger[index] = textInteger[index] - 32;   // 97(letter a) - 32 = 65(letter A)         
	    }
	}

	// for each letter in the text do the following:
    for(int index = 0; index<letterCount; index++){

    	// Convert capitals letters into numbers A = 0, B = 1, C = 2... e.c.t.
    	if(textInteger[index]>=65&&textInteger[index]<=90){ // Makes sure it only converts capital letters (leaves spaces)
    	   textInteger[index]=textInteger[index]-65;

    	   // Adds key value onto code
    	   textInteger[index] = (textInteger[index]+key)%26;

            // Convert text back to capital letters
            textInteger[index]=textInteger[index]+65;
        }
    }

    // Convert integers back to chars
    for(int index = 0; index<letterCount; index++){
        if (textInteger[index]>=65&&textInteger[index]<=90) // Ensures all integer values can fit into a char
                inputText[index] = textInteger[index];
    }
};

/******************************************************************************
Substitution Cipher Functions
******************************************************************************/
/* NAME:
 *  encryptSubstitution
 * USAGE:
 *  Encrypts text using substitution cipher
 *
 * INPUT:
 *  (none)
 *
 * RETURN:
 *  (none)
 *
 * LIMITATIONS:
 *  Only converts English a-z and A-Z characters
 *  Only allows 2000 letters unless changed
 * */
void encryptSubstitution(){
    printf("\n*****************************\nSUBSTITUTION CIPHER: ENCRYPT TEXT\n*****************************");
    int subKey[26];
    zeroIntegerArray(subKey,26); // zeros substitution key array
    int letterCount = 2000; // Stores letter count for use later (to improve encryption/decryption efficiency)
    char inputText[letterCount]; // Used to store text to convert
    zeroCharArray(inputText, letterCount);     // Initialise all array values to 0 using function

    // Get substitution key
    getSubstitutionKey(subKey);

    // Get input text
    getInputText(inputText,&letterCount);

    // Print input text to console
    printf("\nINPUT TEXT:\n");
    printArray(inputText,letterCount);

    // Apply substitution cipher
    substitutionCipher(inputText,subKey,letterCount,1); // 3rd Argument is direction, 1 = encrypt

    // Print output text to the console
    printf("\nOUTPUT TEXT:\n");
    printArray(inputText,letterCount);
}

/* NAME:
 *  decryptSubstitution
 * USAGE:
 *  Encrypts text using substitution cipher
 *
 * INPUT:
 *  (none)
 *
 * RETURN:
 *  (none)
 *
 * LIMITATIONS:
 *  Only converts English a-z and A-Z characters
 *  Only allows 2000 letters unless changed
 * */
void decryptSubstitution(){
    printf("\n*****************************\nSUBSTITUTION CIPHER: DECRYPT TEXT\n*****************************");
    int subKey[26];
    zeroIntegerArray(subKey,26); // zeros substitution key array
    int letterCount = 2000; // Stores letter count for use later (to improve encryption/decryption efficiency)
    char inputText[letterCount]; // Used to store text to convert
    zeroCharArray(inputText, letterCount);     // Initialise all array values to 0 using function

    // Get substitution key
    getSubstitutionKey(subKey);

    // Get input text
    getInputText(inputText,&letterCount);

    // Print input text to console
    printf("\nINPUT TEXT:\n");
    printArray(inputText,letterCount);

    // Apply substitution cipher
    substitutionCipher(inputText,subKey,letterCount,2); // 3rd Argument is direction, 2 = decrypt

    // Print output text to the console
    printf("\nOUTPUT TEXT:\n");
    printArray(inputText,letterCount);
}

/* NAME:
 *  getSubstitutionKey
 * USAGE:
 *  Get Substitution key from user specified area such as:
 *      - Standard input (the console)
 *      - From a file
 *      - Randomly generated substitution key function
 *
 * INPUT:
 *  Substitution Key to use for the substitution cipher
 *
 * RETURN: (modifies input values)
 *  (none)
 *
 *
 * LIMITATIONS:
 *  Only accepts user input key values A-Z and a-z (or a mixture)
 *  Does not check for letter uniqueness (except for randomly generated key)
 *  file path can only be 100 characters long (including extension)
 * */
void getSubstitutionKey(int subKey[]){
    zeroIntegerArray(subKey,26); // Initialise substitution key array
    int userInput; // Stores user menu selection
    char charKey[26]; // Used to grab key as char before converting to integer
    zeroCharArray(charKey,26);

    // Initialise file for sub key
    FILE *keyInput; // Declares key input from file
    char filePath[100]; // Initialise user entered file path
    zeroCharArray(filePath,100); // Initialise char array (zero's all values)


    // Substitution Key Sub Menu
    printf("\n-- Substitution Cipher Key Selection --\n");

    printf("\t Key Location\n");
    // Display menu options
    printf("\t\t 1: Enter key into console\n"); // Collects key from standard input (console)
    printf("\t\t 2: Get key from file\n");      // Collects key from file
    printf("\t\t 3: Randomly Generate Key\n");  // Collects key from random number generation

    printf("\nKey location: ");

    // Get user selection
    scanf("%d",&userInput); // Record User Input

    switch (userInput) {    // User selects where key is to come from
        // Act depending on what the user selects
        case 1:
            // Prompts user to enter key into console and sets key value
            printf("Please Enter Key:");
            scanf("%s",charKey); // Get key from console
            printf("\nThe key is: ");
            printf("%s",charKey); // Print key to console for user confirmation
            break;
        case 2:
            // Prompts user to enter location of file with key and sets file value as key
            printf("Please enter file path of key (e.g. subkey.txt)\n");
            printf("File Path: ./");
            scanf("%s",filePath); // Get key file path from user
            keyInput = fopen(filePath,"r"); // Open file from user specified location

            // Error Check
            if (keyInput == NULL){
                perror("fopen()");
                printf("\nERROR: Invalid location, please try again.\n");
                encryptRotation(); // Restart rotation encryption function
            }
            int position = 0;
            while (feof(keyInput) == 0){ // Read a character until complete
                charKey[position] = fgetc(keyInput); //Record each character to array
                position = ftell(keyInput);
            }

            printArray(charKey,26);// Print key to console for user confirmation
            break;
        case 3:
            // Gets key value from random key function & prints it to console
            printf("\nThe key is: ");// Print key to console for user confirmation
            generateSubKey(subKey); // Get sub key
            break;
        default:
            // Notifies user of invalid selection and prompts them to try again
            printf("\nERROR: Invalid Selection, please try again.\n");
            main(); // Restart application
    }

    // Convert key for substitution cipher
    if (userInput != 3){ // Skips converting key if it came from random function
        for (int index = 0; index <26 ; index++){
            // Covert any lowercase characters to uppercase
            if (charKey[index]>=97&&charKey[index]<=122){ // Checks if the ACII letter is in the lowercase range i.e [97(a) to 122(z)]
                charKey[index] = charKey[index] - (char)32;   // 97(letter a) - 32 = 65(letter A)
            }
            subKey[index] = charKey[index] - 65; // Converts key to values between 0 and 25
        }
    }
}


void generateSubKey(int subKey[]){
    // Generate substitution key
    for (int index = 0; index < 26; index++) {
        subKey[index] = generateKey(); // Generates key using function

        // Checks to ensure each letter is unique (checks through all previously assigned values)
        for (int prevIndex = 0; prevIndex<index;prevIndex++){
            if (subKey[index] == subKey[prevIndex]) {
                index--; // Gets the function to generate a new key for the key at that index
                break;   // Breaks loop that checks for uniqueness as soon as it is found the key is not unique
            }
        }
    }

    // print substitution key
    for (int index = 0; index <26 ; index++){
        printf("%c",subKey[index]+65);
    }
}

/* NAME:
 *  substitutionCipher
 * USAGE:
 *  Encrypt and decrypt text using given substitution key array by acting
 *  as the substitution cipher codec
 *
 * INPUT:
 *  Char array to encrypt
 *  int Key array to encrypt the text with
 *  letterCount so function knows how many letters to convert
 *  direction determines whether to encrypt or decrypt text
 *      1 = Encrypt text
 *      2 = decrypt text
 *
 *
 * RETURN: (but will modify input text)
 *  (none)
 *
 *
 * LIMITATIONS:
 *  Key must contain unique values for each letter, key values can only be between 0-26
 *  Function requires direction
 *
 * */
void substitutionCipher(char inputText[],int subKey[],int letterCount,int direction){
    int textInteger[letterCount]; // Stores text as integer values
    zeroIntegerArray(textInteger, letterCount);


    // Convert char values into integer equivalents before performing mathematical operation
    for(int index = 0; index< letterCount; index++){
        textInteger[index] =  inputText[index];
    }

    // Convert lowercase characters to uppercase
    for(int index = 0; index<letterCount; index++){
        if (textInteger[index]>=97&&textInteger[index]<=122){ // Checks if the ACII letter is in the lowercase range i.e [97(a) to 122(z)]
            textInteger[index] = textInteger[index] - 32;   // 97(letter a) - 32 = 65(letter A)
        }
    }

    for(int index = 0; index<letterCount; index++){

        // Convert capitals letters into numbers A = 0, B = 1, C = 2... e.c.t. (not required for substitution but makes it simpler)
        if(textInteger[index]>=65&&textInteger[index]<=90){ // Makes sure it only converts capital letters (leaves spaces)
            textInteger[index]=textInteger[index]-65;

            // Decides whether or not to encrypt
            if (direction == 1) {
                // Encrypt using substitution
                for (int subIndex = 0; subIndex < 26; subIndex++) {
                    if (textInteger[index] ==
                        subIndex) { //if letter == 0, 1, 2, 3 e.c.t substitute (swap) with key value
                        textInteger[index] = subKey[subIndex];
                        break; // Breaks the loop as soon as the letter is swapped
                    }
                }
            }

            // Decides whether or not to decrypt (direction = 2 means decrypt)
            if (direction == 2) {
                // Decrypt using substitution
                for (int keyIndex = 0; keyIndex < 26; keyIndex++) {
                    if (textInteger[index] ==
                        subKey[keyIndex]) { //if letter == 0,1,2,3 e.c.t substitute (swap) with key index
                        textInteger[index] = keyIndex;
                        break; // Breaks the loop as soon as the letter is swapped back
                    }
                }
            }

        // Convert text back to capital letters
           textInteger[index] = textInteger[index]+65;
        }
    }

    // Convert integers back to chars
    for(int index = 0; index<letterCount; index++){
        if (textInteger[index]>=65&&textInteger[index]<=90) // Ensures all integer values can fit into a char
            inputText[index] = textInteger[index];
    }

}

/******************************************************************************
Shared Functions
******************************************************************************/

/* NAME:
 *  getInputText
 * USAGE:
 * Get text to encrypt/decrypt from either:
 *      - Standard input (the console)
 *      - From a selected file
 *
 * INPUT:
 *  Char array which will store text
 *  Integer value which will store total letter count (from input text)
 *
 * RETURN: (but will modify above input values)
 *  (none)
 *
 *
 * LIMITATIONS:
 *  Size of text (amount of letters) is restricted to 1000000 (hardcoded)
 * */
void getInputText(char textInput[], int *letterCount){
    int userInput; // Stores user menu selection

    // Initialise text from file
    FILE *fileInput; // Declares key input from file
    char filePath[100]; // Initialise user entered file path
    zeroCharArray(filePath,100); // Initialise char array (zero's all values)


    // Text Input Sub Menu
    printf("\n-- Text to Encrypt/Decrypt --\n");
    printf("\t Text Input\n");
    // Display menu options
    printf("\t\t 1: Enter text into console\n"); // Collects text from standard input (console)
    printf("\t\t 2: Get text from file\n");      // Collects text from file

    printf("\nText location: ");

    // Get user selection
    scanf("%d",&userInput); // Record User Input



    switch (userInput){
        case 1:
            // Prompts user to enter text to encrypt into console
            printf("\nPlease Enter Text\n ");
            getchar(); // Clears console (input stream - https://stackoverflow.com/questions/26318275/fgets-skipping-inputs)
            fgets(textInput,*letterCount,stdin); //stores user input into a string
            break;
        case 2:
            // Prompts user to enter location of file, writes file text to array
            printf("Please enter file path of input text (e.g. input.txt)\n");
            printf("File Path: ./");
            scanf("%s",filePath); // Get key file path from user
            fileInput = fopen(filePath,"r"); // Open file from user specified location

            // Error Check
            if (fileInput == NULL){
                perror("fopen()");
                printf("\nERROR: Invalid location, please try again.\n");
                main(); // Restart program
            }
            int position = 0; // Sets array position for each letter
            while (feof(fileInput) == 0){ // Read a character until complete
                textInput[position] = fgetc(fileInput); //Record each character to array
                position = ftell(fileInput);
            }
            break;
        default:
            // Notifies user of invalid selection and prompts them to try again
            printf("\nERROR: Invalid Selection, please try again.\n");
            main(); // Restart program
            break;
    }

    // Determine length of array and pass it to the *letterCount pointer (-1 being the last value of the file input)
    for (int count = 0; count<*letterCount; count++){
        if (textInput[count] == 0 || textInput[count] == -1) {
            *letterCount = count;
            break;
        }
    }
}

/* NAME:
 *  generateKey
 * USAGE:
 *  Get a random key value between 0-25
 *      Used to generate both cipher key values
 *
 * INPUT:
 *  (none)
 *
 * RETURN:
 *  Key value between 0 and 25
 *
 *
 * LIMITATIONS:
 *  Must be checked for a zero value for the rotation cipher
 *
 * */
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

/* NAME:
 *  printArray
 * USAGE:
 *  Used to quickly print array values to console
 *   Creates a new line after array has printed fully
 *
 * INPUT:
 *  char array to print
 *  items in array (array size)
 *
 * RETURN:
 *  (none)
 *
 *
 * LIMITATIONS:
 *  prints all values in an array on a single line
 *  does not check all array values actually exist
 *  only prints arrays of type char
 *
 * */
void printArray(char arrayName[],int arraySize){
    for(int index = 0; index<arraySize; index++){
        printf("%c",arrayName[index]);
    }
    printf("\n"); // Leaves a new line after printed text
}

/* NAME:
 *  zeroCharArray
 * USAGE:
 *  Used to set each value in a char array to zero
 *
 * INPUT:
 *  char array to zero
 *  number of items in array (array size) to zero
 *
 * RETURN:
 *  (none)
 *
 *
 * LIMITATIONS:
 *  does not check all array values actually exist
 *  only zeros arrays of type char
 *
 * */
void zeroCharArray(char arrayName[], int arraySize){
// in above line can use *arrayName or arrayName[]
/* Sets all values in an array to 0;
 * */
    for (int index = 0; index<arraySize; index++){
        arrayName[index] = 0;
    }
}

/* NAME:
 *  zeroIntegerArray
 * USAGE:
 *  Used to set each value in a int array to zero
 *
 * INPUT:
 *  int array you wish to zero
 *  number of items in array (array size) to zero
 *
 * RETURN:
 *  (none)
 *
 *
 * LIMITATIONS:
 *  does not check all array values actually exist
 *  only zeros arrays of type int
 *
 * */
void zeroIntegerArray(int arrayName[], int arraySize){
// in above line can use *arrayName or arrayName[]
/* Sets all values in an array to 0;
 * */
    for (int index = 0; index<arraySize; index++){
        arrayName[index] = 0;
    }
}



/******************************************************************************
Automatic Decryption/Analysis
******************************************************************************/

void crackRotation(){
    int MAXCHAR = 20000;
    int letterCount;
    char inputText[MAXCHAR];
    float chiScore = 0;
    float bestChi = 100;
    int bestKey = 0; // Stores most likely key based on lowest chi score

    getInputText(inputText,&letterCount);
    int textInteger[letterCount];



    for(int index = 0; index<letterCount; index++){
        // Convert char values into integer equivalents
        textInteger[index] = inputText[index];

        // Convert lower to uppercase
        if (textInteger[index]>=97&&textInteger[index]<=122){ // Checks if the ACII letter is in the lowercase range i.e [97(a) to 122(z)]
            textInteger[index] = textInteger[index] - 32;   // 97(letter a) - 32 = 65(letter A)
        }
        // Convert capitals letters into numbers A = 0, B = 1, C = 2... e.c.t.
        if(textInteger[index]>=65&&textInteger[index]<=90){ // Makes sure it only converts capital letters (leaves spaces)
            textInteger[index]=textInteger[index]-65;
        }
    }

// trying to return array after key has been applied, could use for rotation cipher
    for(int key = 25; key>0; key--){
        // for each letter in the text do the following:
        for(int index = 0; index<letterCount; index++){
            // Adds key value onto code
            textInteger[index] = (textInteger[index]+1)%26;
        }
        chiScore = findChiScore(textInteger,letterCount);

        if (chiScore<bestChi) {
            bestChi = chiScore;
            bestKey = key;

        }
    }
    rotationCipher(inputText,bestKey,letterCount);
    printf("Decrypted Text:\n");
    printArray(inputText,letterCount);

    printf("..was worth a try..\n");
};



float findChiScore(int inputText[],int letterCount){ // NOTE ONLY WORKS WITH CAPITAL LETTERS CURRENTLY
    char letters[]= {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
    //A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,

    int stats[26]; // stores letter occurrences
    zeroIntegerArray(stats,26); // zeroes each letter's stats value
    int count = 0;

  //   Perform analysis
    for (int i = 0; i<letterCount; i++){ // For each letter in the input
        for(int index = 0; index<26;index++){ // Check against letters
            if(inputText[i]==index){
               stats[index]++; // add one to the letter count
               count++;
               break; // leave loop as soon as letter is found
            }
        }
    }

    float chiValue;

    // Normal probability of each letter (from https://pages.mtu.edu/~shene/NSF-4/Tutorial/VIG/Vig-IOC.html#English-Freq-Table)
    float normLetterChance[] = {0.0815,0.0144,0.0267,0.0379,0.0311,0.0292,0.0199,0.0526,0.0635,0.0013,0.0042,0.0339,0.0254,0.0710,0.0800,0.0198,0.0012,0.0683,0.0610,0.1047,0.0246,0.0092,0.0154,0.0017,0.0198,0.0008};

    float observedFrequency[26];

    // FOR EACH LETTER (FIND CHI VALUE) - start with one
    chiValue = 0; // initialise chi value each time it runs
    for (int letter = 0;letter<6;letter++){
        // Uses english letter frequency to find expected letter count
        observedFrequency[letter] = stats[letter]/(float)count;

        // Partially completes chi square (goodness of fit) test comparing to English letter frequency
        chiValue = ((observedFrequency[letter]-normLetterChance[letter])*(observedFrequency[letter]-normLetterChance[letter])/normLetterChance[letter]) + chiValue;
    }
    return chiValue;
}





// CONSOLE COLOUR
// https://stackoverflow.com/questions/3219393/stdlib-and-colored-output-in-c