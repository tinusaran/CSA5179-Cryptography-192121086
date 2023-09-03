#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

int main() {
    char input_string[] = "Hello, SHA-256!";
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;

    SHA256_Init(&sha256);
    SHA256_Update(&sha256, input_string, strlen(input_string));
    SHA256_Final(hash, &sha256);

    printf("SHA-256 Hash of '%s': ", input_string);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}

