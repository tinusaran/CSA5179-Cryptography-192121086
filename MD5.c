#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>

int main() {
    char input_string[] = "Hello, MD5!";
    unsigned char digest[MD5_DIGEST_LENGTH];
    MD5_CTX mdContext;

    MD5_Init(&mdContext);
    MD5_Update(&mdContext, input_string, strlen(input_string));
    MD5_Final(digest, &mdContext);

    printf("MD5 Hash of '%s': ", input_string);
    for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        printf("%02x", digest[i]);
    }
    printf("\n");

    return 0;
}

