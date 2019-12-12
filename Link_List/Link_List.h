/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Roman.Liu
 * @Date: 2019-12-12 10:22:16
 * @LastEditors: Roman.Liu
 * @LastEditTime: 2019-12-12 10:22:17
 */
#ifndef  _LINK_LIST_H_
#define  _LINK_LIST_H_

typedef  int ElemTyped;  /* 定义数据类型 */
typedef struct Link_Node
{
    /* data */
    ElemTyped elem;    /* 数据域 */
    /* next point */
    struct Link_Node *Next;   /* 下一个节点指针 */

}Node, *pNode;

pNode CreateList(int length);                /* 创建链表 */
void InserList(pNode List,int pos,int val);  /* 插入链表 */   
void DeleteAllTheList(pNode List);           /* 删除链表 */   
void DeleteListElem(pNode List,int pos);     /* 指定删除链表中的元素 */
void TraverseList(pNode List);               /* 遍历打印所有的链表中的元素 */
int  GetLength(pNode List);                  /* 获取整个链表的长度 */
#endif // DEBUG