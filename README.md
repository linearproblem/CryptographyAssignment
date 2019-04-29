# CryptographyAssignment
Basic Cryptography assignment using C code

Simple console C application written to encrypt and decrypt text from a user given file. Text is encrypted and decrypted using either a rotation cipher (also called a Ceasar Cipher) or by using a Substitution Cipher. 

## Getting Started
This is a C console application (without any command line arguments) so will need to be compiled and then run with compadible console application to make use of it.


## Using the Program
You will at minimum some text to encrypt/decrypt before using this application.
### Keys
Keys can be provided or automatically generated when running the application, the key is set before selecting the input text.
#### Rotation Cipher

The provided key must be between 0 and 26.
*note randomly generated keys will never be 0*

```
e.g if key = 3

inputText = "Hello world"
outputText = "KHOOR ZRUOG"
```


#### Substitution Cipher

Key value should be given as unique characters between A-Z and/or a-z

if 'a' is used 'A' should not be used

```
e.g if key = "QWERTYUIOPAZSXDCFVGBHNJMKL"
inputText = "Hello world"
outputText = "ITZZD JDVZR"
```
### Input Text
To use this cipher you are able to input text into the console or via a file (in the same directory as main.c)
```
$Please enter file path of input text (e.g. input.txt)
$File Path: ./input.txt 

This will take text from the "input.txt" file
```

### Output Text
Output text is printed to console, then automatically written to a file "./output.txt"

## Automatic Decryption
The program is able to decrypt rotation ciphers well and guess a few letters of a substitution cipher

### Automatic Rotation
There are two methods used to try and crack the rotation cipher:
Method 1: find the most common letter in the text, and assume it is one of the most common English characters (produces 4 results)
Method 2: determine the goodness of fit of the text compared to regular English letter frequency for all possible key combinations

### Automatic Substitution Decryption
Tries to crack the key using a hill climbing technique, finds some letter substitutions. Takes a while as it tests a few combinations, how long it takes will depend on the system running it. On testing it took less than a minute, but it will depend on the size of the text. Longer text files are slower, but generally more accurate.

## Known Bug
Auto decryption using the substitution cipher does not work when selected from the main menu. It has been placed at the top of the main file and requires uncommenting to function. For currently unknown reasons, the only input text is seen to be only "\t" or horizontal tab when going through the menu, both when retrieving text from a file and from the console.
The output when selected from the menu will usually be as below:
```
Please wait while loading:

Loading 0%....
```



## Authors

* **linearproblem** - *creator* - [Github](https://github.com/linearproblem)


