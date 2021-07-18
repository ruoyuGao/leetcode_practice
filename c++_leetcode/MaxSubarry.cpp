#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
//因为是连续子数组的和最大，因此不能终端，因此考虑的是当前节点加入还是放弃，同时本题也可以递归，树结构有利于搜索
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len=nums.size();
        vector<int> dp(nums.size()+1);
        dp[1]=nums[0];
        int max_ans=dp[1];
        for(int i=2;i<nums.size()+1;i++)
        {
            dp[i]=max(nums[i-1],dp[i-1]+nums[i-1]);
            max_ans=max(dp[i],max_ans);
        }
        return max_ans;
    }
};