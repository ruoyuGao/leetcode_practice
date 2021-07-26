#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;
//https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/zui-chang-shang-sheng-zi-xu-lie-by-leetcode-soluti/
//上面的方法用动态规划会超时
class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> dictionary;
	    for(int i=0;i<target.size();i++)
	    {
		    dictionary[target[i]]=i;
	    }
	    for(int i=0;i<arr.size();i++)
        {
            if(dictionary.count(arr[i]))arr[i]=dictionary[arr[i]];
            else{arr[i]=-1;}
        }
        arr.erase(remove(arr.begin(),arr.end(),-1), arr.end());
	int t_len=target.size();
	int lenth=arr.size();
        if(lenth==0)return t_len;
	vector<int> dp(lenth,0);
	dp[0]=1;
	int max_subarray=1;
	    for(int i=1;i<lenth;i++)
	    {
		    dp[i]=1;
		    for(int j=0;j<i;j++)
		    {
			    if(arr[i]>arr[j])dp[i]=max(dp[i],dp[j]+1);
		    }
		    max_subarray=max(max_subarray,dp[i]);
	    }
	    return t_len-max_subarray;
    }
};
//https://leetcode-cn.com/problems/minimum-operations-to-make-a-subsequence/solution/de-dao-zi-xu-lie-de-zui-shao-cao-zuo-ci-hefgl/
// 贪心加二分查找 d[i]这个数组表示的是长度为i的最长上升数组的最后一位的最小值
class Solution1 {
public:
    int minOperations(vector<int> &target, vector<int> &arr) {
        int n = target.size();
        unordered_map<int, int> pos;
        for (int i = 0; i < n; ++i) {
            pos[target[i]] = i;
        }
        vector<int> d;
        for (int val : arr) {
            if (pos.count(val)) {
                int idx = pos[val];
                auto it = lower_bound(d.begin(), d.end(), idx);
                if (it != d.end()) {
                    *it = idx;
                } else {
                    d.push_back(idx);
                }
            }
        }
        return n - d.size();
    }
};

