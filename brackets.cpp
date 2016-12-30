#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#define MAXSIZE	 100000

struct stack
{
    int stackPos[MAXSIZE];
    int top;
};

typedef struct stack STACK;
    
STACK lastLeft;

void pop(void);
void push(STACK* , char *);

const char *leftChar ="[{(";
const char *rightChar ="]})";

int main(int argc, char* argv[])
{
	lastLeft.top=-1;
	
    int numString; 
    scanf("%d",&numString);
    for(int i = 0; i < numString; i++)
    {
        char* s = (char *)malloc(10240 * sizeof(char));
        
        scanf("%s",s);
 
        
		while(*s)
		{
			if((lastLeft.top == -1) &&(strchr(rightChar, *s)))
			{
				lastLeft.top = 10;
				break;
			}
			if(strchr(leftChar, *s))
			{
				push(&lastLeft, s);
			}
			else if(strchr(rightChar, *s))
			{
				if((lastLeft.stackPos[lastLeft.top] == *s-2 ) || (lastLeft.stackPos[lastLeft.top] == *s-1))
				{
					pop();
				}
			}
			s++;
		}
		if(lastLeft.top > -1)
			printf("NO\n");
		else
			printf("YES\n");
			
		lastLeft.top = -1;
    }
    return 0;
}
void pop()
{
	lastLeft.top--;
}
void push(STACK *sak, char *toStack)
{
    sak->top++;
    sak->stackPos[sak->top] = *toStack;
}
 
