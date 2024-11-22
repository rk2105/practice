#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *rev(char *ptr);
//int main(int agrc, char *argv[])
int main()
{
	FILE *fp;
	char str[100];
	fp=fopen("data.txt","r+");
	if(fp==NULL)
	{
		printf("no file exist");
		exit(0);
	}
	while(fgets(str,100,fp))
	{
		rev(str);
	}
}
char *rev(char *ptr)
{
	int j=strlen(ptr)-1;
	int i=0;
	static char rev[20];
	while(j>=0)
	{
		rev[i]=ptr[j];
		i++;
		j--;
	}
	rev[i]='\0';
	return rev;
}
