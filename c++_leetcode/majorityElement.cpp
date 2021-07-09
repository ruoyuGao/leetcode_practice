#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;
//https://leetcode-cn.com/problems/find-majority-element-lcci/
//hashmap
class Solution{
	public:
	int majorityElement(vector<int>& nums){
		unordered_map<int,int> mp;
		int max_counter=0;
		int major_number=0;
		for(auto& num:nums)
		{
			mp[num]++;
		}
		for(auto& [number,count]:mp)
		{
			if(count>max_counter)
			{
				major_number=number;
				max_counter=count;
			}
		}
		int len=nums.size()/2;
		if(max_counter>len)return major_number;
		return 0;
	}
};