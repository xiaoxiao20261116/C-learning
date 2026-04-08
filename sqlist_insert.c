#include<stdio.h>
#include<stdbool.h>
#define maxsize 100
typedef struct   //定义结构体，名称
{
	int data[maxsize];
	int length;
}sqList;
bool ListInsert(sqList* L, int pos, int val)//判断是否满足条件
{
	if (pos<1 || pos>L->length + 1)  //判断pos是否在[1,length+1]里
		return false;
	if ( L->length>= maxsize)  //长度不能超过最大
		return false;
	for (int i = L->length; i > pos; i--)  //遍历插入位置后的所有数，并使它们向后移一个单位
	{
		L->data[i] = L->data[i - 1];
	}
	L->data[pos - 1] = val;
	L->length++;
	return true;
}
void printList(sqList* L)  //用来输出
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
	sqList L;  //初始化
	L.length = 0;
	L.data[0] = 7, L.data[1] = 8, L.data[2] = 3;
	L.length = 3;
	printList(&L);
	printf("\n");
	ListInsert(&L, 1, 9);
	printList(&L);  //判断插入是否成功
	return 0;
}
