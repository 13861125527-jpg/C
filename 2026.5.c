#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef int HPDataType;
typedef struct Heap
{
    HPDataType* data;
    int size;
    int capacity;
}Heap;
int main()
{
    HP hp;
    HeatINit(&hp);
        HeapPush(&hp,1);
        HeapPush(&hp,2);
        HeapPush(&hp,3);
            HeapPush(&hp,4);
            HeapPush(&hp,5);
            HeapPush(&hp,6);
            HeapPush(&hp,7);
                HeapPush(&hp,8);
                HeapPush(&hp,9);
                HeapPush(&hp,10);
                HeapPush(&hp,11);
}
void HeapInit(Heap* php);
void HeapDestroy(Heap* php);
void HeapPush(Heap* php,HPDataType x);
//数组存储表示二叉树只适合完全二叉树
void HeapInit(Heap* php)
{
  assert(php);
  php->data=(HPDataType*)malloc(sizeof(HPDataType)*10);
  if(php->data==NULL)
  {
    perror("malloc fail");
    return;
  }
  php->size=0;
  php->capacity=10;
}
void HeapDestroy(Heap* php)
{
    assert(php);
    free(php->data);
    php->data=NULL;
    php->size=0;
    php->capacity=0;
}
void Swap(HPDataType*p1,HPDataType*p2)
{
    HPDataType x=*p1;
    *p1=*p2;
    *p2=x;
}
void AdjustUp(HPDataType* data,int child)
{
    int parent= (child-1)/2;
    while(child>0)
    {
        if(data[child]>data[parent])
        {
            //HPDATAtype tmp=data->child;
            //data->child=data->parent;
            //data->parent=tmp;
            SWAP(&data[child].*data[parent]);
            child=parent;
            parent=(child-1)/2;
        }
        else
        {
            break;
        }
    }

}
void HeapPush(Heap* php,HPDataType x)
{
    assert(php);
    if(php->size==php->capacity)
    {
        HPDataType* tmp=(HPDataType*)realloc(php->data,sizeof(HPDataType)*php->capacity*2);
        if(tmp==NULL)
        {
            perror("realloc fail");
            return;
        }
        php->data=tmp;
        php->capacity*=2;
    }
    php->data[php->size]=x;
    php->size++;
    AdjustUp(php->data,php->size-1);

}
