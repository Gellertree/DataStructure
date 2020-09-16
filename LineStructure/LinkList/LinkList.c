//
// Created by ZYBO_o on 2020/9/15.
//

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "LinkList.h"

List LinkList_Create(){
    List LinkList;
    LinkList = (List)malloc(sizeof(List));
    LinkList->Next = NULL;
    return LinkList;
}

void LinkList_Destroy(List list){
    free(list);
    return ;
}

void LinkList_Clear(List list){
    List p = list->Next;
    while (p)
    {
        free(p);
    }
}

int LinkList_Length(List list){
  int length = 0;
  List p = list->Next;
  while (p)
  {
      length++;
      p = p->Next;
  }
  return  length;
}

int LinkList_Insert(List *list, ElementType node, int pos){
    if (pos == 1)
    {
        List temp = (List)malloc(sizeof(List));
        temp->Data = node;
        temp->Next = *list;
        *list = temp;
        return 1;
       
    }
    if (pos < 1 || pos > LinkList_Length(*list)+1)
    {
        printf("this position is wrong!\n");
        return -1;
    }
    if (pos > 1 || pos < LinkList_Length(*list)+2)
    {
        List p = *list;
        List temp = (List)malloc(sizeof(List));
        temp->Data = node;
        for (int i = 0; i < pos-2; i++)
        {
            p = p->Next;
        }
        temp->Next = p->Next;
        p->Next = temp;
        return 1;
    }
}

void LinkList_ShowList(List list){
    List p = list;
    int i = 0;
    while (p->Next)
    {
        printf("List[%d] = %d\n", i + 1,p->Data);
        p = p->Next;
        i++;
    }
}

ElementType LinkList_Get(List list, int pos){
    if (pos < 1 || pos > LinkList_Length(list) + 1)
    {
        printf("the position is wrong!\n");
        return 0;
    }
    List p = list;
    for (int i = 0; i < pos-1; i++)
    {
        p = p->Next;
    }
    return p->Data;
}

int LinkList_Find(List list, ElementType node){
    int i = 0;
    List p = list;
    while (p->Data != node && p->Next)
    {
        p = p->Next;
        i++;
    }
    if(p->Next){
        return i+1;
    }else
    {
        printf("Cann't fint it !\n");
        return -1;
    }
    
}

void LinkList_Delete(List* list, int pos){
    List p = *list;
    if (pos < 1 || pos > LinkList_Length(*list))
    {
        printf("The poistion is wrong!\n");
        return;
    }else if (pos == 1)
    {
        *list = p->Next;
        free(p);
    }else
    {
        for (int i = 0; i < pos-2; i++){
            p = p->Next;
        }
        List temp = p->Next;
        p->Next = temp->Next;
        free(temp);
    }
}

