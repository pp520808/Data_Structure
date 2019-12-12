
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/* 创建队列 */
int Init_Queue(pqueue q,int max_size)
{
  int ret;
  q->front = q->rear;
  q->max_size = max_size;
  q->data =(elem *)malloc(max_size * sizeof(elem));
  if(q->data == NULL) 
  {
      ret = 0;
      printf("Queue Creat Failed\r\n");
  }
  else  
  {
      printf("Queue Creat Successfully\r\n");
      ret = 1;
  }
  return ret;
}
/* 判断队列是否队空 */
int Full_Queue(pqueue q)
{
    return (q->front == (q->rear+1)%q->max_size) ? 1 : 0;
}
/* 判断队列是否队满 */  
int Empty_Queue(pqueue q)
{
    return (q->front == q->rear) ? 1 :0;
}
/* 进队 */
int Enqueue(pqueue q,elem val)
{
    /* 1.判断队列是否队满 */
    if(Full_Queue(q))
    {
        printf("The Queue Is Full");
        return 0;
    }
    else
    {
    /* 2.插入数据 */
       q->data[q->rear] = val;
    /* 3.队列尾部后移 ！！注意队列保护*/    
       q->rear = (q->rear +1) % q->max_size;   
    }
    return 1;
    
}
/* 出队 */
elem Dequeue(pqueue q)
{   
    elem num;
    /* 1.判断队列是否队空*/
    if(Empty_Queue(q))
    {
        printf("The Queue Is Empty");
        return 0;
    }
    else
    {
    /* 2.取出数据 */    
        num = q->data[q->front];
    /* 3.队列头部后移 ！！注意队列保护*/     
        q->front = (q->front+1)%q->max_size;
    }
    return num;  
}
/* 遍历整个队列 */
void Printf_Queue(pqueue q)
{
    int i;
    if(Empty_Queue(q)) {
        printf("queue is empty\n");
        return ;
    } else {
        for(i = q->front; i < q->rear; i++)
            printf("queue data is %d\n", q->data[i]);
    }
    return;
}

int main(void) 
{
    int i;
    int num;
    queue Q;
    Init_Queue(&Q, 100);
    for(i = 0; i < 10; i++)
    {      
        printf("please input a number:");
        scanf("%d", &num);
        printf("\n");
        Enqueue(&Q,num);
            
    }
    for(i = 0; i < 10; i++)
    {      
        num = Dequeue(&Q);
        printf("number:%d\r\n",num);
        
            
    }
    Printf_Queue(&Q);

    return 0;
} 