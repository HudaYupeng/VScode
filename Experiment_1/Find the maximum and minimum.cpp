//分治法查找最大值与最小值
#include <iostream>
#include <cmath>
#include <time.h>
#include <fstream>
#include <windows.h>
using namespace std;
LARGE_INTEGER frequency;//时钟频率
const int Maxn = 1e5;//100k
int Array[Maxn + 1] = { 0 };//存储产生的随机数
double start, end1;
double dft, dff, dfm;
void read(fstream& infile, int n, int A[])//从文件读取数据
{
    for (int i = 0; i < n; i++)
    {
        infile>>A[i];
    }
}
int prior(int x, int y)
{
    return x < y;
}
void swap(int &a,int &b)
{
    a=b-a+(b=a);
}
void solution_1(fstream& outfile, int A[], int n)//插入排序
{
    QueryPerformanceCounter(&frequency);
    start = frequency.QuadPart;//获得初始值
    int result;
    for(int i=1;i<n;i++)
    {
        for(int j=i;j>0;j--)
        {
            if(A[j]<A[j-1])
            swap(A[j],A[j-1]);
            else break;
        }
    }
    QueryPerformanceCounter(&frequency);
    end1= frequency.QuadPart;//获得终止值
    dfm = (double)(end1 - start);//差值
    dft = dfm / dff;//差值除以频率得到时间
    cout << "execute time is : " << dft * 1000 << "ms" << endl<<
    "the minimum and maximum are :"<<A[0]<<' '<<A[n-1]<<endl;
    outfile << "execute time is : " << dft * 1000 << "ms" << endl<<
    "the minimum and maximum are :"<<A[0]<<' '<<A[n-1]<<endl;
}
void solution_2(fstream& outfile,int A[],int left,int right)//快速排序
{
    if(left>=right) return;
    int k=A[(left+right)/2];
    swap(A[left],A[(right+left)/2]);
    int i=left,j=right;
    while(i!=j)
    {
        while(j>i&&A[j]>=k) --j;
        swap(A[i],A[j]);
        while(j>i&&A[i]<=k) ++i;
        swap(A[i],A[j]);
    }
    solution_2(outfile,A,left,i-1);
    solution_2(outfile,A,i+1,right);
}
int main()
{
    srand((int)time(NULL));
    string files[6] = { "5.txt","0.5k.txt","50k.txt",
    "out_5.txt","out_0.5k.txt","out_50k.txt"};
    fstream file;//用file代理文件名
    QueryPerformanceFrequency(&frequency);//获得时钟频率
    dff = (double)frequency.QuadPart;//取得频率
    int k=5,t;
    for (int i = 0; i < 3; i++)
    {
        file.open(files[i], ios::in);//读文件
        read(file, k, Array);
        file.close();

        cout<<"number of test data is :" << k <<endl;
        t=clock();
        file.open(files[i+3], ios::out);//写文件
        solution_2(file,Array,0,k-1);
        t=clock()-t;
        cout << "execute time is : " << t << "ms" << endl<<
        "the minimum and maximum are :"<<Array[0]<<' '<<Array[k-1]<<endl;
        file << "execute time is : " << t << "ms" << endl<<
        "the minimum and maximum are :"<<Array[0]<<' '<<Array[k-1]<<endl;
        file.close();
        k*=100;
        system("pause");
    }
    return 0;
}

