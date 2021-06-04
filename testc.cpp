#include <iostream>
using namespace std;
// Given an integer n, return true if it is a power of two. Otherwise, return false.
//An integer n is a power of two, if there exists an integer x such that n == 2x.
// 关键在于利用位于运算符&来判断，位于的意思是两个二进制数在同一位置上全为1才是1 否则为0
//另一个比较朴素的做法是，不断用while循环整除2，直到最后为1，否则返回0，和上面的方法比，缺点是时间复杂度高很多
class solution{
    public:
    bool ispoweroftwo(int n)
    {
        return n>0 && (n&(n-1))== 0;
    }
};
int main()
{

    //cout << "Hello, world!" << endl;
    //system("pause");
    int number=0;
    solution A;
    cin>> number;
    cout<< A.ispoweroftwo(number)<< endl;
    system("pause");
    return 0;
}