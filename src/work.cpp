#include<stdio.h>
 
int main()
{
    int n;
    scanf("%d",&n);
    
    //printf("  *  \n * * \n* * *"); // 模拟输入为1的状态 其他状态由此构成   //不太行 换行不知道怎么处理
    for(int i=1;i<=3*n;i++) //圣诞树
    {
        int a=i%3;
        int b=i/3;   
        for(int j=3*n-i;j>=1;j--)// 树两边的空格
            printf(" ");
        if(a==1)
        {
            for(int j=1;j<=b;j++)
                printf("*     ");
            printf("*");     
        }
        else if(a==2)
        {
            for(int j=1;j<=b;j++)
                printf("* *   ");
            printf("* *");  
        }
        else
        {
            for(int j=1;j<=b-1;j++)
                printf("* * * ");
            printf("* * *");  
        }
        for(int j=3*n-i;j>=1;j--) // 树两边的空格 中间以“* ”打印 所以少一个空格
            printf(" ");
        printf("\n");
    }
    for(int j=n;j>=1;j--) //尾部
    {    
        for(int i=3*n-1;i>=1;i--)
            printf(" ");
        printf("*\n");    
    }
    return 0;
}
