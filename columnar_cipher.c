#include<stdio.h>
#include<string.h>
void encrypt(char message[],int key){
	int len=strlen(message),row=(len+key-1)/key,m=0;
	char encry[100][100];
	int index=0,i,j;
	for(i=0;i<row;i++){
		for(j=0;j<key;j++){
			if(m<len){
				encry[i][j]=message[m];
				m++;	
			}
			else{
				encry[i][j]='X';
			}
			
		}
	}
	for(j=0;j<key;j++){
		for(i=0;i<row;i++){
			if(encry[i][j]!='X')
				printf("%c ",encry[i][j]);
		}
	}
}
int main(){
	char message[100],key_l[100];
	int key;
	printf("Enter a Message : ");
	scanf("%s",&message);
	printf("Enter the key : ");
	scanf("%s",&key_l);
	printf("Encryted message...\n");
	key=strlen(key_l);
	encrypt(message,key);
}
	
