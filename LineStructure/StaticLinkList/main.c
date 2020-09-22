#include<stdio.h>
#include<stdlib.h>
#include"StaticLinkList.h"

int main() {
    List staticlinklist = StaticLinkList_Create();
    
    printf("The length of the StaticLinkList is %d\n",StaticLinkList_Length(staticlinklist));
    
    StaticLinkList_Insert(staticlinklist,10,1);
    StaticLinkList_Insert(staticlinklist,20,1);
    StaticLinkList_Insert(staticlinklist,30,3);
    StaticLinkList_Insert(staticlinklist,40,3);

    StaticLinkList_ShowList(staticlinklist);
    
    printf("The length of the StaticLinkList is %d\n",StaticLinkList_Length(staticlinklist));

    printf("The 2 number is %d\n",StaticLinkList_Get(staticlinklist,2));

    printf("The 50 at the position of %d\n",StaticLinkList_Find(staticlinklist,50));

    StaticLinkList_Delete(staticlinklist,1);

    StaticLinkList_ShowList(staticlinklist);
    return 0;
}