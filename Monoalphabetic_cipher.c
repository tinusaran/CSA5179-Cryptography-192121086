#include<stdio.h>
#include<conio.h>
#include<string.h>
int main(){
	char pt[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	char ct[26]={'z','y','x','w','v','u','t','s','r','q','p','o','n','m','l','k','j','i','h','g','f','e','d','c','b','a'};
	char p[20]={'\0'},c[20]={'\0'},r[20]={'\0'};
	int i,j;
	printf("Enter your plain text :");
	scanf("%s",p);
	for(i=0;i<strlen(p);i++)
	{
		for(j=0;j<26;j++)
		{
			if(pt[j]==p[i])
			{
				c[i]=ct[j];
			}
		}
	}
	printf("Encrypted cipher text : %s \n",c);
	for(i=0;i<strlen(c);i++)
	{
		for(j=0;j<26;j++)
		{
			if(ct[j]==c[i])
			{
				r[i]=pt[j];
			}
		}
	}
	printf("Decrypted plain text : %s",r);
}
