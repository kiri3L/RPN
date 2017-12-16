#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include"Stack_float.h"


int main()
{
	char exp[256];
	float a,b;
	printf("\nEnter expression\n");
	for(;;)
	{
		scanf("%s",exp);
		if(exp[0] == '+')
				{
					a = pop();
					b = pop();
					push(a+b);
				}
		else if(exp[0] == '-')
			{
				a = pop();
				b = pop();
				push(b - a);
			}
		else if (exp[0] == '*')
			{			
				a = pop();
				b = pop();
				push(b*a);
			}
		else if(exp[0] == '/')
			{
				a = pop();
				b = pop();
				if ( a != 0)
					push((b / a));
			}
		else if(exp[0] == '=')
			{
				a = pop();
				push(a);
				printf("\n%f\n",a);
			}
		else if(exp[0] == 'c')
			{
				clean_stack();
			}
		else push(atof(exp));

			
		
	}
	return 0;
}
