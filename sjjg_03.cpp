#include<iostream>
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
using namespace std;
#define MaxSize 50
typedef int ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int length;
}SqList;
void InitList(SqList *&L)
{
	L=(SqList*)malloc(sizeof(SqList));
	L->length=0;
}
 void DestroyList(SqList *L)
 {
 	free(L);
 }
 bool ListEmpty(SqList *L)
 {
    return (L->length==0);
 }
 int ListLength(SqList *L)
 {
 	return(L->length);
 }
 void DispList(SqList *L)
{
        for(int i=0;i<L->length;i++)
        printf("%d",L->data[i]);
        printf("\n");
}
 bool GetElem(SqList *L,int i,ElemType &e)
 {
 	if(i<1||i>L->length)
	return false;
	e=L->data[i-1];
	return true;

 }
 int LocateElem(SqList *&L,ElemType e)
 {
 	int i=0;
 	while(i<L->length&&L->data[i]!=e)
 	i++;
 	if(i>=L->length)
 	return 0;
 	else
 	return i+1;
 }
bool ListInsert(SqList *&L,int i,ElemType e)
{
	int j;
	if(i<1||i>L->length+1)
	return false;
	i--;
	for(j=L->length;j>i;j--)
	L->data[j]=L->data[j-1];
	L->data[i]=e;
	L->length++;
	return true;
}
bool ListDelete(SqList *&L,int i)
{
	int j;
		if(i<1||i>L->length+1)
	return false;
	i--;
	for(j=i;j<L->length-1;j++)
	L->data[j]=L->data[j+1];
	L->length--;
	return true;
}
int main() 
{
    SqList *L;
    int M;
    printf("(1)初始化顺序表L\n");
    InitList(L);
    printf("(2)输入顺序表的长度M：");
    scanf("%d",&M);
    printf("\n(3)依次插入M个元素\n");
    for(int i=0;i<M;i++)
    {
        int k;
        scanf("%d",&k);
        ListInsert(L,i+1,k);
    }
    printf("(4)输入要删除的数据元素的值:");
    int d;
    scanf("%d",&d);
	do
	{
		int l=LocateElem(L,d);
		ListDelete(L,l);
    }while(0!=LocateElem(L,d));
	printf("\n(5)输出删除后的顺序表:");
    DispList(L);
	system("pause");
}


