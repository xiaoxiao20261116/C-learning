#include<stdio.h>
#include<stdbool.h>
#define maxsize 100
typedef struct
{
	int length;
	int data[maxsize];
}sqlist;
int listSearch(sqlist* L, int val)
{
	for (int i = 0; i < L->length; i++)
	{
		if (L->data[i] == val)
			return  i+1;
	}
	return -1;
}
void linkprint(sqlist* L)
{
	if (L->length == 0) return;
	printf("%d", L->data[0]);
	for (int i = 1; i < L->length; i++)
		printf(",%d", L->data[i]);
	printf("\n");
}
int main()
{
	sqlist L;
	L.length = 0;
	L.data[0] = 7, L.data[1] = 8, L.data[2] = 6, L.data[3] = 0;
	L.length = 4;
	linkprint(&L);
	int target = 0;
	int pos = listSearch(&L, target);
	if (pos != -1)
	{
		printf("找到元素%d,位置%d", target, pos);
	}
	else printf("没有找到元素%d", target);
	linkprint(&L);
	return 0;
}