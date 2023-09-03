#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/des.h>

void print_hex(const unsigned char* buffer, size_t length) {
    for (size_t i = 0; i < length; i++) {
        printf("%02x", buffer[i]);
    }
    printf("\n");
}

int main() {
    const char* input_string = "Hello, DES!";
    const char* key_string = "SecretKey"; // 8 bytes key
    DES_cblock key;
    DES_key_schedule key_schedule;

    if (strlen(key_string) != 8) {
        fprintf(stderr, "Key must be exactly 8 bytes.\n");
        return 1;
    }

    // Initialize the key
    memcpy(key, key_string, 8);
    DES_set_key_checked(&key, &key_schedule);

    // Initialize the input data
    unsigned char input_data[8];
    memset(input_data, 0, 8); // Initialize with zeros
    memcpy(input_data, input_string, strlen(input_string));

    // Encrypt the data
    unsigned char output_data[8];
    DES_ecb_encrypt(input_data, output_data, &key_schedule, DES_ENCRYPT);

    printf("Input:  %s\n", input_string);
    printf("Key:    %s\n", key_string);
    printf("Cipher: ");
    print_hex(output_data, 8);

    return 0;
}

