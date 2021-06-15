#include<iostream>
#include<vector>
using namespace std;
//题目:https://leetcode-cn.com/problems/peak-index-in-a-mountain-array/
//方法2：二分查找
class Solution {
public:
    
    int peakIndexInMountainArray(vector<int>& arr) {
            int length=arr.size();
            int max=0;
            int count=0;
            for(int i=0;i<length;i++)
            {
                if(arr[i]>max)
                {
                    max=arr[i];
                    count=i;
                }
                
            }
            return count;
    }
};