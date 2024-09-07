#include <stdio.h>
#include <stdlib.h>
#include "cipher.h"

void print_menu() {
    printf("Vælg en mulighed:\n");
    printf("(e) Encrypt\n");
    printf("(d) Decrypt\n");
    printf("(q) Exit\n");
}

int main() {
    init();
    char choice;
    char text[256];
    int shift_value;

    while (1) {
        print_menu();
        scanf(" %c", &choice); // Add a space to skip leading whitespace

        if (choice == 'q') {
            break;
        }

        printf("Indtast tekst: ");
        scanf(" %[^\n]", text); // Read until newline

        do {
            printf("Indtast shift-værdi (0-29): ");
            scanf("%d", &shift_value);
        } while (shift_value < 0 || shift_value >= ALPHABET_LENGTH);

        switch (choice) {
            case 'e':
                encrypt(text, shift_value);
                printf("Krypteret tekst: %s\n", text);
                break;
            case 'd':
                decrypt(text, shift_value);
                printf("Dekrypteret tekst: %s\n", text);
                break;
            default:
                printf("Ugyldigt valg\n");
        }
    }

    return 0;
}