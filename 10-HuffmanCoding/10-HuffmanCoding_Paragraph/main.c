#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <windows.h>
#include <math.h>
#define maxn 1000
#define maxlen 100
#define maxascii 128

//����������:һ���Ƕ�����������Ϊ01��
//����������:һ���ַ��ı��벻��������һ�������ǰ׺�������ܲ�������
//���ڶ���������Ϊһ�㷭���ĵ���Ҫ�����̣�����һ��01���벻��ܳ�
//������С�Ļ��������룬Ҷ�ӽ��(��Ϣ)��Ŀ���ڲ����(����)��Ŀ��1������n���ַ�ʱ���������ĿΪ2n+1

struct node
{
    char ch;
    struct node *left,*right;
}*tree[maxn+1];

struct rec
{
    long value,addr;
}a[maxn+1];

char code[maxascii][maxlen],str[maxlen];
long root;

//�����б��뽨����ÿ����һ��0/1����û�бߣ����ż�1�������;���򵽴��Ӧ��ŵĽ��
//Խ�������㣬�����С���������Ϊ1

//����ַ����룺������ÿ������һ����㣬����ż�1������㣬�������е���������
//Խ�������㣬�����󣬸������Ϊ2*n-1(������)

//�������б�����������Ҫ��̬������������ַ�������Ҫ�ַ����룬����ϸ���
//ʹ������������ͬʱ�ṹ������ָ�����������

void work1()
{
    long n,len,sum,i,j,k;
    char c,s[maxlen];
    struct node *pos;
    tree[1]=(struct node *) malloc (sizeof(long));
    tree[1]->left=NULL;
    tree[1]->right=NULL;
    sum=1;
    root=1;

    printf("Please input n rule(s):\t");
    scanf("%ld",&n);
    printf("Please input char & coding\n");
    for (k=1;k<=n;k++)
    {
        //skip '\n'
        scanf("%c",&c);
        scanf("%c%s",&c,s);
        if (strcmp(s,"")==0)
        {
            system("cls");
            printf("Wrong\n");
            break;
        }
        strcpy(code[(long)c],s);
        len=strlen(s);
        pos=tree[1];
        for (i=0;i<len;i++)
            if (s[i]=='0')
            {
                if (pos->left==NULL)
                {
                    sum++;
                    tree[sum]=(struct node *) malloc (sizeof(struct node));
                    pos->left=tree[sum];
                    pos=tree[sum];
                    break;
                }
                else
                    pos=pos->left;
            }
            else
            {
                if (pos->right==NULL)
                {
                    sum++;
                    tree[sum]=(struct node *) malloc (sizeof(struct node));
                    pos->right=tree[sum];
                    pos=tree[sum];
                    break;
                }
                else
                    pos=pos->right;
            }
        //���뾭���Ľ�㶼�����У�δ�½���㣬���������ض���֮ǰһ�������ǰ׺
        if (i==len)
        {
            system("cls");
            printf("Wrong\n");
            break;
        }
        //���Ҫ�½������Ӹ���㵽����½��Ľ��֮���01���벻��֮ǰ�����ǰ׺
        else
        {
            for (j=i+1;j<len;j++)
                if (s[j]=='0')
                {
                    sum++;
                    tree[sum]=(struct node *) malloc (sizeof(struct node));
                    pos->left=tree[sum];
                    pos->right=NULL;
                    pos=tree[sum];
                }
                else
                {
                    sum++;
                    tree[sum]=(struct node *) malloc (sizeof(struct node));
                    pos->right=tree[sum];
                    pos->right=NULL;
                    pos=tree[sum];
                }
            pos->left=NULL;
            pos->right=NULL;
            pos->ch=c;
        }
    }
}

void work2()
{
    char s[1000],str[10000];
    long i,len;
    printf("Please input a string:\n");
    printf("\tA blank line means the end of input\n");
    strcpy(str,"");
    gets(s);
    while (1)
    {
        gets(s);
        len=strlen(s);
        if (len==0)
            break;
        strcat(str,s);
    }
    len=strlen(str);
    for (i=0;i<len;i++)
        //judge whether exist or not,��ʼ��Ϊ"",���и��ַ��ı��룬����޸ģ���Ϊ""
        if (strcmp(code[(long)str[i]],"")==0)
        {
            system("cls");
            printf("Wrong\n");
            return ;
        }
        else
	    printf("%s",code[(long)str[i]]);
    printf("\n");
}

void work3()
{
    struct node *p;
    char s[1000],str[10000];
    long i,len;
    printf("Please input a string:\n");
    printf("\tA blank line means the end of input\n");
    strcpy(str,"");
    gets(s);
    while (1)
    {
        gets(s);
        len=strlen(s);
        if (len==0)
            break;
        strcat(str,s);
    }
    len=strlen(str);
    p=tree[root];

    for (i=0;i<len;i++)
    {
        if (str[i]=='0')
        {
            if (p->left==NULL)
            {
                system("cls");
                printf("Wrong");
                return ;
            }
            else
                p=p->left;
        }
        else
        {
            if (p->right==NULL)
            {
                system("cls");
                printf("Wrong");
                return ;
            }
            else
                p=p->right;
        }
        if (p->left==NULL && p->right==NULL)
        {
            printf("%c",p->ch);
            p=tree[root];
        }
    }
    //�������ʣ�࣬���Ǵ����
    if (p!=tree[root])
    {
        system("cls");
        printf("Wrong\n");
        return ;
    }
    printf("\n");
}

void CodeCh(struct node *p,long lens)
{
    //Ҷ�ӽ��(��Ϣ)
    if (p->left==NULL && p->right==NULL)
    {
        str[lens]='\0';
        strcpy(code[(long)p->ch],str);
        return ;
    }
    str[lens]='0';
    CodeCh(p->left,lens+1);
    str[lens]='1';
    CodeCh(p->right,lens+1);
}

void work4()
{
    long n,ans=0,num,i,j,k;
    struct rec temp;
    char str[1000];
    long g[128],len;
    for (i=0;i<128;i++)
        g[i]=0;
    printf("Please input a paragraph:\n");
    printf("\tA blank line means the end of input\n");
    gets(str);
    while (1)
    {
        gets(str);
        len=strlen(str);
        if (len==0)
            break;
        len=strlen(str);
        for (i=0;i<len;i++)
            g[(long)str[i]]++;
    }
    n=0;
    for (i=0;i<128;i++)
        if (g[i]!=0)
        {
            n++;
            tree[n]=(struct node *) malloc (sizeof(struct node));
            tree[n]->ch=(char)(i);
            a[n].value=g[i];
            a[n].addr=n;
            tree[n]->left=NULL;
            tree[n]->right=NULL;
        }

    num=n;
    for (i=n;i>1;i--)
    {
        //sort a[1]~a[i]
        for (j=i;j>1;j--)
            for (k=1;k<j;k++)
                if (a[k].value>a[k+1].value)
                {
                    temp=a[k];
                    a[k]=a[k+1];
                    a[k+1]=temp;
                }
        //merge
        num++;
        tree[num]=(struct node *) malloc (sizeof(struct node));
        a[1].value+=a[2].value;
        tree[num]->left=tree[a[1].addr];
        tree[num]->right=tree[a[2].addr];
        a[1].addr=num;          //new point number
        a[2].value=a[i].value;    //fill the blank
        a[2].addr=a[i].addr;
        ans+=a[1].value;
    }

    if (n==1)
    {
        printf("Ans=%ld\n",a[1].value);
        //"1"Ҳ����
        printf("%c : %s\n",tree[1]->ch,"0");
    }
    else
    {
        printf("Ans=%ld\n",ans);
        //�����ı��
        root=num;
        CodeCh(tree[root],0);
        for (i=1;i<=n;i++)
            printf("%c : %s\n",tree[i]->ch,code[(long)tree[i]->ch]);
    }
}

int main()
{
    long mode,i;
    for (i=0;i<=maxascii;i++)
        strcpy(code[i],"");
    while (1)
    {
        system("cls");
        printf("0:exit\n");
        printf("1:Rule\n");
        printf("2:Coding\n");
        printf("3:Discoding\n");
/*���������ַ����ֵĴ��������ַ����б���(ֻ����01)��ʹ�����ܳ�����С
1.��������������2.�ַ����룺�Ӹ���㿪ʼ�����ַ����ڵ�Ҷ�ӽ�㣬��������'0'.��������'1'*/
        printf("4:Build Rule\n");
        printf("Please input a mode:\t");
        scanf("%ld",&mode);
        switch(mode)
        {
            case 0:
                system("cls");
                exit(0);
            case 1:
                system("cls");
                printf("1:Rule\n");
                work1();
                break;
            case 2:
                system("cls");
                printf("2:Coding\n");
                work2();
                break;
            case 3:
                system("cls");
                printf("3:Discoding\n");
                work3();
                break;
            case 4:
                system("cls");
                printf("4:Build Rule\n");
                work4();
                break;
        }
        system("pause");
    }
    return 0;
}
/*
1
3
a 0
b 10
c 11

2
cbabc

2
abcd

3
111001011

3
01

4
abc
cba
ccde

*/
/*
FAFDEFADCBDFBAAFCC
*/