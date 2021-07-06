#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//题目：https://leetcode-cn.com/problems/form-largest-integer-with-digits-that-add-up-to-target/
//在原本的动态规划的基础上，考虑一下dp[j]的来源，然后因为优先大的数字在前，因此倒序遍历
class Solution{
	public:
	string largestNumber(vector<int>& cost, int target) 
	{
		vector<int> dp(target+1,INT_MIN);
		dp[0]=0;
		for(int i=1;i<=9;i++)
		{
			for(int j=cost[i-1];j<=target;j++)
			{
				dp[j]=max(dp[j],dp[j-cost[i-1]]+1);
			}
		}
		string ans;
        	if(dp[target]<0)
        	{
            		return "0";
        	}
		for(int x=8,j=target;x>=0;x--)
        	{
            		for(int c=cost[x];j>=c && dp[j]==dp[j-c]+1;j-=c)
            		{
                		ans+='1'+x;
            		}
        	}
		return ans;
    	}
};

int main()
{
	int a[]={7,6,5,5,5,6,8,7,8};
	vector<int> cost(a,a+9);
	Solution s;
	cout<<s.largestNumber(cost,12)<<endl;
	system("pause");
	return 0;
}