#include<stdio.h>
#include<stdbool.h>
#define maxsize 100
typedef struct  //结构体
{
	int length;
	int data[maxsize];
}sqlist;
int listSearch(sqlist* L, int val)  //查找
{
	for (int i = 0; i < L->length; i++)//查找区间为[0,length]
	{
		if (L->data[i] == val)
			return  i+1;
	}
	return -1;
}
void linkprint(sqlist* L)
{
	if (L->length == 0) return;//判断是否为空
	printf("%d", L->data[0]);
	for (int i = 1; i < L->length; i++)
		printf(",%d", L->data[i]);//这里的逗号可以将数值分开
	printf("\n");
}
int main()
{
	sqlist L;
	L.length = 0;
	L.data[0] = 7, L.data[1] = 8, L.data[2] = 6, L.data[3] = 0;
	L.length = 4;
	linkprint(&L);
	int target = 0;  //定义需要求的数
	int pos = listSearch(&L, target);  //定义需要求的位置
	if (pos != -1)
	{
		printf("找到元素%d,位置%d", target, pos);
	}
	else printf("没有找到元素%d", target);
	linkprint(&L);  //再次验证
	return 0;
}
