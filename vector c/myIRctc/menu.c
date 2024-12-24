#include"myIRctc.h"
int main()
{
	char choice;
	while(1)
	{
		printf("i-sigin u-sigup E-exit\n");
		printf("Enter your choice\n");
		__fpurge(stdin);
		scanf("%c",&choice);
		switch(choice)
		{
			case 'i' : sigin;
				   break;
		//        case 'u' : sigup;
		//		   break;
			case 'E' : exit(0);	   
		}
	}
}
