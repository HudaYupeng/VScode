//生成三个测试文件（数据样例为5个，500个和50000个）
#include <iostream>
#include <math.h>
#include <fstream>
#include <time.h>
using namespace std;
#define random(x) (int)(((double)rand()/RAND_MAX)*pow(10,rand()%x))
const int Maxn = 1e5;//100k
int Array[Maxn + 1];
void print(fstream& outfile, int n, int A[])//将数据载入文件
{
    for (int i = 0; i < n; i++)
    {
        outfile << A[i] << endl;
    }
}
int main()
{
    srand((int)time(NULL));
    string files[3] = { "5.txt","500.txt","50k.txt"};
    fstream file;//产生测试文件
    int k = 5;//最小的测试数据为5
    for (int i = 0; i < 3; i++)//装载3个test文件
    {
        file.open(files[i], ios::out);//打开文件
        for (int i = 0; i < k; i++)
       {
        Array[i] = random(6);//最大数为1e5
        //Array数组有100k个整数，范围为(0~1e5)
       }
        print(file, k, Array);
        file.close();//关闭文件
        k *= 100;
    }
    return 0;
}

