#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int result=0;
        if(nums.size()<3)return 0;
        for(int i=0;i<nums.size()-2;i++)
        {
            for(int j=i+1;j<nums.size()-1;j++)
            {
                int left=j+1, right=nums.size()-1,count=j;
                while(left<=right)
                {
                    int mid=(left+right)/2;
                    if(nums[mid]>=nums[i]+nums[j]){
                        right=mid-1;
                    }
                    else{
                        left=mid+1;
                        count=mid;
                    }
                }
                result+=count-j;
            }
        }
        return result;
    }
};
//不需要二分这里，因为每一次新的k都会大于之前的k，因此从之前的k开始继续查找就行
class Solution2 {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int k = i;
            for (int j = i + 1; j < n; ++j) {
                while (k + 1 < n && nums[k + 1] < nums[i] + nums[j]) {
                    ++k;
                }
                ans += max(k - j, 0);
            }
        }
        return ans;
    }
};