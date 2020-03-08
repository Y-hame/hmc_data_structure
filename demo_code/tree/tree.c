#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define OK 1
#define ERROR 0
typedef char elementType; // 这里暂定int为队列中的基本元素，当然可以扩展为更加复杂的struct对象
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

// 因为改变的是指针的数值，所以要传入指针的地址；
// 如果你传入的是指针，那改变的只能是指针指向对象的数值，而不是指针本身
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

// 先序遍历递归写法
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
    // 第一种方法
    // TreeNode * root =createTree();
    // 第二种方法
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
