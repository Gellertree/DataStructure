#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#define MAXSIZE 100
typedef int ElementType;


typedef struct LNode *List; struct LNode
{
    ElementType Data[MAXSIZE];
	int Last;
} ;

List SeqList_Create( );

void SeqList_Destroy(List list);

void SeqList_Clear(List list);

int SeqList_Length(List list);


void SeqList_Insert(List list, ElementType node, int pos);

void SeqList_ShowList(List list);

ElementType SeqList_Get(List list, int pos);

ElementType SeqList_Find(List list, ElementType node);

void SeqList_Delete(List list, int pos);

#endif

