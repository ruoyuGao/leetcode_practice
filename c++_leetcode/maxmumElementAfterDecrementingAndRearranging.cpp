#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        arr[0]=1;
        int n=arr.size()-1;
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i]>arr[i-1])arr[i]=arr[i-1]+1;
            else{continue;}
        }
        return arr[n];
    }
};


class Solution2 {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int> &arr) {
        int n = arr.size();
        vector<int> cnt(n + 1);
        for (int v : arr) {
            ++cnt[min(v, n)];
        }
        int miss = 0;
        for (int i = 1; i <= n; ++i) {
            if (cnt[i] == 0) {
                ++miss;
            } else {
                miss -= min(cnt[i] - 1, miss); // miss 不会小于 0，故至多减去 miss 个元素
            }
        }
        return n - miss;
    }
};
