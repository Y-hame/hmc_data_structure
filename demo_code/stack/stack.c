#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 10
#define OK 1
#define ERROR 0

// ������˳��洢��Ϊ����
typedef int elementType; // �����ݶ�intΪջ�еĻ���Ԫ�أ���Ȼ������չΪ���Ӹ��ӵ�struct����
typedef struct
{
    elementType data[MAX_SIZE];
    int top; // ��ʾͷԪ�ص�λ��
    /* data */

} MyStack;


int push(MyStack *stack, elementType value)
{
    if (stack == NULL)
    {
        return ERROR;
    }
    if (stack->top == MAX_SIZE - 1) //˵��ջ�Ѿ�����
    {
        return ERROR;
    }
    stack->top++;
    stack->data[stack->top] = value;
    return OK;
}

int pop(MyStack *stack, elementType *poppedValue)
{
    if (stack == NULL)
    {
        return ERROR;
    }
    if (stack->top == -1) //˵��ջ�Ѿ�����
    {
        // printf()
        return ERROR;
    }
    *poppedValue = stack->data[stack->top];
    stack->top--;
    return OK;
}

void showStack(MyStack *stack)
{
    if (stack == NULL || stack->top == -1)
    {
        printf("Stack is empty");
    }
    for (int i = 0; i <= stack->top; ++i)
    {
        printf(" %d ", stack->data[i]);
    }
    printf("\n");
}

MyStack *createStack()
{
    MyStack* pStack = (MyStack *)malloc(sizeof(MyStack));
    pStack->top = -1;
    showStack(pStack);
    return pStack;
}

void pushOperationInStack(MyStack *pStack)
{
    push(pStack, 1);
    printf("push element %d\n",1);
    showStack(pStack);

    push(pStack, 2);
    printf("push element %d \n",2);
    showStack(pStack);

    push(pStack, 3);
    printf("push element %d \n",3);
    showStack(pStack);
}

void popOperationInStack(MyStack *pStack)
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
int getStackLength(MyStack * pStack){
    /*todo*/
    return 0;
}

//�ж� ջ�Ƿ�Ϊ��
bool isStackEmpty(MyStack * pStack){
    return true;
}

bool findElementInStack(MyStack * pStack ,elementType value){
    return false;

}

int deleteValueInStack(MyStack *pStack, elementType target){
    if(pStack == NULL){
        return ERROR;
    }
    for (size_t i = 0; i < pStack->top; i++)
    {
        int  index = i;
        if(pStack->data[index] == target){

        }
        
    }
}

// ����ֵ��ֵǰ��
void move(MyStack *pStack,elementType target,int index){
    if(pStack == NULL){
        return;
    }
    for (size_t i = index; i < pStack->top; i++)
    {
        pStack->data[index] = pStack->data[index+1];
        /* code */
    }
    
}

int main(int argc, char const *argv[])
{
    // ����ջ
    MyStack *pStack = createStack();
    for (size_t i = 0; i < length; i++)
    {
        
    }



    // ��ջ����
    // pushOperationInStack(pStack);

    // // ��ջ����
    // popOperationInStack(pStack);

    return 0;
}
