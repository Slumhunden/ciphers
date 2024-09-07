#include "cipher.h"
#include <stdio.h>
#include <ctype.h>

char DANISH_ALPHABET[ALPHABET_LENGTH + 1] = "ABCDEFGHIJKLMNOPQRSTUVWXYZÆØÅ";

void init() {
    // Hardcoded array, no need for dynamic initialization in this implementation
}

int letterToNumber(char letter) {
    letter = toupper(letter);
    for(int i = 0; i < ALPHABET_LENGTH; i++) {
        if(DANISH_ALPHABET[i] == letter) {
            return i + 1; // Return 1-based index
        }
    }
    return 0; // Return 0 for non-alphabet characters
}

char numberToLetter(int number) {
    if(number < 1 || number > ALPHABET_LENGTH) {
        return ' '; // Return space for out-of-bound numbers
    }
    return DANISH_ALPHABET[number - 1];
}

int shift(int number, int shift_value) {
    int shifted_number = (number + shift_value) % ALPHABET_LENGTH;
    if(shifted_number < 1) {
        shifted_number += ALPHABET_LENGTH;
    }
    return shifted_number;
}

void encrypt(char *text, int shift_value) {
    for(int i = 0; text[i] != '\0'; i++) {
        int num = letterToNumber(text[i]);
        if(num != 0) {
            text[i] = numberToLetter(shift(num, shift_value));
        }
    }
}

void decrypt(char *text, int shift_value) {
    for(int i = 0; text[i] != '\0'; i++) {
        int num = letterToNumber(text[i]);
        if(num != 0) {
            text[i] = numberToLetter(shift(num, -shift_value));
        }
    }
}