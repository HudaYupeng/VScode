#include <stdio.h>
#include <windows.h>
#include <algorithm>
using namespace std;
int gcd(int a,int b)//n
{
    int t=min(a,b);
    while(a%t||b%t) t--;
    return t;
}
int gcd_2(int a,int b)//log2，辗转相除法
//如（78,14），（14.8），（8,6），（6,2）
{
    int t=a;
    if(a<b) 
    {
        a=b;
        b=t;
    }
    if(b==0) return a;
    while(a%b)
    {
        t=b;
        b=a%b;
        a=b;
    }
    return b;
}
int gcd_3(int m,int n)//不用判断大小
{
    int res;
    while(n>0)
    {
        res=m%n;
        m=n;
        n=res;
    }
    return m;
}
int main() { //文件读写  
   int n;
   scanf("%d",&n);
   int a,b;
   for(int i=0;i<n;i++)
   {
       scanf("%d%d",&a,&b);
       printf("%d\n",gcd_3(a,b));
   }
    system("pause");
    return 0;
}