/*
 * @Description: Application for LinkList
 * @Version: 0.1
 * @Autor: Roman.Liu
 * @Date: 2019-12-10 11:10:50
 * @LastEditors: Roman.Liu
 * @LastEditTime: 2019-12-12 17:42:03
 */
/* The begin of Include */
#include <stdio.h>
#include <stdlib.h>
#include "Link_List.h"
/* The end of Include */
/**
 * @description: Create a List 
 * @param {int} length
 * @return: The head point of list
 * @author: Roman.Liu
 */
pNode CreateList(int length)/* 创建链表 */
{
    int i;
    /* 1.创建头节点 */
    pNode pHead = (pNode)malloc(sizeof(Node));
    /* 2.添加判断防止堆溢出 */
    if(pHead == NULL)
    {
        printf("Create Failed");
        return NULL;
    }
    /* 3.创建尾节点、尾节初始指向头节点*/
    pNode pTail = pHead;
    /* 4.尾节点指向NULL表示链表结束*/
    pTail->Next = NULL;
    for (int i = 0; i < length; i++) 
    {

        pNode pNew = (pNode)malloc(sizeof(Node));    //    分配一个新节点
        if (pNew == NULL) 
        {
            printf("分配新节点失败\n");
            return NULL;
        }      
        pNew->elem = 0;        //把数据赋值给节点数据域
        pTail->Next = pNew;    //末尾节点指针指向下一个新节点
        pNew->Next = NULL;     //新节点指针指向为空
        pTail = pNew;          //将新节点复制给末尾节点        
    }
    return pHead;
}
/**
 * @description: Insert a elem in List
 * @param {pNode} pNode List,int pos,int val
 * @return: NULL
 * @author: Roman.Liu
 */
void InserList(pNode List,int pos,int val)/* 插入链表 */   
{
    int position = 0;
    /* 1.定义节点p指向头节点 */
    pNode p = List;
    /* 2.判断节点是否存在并寻找插入位置的前驱点 */
    while(p != NULL && position <pos -1)
    {
        p = p->Next;
        ++position;
    }
    /* 3.创建一个零时节点来存储需要写入的数据 */
    pNode NewNode = (pNode)malloc(sizeof(Node));
    /* 4.添加判断防止堆溢出 */
    if(NewNode == NULL)
    {
        printf("Create New Node Failed");
    }
    /* 5.将数据赋值到节点数据 */
    NewNode->elem = val;
    /* 6.将新节点指向尾部 */
    NewNode->Next = p->Next;
    /* 7.将最后一个节点后节点指针指向新节点 */
    p->Next = NewNode;
}
/**
 * @description: Delete All List elem
 * @param {pNode} List
 * @return: NULL
 * @author: Roman.Liu
 */
void DeleteAllTheList(pNode List)/* 删除链表 */   
{
   pNode p,temp;
   /* 1.定义指针指向需要删除链表的第一个节点 */
   p = List->Next;
   List->Next = NULL;
   while (p != NULL)
   {
    /* 2.定义temp指向要删除节点的下一个节点 */    
       temp = p->Next;
    /* 3.释放指针p指向的节点 */    
       free(p);
    /* 4.重新赋值 */       
       p = temp;
       /* code */
   }
   
}
/**
 * @description: Delete someone elem in the List
 * @param {pNode,int} List,pos
 * @return: NULL
 * @author: Roman.Liu
 */
void DeleteListElem(pNode List,int pos)/* 指定删除链表中的元素 */
{
    int position = 0;
    /* 1.定义一个指针指向链表的头指针 */
    pNode p = List;
    /* 2.找到需要删除节点的前驱节点 */
    while(p != NULL&&position < pos -1)
    {
        p = p->Next;
        ++position; 
    }
    /* 3.定义一个临时节点指向需要删除的节点 */
    pNode temp = p->Next;
    /* 4.将需要删除的节点的前驱节点指向其后驱节点 */
    p->Next = temp->Next;
    /* 5.释放删除节点的空间 */
    free(temp);
    /* 6.使零时指针指向空 ！！防止野指针出现 */
    temp = NULL;
}
/**
 * @description: Printf all the LinkList
 * @param {pNode} List
 * @return: NULL
 * @author: Roman.Liu
 */
void TraverseList(pNode List) /* 遍历打印所有的链表中的元素 */
{
    pNode p = List->Next;
    if(p == NULL)
    {
        printf("link list is empty");
    }
    while(p != NULL)
    {
        printf("%d",p->elem);
        p = p->Next;
    }
    printf("\n");
}
/**
 * @description: Get the length of linklist
 * @param {type} 
 * @return:  length
 * @author: Roman.Liu
 */
int GetLength(pNode List)/* 获取整个链表的长度 */
{
    pNode p = List;
    int i = 0;
    while (p->Next != NULL)
    {
        /* code */
        i++;
        p = p->Next;
    }
    return i;
}
