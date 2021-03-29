#include <stdio.h>
#include <windows.h>
int Callatz(int n)//求出数据处理的次数
{
    int t=0;
    while(n>1)
    {
        if(n%2!=0) n=3*n+1;
        else n/=2;
        t++;
    }
    return t;
}
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d\n",Callatz(n));
    system("pause");
}