#include<iostream>
#include<malloc.h>
#include<cstdlib>
using namespace std;
typedef int KeyType;
typedef int InfoType;
typedef struct {
    KeyType key;
    InfoType info;
} RecType;
void Merge(RecType R[],int left,int mid,int right)
{
    RecType *R1;
    int i=left,j=mid+1,k=1; //k是R1下标,i、j是第1、2段的下标
    R1=(RecType *)malloc((right-left+1)*(sizeof(RecType)));
    while(i<=mid && j<=right)
    {
        if(R[i].key<=R[j].key)
        {
            R1[k]=R[i];
            i++;k++;
        }
        else
        {
            R1[k]=R[j];
            j++;k++;
        }
    }    
    while(i<=mid)
    {
        R1[k]=R[i];
        i++;k++;
    }
    while(j<=right)
    {
        R1[k]=R[j];
        j++;k++;
    }
    for(k=1,i=left;i<=right;k++,i++)
        R[i]=R1[k];
}

void MergePass(RecType R[],int length,int n)
{
    int i;
    for(i=1;i+2*length-1<=n;i=i+2*length)
        Merge(R,i,i+length-1,i+2*length-1);
        if(i+length<=n)
            Merge(R,i,i+length-1,n);
}

void MergeSort(RecType R[],int n)
{
    int length;
    for(length=1;length<n;length=2*length)
        MergePass(R,length,n);
}
int main()
{
    // 测试归并排序
    const int size = 8;
    RecType arr[size] = {{49, 1}, {38, 2}, {65, 3}, {97, 4}, {76, 5}, {13, 6}, {27, 7}, {49, 8}};

    cout << "原始数组：";
    for (int i = 0; i < size; ++i)
        cout << "(" << arr[i].key << "," << arr[i].info << ") ";

    MergeSort(arr, size);

    cout << "\n排序后数组：";
    for (int i = 0; i < size; ++i)
        cout << "(" << arr[i].key << "," << arr[i].info << ") ";
    system("pause");
    return 0;
}