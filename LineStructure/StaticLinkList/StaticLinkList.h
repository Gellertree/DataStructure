//
// Created by ZYBO_o on 2020/9/17.
//

#ifndef STAIC_LINKLIST_H
#define STAIC_LINKLIST_H
#define MAXSIZE 100

typedef int  ElementType;

typedef struct LNode *List; struct LNode{
	ElementType Data;
    //Cursor,为0时表示无指向 
	int Cur; 
};

List StaticLinkList_Create();

void StaticLinkList_ShowList(List list);

int StaticLinkList_Length(List list);

int MallocStaticLinkList(List list);

int StaticLinkList_Insert(List list, ElementType node, int pos);

ElementType StaticLinkList_Get(List list, int pos);

int StaticLinkList_Find(List list, ElementType node);

void FreeStaticLinkList(List list, int pos);

void StaticLinkList_Delete(List list, int pos);



#endif 