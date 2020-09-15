#include <stdio.h>
#include <stdlib.h>
#include "SeqList.h"



int main(int argc, char *argv[]) 
{
    List seqlist = SeqList_Create();
    SeqList_Insert(seqlist,1,1);
    SeqList_Insert(seqlist,2,1);
    SeqList_Insert(seqlist,3,1);
    SeqList_Insert(seqlist,4,2);
    SeqList_Insert(seqlist,5,5);

    printf("the 2nd number is %d\n",SeqList_Get(seqlist,2));

    printf("the number of 4 at the position of  %d\n",SeqList_Find(seqlist,4));

    printf("the list before delete is:\n");

    SeqList_ShowList( seqlist);
    
    SeqList_Delete(seqlist,2);
   
    printf("\nthe list after delete is:\n");

    SeqList_ShowList(seqlist);
    return 0;
}
