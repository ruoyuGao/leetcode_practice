class Solution {
public:
  //本题使用回溯算法，本质上这里使用的是dfs，时间复杂度是2的n次方
  //https://leetcode-cn.com/problems/target-sum/
  //第二种方法是动态规划：neg=sum-target/2,neg是符号为-的所有元素的和，因此要求neg非负且为2的倍数，动态规划中，dp[i][j]的结果为不选去当前元素的种类数，和选取当前元素条件下的方法种类数
  //动态规划和前面的回溯相比，时间复杂度降低到了n的平方（提升很大），但是内存消耗增加（不太多）
    int count=0;
    void backtrack(vector<int>& nums,int target, int index,int sum)
    {
        if(index==nums.size())
        {
            if(sum==target)
            {
                count++;
            }
        }
        else{
            backtrack(nums, target, index+1, sum+nums[index]);
            backtrack(nums, target, index+1, sum-nums[index]);
        }
    }
    int findTargetSumWays(vector<int>& nums, int target) 
    {
            backtrack(nums, target, 0, 0);
            return count;

    }
  int findTargetSumWays2(vector<int>& nums, int target) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        int diff=sum-target;
        if(diff<0|diff%2!=0)
        {
            return 0;
        }
        int neg=diff/2;
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(neg+1));
        dp[0][0]=1;
        for(int i=1;i<n+1;i++)
        {
            
            int num=nums[i-1];
            for(int j=0;j<neg+1;j++)
            {
                dp[i][j]=dp[i-1][j];
                if(j>=num)
                {
                    dp[i][j]+=dp[i-1][j-num];
                }
            }
        }
        return dp[n][neg];
    }
};
