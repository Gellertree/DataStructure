#include <stdio.h>
#include <malloc.h>
#include "SeqList.h"


//Create a List
List SeqList_Create() 
{
    List SeqList;
    SeqList = (List)malloc(sizeof(List));
    SeqList->Last=-1;
    return SeqList;
}

void SeqList_Destroy(List list) 
{
    free(list);
}

void SeqList_Clear(List list) 
{
    if (list->Last != 0)
    {
        list->Last = 0;
    }
}

int SeqList_Length(List list) 
{
    return (list->Last + 1);
}


void SeqList_Insert(List list, ElementType node, int pos) 
{
    if(list->Last == MAXSIZE - 1){
        printf("the List is full!\n");
        return;
    }
    if (pos-1 < 0 || pos >  list->Last + 2)
    {
        printf("the position is wrong!\n");
        return;
    }
    for (int i = list->Last; i > pos-2; i--)
    {
        list->Data[i+1] = list->Data[i];
    }
    list->Data[pos-1] = node;
    list->Last++;
}


void SeqList_ShowList(List list)
{
    for (int i = 0; i < SeqList_Length(list); i++)
    {
        printf("list[%d] = %d\n",i+1,list->Data[i]);
    }
}

ElementType SeqList_Get(List list, int pos)
{
    if (pos < 1 || pos > list->Last + 1)
    {
        printf("the position is wrong!\n");
	return -1;
    }
    else{
    	return list->Data[pos-1];
    }
}

ElementType SeqList_Find(List list,ElementType node)
{
    int pos = 0;
    while (pos < list->Last+1 && list->Data[pos] != node )
    {
        pos++;
    }

    if (pos > list->Last)
    {
         printf("Cann't fint it !\n");
         return -1;
    }
    return pos + 1;  
}

void SeqList_Delete(List list, int pos) 
{
    if(pos < 1 || pos > list->Last+1){
        printf("the position is wrong!\n");
        return;
    }
    for (int i = pos-1; i < list->Last + 1; i++)
    {
        list->Data[i] = list->Data[i+1];
    }
    list->Last--;
}
