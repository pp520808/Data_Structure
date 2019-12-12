#ifndef  _QUEUE_H_
#define  _QUEUE_H_ 
/* 队列定义 */
#define elem int /*队列元素类型*/
typedef struct Cmd
{
    /* data */
    
};

typedef struct Queue
{
    /* data */
    elem* data;
    /* head */
    int front;
    /* tail */
    int rear;
    /* size */
    int max_size;

}queue,*pqueue;

void Printf();
int Init_Queue(pqueue q,int max_size);
int Full_Queue(pqueue q);
int Empty_Queue(pqueue q);
int Enqueue(pqueue q,elem val);
elem Dequeue(pqueue q);
void Printf_Queue(pqueue q);

#endif // ! _QUEUE_H_
 