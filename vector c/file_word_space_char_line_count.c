#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *readfromfile(char *filename)
{
	FILE *fp;
	long size;
	char *p;
	fp=fopen(filename,"r");
	if(fp==NULL)
	{
		printf("file is not open");
		exit(0);
	}
	fseek(fp,0,2);
	size=ftell(fp);
	rewind(fp);
	p=calloc(1,size+1);
	fread(p,size,1,fp);
	p[size+1]='\0';
	fclose(fp);
	return p;
}
long noofchar(char *buf, char ch)
{
	long cnt=0;
	while(buf=strchr(buf,ch))
	{
		cnt++;
		buf++;
	}
	return cnt; 
}
int main(int argc, char *argv[])
{
	char *buf=NULL;
	long lcnt,wcnt,ccnt;
	if(argc!=2)
	{
		printf("invalid input");
		exit(0);
	}
	buf=readfromfile(argv[1]);
	lcnt=noofchar(buf,'\n');
	wcnt=noofchar(buf,32);
	ccnt=strlen(buf);
	printf("word count=%ld line count=%ld char count=%ld space count=%ld\n", wcnt+lcnt, lcnt, ccnt, wcnt);

}
