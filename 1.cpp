#include<stdio.h>
#include<stdbool.h>
#define maxsize 100
typedef struct
{
	int length;
	int data[maxsize];
}sqlist;
bool listdelete(sqlist *L, int pos, int* e)
{
	if (pos<1 || pos>L->length)
		return false;
	*e = L->data[pos - 1];
	for (int i = pos - 1; i < L->length; i++)
	{
		L->data[i - 1] = L->data[i];
	}
	L->length--;
	return true;
}
void linkprint(sqlist *L)
{
	printf("%d", L->data[0]);
	for (int i = 1; i < L->length; i++)
	{
		printf(",%d", L->data[i]);
	}
}
int main()
{
	sqlist L;
	int e;
	L.length = 0;
	L.data[0] = 3, L.data[1] = 7, L.data[2] = 4;
	L.length = 3;
	linkprint(&L);
	printf("\n");
	listdelete(&L, 1, &e);
	linkprint(&L);
	return 0;
}