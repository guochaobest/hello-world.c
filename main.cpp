#include<bits/stdc++.h>
using namespace std;
#define MAXSIZE 100 // 线性表最大长度
typedef elemtype int
// 线性表的动态分配顺序存储结构



typedef struct
{
    elemtype *data; // 储存空间基地址
    int length;  // 长度

}Sqlist;


//  线性表的静态分配顺序存储结构

typedef struct
{
    elemtype data[MAXSIZE];
    int length;

}Sqlist;

// 动态分配顺序存储结构

void createlist (Sqlist L,int a[],int n)
{
    int i=0,k=0;
    L=(Sqlist *)malloc(sizeof(Sqlist)); //分配存储线性表的空间
    while(i<n)
    {
        L.data[k++]=a[i++];
    }
    L.length=k;

}

// 关于顺序表的几个基础算法

void initlist(Sqlist &L)// 初始化
{
    L=(Sqlist *)malloc(sizeof(Sqlist)); //分配空间
    L.length=0;
}

void destroylist(Sqlist &L)//销毁线性表
{
    free(L);
}

bool is_empty(Sqlist &L)//判空
{
    if(L.length==0)return true;
    else return false;
}

int listlength(Sqlist &L)// 表长
{
    return L.length;
}

void printlist(Sqlist &L) // 打印表
{

    for(int i=0;i<L.length;i++)cout<<L.data<<" ";
}

bool detelem(Sqlist L,int i,elemtype &e) // 定位第i个元素的值，并返回到e
{
    if(i < 1 || i > L.length)return false; //判断是否合理
    else
    {
        e=L.data[i-1];
        return true;
    }
}

int locate(Sqlist L,int e) // 按值查找 并且返回 第一个与e相等的位置
{
    for(int i=0;i<L.length;i++)
    {
        if(L.data[i++]==e)return i+1;
    }
}

bool listinsert(Sqlist &L,int i,elemtype e)// 在第i个位置插入新元素e
{
    if(i<1 || i>L.length+1)return false;
    i--;
    for(int j=L.length-1;j>i;j--)
    {
        L.data[j+1]=L.data[j]; //元素后移
    }
    L.data[i]=e;
    L.length++;
    return true;

}

bool listdelete(Sqlist &L,int i,elemtype &e) //  删除第i个位置的元素，并用e 来接收返回
{
    if(i<1 || i>L.length)return false

    i--;
    e=L.data[i];

    for(int j=i;i<L.length;j++)
    {
        L.data[j]=L.data[j++];
    }

    L.length--;
    return true;

}


//单元真题和习题

//1 给定一个整数数组 在时间尽可能高效的情况下 找出未出现最小正整数

int findminint(int A[],int n)
{
    int i,*B;
    B=(int *)malloc(sizeof(int));
    memset(B,0,sizeof(int)*n);
    for(int i=0;i<n;i++)
    {
        if(A[i]>0&&A[i]<n)// 如果A[i]的值介于 1~n，那么就标记数组B
            B[A[i]-1]=1;
    }
    f0r(int i=0;i<n;i++)
    {
        if(B[i]==0)break;
    }
    return i+1;

}

// 2 在给定的一个数组中 如果相同值的元素个数达到了数组总个数的一半以上 那么就称其存在主元素 否则就不存在主元素

// 基本思想 首先对整个数组进行排序，然后运用双指针遍历，统计出现相同元素的个数 如果后面出现更多的相同元素 那么就替换之前保留的相同元素的最大值 遍历结束与n/2比较

void quick_sort(int q[],int l,int r)// 快速排序的递归写法
{
    if(l>=r)return;
    int i=l-1,j=r+1;
    int mid =q[l+r >> 1];//找到枢值

    while(i<j)
    {
        do i++;while(q[i]<mid);
        do j--;while(q[j]>mid);
        if(i<j)swap(q[i],q[j]);
    }

    quick_sort(q,l,j);//递归左半边
    quick_sort(q,j+1,r);//递归右半边
}

int samemaxnumber(int q[],int n)
{
    int num=1,val=q[0];
    for(int i=0;i<n;i++)
    {
        int j=i+1;//双指针
        int tempnum=1,tempval=q[i];
        while(j<n)//寻找相同元素的个数
        {
            if(q[i]==q[j])
            {
                tempnum++;
                j++;
            }
        }
        if(tempnum>num)//满足主元素
        {
            num=tempnum;
            val=tempval;
        }
    }

    if(num>n/2)
    {
        cout<<val<<endl;
    }
    else
    {
        cout<<-1<<endl;
    }

    return 0;
}

// 3 寻找升序序列中的中位数，如果总个数n为单数，则为n/2+1 如果为偶数则为n/2

// 基本思想 首先采用归并排序实现两个序列的整合，然后直接根据总个数来算出中位数

int merge_sort(int a[],int b[],const int n)
{
    const int len=n;
    int c[2*len];//应为c的元素个数一定是偶数 ，所以就直接n/2

    int i,j,k;
    i=0,j=0,k=0;
    while(i<n&&j<n)
    {
        if(a[i]<b[j])c[k++]=a[i++];
        else c[k++]=b[j++];
    }
    while(i<n)c[k++]=a[i++];// 归并完a剩余的部分
    while(j<n)c[k++]=b[j++];// 归并完b剩余的部分

    return c[len];
}

// 4 将整数序列左移p个单位

// 基本思想 首先逆序前p-1个数据 然后逆序后n-p+1 个数据 然后逆序整个序列 即完成左移

void reverse(int q[],int l,int r)
{
    int i;
    for(i=0;i<(r-l+1)/2;i++)
    {
        swap(q[l+i],q[r-i]);
    }
}

void converse(int q[],int n,int p)
{
    reverse(q,0,p-1);
    reverse(q,p,n-1);
    reverse(q,0,n-1)
}

// 线性表的链式存储结构

// 单链表的定义

typedef struct LNode
{
    elemtype data;
    struct LNode *next;
}LinkNode;

// 头插法建立链表

void headcreatelist(LinkNode &L,int a[],int n)
{
    LinkNode *s;
    int i;
    L=(LinkNode *)malloc(sizeof(LinkNode));
    L.next=NULL;
    for(int i=0;i<n;i++)
    {
        s=(LinkNode*)malloc(sizeof(LinkNode));//头插法的基本操作 最终实现的是逆序建表
        s->data=a[i];
        s->next=L.next;
        L->next=s;
    }
}

// 尾插法建立链表
void tailcreatelist(LinkNode &L,int a[],int n)
{
    LinkNode *s,*r;
    L=(LinkNode*)malloc(sizeof(LinkNode));
    r=L;
    int i;
    for(int i=0;i<n;i++) //尾差法建立链表 最终实现顺序建表
    {
        s=(LinkNode*)malloc(sizeof(LinkNode));
        s->data=a[i];
        r->next=s;
        r=s;
    }
    r->next=NULL:
}

// 带头节点的链表的基本操作

//初始化链表
void InitList(LinkNode &L)
{
    L=(LinkNode *)malloc(sizeof(LinkNode));
    L->next=NULL;
}

// 销毁链表

void DestroyList(LinkNode &L)
{
    LinkNode *pre=L,*p=L->next;
    while(p)
    {
       free(pre);
       pre=p;
       p=p->next;
    }
    free(pre);
}

// 链表判空

bool Isempty(LinkNode &L)
{
    return (L->next==NULL);
}

// 单链表长度

int ListLength(LinkNode &L)
{
    int len=0;
    LinkNode *p=L;
    while(p->next)
    {
        len++;
        p=p->next;
    }

    return len;
}

// 输出单链表

void PrintList(LinkNode &L)
{
    LinkNode *p=L;
    while(p->next)
    {
        cout<<p->next->data<<" ";
        p=p->next;
    }

}

// 求单链表L中第i个节点 若存在 就返回给变量e

bool Getelem(LinkNode &L,int i,int &e)
{
    int j=0;
    LinkNode *p=L->next;
    while(j<i&&p)
    {
        j++;
        p=p->next;
    }
    if(p==NULL)return false;
    else {
        e=p->data;
        return true;
    }
}

// 按值查找, 返回其位置

int LocateElem(LinkNode &L,int e)
{
    int i=1;
    LinkNode *p=L->next;
    while(p&&p->data[i]!=e)
    {
        i++;
        p=p->next;
    }
    if(p==NULL)
    {
        return o;
    }else
    {
        return i;
    }
}

// 插入数据元素 再第i个位置插入元素e

bool ListInsert(LinkNode &L,int i,int e)
{
    int j=0;
    LinkNode *p=L,*s;
    if(i<0)return false;
    while(j<i-1&&p)
    {
        j++;
        p=p->next;
    }
    if(!p)
    {
        p=p->next;
    }else
    {
        s=(LinkNode *)malloc(sizeof(LinkNode));
        s->data=e;
        s->next=p->next;
        p->next=s;
        return true;
    }


}

// 删除链表中的数据元素  删除第i个节点 并用e来返回被删除的节点元素

bool DeleteList(LinkNode &L,int i,int &e)
{
    int j=0;
    LinkNode *p=L,*s;
    if(i<=0)return false;
    while(j<i-1&&p)
    {
        j++;
        p=p->next;
    }

    if(!p)return false;
    else
    {
        s=p->next;
        if(s==NULL)return false;
        e=s->data;
        p->next=s->next;
        free(s);
        return true;

    }
}

// 双链表的一些定义和操作

typedef struct DNode
{
    int data;
    struct DNode *prior;
    struct DNode *next;
}DLinkNode;


// 头插法建立双链表

void headcreateDLinkNode(DLinkNode &L,int a[],int n)
{
    DLinkNode *s;
    int i;
    L=(DLinkNode *)malloc(sizeof(DLinkNode));
    L->prior=L->next=NULL;
    for(int i=0;i<n;i++)
    {
        s=(DLinkNode*)malloc(sizeof(DLinkNode));
        s->data=a[i];
        s->next=L->next;
        if(!L->next)
        {
            L->next->prior=s;

        }
        L->next=s;
        s->prior=L;
    }
}

// 尾插法建立双链表

void tailcreateDLinkNode(DLinkNode &L,int a[],int n)
{
    DLinkNode *s,*r;
    int i;
    L=(DLinkNode *)malloc(sizeof(DLinkNode));
    r=L;

    for(int i=0;i<n;i++)
    {
        s=(DLinkNode *)malloc(sizeof(DLinkNode));
        s->data=a[i];
        r->next=s;
        s->prior=r;
        r=s;
    }
    r->next=NULL;
}

// 单元综合应用题
// 01 链表 a1,a2,a3,a4,a5,a6 在空间复杂度为O(1)的情况下 将链表转化为 a1 a6 a2 a5 a3 a4

typedef struct node
{
    int data;
    struct node *next;

}node;

// 基本思想 首先将后半段的线性表进行逆置 然后每次从前半段选一个然后再从后半段选一个

int length(node &L) {
    int i = 0;
    node *p = L;
    while (p) {
        i++;
        p = p->next;
    }

    return i;
}
node* reverseLinkList(node &L)
{
    node *p=L,*q=p->next,*s=q->next;
    while(q->next)
    {
        q->next=p;
        p=q;
        q=s;

    }

    return q;
}

node* changelist(node &L,int n)
{
    node *p=L;
    for(int i=0;i<n/2-1;i++)p=p->next;//前半段
    node *mid=p->next;//后半段
    p->next=NULL;


    node *q;//新链表的起始节点
    q=(node *)malloc(sizeof(node));
    node *s=L;//遍历前半段的起始节点
    while(s && mid)
    {
        q->next=s,q=s,s=s->next;
        q->next=mid,q=mid,mid=mid->next;
    }

    return q;


}

// 02 带头节点的单链表 共m个整数，对于链表中绝对值相等的节点，只保存第一个出现的节点；要求时间复杂度尽可能高效

// 基本思想 建立一个s[n]数组来标记某个节点值的绝对值是否之前出现过，如果在后续遍历中又出现绝对值相同时，删除该节点


typedef struct Lnode
{
    int data;
    struct LNode *next;
}LNode;
void Deletesameabs(LNode &L,int m,const int n)
{
    bool s[n];
    for(int i=0;i<n;i++)s[i]=false;  //开始之前都为出现过

    LinkNode *q=L,*p=q->next;
    while(p)
    {

        if(!s[p->data])
        {
            s[p->data]==true;
        }else
        {
            q->next=p->next;
            LinkNode *s=p;
            p=p->next;
            free(s);

        }
        q=p;
        p=p->next;
    }
}

