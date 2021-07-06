#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//题目：https://leetcode-cn.com/problems/stone-game/
//本题有三种方法，动态规划，数学方法和递归
//通过计算两人的石头数量的差，来判断谁可以获胜，动态规划需要注意，在更新dp[i]之前需要知道dp[i+1]，因此需要倒序遍历。
// 数学方法的本质是，将石头分成了偶数下标和奇数下标两组，alex选完第一个，lee只能从第二组中选择，因此在第一手的时候，alex就可以通过计算哪一组sum大，选择哪一组，因此一定回事true
//list,map, vector在c++的区别：https://blog.csdn.net/alex_xhl/article/details/37692297
class Solution{
	public:
	bool stoneGame(vector<int>& piles)
	{
		int length=piles.size();
		auto dp=vector<vector<int>>(length,vector<int>(length));
		for(int i=0;i<length;i++)
		{
			dp[i][i]=piles[i];
		}
		for(int i=length-2;i>=0;i--)
		{
			for(int j=i+1;j<length;j++)
			{
				dp[i][j]=max(piles[i]-dp[i+1][j],piles[j]-dp[i][j-1]);
			}
		}
		return dp[0][length-1]>0;
	}

	bool stone(vector<int>& piles,int i,int j, int gap, bool alex)
	{
		int left_result,right_result;
		if(i==j)
		{
			return(((alex)?gap+piles[i]:gap-piles[i])>0);
		}
		left_result=(alex)?(gap+piles[i]):(gap-piles[i]);
		right_result=(alex)?(gap+piles[j]):(gap-piles[j]);

		return stone(piles, i+1,j, left_result,!alex) || stone(piles,i,j-1,right_result,!alex);
	}
	bool stoneGame2(vector<int>& piles)
	{
		return stone(piles,0,piles.size()-1,0,true);
	}
	bool stoneGame3(vector<int>& piles)
	{
		return true;
	}
};

