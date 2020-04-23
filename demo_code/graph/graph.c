#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//********************************�ڽӾ���**********************************
/* ��������Ӧ���û����� */
typedef char VertexType;             
/* ���ϵ�Ȩֵ����Ӧ���û����� */
typedef int EdgeType;                
/* ��󶥵�����Ӧ���û����� */
#define MAXVEX 100                   
/* ��65535������� */
#define INFINITY 65535               
typedef struct
{/* ����� */
    VertexType vexs[MAXVEX];         
    /* �ڽӾ��󣬿ɿ����߱� */
    EdgeType arc[MAXVEX][MAXVEX];    
    /* ͼ�е�ǰ�Ķ������ͱ��� */
    int numVertexes, numEdges;       
} MGraph;

/* ����������ͼ���ڽӾ����ʾ */
void CreateMGraph(MGraph *G)
{
    int i, j, k, w;
    printf("���붥�����ͱ���:\n");
    /* ���붥�����ͱ��� */
    scanf("%d,%d", &G->numVertexes, &G->numEdges);    
    /* ���붥����Ϣ����������� */
    for (i = 0; i < G->numVertexes; i++){
        scanf(&G->vexs[i]);
    }           
    for (i = 0; i < G->numVertexes; i++)
    {
        for (j = 0; j <G->numVertexes; j++)
        {
            /* �ڽӾ����ʼ�� */
            G->arc[i][j] = INFINITY;
        }
    }
    /* ����numEdges���ߣ������ڽӾ��� */
    for (k = 0; k < G->numEdges; k++)                 
    {
        printf("�����(vi,vj)�ϵ��±�i���±�j��Ȩw:\n");
        scanf("%d,%d,%d",&i,&j,&w); //�����vi,vj�ϵ�Ȩ��w
        G->arc[i][j] = w;
        G->arc[j][i] = G->arc[i][j]; //����ͼ������Գ�
    }

}

//********************************�ڽӾ���**********************************



//********************************�ڽӱ�************************************

/* ��������Ӧ���û����� */
typedef char VertexType;          
/* ���ϵ�Ȩֵ����Ӧ���û����� */
typedef int EdgeType;             
/* �߱��� */
typedef struct EdgeNode           
{
    /* �ڽӵ��򣬴洢�ö����Ӧ���±� */
    int adjvex;                   
    /* ���ڴ洢Ȩֵ�����ڷ���ͼ���Բ���Ҫ */
    EdgeType weight;              
    /* ����ָ����һ���ڽӵ㡡 */
    struct EdgeNode *next;        
} EdgeNode;
/* ������� */
typedef struct VertexNode         
{
    /* �����򣬴洢������Ϣ */
    VertexType data;              
    /* �߱�ͷָ�� */
    EdgeNode *firstedge;          
} VertexNode, AdjList[MAXVEX];
typedef struct
{
    AdjList adjList;
    /* ͼ�е�ǰ�������ͱ��� */
    int numVertexes, numEdges;    
} GraphAdjList;


/* ����ͼ���ڽӱ�ṹ */
void  CreateALGraph(GraphAdjList *G)
{
    int i, j, k;
    EdgeNode *e;
    printf("���붥�����ͱ���:\n");
    /* ���붥�����ͱ��� */
    scanf("%d,%d", &G->numVertexes, 
          &G->numEdges);    
    /* ���붥����Ϣ����������� */
    for (i = 0; i < G->numVertexes; i++)              
    {
        /* ���붥����Ϣ */
        scanf(&G->adjList[i].data);                   
        /* ���߱���Ϊ�ձ� */
        G->adjList[i].firstedge = NULL;               
    }

     /* �����߱� */
    for (k = 0; k < G->numEdges; k++)                 
    {
        printf("�����(vi,vj)�ϵĶ������:\n");
        /* �����(vi,vj)�ϵĶ������ */
        scanf("%d,%d", &i, &j);                       
        /* ���ڴ�����ռ䣬 */
        /* ���ɱ߱��� */
        e = (EdgeNode *)malloc(sizeof(EdgeNode));     
        /* �ڽ����Ϊj */
        e->adjvex = j;                                
        /* ��eָ��ָ��ǰ����ָ��Ľ�� */
        e->next = G->adjList[i].firstedge;            
        /* ����ǰ�����ָ��ָ��e */
        G->adjList[i].firstedge = e;                  
        /* ���ڴ�����ռ䣬 */
        /* ���ɱ߱��� */
        e = (EdgeNode *)malloc(sizeof(EdgeNode));     
        /* �ڽ����Ϊi */
        e->adjvex = i;       
        e->next = G->adjList[j].firstedge;     //��eָ��ָ��ǰ����ָ��Ľ��
        G->adjList[j].firstedge = e; //����ǰ�����ָ��ָ��e  
    }
}            

//********************************�ڽӱ�************************************




int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
