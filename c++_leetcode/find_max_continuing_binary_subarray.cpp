#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
//哈希表详解：https://blog.csdn.net/hk2291976/article/details/51037095
//本题的关键在于计算0和1的数量差，因此我们使用前序和，把0替换成-1方便计算，同时使用hash表，key是counter的值，value是原数组下标
//同key的情况下，下标的差就是连续01数量相同数组的长度
//因此本题的关键在于思维逆用思维，key是前序和而value是下标，如果反过来我认为也可，即开创一个数组，对应下标对应的就是前序和，缺点就是每次查找需要遍历，复杂度大大提高，因此不好
class solution
{
    public:
        int findmaxlength(vector<int>& nums)
        {
            unordered_map<int,int> mp;
            mp[0]=-1;
            int count1=0;
            int maxlength=0;
            for(int i=0;i<nums.size();i++)
            {
                int temp=nums[i];
                //下面这个是ifelse的简略写法
                count1 += nums[i] ? 1 : -1;
                if(mp.count(count1))
                {
                    int preindex=mp[count1];
                    maxlength=max(maxlength, i-preindex);
                }
                else{mp[count1]=i;}
            }
            return maxlength;
        }
};

int main()
{
    int array[]={0,0,1,0,0,0,1,1};
    vector<int> nums(array,array+8);
    solution a;
    cout<<a.findmaxlength(nums)<<endl;
    system("pause");
}