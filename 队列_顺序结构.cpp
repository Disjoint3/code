#include<stdio.h>
#include<stdlib.h>
typedef int Position;
typedef char ElementType;
typedef struct QNode *PtrToQNode;
struct QNode {
	ElementType *Data;     /* 存储元素的数组 */
	Position Front, Rear;  /* 队列的头、尾指针 */
	int MaxSize;           /* 队列最大容量 */
};
typedef PtrToQNode Queue;

Queue Create(int MaxSize) {
	Queue q=(Queue)malloc(sizeof(struct QNode));
	q->Data=(ElementType *)malloc(MaxSize*sizeof(ElementType));
	q->MaxSize=MaxSize;
	q->Front=q->Rear=4;
	
	return q;
}

bool AddQ(Queue q,ElementType x)
{
	//printf("%d %d\n",q->Front,q->Rear);
	if ((q->Rear+1)%q->MaxSize==q->Front)
	{
		printf("队列满**\n");
		return false; 
	}
	
	q->Rear=(q->Rear+1)%q->MaxSize;
	q->Data[q->Rear]=x;
	return true;
}

ElementType DeleteQ(Queue q)
{
	if (q->Front==q->Rear)
	{
		printf("队列空\n");
		return '\0';
	}
	
	q->Front=(q->Front+1)%q->MaxSize;
	return q->Data[q->Front];
}

void print(Queue q)
{
	if (q->Front==q->Rear) printf("队列空\n");
	else
	   for (int i=(q->Front+1)%q->MaxSize;i<=q->Rear%q->MaxSize;i=(i+1)%q->MaxSize)
	      printf("%c ",q->Data[i]);
}


int main() 
{
	Queue q;
	q=Create(5);
	
	DeleteQ(q);
	AddQ(q,'A');
	print(q);
	AddQ(q,'B');
	AddQ(q,'C');
	AddQ(q,'D');
	AddQ(q,'E');
	print(q);
	
	char str;
	str=DeleteQ(q);
	if (str!='\0')
	 printf("%c已被删除\n",str);
	 
	print(q);
	
	return 0;
}
