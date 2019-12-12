/*
 * @Description: main.c for application linklist
 * @Version: 1.0
 * @Autor: Roman.Liu
 * @Date: 2019-12-10 10:13:04
 * @LastEditors: Roman.Liu
 * @LastEditTime: 2019-12-12 17:36:18
 */
/* The begin of Include */
#include <stdio.h>
#include <stdlib.h>
#include "Link_List.h"
/* The end of Include */
int main(void)/* 主程序入口 */
{
    pNode List = CreateList(5);      // 创建一个指针，使其指向新创建的链表的头指针    
    printf("%d\n",GetLength(List));   /* 打印链表长度 */
    InserList(List,4 ,1);             /* 插入链表 */  
    printf("%d\n",GetLength(List));   /* 打印链表长度 */
    TraverseList(List);               /* 遍历打印所有的链表中的元素 */
    DeleteListElem(List,0);           /* 指定删除链表中的元素 */
    printf("%d\n",GetLength(List));   /* 打印链表长度 */
    TraverseList(List); 
    DeleteAllTheList(List);           /* 删除链表 */   
    TraverseList(List); 
    printf("%d\n",GetLength(List));   /* 打印链表长度 */
    return 0;
}