#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// #include<stack>
// #include<queue.h>
// #include<list>

#define OK 1
#define ERROR 0
typedef char elementType; // �����ݶ�intΪ�����еĻ���Ԫ�أ���Ȼ������չΪ���Ӹ��ӵ�struct����
typedef struct TreeNode
{
    elementType data;
    struct TreeNode *lChild;
    struct TreeNode *rChild;
} TreeNode;

TreeNode *createTree()
{
    printf("input the value for this node:");
    elementType value;
    scanf(" %c", &value);
    getchar();
    if (value == '#')
    {
        return NULL;
    }
    else
    {
        TreeNode *treeNode = (TreeNode *)malloc(sizeof(TreeNode));
        treeNode->data = value;
        treeNode->lChild = createTree();
        treeNode->rChild = createTree();
        return treeNode;
    }
}

// ��Ϊ�ı����ָ�����ֵ������Ҫ����ָ��ĵ�ַ��
// ����㴫�����ָ�룬�Ǹı��ֻ����ָ��ָ��������ֵ��������ָ�뱾��
// �����������˳�������� AB#D##C##
void createTreeAnotherWay(TreeNode **root)
{
    printf("input the value for this node:");
    elementType value;
    scanf(" %c", &value);
    getchar();
    if (value == '#')
    {
        *root = NULL;
    }
    else
    {
        *root = (TreeNode *)malloc(sizeof(TreeNode));
        (*root)->data = value;
        //  (*root)->lChild = NULL;
        //  (*root)->rChild = NULL;
        createTreeAnotherWay(&((*root)->lChild));
        createTreeAnotherWay(&((*root)->rChild));
    }
}

int depth(TreeNode *root){
    if(root == NULL){
        return 0;
    }
    int leftDepth = depth(root->lChild);
    int rightDepth =depth(root->rChild);
    int max =leftDepth>rightDepth?leftDepth:rightDepth;
    return max+1;
}

// ��������ݹ�д��
void preOrderTraverse(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%c ", root->data);
    preOrderTraverse(root->lChild);
    preOrderTraverse(root->rChild);
}

// ��������ݹ�д��
void preOrderTraverse2(TreeNode *root)
{
    int myDepth = depth(root);
    int spaceNumber = myDepth*2;
    // for (size_t i = 0; i < spaceNumber; i++)
    // {
    //     /* code */
    //     printf(" ");
    // }
    if (root == NULL)
    {
         printf("#");
         return;
    }
    printf("%c ", root->data);
    printf("\n");
    preOrderTraverse2(root->lChild);
    preOrderTraverse2(root->rChild);
}



// �������
void inOrderTraverse(TreeNode *root)
{
    // �Լ�д
}

// �������
void postOrderTraverse(TreeNode *root)
{
    // �Լ�д
}

// ��������ķ�ʽ���������Ը���㣬���㣬�ҽ��������˳�����룬���ӽ��գ�����#�����ʾ
void createTreeExample()
{
    printf("please input values(one by one) to create a tree\n");
    // ��һ�ַ���
    // TreeNode * root =createTree();
    // �ڶ��ַ���
    TreeNode *root = NULL;
    createTreeAnotherWay(&root);
    if (root == NULL)
    {
        printf("tree is empty");
    }
    // preOrderTraverse(root);
    preOrderTraverse2(root);
    printf("depth = %d",depth(root));
}


int main(int argc, char const *argv[])
{
    /* code */
    createTreeExample();
    return 0;
}

