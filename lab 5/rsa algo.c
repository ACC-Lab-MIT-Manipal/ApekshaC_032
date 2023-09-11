#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to compute the greatest common divisor (GCD) of two numbers
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to calculate the modular inverse of 'a' modulo 'm'
int modInverse(int a, int m) {
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return -1; // Modular inverse does not exist
}

int main() {
    int p, q, n, phi, e, d, plaintext, encrypted, decrypted;

    // Step 1: Input two prime numbers 'p' and 'q' from the user
    printf("Enter prime number p: ");
    scanf("%d", &p);

    printf("Enter prime number q: ");
    scanf("%d", &q);

    // Step 2: Calculate 'n' (the modulus)
    n = p * q;

    // Step 3: Calculate Euler's totient function 'phi(n)'
    phi = (p - 1) * (q - 1);

    // Step 4: Choose 'e' (public key exponent)
    printf("Enter public key exponent 'e' (typically a small prime number): ");
    scanf("%d", &e);

    // Ensure 'e' and 'phi' are coprime (GCD = 1)
    if (gcd(e, phi) != 1) {
        printf("Error: 'e' is not coprime with 'phi'\n");
        return 1;
    }

    // Step 5: Calculate 'd' (private key exponent)
    d = modInverse(e, phi);

    if (d == -1) {
        printf("Error: Modular inverse of 'e' does not exist\n");
        return 1;
    }

    // Step 6: Encryption
    printf("Enter plaintext (an integer): ");
    scanf("%d", &plaintext);

    encrypted = 1;
    for (int i = 0; i < e; i++) {
        encrypted = (encrypted * plaintext) % n;
    }

    printf("Encrypted: %d\n", encrypted);

    // Step 7: Decryption
    decrypted = 1;
    for (int i = 0; i < d; i++) {
        decrypted = (decrypted * encrypted) % n;
    }

    printf("Decrypted: %d\n", decrypted);

    return 0;
}
