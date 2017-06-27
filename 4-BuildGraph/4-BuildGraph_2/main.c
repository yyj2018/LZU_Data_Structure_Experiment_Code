#include <stdio.h>
#include <stdlib.h>
#define maxn 1000
#define LONG_MAX 2000000000

//A�����������B,C��û��
//�ų�A����ͬ��Ԫ��

long cmp(const void *a,const void *b)
{
    return *(long *)a-*(long *)b;
}

int main()
{
    //+1: for safety
    long a[maxn+1],b[maxn+1],c[maxn+1],d[maxn+1],ansa,ansb,ansc,ansd,i,j,k;
    //�±�Ϊ0��ʼ������ʹ��qsort
    printf("Linear List A:\n");
    scanf("%ld",&ansa);
    for (i=0;i<ansa;i++)
        scanf("%ld",&a[i]);

    printf("Linear List B:\n");
    scanf("%ld",&ansb);
    for (i=0;i<ansb;i++)
        scanf("%ld",&b[i]);

    printf("Linear List C:\n");
    scanf("%ld",&ansc);
    for (i=0;i<ansc;i++)
        scanf("%ld",&c[i]);

    //ʹa,b,c��Ϊ�����(Ԫ���ǰ�������/�������е�)
    qsort(a,ansa,sizeof(long),cmp);
    qsort(b,ansb,sizeof(long),cmp);
    qsort(c,ansc,sizeof(long),cmp);

    i=0;
    j=0;
    k=0;
    ansd=0;
    //ʹ����b/c�����һ��������������a�е�����һ����
    b[ansb]=LONG_MAX;
    c[ansc]=LONG_MAX;
    //�ų�A�����е���B��,��C�г��ֵ�Ԫ��
    while (i<ansa)
    {
        //��B/C�������ҵ���һ�����ڵ���a[i]����(�����Ҳ���)
        //Ҫ��j<ansb����ǰ�棬�������ж�j���±��Ƿ�������ʹ�÷�Χ��
        while (j<ansb && b[j]<a[i])
            j++;
        while (k<ansc && c[k]<a[i])
            k++;
        if (a[i]!=b[j] && a[i]!=c[k])
        {
            d[ansd]=a[i];
            ansd++;
        }
        //�ų�A����ͬ��Ԫ��
        while (i<ansa-1 && a[i]==a[i+1])
            i++;
        i++;
    }
    //��ĿҪ���������D������û�в��������飬ֱ�����
    printf("Linear List D:\n");
    for (i=0;i<ansd;i++)
        printf("%ld ",d[i]);
    printf("\n");
    return 0;
}
/*
Input:
6
1 2 3 1 4 5
4
2 3 4 8
3
5 4 3
Output:
1
*/
/*
Input:
6
1 3 2 4 4 5
2
3 4
4
1 4 4 5
Output:
2
*/