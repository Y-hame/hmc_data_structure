#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#define STUDENT_NUMBER 5;
struct Student
{
    /* data */
    char *name;
    char *homeTown;
    int birthYear;
    struct Student *nextStudent;
};

int getCurrentYear()
{
    time_t timer;
    struct tm *tblock;
    time(&timer);
    tblock = gmtime(&timer);
    return tblock->tm_year + 1900;
}

int main(int argc, char const *argv[])
{
    /* code */
    printf("welcome to data structure");
    struct Student students[5];
    // struct Student students[STUDENT_NUMBER];
    // char names[STUDENT_NUMBER][20] ={"handsome","smart","beautiful","lovely","strong"};
    // char homeTowns[STUDENT_NUMBER][20] = {"hangzhou","ningbo","shaoxing","taizhou","wenzhou"};
    // int ages[STUDENT_NUMBER] = {2000,2001,2000,2001,2000};

    char names[5][20] = {"handsome", "smart", "beautiful", "lovely", "strong"};
    char homeTowns[5][20] = {"hangzhou", "ningbo", "shaoxing", "taizhou", "wenzhou"};
    int ages[5] = {2000, 2001, 2000, 2001, 2000};
    for (int i = 0; i < 5; i++)
    {
        struct Student st;
        st.name = names[i];
        st.homeTown = homeTowns[i];
        st.birthYear = ages[i];
        students[i] = st;
        // struct Student student = {names[i],homeTowns[i],ages[i]};
        // students[i] =  struct Student(names[i],homeTowns[i],ages[i]);
        /* code */
    }

    // printf("current year is %d",tblock->tm_year);
    /*
//  /////////////////////////////////////结构体例子
    for (int i = 0; i < 5; i++)
    {
        printf("student %s  homeTown is: %s, age %d: \n",students[i].name,students[i].homeTown,getCurrentYear()-students[i].birthYear);
    }
    */

    /*
    ///////////////////////////数据结构 第2章 线性存储关键属性(数组起始位置和每个元素的内存地址) 例子
    // char 数组的线性存储
    char charArray[5] ={'a','b','c','d','e'};
    for (int i = 0; i < 5; i++)
    {
        //打印charArray数组每个int类型元素的内存地址
        printf("\n charArray [%d] 's address: %p",i,&charArray[i]);
    }

    // int 数组的线性存储
    int intArray[5]={1,2,3,4,5};
    for (int i = 0; i < 5; i++)
    {
        //打印intArray数组每个int类型元素的内存地址
        printf("\n array [%d] 's address: %p",i,&intArray[i]);
    }

    // double 数组的线性存储
    double doubleArray[5]={1,2,3,4,5};
    for (int i = 0; i < 5; i++)
    {
        //打印doubleArray数组每个int类型元素的内存地址
        printf("\n doubleArray [%d] 's address: %p",i,&doubleArray[i]);
    }

*/

    /*
    /////////////////////线性存储 插入， 插入一个元素 "99"到第2个元素位置（下标为1）

     
     int intArray[5]={1,2,3,4,5};
     //第1步，开辟新的存储空间，保证足够插入
     int intArray2[6];
     int insertPosition = 1;
     int insertValue = 99;
     // 第2步，将原先的数值拷贝到目标空间
     for (int i = 0; i < 5; i++)
     {
         intArray2[i]=intArray[i];
     }
    //  第3步 移动数值位置，空出 需要插入的空间
     for (int i = 5; i>= insertPosition; i--)
     {
         intArray2[i] =intArray2[i-1];
     }
    //  第4步 将数值插入
     intArray2[insertPosition] = insertValue;
    //  第5步，验证是否操作成功
     for (int i = 0; i < 6; i++)
     {
         printf("\n %d",intArray2[i]);
     }
*/

    /*
     //////////////////////线性存储删除,较为简单。两种方式
    //  1.把原来的数值抹掉即可，浪费了一个元素的空间
    //  2. 开辟新的空间。节约了空间，但导致大量的操作
    
    int intArray[5]={1,2,3,4,5};
     int deletePosition = 1;
     // 第1步，将从 deletePosition之后的元素前移
     for (int i = deletePosition; i < 5; i++)
     {
         intArray[i]=intArray[i+1];
     }

//  第2步，验证是否操作成功
     for (int i = 0; i < 4; i++)
     {
         printf("\n %d",intArray[i]);
     }
     
     */

    // 数据结构 第2章，链式存储
    // 第1步 定义 数据节点结构
    //要typedef后才能 sizeof
    typedef struct dateNode
    {
        char *dateName;
        struct dateNode *nextData;
    } dateNode;

    //声明头节点，头结点就是一根列表的头，拎着它，能操作整条链表
    struct dateNode *listHead;
    // 用来对nextData指针赋值
    struct dateNode *previousNode;

    char *dates[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    // 创建列表
    for (int i = 0; i < 7; ++i)
    {
        dateNode *date = (dateNode *)malloc(sizeof(dateNode));
        date->dateName = dates[i];
        if (i == 0)
        {
            listHead = date;
            previousNode = date;
        }
        else
        {
            previousNode->nextData = date;
            previousNode = date;
        }
    }
    // 第2步验证是否创建成功，遍历列表
    struct dateNode *cursor = listHead;
    while (cursor != NULL)
    {
        printf("\n %s ", cursor->dateName);
        cursor = cursor->nextData;
    }

    return 0;
}