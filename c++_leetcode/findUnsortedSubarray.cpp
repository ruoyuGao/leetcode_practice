#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
//将数组分成三个部分，只有中间部分修改才能重新排序，因此前面和和后面排序没有用，因此重新排序数组后，从前往后和从后往前找到第一个不同的点就是中间数组的起点和终点。
//https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> nums_copy=nums;
        sort(nums_copy.begin(),nums_copy.end());
        int start=0;
        int end=nums.size()-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums_copy[i]!=nums[i])
            {
                start=i;
                break;
            }
            if(i==end)return 0;
        }
        for(int j=end;j>0;j--)
        {
            if(nums_copy[j]!=nums[j])
            {
                end=j;
                break;
            }
        }
        return end-start+1;
    }
};