#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;
//暴力法超时了
//https://leetcode-cn.com/problems/count-good-meals/submissions/
class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        auto ispowerofTwo=[&](int& n)->bool{
			return n>0 && (n&(n-1))==0;
		};
		int len=deliciousness.size();
		int count=0;
		int delicious;
		for(int i=0;i<len;i++)
		{
			for(int j=i+1;j<len;j++)
			{
				delicious=deliciousness[i]+deliciousness[j];
				if(ispowerofTwo(delicious))count++;
			}
		}
		return count;
    }
};
//正确的做法十hash表枚举
class Solution1 {
public:
    static constexpr int MOD = 1'000'000'007;

    int countPairs(vector<int>& deliciousness) {
        int maxVal = *max_element(deliciousness.begin(), deliciousness.end());
        int maxSum = maxVal * 2;
        int pairs = 0;
        unordered_map<int, int> mp;
        int n = deliciousness.size();
        for (auto& val : deliciousness) {
            for (int sum = 1; sum <= maxSum; sum <<= 1) {
                int count = mp.count(sum - val) ? mp[sum - val] : 0;
                pairs = (pairs + count) % MOD;
            }
            mp[val]++;
        }
        return pairs;
    }
};
