#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
//https://leetcode-cn.com/problems/chuan-di-xin-xi/
//DFS
class Solution{
	vector<vector<int>> relation_map;
	int count=0;
	void DFS(int start,int step,int n,int k)
	{
		if(start==n&& step==k)
		{
			count++;
			return;
		}
		if(step==k)return;
		for(int i=0;i<=n;i++)
		{
			if(relation_map[start][i]==-1)continue;
            DFS(i,step+1,n,k);
		}
	}
	int numWays(int n,vector<vector<int>>& relation, int k){
		vector<vector<int>> temp_map(n,vector<int>(n,-1));
		for(int i=0;i<relation.size();i++)
		{
			int row=relation[i][0];
			int column=relation[i][1];
			temp_map[row][column]=1;
		}
		relation_map=temp_map;
		DFS(0,0,n-1,k);
		return count;
	}
};
//动态规划 d[i][j] 表示第i轮传到第j个玩家的方法数 其等于d[i-1][x]的和 x指的是所有有关系（x，j）的x（即x可以一步传递到j）
class Solution1 {
public:
    int numWays(int n, vector<vector<int>>& relation, int k) {
        vector<vector<int>> dp(k + 1, vector<int>(n));
        dp[0][0] = 1;
        for (int i = 0; i < k; i++) {
            for (auto& edge : relation) {
                int src = edge[0], dst = edge[1];
                dp[i + 1][dst] += dp[i][src];
            }
        }
        return dp[k][n - 1];
    }
};
