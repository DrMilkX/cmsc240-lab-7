/*
    Main program for the enigma machine simulator.
    This file is responsible for handling command-line arguments,
    reading input from the user, and invoking the Enigma class to
    perform encryption or decryption.

    !!   DO NOT MODIFY THIS FILE.   !!

*/


#include <iostream>
#include <string>
#include "Enigma.h"
using namespace std;




int main(int argc, char* argv[]) 
{

    // Validate command line arguments.
    if (argc != 6) {
        cerr << "Invalid arguments!" << endl;
        cerr << "Usage: ./comms <innerRotorNumber> <middleRotorNumber> <outerRotorNumber> <initialRotorPositionCharacters> <encrypt|decrypt>" << endl;
        return 1;
    }


    // define parameters
    int innerRotorNumber, middleRotorNumber, outerRotorNumber;
    string rotorChar, mode;

    // parse and validate arguments
    try{
        innerRotorNumber = stoi(argv[1]);
        middleRotorNumber = stoi(argv[2]);
        outerRotorNumber = stoi(argv[3]);
        rotorChar = argv[4];
        mode = argv[5];

        // invalid rotor numbers or positions (can only be 1-5 and A-Z)
        if (innerRotorNumber < 1 || innerRotorNumber > 5 ||
            middleRotorNumber < 1 || middleRotorNumber > 5 ||
            outerRotorNumber < 1 || outerRotorNumber > 5) {
            throw invalid_argument("Rotor numbers must be between 1 and 5.");
        }

        // invalid initial rotor position characters
        if (rotorChar.length() != 3) {
            throw invalid_argument("Initial rotor position characters must be three characters (A-Z or #)");
        }

        // invalid encrypt or decrypt argument
        if (mode != "encrypt" && mode != "decrypt") {
            throw invalid_argument("Last argument must be either 'encrypt' or 'decrypt'.");
        }

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }



    // Store the message.
    string message;
    getline(cin, message);

    // Create the Enigma machine. 
    Enigma enigma = Enigma(innerRotorNumber, middleRotorNumber, outerRotorNumber, rotorChar);

    // Encrypt or decrypt the message.
    if (mode == "encrypt") {
        cout << enigma.encrypt(message) << endl;
    } else {
        cout << enigma.decrypt(message) << endl;
    }

    return 0;
}