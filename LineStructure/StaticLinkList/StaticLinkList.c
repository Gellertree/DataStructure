#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include"StaticLinkList.h"

List StaticLinkList_Create()
{
    List list = (List)malloc(sizeof(List)*MAXSIZE);
    for (int i = 0; i < MAXSIZE - 1; i++)
    {
        list[i].Cur = i+1;
    }
    list[MAXSIZE - 1].Cur = 0;
    return list;
}

//若备用空间链表非空，则返回分配的结点下标，否则返回0 
int MallocStaticLinkList(List list)
{
    int i = list[0].Cur;
    if (list[0].Cur)
    {
        list[0].Cur = list[i].Cur;
    }
    return i;   
}

int StaticLinkList_Insert(List list, ElementType node, int pos)
{
    //判断插入的位置是否正确
    int index = MAXSIZE - 1;
    if (pos < 1 || pos > index)
    {
        printf("The position is  error\n");
        return -1;
    }
    int insert_pos = MallocStaticLinkList(list);
    if (insert_pos)
    {
        list[insert_pos].Data = node;
        for (int i = 1; i < pos; i++)
        {
            index = list[index].Cur;
        }
        list[insert_pos].Cur = list[index].Cur;
        list[index].Cur = insert_pos;
        return 1;
    }  
    return -1;
}

void StaticLinkList_ShowList(List list)
{
    int index = MAXSIZE - 1;
    int count = 1;
    while(list[list[index].Cur].Data != 0)
    {
        printf("The %d number is %d\n",count++,list[list[index].Cur].Data);
        index = list[index].Cur;
    }
}

int StaticLinkList_Length(List list)
{
    int index = MAXSIZE - 1;
    if (list[list[index].Cur].Data == 0)
    {
        return 0;
    }
    else
    {
        int count = 0;
        while(list[list[index].Cur].Data != 0)
        {
            count++;
            index = list[index].Cur;
        }
        return count;
    }
    return 0;
}

int StaticLinkList_Find(List list, ElementType node)
{
    int index = MAXSIZE - 1;
    int flag = 0;
    int count = 1;
    while(list[list[index].Cur].Data != 0)
    {
        if (node ==list[list[index].Cur].Data){
            flag = 1;
            break;
        }
        index = list[index].Cur;
        count++;
    }
    if (flag == 0)
    {
        printf("Cann't not find this number \n");
        return -1;
    }else
    {
        return count;
    }  
}

ElementType StaticLinkList_Get(List list, int pos)
{
    int index = MAXSIZE - 1;
    if (pos < 1 || pos > index)
    {
        printf("The position is  error\n");
        return -1;
    }
    for (int i = 1; i < pos; i++)
    {
         index = list[index].Cur;
    }
    return list[list[index].Cur].Data;
}


void FreeStaticLinkList(List list, int pos)
{
    list[pos].Cur = list[0].Cur;
    list[0].Cur = pos;
}


void StaticLinkList_Delete(List list, int pos)
{
    int index = MAXSIZE - 1;
    if (pos < 1 || pos > index)
    {
        printf("The delete position is wrong!\n");
        return ;
    }
    for (int i = 1; i < pos; i++)
    {
        index = list[index].Cur;
    }
    int temp = list[index].Cur;
    list[index].Cur = list[temp].Cur;
    FreeStaticLinkList(list,temp);
}




