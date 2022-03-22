#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAXNSIZE 3
struct stack
{
	char Data[MAXNSIZE];
	int top;
};
typedef struct stack Stack;

bool Isfull();
void print(Stack s);
bool Isemptry(Stack s);
bool Push(Stack *ptrS,char c);
bool Pop(Stack *ptrS);

int main()
{
	Stack s;
	s.top=-1;
	Pop(&s);
	
	Push(&s,'A');
	Push(&s,'B');
	Push(&s,'C');
	printf("the stack_s is:");
	print(s);
	printf("\n"); 
	Push(&s,'D');
	printf("**Pop:");
	Pop(&s);
	return 0;
} 

void print(Stack s)
{
	if (Isemptry(s)) printf("ø’’ª\n");
	else for (int i=0;i<=s.top;i++) printf("%c ",s.Data[i]);
}
bool Isemptry(Stack s)
{
	return (s.top==-1);
}
bool Isfull(Stack s)
{
	return (s.top==MAXNSIZE-1);
}
bool Push(Stack *ptrS,char c)
{
	if (Isfull(*ptrS))
	{
		printf("**Push:¬˙’ª\n"); 
		return false;
	}
	
	ptrS->top++;
	ptrS->Data[ptrS->top]=c;
	return true;
}
bool Pop(Stack *ptrS)
{
	if (Isemptry(*ptrS))
	{
		printf("**Pop:ø’’ª\n");
		
		return false;
	}
	printf("%c\n",ptrS->Data[ptrS->top]);
	ptrS->Data[ptrS->top]='\0';
	ptrS->top--;
	return true;
}

