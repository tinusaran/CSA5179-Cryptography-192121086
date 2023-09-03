#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/dsa.h>
#include <openssl/engine.h>

void handleErrors(void) {
    ERR_print_errors_fp(stderr);
    abort();
}

int main() {
    DSA *dsa = NULL;
    unsigned char message[] = "This is a sample message to be signed.";
    unsigned char signature[DSA_size(dsa)];

    // Initialize OpenSSL library
    OpenSSL_add_all_algorithms();
    ERR_load_crypto_strings();

    // Generate DSS key pair
    dsa = DSA_generate_parameters(1024, NULL, 0, NULL, NULL, NULL, NULL);
    if (dsa == NULL) {
        handleErrors();
    }

    if (!DSA_generate_key(dsa)) {
        handleErrors();
    }

    // Sign the message
    if (DSA_sign(0, message, strlen((char *)message), signature, NULL, dsa) != 1) {
        handleErrors();
    }

    // Verify the signature
    if (DSA_verify(0, message, strlen((char *)message), signature, sizeof(signature), dsa) != 1) {
        printf("Signature verification failed.\n");
    } else {
        printf("Signature verification succeeded.\n");
    }

    // Clean up
    DSA_free(dsa);
    ENGINE_cleanup();
    ERR_free_strings();

    return 0;
}

