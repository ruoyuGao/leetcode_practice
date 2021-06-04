#include<iostream>
using namespace std;
//Given an integer n, return true if it is a power of four. Otherwise, return false.
//An integer n is a power of four, if there exists an integer x such that n == 4x.
//method2:同余有基本定律 a≡b（mod d）则a^n≡b^n(mod d) 
// 所以 4^x≡(3+1)^x≡1^x≡1(mod 3)

//method1: 我们可以知道4的幂在二级制下偶数位为1，奇数位为0，并且int是32位，所以可以创造一个32位偶数位置为1的mask和n位与运算，并判断是否为2的幂即可得出答案
class solution
{
    public:
    bool isPowerofFour(int n)
    {
        return n>0 && (n&(n-1))==0 && (n&0xaaaaaaaa)==0;
    }
    bool ispoweroffour(int n)
    {
        return  n>0 && (n&(n-1))==0 && n%3==1;
    }
};

int main()
{
    int n=0;
    solution a;
    cin>>n;
    cout<<a.isPowerofFour(n)<<endl;
    cout<<"method2:"<<a.ispoweroffour(n)<<endl;
    system("pause");
    return 0;
}