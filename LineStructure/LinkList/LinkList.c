//
// Created by ZYBO_o on 2020/9/15.
//

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "LinkList.h"

typedef struct _tag_LinkList
{
    LinkListNode head;
    int length;
}TLinkList;

LinkList* LinkList_Create()
{
    //动态生成一个表头结点
    TLinkList* ret = (TLinkList*)malloc(sizeof(TLinkList));
    //判断是否创建成功
    if(ret != NULL)
    {
        ret->length = 0;
        ret->head.next = NULL;
    }
    //返回创建的链表
    return ret;
}

void LinkList_Destroy(LinkList* list)
{
    free(list);
}

void LinkList_Clear(LinkList* list)
{
    //进行强制转换
    TLinkList* slist = (TLinkList*)list;

    //长度设置为0，头结点指向空
    if(slist != NULL)
    {
        slist->length = 0;
        slist->head.next = NULL;
    }
}


int LinkList_Length(LinkList* list)
{
    //进行强制转换
    TLinkList* slist = (TLinkList*)list;
    int ret = -1;
    //长度赋给变量然后返回
    if(slist != NULL)
    {
        ret = slist->length;
    }

    return ret;
}


int LinkList_Insert(LinkList* list, LinkListNode* node, int pos)
{
    //进行强制转换
    TLinkList* slist = (TLinkList*)list;
    //进行条件检测
    int ret = (slist != NULL) && (pos >= 0) && (node != NULL);

    if(ret)
    {
        //定义一个插入指针指向头结点
        LinkListNode* current = (LinkListNode*)slist;
        //移动指针到需要插入的地方
        for(int i = 0; (i < pos) && (current->next != NULL); i++)
        {
            current = current->next;
        }
        //插入节点
        node->next = current->next;
        current->next = node;
        //链表长度加一
        slist->length++;
    }
    return ret;
}

LinkListNode* LinkList_Get(LinkList* list, int pos)
{
    //进行强制转换
    TLinkList* slist = (TLinkList*)list;
    LinkListNode* ret = NULL;
    //进行条件检测
   if((slist != NULL) && (pos >= 0) && (pos < slist->length))
    {
        //定义一个插入指针指向头结点
        LinkListNode* current = (LinkListNode*)slist;
        //移动指针到指定的地方
        for(int i = 0; (i < pos) && (current->next != NULL); i++)
        {
            current = current->next;
        }
        //把对应的节点地址赋给ret
        ret = current->next;
    }
    return ret;
}

LinkListNode* LinkList_Delete(LinkList* list, int pos)
{
    //进行强制转换
    TLinkList* slist = (TLinkList*)list;
    LinkListNode* ret = NULL;
    //进行条件检测
    if((slist != NULL) && (pos >= 0) && (pos < slist->length))
    {
        //定义一个插入指针指向头结点
        LinkListNode* current = (LinkListNode*)slist;
        //移动指针到指定的地方
        for(int i = 0; (i < pos) && (current->next != NULL); i++)
        {
            current = current->next;
        }
        //进行删除操作
        ret = current->next;
        current->next = ret->next;

        //链表长度减一
        slist->length--;
    }
    return ret;
}


