#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */



int main(int argc, char *argv[])
{

    LinkList* list = LinkList_Create(10);

    int index = 0;

    int i = 0;
    int j = 1;
    int k = 2;
    int x = 3;
    int y = 4;
    int z = 5;

    LinkList_Insert(list, &i, 0);
    LinkList_Insert(list, &j, 0);
    LinkList_Insert(list, &k, 0);

    for(index=0; index<LinkList_Length(list); index++)
    {
        int* p = (int*)LinkList_Get(list, index);

        printf("%d\n", *p);
    }

    printf("\n");

    return 0;
}





