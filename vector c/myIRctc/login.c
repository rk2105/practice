//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
#include"myIRctc.h"
void writetofilepass(char *pass);
void writetofileuser(char *user);
int isvalidpass(char *pass);
int main()
{
	char pass[20],user[20];
	printf("Enter your USER-ID: ");
	scanf("%s", user);
reenter:printf("Enter your PASSWORD: ");
	scanf("%s", pass);
	writetofileuser(user);
	if(isvalidpass(pass))
	{
		printf("valid password");
		writetofilepass(pass);//password cpy to file(login.txt)
	}
       else
        	goto reenter;//reEnter password
}
int isvalidpass(char *pass)
{
	int i, upper=0, lower=0, numic=0, spical=0;
	for(i=0;pass[i]!='\0';i++)
	{
		if(pass[i]>='A' && pass[i]<='Z')
			upper=1;
		else if(pass[i]>='a' && pass[i]<='z')
			lower=1;
	        else if(pass[i]>=48 && pass[i]<=57)
			numic=1;
		else
			spical=1;
	}
	if(upper && lower && numic && spical)
                     return 1;
}
void writetofilepass(char *pass)
{
	FILE *fp; char *p=NULL; long size;
	fp=fopen("login.txt","a");
	fprintf(fp,"%s",pass);
	fseek(fp,0,2);
	size=ftell(fp)+1;
	fseek(fp,0,0);
	p=calloc(1,size);
	fread(p,size,1,fp);
	p[size-1]='\0';
	fclose(fp);
}
void writetofileuser(char *user)
{
	FILE *fp; char *p; long size;
	fp=fopen("login.txt","a");
	fprintf(fp,"%s",user);
	fseek(fp,0,2);
	size=ftell(fp)+1;
	fseek(fp,0,0);
	p=calloc(1,size);
	fread(p,size,1,fp);
	p[size-1]='\0';
	p[size]=' ';
	fclose(fp);
}
