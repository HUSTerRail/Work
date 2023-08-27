//这道题有股递归地味道 每一级是它上一级的三个组成 但是递归怎么写呢？0_0
//参考题解可以用字符数组模拟递归
#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    scanf("%d",&n);
    int i,j,k;
    int row=3;
    int col=5;
    char ch[400][800]={"  *  "," * * ","* * *"};
    for( i=0;i<n-1;i++) // 上面的大三角部分递归次数 也就是复制的次数
    {
       for( j=0;j<row;j++)
       {
           for(k=0;k<col;k++)
           {
               ch[j+row][k]=ch[j][k]; // 左下角的图形复制
               ch[j+row][k+1+col]=ch[j][k]; //右下角图形复制
           } 
       }
   for(j=0;j<row;j++)  //清空原来的三角位置
       {
           for(k=0;k<col;k++)
           {
               ch[j][k]=' ';
           } 
       }
     for(j=0;j<row;j++)  //将左下角的三角复制到两个中间去
       {
           for( k=0;k<col;k++)
           {
              ch[j][k+row]=ch[j+row][k];
           } 
       }      
    row*=2;            // 递归使用
    col=col*2+1;      
    }
    for( j=0;j<row;j++)  //将左下角的三角复制到两个中间去
       {
           for(k=0;k<col;k++)
           {
              if(ch[j][k]=='*')
                 printf("%c",ch[j][k]);
               else
                   printf(" ");
           } 
        printf("\n");
       }
	for(j=0;j<n;j++)  //打印树干 
       {
           for( k=0;k<row-1;k++)
           {
              printf(" ");
           } 
           printf("*\n");
       }         
    return 0;
}
