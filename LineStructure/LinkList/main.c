#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */



int main(int argc, char *argv[])
{
    List linklist = LinkList_Create();

    printf("The length of the List is %d\n",LinkList_Length(linklist));

    LinkList_Insert(&linklist,1,1);
    LinkList_Insert(&linklist,2,1);
    LinkList_Insert(&linklist,3,1);
    LinkList_Insert(&linklist,4,2);
    LinkList_Insert(&linklist,5,5);

    printf("The length of the List is %d\n",LinkList_Length(linklist));

    printf("The List is\n");
    LinkList_ShowList(linklist);

    // printf("The 3rd of the List is %d\n",LinkList_Get(linklist,3));

    // printf("The number of the 2 at %d\n",LinkList_Find(linklist,2));

    LinkList_Delete(&linklist,1);

    printf("After delete,the List is\n");
    LinkList_ShowList(linklist);
    return 0;
}





