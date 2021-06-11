#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;
//四平方数和定则：所有正整数最多可以表示为四个完全平方数的的和
//因此答案只有1，2，3，4。1的情况下n是完全平方数，2的情况下是完全平方数的和。4的情况下n=4^k(8m+7),即对4余数为0的情况下，对8余数为7，剩余情况下答案是3
//这个定则使用后，时间复杂度最低只有根号n
//常规的动态规划是n*根号n
//题目：https://leetcode-cn.com/problems/perfect-squares/
class solution{
	public:
	int numSquare(int n)
	{
		//思路错误，因为我这个写法意味着，在每个完全平方数上只能取1
		int perfect_square_size=100;
		vector<vector<int>> dp(perfect_square_size+1,vector<int>(n+1));
		dp[0][0]=0;
		for(int i=1;i<=perfect_square_size;i++)
		{
			int perfect_square=pow(i,2);
			for(int j=0;j<=n;j++)
			{
				dp[i][j]=dp[i-1][j];
				if(j>=perfect_square)
				{
					dp[i][j]=min(dp[i-1][j],dp[i-1][j-perfect_square]+1);
				}
			}
		}
		return dp[perfect_square_size][n];

	}
	int numSquares(int n)
	{
		//动态规划：在选取j的平方的情况下，总数-j*j时最少组合数
		vector<int> dp(n+1);
		for(int i=1;i<=n;i++)
		{
			int min_number=INT_MAX;
			for(int j=1;j*j<=i;j++)
			{
				int temp=pow(j, 2);
                		min_number=min(min_number,dp[i-temp]);
			}
			dp[i]=1+min_number;
		}
		return dp[n];
	}
    	bool isPerfectSquare(int x) {
        int y = sqrt(x);
        return y * y == x;
    }

    // 判断是否能表示为 4^k*(8m+7)
    	bool checkAnswer4(int x) {
        while (x % 4 == 0) {
            x /= 4;
        }
        return x % 8 == 7;
    }

    int numSquares2(int n) {
        if (isPerfectSquare(n)) {
            return 1;
        }
        if (checkAnswer4(n)) {
            return 4;
        }
        for (int i = 1; i * i <= n; i++) {
            int j = n - i * i;
            if (isPerfectSquare(j)) {
                return 2;
            }
        }
        return 3;
    }
};

int main()
{
	int number=12;
	solution a;
	cout<<a.numSquares2(number)<<endl;
	system("pause");
	return 0;
}