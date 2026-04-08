#include<stdio.h>
#include<stdbool.h>
#define maxsize 100
typedef struct  //定义一个结构体，名称
{
	int length;
	int data[maxsize];
}sqlist;
bool listdelete(sqlist *L, int pos, int* e)  //bool函数判断
{
	if (pos<1 || pos>L->length)  //判断pos是否在[1，length]之间
		return false;
	*e = L->data[pos - 1];  //指针e来存放删除的数据
	for (int i = pos - 1; i < L->length; i++)  //从pos-1开始后的每一位向前进1
	{
		L->data[i - 1] = L->data[i];
	}
	L->length--;
	return true;
}
void linkprint(sqlist *L)  //输出
{
	printf("%d", L->data[0]);
	for (int i = 1; i < L->length; i++)
	{
		printf(",%d", L->data[i]);
	}
}
int main()
{
	sqlist L;  //初始化结构体
	int e;
	L.length = 0;
	L.data[0] = 3, L.data[1] = 7, L.data[2] = 4;
	L.length = 3;  //修改后的
	linkprint(&L);
	printf("\n");
	listdelete(&L, 1, &e);
	linkprint(&L);  //判断是否删除成功
	return 0;
}
