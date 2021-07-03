#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<numeric>
//https://leetcode-cn.com/problems/set-mismatch/submissions/
using namespace std;
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int size=nums.size();
		set<int> a(nums.begin(),nums.end());
		set<int> temp;
		//set<int>result;
        	//set_difference(temp.begin(),temp.end(),a.begin(),a.end(),inserter(result,result.begin()));
		int sum_nums=accumulate(nums.begin(),nums.end(),0);
		int sum_temp=size*(size+1)>>1;
		int sum_a=accumulate(a.begin(),a.end(),0);
		vector<int> final(2);
		final[1]=sum_temp-sum_a;
		final[0]=sum_nums-sum_a;
		return final;
    }
//超快速的方法
    vector<int> findErrorNums1(vector<int> &nums) {
        int n=nums.size(),i=0,a1=0,a2=0;n=(n*(n+1))>>1;
        for(int k:nums) n-=k;
	//排序方法，回头看一下，疑似桶排序
        do{while((a1=nums[i])!=(a2=nums[nums[i]-1]))
        {nums[a1-1]=a1;nums[i]=nums[a2-1];nums[a2-1]=a2;}}
        while(a1==++i);
        return {a1,a1+n};
    }
};