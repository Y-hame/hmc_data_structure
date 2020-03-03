
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
// ˳��洢ʵ�ֶ���
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$



#include "stdio.h"
#include <stdlib.h>
#include <stdbool.h>
#define OK 1
#define ERROR 0
#define MAX_QUEUE_SIZE 10
typedef int elementType; // �����ݶ�intΪ�����еĻ���Ԫ�أ���Ȼ������չΪ���Ӹ��ӵ�struct����

typedef struct Queue
{
    int front; //����ͷָ��
    int rear;  // ����βָ��
    elementType array[MAX_QUEUE_SIZE];
    // ��Ϊ�������Ϳն��� queue->front == queue->rear �����������������������������
    int elementCount;
    /* data */
} Queue;

// �ж϶����Ƿ�����
bool isQueueFull(Queue *queue){
    return  queue!=NULL &&queue->elementCount == MAX_QUEUE_SIZE;
}

// �ж϶����Ƿ��
bool isQueueEmpty(Queue *queue){
    return  queue != NULL && queue->elementCount == 0;
}

// ��ӡ�������ݣ��Ӷ�ͷ ->����
void showQueue(Queue *queue)
{
    if (queue == NULL)
    {
        printf("\n the queue does not exist 111 ");
        return;
    }
    // if (queue->front == -1 || queue->front == queue->rear) //ѭ�����У��б�β(�����еĵط�)�����б�ͷ(���Գ��еĵط�)
    if (isQueueEmpty(queue)) //ѭ�����У��б�β(�����еĵط�)�����б�ͷ(���Գ��еĵط�)
    {
        printf(" \n (queue empty) ");
        return;
    }
    int front = queue->front;
    int rear = queue->rear;
    printf("\n");
    // ���������ˣ�rear == front Ϊ��������whileѭ����ʼ,��Ϊwhile��������front !=front��
    bool queueIsFullSoToBeginTheWhile = false;
    if(isQueueFull(queue)){
        queueIsFullSoToBeginTheWhile = true;
    }
    int stopFlag =  (rear+MAX_QUEUE_SIZE)% MAX_QUEUE_SIZE;
    while (front != rear ||queueIsFullSoToBeginTheWhile)
    {
        printf(" %d ", queue->array[front]);
        front = (front + 1) % MAX_QUEUE_SIZE;
        // ������ֻ��һ�μ�ʧЧ
        if(queueIsFullSoToBeginTheWhile){
            queueIsFullSoToBeginTheWhile = false;
        }
    }
    // printf("\n");
}

// �������(����)
int enqueue(Queue *queue, elementType value)
{
    if (queue == NULL)
    {
        printf("\n the queue does not exist 222");
        return ERROR;
    }
    // ��������
    if (isQueueFull(queue))
    {
        printf("\n the queue is Full,you can't do enqueue operation");
        return ERROR;
    }
    queue->array[queue->rear] = value;
    queue->elementCount++;
    // ע��˳��showQueue �����õ��� queue->rear����ֵ����������ĸı��Ӱ��showQueue�Ľ��
    // ��Ȼ�������ϣ��Ȳ���
    
    queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    printf("\n insert value : %d into the queue",value);
    showQueue(queue);
    
    return OK;
}

// ����(ɾ��)
int dequeue(Queue *queue, elementType *valuePointer)
{
    if (queue == NULL)
    {
        printf("\n the queue does not exist 444");
        return ERROR;
    }
    //  if (queue->front == -1 || queue->front == queue->rear) //ѭ�����У��б�β(�����еĵط�)�����б�ͷ(���Գ��еĵط�)
    if (isQueueEmpty(queue)) //ѭ�����У��б�β(�����еĵط�)�����б�ͷ(���Գ��еĵط�)
    {
        printf("\n the queue is Empty , so you can't do dequeue operation");
        return ERROR;
    }
    if (valuePointer != NULL)
    {
        *valuePointer = queue->array[queue->front];
    }
    printf("\n value : %d out of the queue",queue->array[queue->front]);
    queue->elementCount --;
    // ͬenqueue,ע�����������˳��
    
    queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
    showQueue(queue);
    return OK;
}

Queue *createEmptyQueue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    // ��Ҫ�ĳ�ʼ������Ȼ����ֲ��ɿص����⡣
    queue->front = 0; //
    queue->rear = 0;   // �����桰�����Ԫ����ֵ���ĵط�
    queue->elementCount = 0;
    return queue;
}

// �����У��ڳ���
void testEnqueueFirstAndDequeue(){
    /* code */
    // �����յĶ���
    Queue *queue = createEmptyQueue();

    // �����
    for (int i = 1; i <= 15; ++i)
    {
        enqueue(queue, i);
    }
    // ������
    for (int i = 0; i < 5; ++i)
    {
        elementType *valueP;
        dequeue(queue,valueP);
        // showQueue(Queue);
    }
    free(queue);
}

// ��� ��/�� ���У���������Ҫ���� ������
void testEnqueueAndDequeueInCross(){
     /* code */
    // �����յĶ���
    Queue *queue = createEmptyQueue();
    // showQueue(queue);
    elementType *p ;
    int enqueueValue = 1;
    dequeue(queue,p);
     enqueue(queue, enqueueValue++);
     dequeue(queue,p);
     enqueue(queue, enqueueValue++);
     dequeue(queue,p);
     enqueue(queue, enqueueValue++);
     dequeue(queue,p);
     dequeue(queue,p);
     dequeue(queue,p);



    
    free(queue);
}


int main(int argc, char const *argv[])
{
   testEnqueueFirstAndDequeue();
//    testEnqueueAndDequeueInCross();

    return 0;
}
