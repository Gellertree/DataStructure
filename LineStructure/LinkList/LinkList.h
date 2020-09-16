//
// Created by ZYBO_o on 2020/9/15.
//

#ifndef LIST_LINKLIST_H
#define LIST_LINKLIST_H

typedef int  ElementType;

typedef struct LNode *List; struct LNode{
	ElementType Data;
	List Next; 
};

List LinkList_Create();

void LinkList_Destroy(List list);

void LinkList_Clear(List list);

void LinkList_ShowList(List list);

int LinkList_Length(List list);

int LinkList_Insert(List *list, ElementType node, int pos);

ElementType LinkList_Get(List list, int pos);

int LinkList_Find(List list, ElementType node);

void LinkList_Delete(List* list, int pos);

#endif //LIST_LINKLIST_H
