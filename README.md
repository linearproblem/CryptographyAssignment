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

## Authors

* **linearproblem** - *creator* - [Github](https://github.com/linearproblem)


