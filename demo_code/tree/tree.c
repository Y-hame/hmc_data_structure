#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
    printf("input the value for this node beginning:");
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
        ;
        treeNode->rChild = createTree();
        return treeNode;
    }
}

// ��Ϊ�ı����ָ�����ֵ������Ҫ����ָ��ĵ�ַ��
// ����㴫�����ָ�룬�Ǹı��ֻ����ָ��ָ��������ֵ��������ָ�뱾��
void createTreeAnotherWay(TreeNode **root)
{
    printf("input the value for this node beginning:");
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

// ��������ݹ�д��
void printTree(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%c ", root->data);
    printTree(root->lChild);
    printTree(root->rChild);
}

void createTreeExample()
{
    printf("please input values to create a tree\n");
    // ��һ�ַ���
    // TreeNode * root =createTree();
    // �ڶ��ַ���
    TreeNode *root = NULL;
    createTreeAnotherWay(&root);
    if (root == NULL)
    {
        printf("tree is empty");
    }
    printTree(root);
}

int main(int argc, char const *argv[])
{
    /* code */
    createTreeExample();
    return 0;
}
