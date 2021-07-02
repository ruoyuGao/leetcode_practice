#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//dp超时，我是真的没想到
//考察排序算法，排的越快效果越好
//https://leetcode-cn.com/problems/maximum-ice-cream-bars/
class Solution{
	public:
	int maxIceCream(vector<int>& costs, int coins){
		int length=costs.size();
		vector<vector<int>> dp(length,vector<int>(coins+1));
		dp[0][0]=0;
		sort(costs.begin(),costs.end());
		if(costs[0]>coins)return 0;
		for(int i=costs[0];i<=coins;i++)
		{
			dp[0][i]=1;	
		}
		for(int i=1;i<length;i++)
		{
			for(int j=1;j<=coins;j++)
			{
				if(j-costs[i]>0)
				{
					dp[i][j]=max(dp[i-1][j],dp[i-1][j-costs[i]]+1);
				}
				else
				{
					dp[i][j]=dp[i-1][j];
				}
			}
		}
		return dp[length-1][coins];
	}
};
//greddy 
class Solution2{
	public:
	int maxIceCream(vector<int>& costs, int coins){
		sort(costs.begin(),costs.end());
		int number=0;
		if(coins<costs[0])return 0;
		for(int i=0;i<costs.size();i++)
		{
			coins-=costs[i];
			if(coins<0)break;
			number++;
	
		}
		return number;
	}
};