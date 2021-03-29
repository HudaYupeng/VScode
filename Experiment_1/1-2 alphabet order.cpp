// 'a'=97,z='122'
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <fstream>
#include <string>
using namespace std;
const int Maxn=101;
int k=5;
string Array[Maxn];
string Array_2[Maxn];
void print(fstream& outfile,int n,string A[])
{
    for(int i=0;i<n;i++) outfile<<A[i]<<endl;
}
void read(fstream &infile,int n,string A[])
{
    for(int i=0;i<n;i++) infile>>A[i];
}
int f(int i,int k)
{
    if(k==1) return 1;
    int sum=0;
    for(int j=i+1;j<=26;j++) sum+=f(j,k-1);
    return sum;
}
int g(int k)
{
    int sum=0;
    for(int i=1;i<=26;i++) sum+=f(i,k);
    return sum;
}
int Solution(string s)
{
    int sum=0;
    int c=s[0]-'a'+1;
    int k=s.length();
    for(int i=1;i<k;i++) sum+=g(i);
    for(int i=1;i<c;i++) sum+=f(i,k);
    for(int i=1,temp=c;i<k;i++)
    {
        //计算从首字母开始，相邻字母之间，长度为k的字符串个数
        c=s[i]-'a'+1;
        k--;
        for(int j=temp+1;j<c;j++) sum+=f(j,k);
        temp=c;
    }
    return ++sum;//使用之前先加1，因为还未算上最后一个字母 
}
int main()
{
    Array[0]='a';
    Array[1]="z";
    Array[2]="ab";
    Array[3]="az";
    Array[4]="abc";
    string files[2]={"1-2_alphabet_order.txt",
    "1-2_result.txt"};
    fstream file;
    file.open(files[0],ios::out);
    print(file,k,Array);
    file.close();

    file.open(files[0],ios::in);
    read(file,k,Array_2);
    file.close();

    file.open(files[1],ios::out);
    for(int i=0;i<k;i++)
    {
        file<<Solution(Array_2[i])<<endl;
    }
    file.close();

    system("pause");
    return 0;
}
