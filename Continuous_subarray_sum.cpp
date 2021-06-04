#include<iostream>
#include <unordered_map>
#include<vector>
using namespace std;
class solution
{
    //题目：https://leetcode-cn.com/problems/continuous-subarray-sum/
    //技术复盘：hash表，unordered_map<int,int> mp. mp.count()来查找下标
    //unordered_map(用法详解):http://c.biancheng.net/view/7231.html
    //vector初始化方法：https://blog.csdn.net/yjunyu/article/details/77728410
    public:
    //复杂度n的平方，超时了，朴素的方法吧可能这就是
      bool checkSubarraySum(vector<int>& nums, int k) {
        int num_size=nums.size();
        if(num_size==1){return 0;}
            vector<int> sum_subarray;
            for(int i=0; i<num_size;i++)
            {
                int temp=nums[i];
                int result;
                for(int j=i+1;j<num_size;j++)
                {
                    temp=temp+nums[j];
                    result=temp%k;
                    sum_subarray.push_back(result);
                }
            }
            for(int i=0; i<sum_subarray.size();i++)
            {
                if(sum_subarray[i]==0){ return 1;}
            }
            return 0;
        }
    //正确的思路是使用hash表和同余，首先我们将部分连续数组的和表示为sum(m:n)=sum(0:m)-sum(0:n),这样可以少跑一次循环
    //因为同余的两个数的差可以被这个k整除，因此我们选择哈希表，第一组为0，-1（因为最初不存在和也不存在余数，因此这样开创），之后如果没有该余数就插入hash表，有的话就计算这两个index的差是否大于2，大于2返回true
        bool checkSubarraySum2(vector<int>& nums, int k) {
            int m = nums.size();
            if (m < 2) {
                return false;
        }
            unordered_map<int, int> mp;
            mp[0] = -1;
            int remainder = 0;
            for (int i = 0; i < m; i++) {
                remainder = (remainder + nums[i]) % k;
                if (mp.count(remainder)) {
                    int prevIndex = mp[remainder];
                    if (i - prevIndex >= 2) {
                        return true;
                }
                } else {
                 mp[remainder] = i;
            }
        }
            return false;
    }
};

int main()
{
    // int nums[5]={23,2,4,6,7}; 定长数组不能初始化vector
    //vector初始化方法：https://blog.csdn.net/yjunyu/article/details/77728410
    int a[5]={23,2,4,6,7};
    vector<int> nums(a,a+5);//左闭右开
    int k_test=6;
    solution b;
    cout<<b.checkSubarraySum2(nums,k_test)<< endl;
    system("pause");
}