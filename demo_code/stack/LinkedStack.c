#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 10
#define OK 1
#define ERROR 0
typedef int elementType; // �����ݶ�intΪջ�еĻ���Ԫ�أ���Ȼ������չΪ���Ӹ��ӵ�struct����

//$$$$$$$$$$$$$$$$$$��ʽ�洢��ջ����$$$$$$$$$$$$$$$$$$$$$$$$
typedef struct
{
    elementType data;       // �ڵ���ֵ
    struct StackNode *next; // ��ʾ��һ���ڵ��λ��
} StackNode;

typedef struct
{
    struct StackNode *top; //��ʾջ��Ԫ��ָ��
    int count;             // ��ʾԪ�ظ���
} LinkedStack;

int push(LinkedStack *stack, elementType value)
{
    if (stack == NULL)
    {
        return ERROR;
    }
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
    newNode->data = value;
    //ǰһ��top��Ϊ���ڵ�next
    if (stack->top == NULL)
    {
        newNode->next = NULL;
    }
    else
    {
        newNode->next = stack->top;
    }
    //ͷ�ڵ�ָ����£�
    stack->top = newNode;
    stack->count++;
    return OK;
}

// ע��ɾ���ڵ��ʱ��topָ��ĸ���
int pop(LinkedStack *stack, elementType *poppedValue)
{
    if (stack == NULL)
    {
        return ERROR;
    }
    if (stack->count == 0) //˵��ջ�Ѿ�����
    {
        return ERROR;
    }
    StackNode *currentTopnode = stack->top;
    if (currentTopnode == NULL)
    {
        return ERROR;
    }
    *poppedValue = currentTopnode->data;
    stack->top = currentTopnode->next;
    //�ڵ㱻����(ɾ��)��Ҫ�ͷ��ڴ�ռ䣬��ֹ�ڴ����
    free(currentTopnode);
    (stack->count)--;
    return OK;
}

void showStack(LinkedStack *stack)
{
    if (stack == NULL || stack->count == 0)
    {
        printf("Stack is empty");
    }
    StackNode *cursor = stack->top;
    while (cursor != NULL)
    {
        printf(" %d ", cursor->data);
        cursor = cursor->next;
        /* code */
    }

    printf("\n");
}

LinkedStack *createStack()
{
    LinkedStack *pStack = (LinkedStack *)malloc(sizeof(LinkedStack));
    pStack->count = 0;
    pStack->top = NULL;
    showStack(pStack);
    return pStack;
}

void pushOperationInStack(LinkedStack *pStack)
{
    push(pStack, 1);
    printf("push element %d\n", 1);
    showStack(pStack);
    push(pStack, 2);
    printf("push element %d \n", 2);
    showStack(pStack);
    push(pStack, 3);
    printf("push element %d \n", 3);
    showStack(pStack);
}

void popOperationInStack(LinkedStack *pStack)
{
    elementType value;
    elementType *pValue = &value;
    printf("pop element\n");
    pop(pStack, pValue);
    showStack(pStack);
    printf("pop element\n");
    pop(pStack, pValue);
    showStack(pStack);
}

// ���� ջ��Ԫ�ظ���
int getStackLength(LinkedStack *pStack)
{
    /*todo*/
    return 0;
}

//�ж� ջ�Ƿ�Ϊ��
bool isStackEmpty(LinkedStack *pStack)
{
    return true;
}

bool findElementInStack(LinkedStack *pStack, elementType value)
{
    return false;
}

int main(int argc, char const *argv[])
{
    // ����ջ
    LinkedStack *pStack = createStack();

    // ��ջ����
    pushOperationInStack(pStack);

    // ��ջ����
    popOperationInStack(pStack);

    return 0;
}
