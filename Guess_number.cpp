#include<iostream>
using namespace std;
//题目：https://leetcode-cn.com/problems/guess-number-higher-or-lower/ 
//缩小范围的时候记得排除错误答案
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int mid=n/2;
        int low=0;
        int high=n;
        while(low!=high)
        {
            if(guess(mid)<=0)
            {
                  high=mid;   
            }
            else
            {
               low=mid+1;
            }
            mid=low+(high-low)/2;
        }
        return low;
    }
};