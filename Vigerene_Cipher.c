#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
void encrypt(){
    unsigned int i, j; 
    char plain[127];
    char key[15];
    printf("\n Enter the plaintext (maximum 128 characters): ");
    scanf("%s",&plain);
    printf("\n Enter the key (maximum 16 characters): ");
    scanf("%s",&key);
    printf("\n Cipher Text: ");
    for (i = 0, j = 0; i < strlen(plain); i++, j++){
        if (j >= strlen(key)){
            j = 0;
        }
        printf("%c", 65 + (((toupper(plain[i]) - 65) + (toupper(key[j]) - 65)) % 26));
    }
    printf("\n");
}
void decrypt(){
    unsigned int i, j;
    char plain[127];
    char key[15];
    int value;
    printf("\n Enter the cipher text: ");
    scanf("%s",&plain);
    printf("\n Enter the key: ");
    scanf("%s",&key);
    printf("Decrypted message...\n");
    for (i = 0, j = 0; i < strlen(plain); i++, j++){
        if (j >= strlen(key)){
            j = 0;
        }
        value = (toupper(plain[i]) - 64) - (toupper(key[j]) - 64);
        if (value < 0){
            value = value + 26;
        }
        printf("%c", 65 + (value % 26));
    }
}
int main(){
    int option;
    while (1){
        printf("\n 1. Encipher!!");
        printf("\n 2. Decipher!!");
        printf("\n 3. Exit \n");
        printf("\n Enter your option: ");
        scanf("%d", &option);
        if (option == 3)
            exit(0);
        else if (option == 1)
            encrypt();
        else if (option == 2)
            decrypt();
        else
            printf("\n Invalid selection!!Try again!! ");
    }
    return 0;
}
