#include<iostream>
#include<vector>
using namespace std;
class solution{
    //题目:https://leetcode-cn.com/problems/coin-change-2/
    //动态规划 dp[i]表示在总钱数为i的情况下有多少种组合
    public:
        int change(int amount,vector<int> coins)
        {
            vector<int> dp(amount+1);
            dp[0]=1;
            for(int i=0;i<coins.size();i++)
            {
                for(int j=coins[i];j<=amount;j++)
                {
                    dp[j]+=dp[j-coins[i]];
                }
            }
            return dp[amount];
        }
};

int main()
{
    int a[]={1,2,5};
    vector<int> coins(a,a+3);
    solution s;
    cout<<s.change(5,coins)<<endl;
    system("pause");
    return 0;

}