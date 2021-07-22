#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
//https://leetcode-cn.com/problems/frequency-of-the-most-frequent-element/
class Solution{
	public:
	int maxFrequency(vector<int>& nums,int k)
	{
		sort(nums.begin(),nums.end());
		int n=nums.size();
		int left_edge=0;
		long long total =0;
		int result=1;
		for(int right_edge=1;right_edge<n;right_edge++)
		{
			total+=(long long)(nums[right_edge]-nums[right_edge-1])*(right_edge-left_edge);
			while(total>k)
			{
				total-=nums[right_edge]-nums[left_edge];
				left_edge++;
			}
			result=max(result,right_edge-left_edge+1);
		}
		return result;
	}
};