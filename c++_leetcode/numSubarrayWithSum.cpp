#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;
//https://leetcode-cn.com/problems/binary-subarrays-with-sum/
class Solution{
	public:
	//不能dp，dp判断不了是不是连在一起的数组
	int numSubarrayWithSum(vector<int>& nums,int goal){
		int len=nums.size();
		vector<vector<int>> dp(len,vector<int>(goal+1));
		if(goal>=nums[0])
		{
			int temp_goal=nums[0];
			dp[0][temp_goal]=1;
			for(int i=1;i<len;i++)
			{
				for(int j=1;j<=goal;j++)
				{
					if(j>=nums[i])dp[i][j]=max(dp[i-1][j],dp[i-1][j-nums[i]]+1);
                    else{dp[i][j]=dp[i-1][j];}                    
				}
            }
		}
		return dp[len-1][goal];
	}
};
//hashtable
class Solution1 {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum = 0;
        unordered_map<int, int> cnt;
        int ret = 0;
        for (auto& num : nums) {
            cnt[sum]++;
            sum += num;
            ret += cnt[sum - goal];
        }
        return ret;
    }
};
//滑动窗口，左一和左二之间为当前右边界下的所有符合条件的情况
class Solution2 {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int left1 = 0, left2 = 0, right = 0;
        int sum1 = 0, sum2 = 0;
        int ret = 0;
        while (right < n) {
            sum1 += nums[right];
            while (left1 <= right && sum1 > goal) {
                sum1 -= nums[left1];
                left1++;
            }
            sum2 += nums[right];
            while (left2 <= right && sum2 >= goal) {
                sum2 -= nums[left2];
                left2++;
            }
            ret += left2 - left1;
            right++;
        }
        return ret;
    }
};