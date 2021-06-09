class Solution {
public:
    //题目：https://leetcode-cn.com/problems/profitable-schemes/
    //用位操作符移动的方法取子集：https://zhidao.baidu.com/question/204693762.html
    //全部子集求法：https://blog.csdn.net/qq_41528502/article/details/104162599?utm_medium=distribute.pc_relevant.none-task-blog-baidujs_title-1&spm=1001.2101.3001.4242
    //为什么要取模1e9，以及容易取模的时候的错误：https://blog.csdn.net/qq_43827595/article/details/104267327
    //该方法超时了
     int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int size=profit.size();
        int end=(1<<(size))-1;
        long long count=0;
        long long mod=1e9+7;
        //vector<int> subset_sum;
        for(int mark=0; mark<=end;mark++)
        {
            int sum=0;
            int total_member=0;
            for(int j=0;j<size;j++)
            {
                if((mark&(1<<j))!=0) 
                {
                    sum+=profit[j];
                    total_member+=group[j];
                }
            }
            if(sum>=minProfit && total_member<=n) count=((count+1) % mod);
        }
        return count;
    }
};
