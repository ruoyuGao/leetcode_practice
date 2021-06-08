class Solution {
public:
  //题目：https://leetcode-cn.com/problems/last-stone-weight-ii/
  //方法：动态规划，判断这个最大重量下能不能得到 经典的min=sum-2*max_eng-> max_neg=sum/2的向下取整
  //如果dp里面的表示这种情况下的重量，所有dp
    int lastStoneWeightII(vector<int>& stones) {
        int sum=0;
        for(int i=0;i<stones.size();i++)
        {
            sum+=stones[i];
        }
        int max_neg= floor(sum/2);
        int size=stones.size();
        vector<vector<int>>dp(size+1,vector<int>(max_neg+1));
        dp[0][0]=true;
        for(int i=1;i<size+1;i++)
        {
            int temp=stones[i-1];
            for(int j=0;j<max_neg+1;j++)
            {
                dp[i][j]=dp[i-1][j];
                if(j>=temp)dp[i][j]=dp[i-1][j]||dp[i-1][j-temp];
            }
        }
         for (int j = max_neg;; --j) {
            if (dp[size][j]) {
                return sum - 2 * j;
            }
        }
   
    }
};
