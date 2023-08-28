#include <stdio.h>
#include <ctype.h>
#include <string.h>

void vigenere_encrypt(char *plaintext, char *key) {
    int key_length = strlen(key);
    int i;
    for (i = 0; i < strlen(plaintext); i++) {
        if (isalpha(plaintext[i])) {
            char base = islower(plaintext[i]) ? 'a' : 'A';
            char shift = islower(key[i % key_length]) ? 'a' : 'A';
            plaintext[i] = (plaintext[i] - base + (key[i % key_length] - shift)) % 26 + base;
        }
    }
}

void vigenere_decrypt(char *ciphertext, char *key) {
    int key_length = strlen(key);
    for (int i = 0; i < strlen(ciphertext); i++) {
        if (isalpha(ciphertext[i])) {
            char base = islower(ciphertext[i]) ? 'a' : 'A';
            char shift = islower(key[i % key_length]) ? 'a' : 'A';
            ciphertext[i] = (ciphertext[i] - base - (key[i % key_length] - shift) + 26) % 26 + base;
        }
    }
}

int main() {
    char plaintext[] = "Anki";
    char ciphertext[100];
    char key[] = "KEY";

    strcpy(ciphertext, plaintext);
    vigenere_encrypt(ciphertext, key);
    printf("Vigenere Cipher - Encryption: %s\n", ciphertext);

    vigenere_decrypt(ciphertext, key);
    printf("Vigenere Cipher - Decryption: %s\n", ciphertext);

    return 0;
}
