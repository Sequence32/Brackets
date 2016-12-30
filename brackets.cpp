#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
	/*Start the stacks top at -1 we will add one every time until a left bracket 
		is seen when we loop through the array of chars, when a right bracket is seen
		if the right bracket matches the left bracket we pop of top off  the stack.
		
	*/
	lastLeft.top=-1;
	
	//Numbering is the number of strings that the user will be prompt for
    int numString; 
    scanf("%d",&numString);
    for(int i = 0; i < numString; i++)
    {
    	//This is just an array or pointer to memory location 
        char* s = (char *)malloc(10240 * sizeof(char));
        
        scanf("%s",s);
 
        
		while(*s)
		{
			if((lastLeft.top == -1) &&(strchr(rightChar, *s)))
			{
				//I set this to 10 just to let the if outside the while know to print NO
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
 
