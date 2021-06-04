#include<iostream>
#include<vector>
using namespace std;

class solution
{
//题目描述：https://leetcode-cn.com/problems/can-you-eat-your-favorite-candy-on-your-favorite-day/
//本题的陷阱在于，第i天其实应该+1，因为我们在本题中是从第零天开始过的
//同时 vector在本题中教会了我们可以生成不定长度的数组，而不用提前分配空间
    public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries)
    {
        //超时错误，时间复杂度太高了，和标准答案相比，我的复杂度是n的平方，我应该吧算糖果区间的第一个for，拉到循环外面去，而不应该循环嵌套
        vector<bool> answer(queries.size());
        for(int i=0;i<queries.size();i++){
            queries[i][0];
             long int min_candies_number=0;
             long int max_candies_number=candiesCount[queries[i][0]];
            for(int j=0;j<queries[i][0];j++){
                min_candies_number=min_candies_number+candiesCount[j];
                max_candies_number=max_candies_number+candiesCount[j];
            }
            if(((long double)queries[i][2]*(queries[i][1]+1)>=min_candies_number) && max_candies_number>=(queries[i][1]+1)){ 
                answer[i]=1;
            }
        }
        return answer;
    };
    //根据答案自行修改得出，降低了时间复杂度，之前的复杂度太高了
    vector<bool> canEat2(vector<int>& candiesCount, vector<vector<int>>& queries) {
        vector<bool> answer(queries.size());
        int n=candiesCount.size();
        vector<long long> sum(n);
        sum[0] = candiesCount[0];
        for (int i = 1; i < n; ++i) {
            sum[i] = sum[i - 1] + candiesCount[i];
        }

        for(int i=0;i<queries.size();i++){
            int type=queries[i][0];
            long long min_candies_number=0;
            long long max_candies_number=0;
            if(type==0)
            {min_candies_number=0;max_candies_number=sum[type];}
            else
            {
                min_candies_number=sum[type-1];
                max_candies_number=sum[type];
            }
            
            if(((long long)queries[i][2]*(queries[i][1]+1)>min_candies_number) && max_candies_number>=(queries[i][1]+1)){ 
                answer[i]=1;
            }
        }
        return answer;

    };
};
int main()
{
    return 0;
}