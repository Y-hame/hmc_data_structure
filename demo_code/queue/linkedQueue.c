#include "stdio.h"
#include <stdlib.h>
#include <stdbool.h>
#define OK 1
#define ERROR 0
typedef int elementType; // �����ݶ�intΪ�����еĻ���Ԫ�أ���Ȼ������չΪ���Ӹ��ӵ�struct����
typedef struct LinkedQueueNode
{
    elementType data;
    struct LinkedQueueNode *next;
    /* data */
} LinkedQueueNode;

typedef struct LinkedQueue
{
    struct LinkedQueueNode *front; //����ͷָ��
    struct LinkedQueueNode *rear;  // ����βָ��
    int length;
    /* data */
} LinkedQueue;

void showLinkedQueue(LinkedQueue *queue)
{
    if (queue == NULL)
    {
        printf("\n the queue does not exist");
        return;
    }
    if (queue->length == 0)
    {
        printf("\n the queue is empty");
        return;
    }
    LinkedQueueNode *cursor = queue->front;
    printf("\n");
    while (cursor != NULL)
    {
        printf(" %d ", cursor->data);
        cursor = cursor->next;
    }
}

// �������
int enqueue(LinkedQueue *linkedQueue, elementType value)
{
    if (linkedQueue == NULL)
    {
        printf("the queue does not exist");
        return ERROR;
    }
    LinkedQueueNode *node = (LinkedQueueNode *)malloc(sizeof(LinkedQueueNode));
    node->data = value;
    node->next = NULL;
    LinkedQueueNode *front = linkedQueue->front;
    LinkedQueueNode *rear = linkedQueue->rear;
    // ֱ��д�� linkedQueue->rear->next �������Ϊ typedef struct{}name. ���� typedef struct name{}name ��û��������ȥ�о�һ��
    //  ���б��ʱ��ͷ��β��ָ��ͬ���ڵ�
    if (linkedQueue->length == 0)
    {
        linkedQueue->front = node;
        linkedQueue->rear = node;
    }
    else
    {
        linkedQueue->rear->next = node; // ���½ڵ���Ϊ��β����һ���ڵ�
        linkedQueue->rear = node;       // ���¶�βָ��
    }
    linkedQueue->length++;
    return OK;
}

int dequeue(LinkedQueue *linkedQueue)
{
    if (linkedQueue == NULL)
    {
        printf("the queue does not exist");
        return ERROR;
    }
    if (linkedQueue->front == NULL && linkedQueue->rear == NULL) //�б�Ϊ�գ�ע��front��ָ�����ڵ㣬������һ������ר�ŵ�ͷ�ڵ�
    {
        printf(" the queue is empty ");
        return OK;
    }
    LinkedQueueNode *poppedNode = linkedQueue->front;
    printf(" \n node which value is : % d is popped out", poppedNode->data);
    LinkedQueueNode *newFront = poppedNode->next;
    free(poppedNode);
    linkedQueue->front = newFront;
    linkedQueue->length--;
    return OK;
}

LinkedQueue *createEmptyLinkedQueue()
{
    LinkedQueue *linkedQueue = (LinkedQueue *)malloc(sizeof(LinkedQueue));
    // ��Ҫ�ĳ�ʼ������Ȼ����ֲ��ɿص����⡣
    linkedQueue->front = NULL;
    linkedQueue->rear = NULL;
    linkedQueue->length = 0;
    return linkedQueue;
}

int main(int argc, char const *argv[])
{
    /* code */
    // �����յĶ���
    LinkedQueue *linkedQueue = createEmptyLinkedQueue();
    showLinkedQueue(linkedQueue);

    // �����
    for (int i = 1; i <= 10; ++i)
    {
        enqueue(linkedQueue,i );
        showLinkedQueue(linkedQueue);
    }
    // ������
    for (int i = 0; i < 5; ++i)
    {
        dequeue(linkedQueue);
        showLinkedQueue(linkedQueue);
    }

    return 0;
}
