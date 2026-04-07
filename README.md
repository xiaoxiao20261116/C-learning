# C-learning
My C language learning notes and codes
#include<stdio.h>
#include<stdbool.h>
#define maxsize 100
typedef struct
{
	int data[maxsize];
	int length;
}sqList;
bool ListInsert(sqList* L, int pos, int val)
{
	if (pos<1 || pos>L->length + 1)
		return false;
	if ( L->length>= maxsize)
		return false;
	for (int i = L->length; i > pos; i--)
	{
		L->data[i] = L->data[i - 1];
	}
	L->data[pos - 1] = val;
	L->length++;
	return true;
}
void printList(sqList* L)
{
	int i;
	if (L->length == 0)return;
	printf("%d", L->data[0]);
	for (i = 1; i < L->length ; i++)
	{
		printf(",%d", L->data[i]);
	}
}
int main()
{
	sqList L;
	L.length = 0;
	L.data[0] = 7, L.data[1] = 8, L.data[2] = 3;
	L.length = 3;
	printList(&L);
	printf("\n");
	ListInsert(&L, 1, 9);
	printList(&L);
	return 0;
}
