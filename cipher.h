
#ifndef CIPHER_H
#define CIPHER_H

#define ALPHABET_LENGTH 29

void init();
int letterToNumber(char letter);
//int numberToLetter(int number);
char numberToLetter(int number);
int shift(int number, int shift_value);
void encrypt(char *text, int shift_value);
void decrypt(char *text, int shift_value);

#endif // CIPHER_H