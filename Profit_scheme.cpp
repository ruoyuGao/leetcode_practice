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
    //动态规划，本来应该是三维的，但是因为i，也就是dp当前可选择的工作，已选择的小组员工人数，以及目前状态的工作获利下限时候的方案数量。同时因为前i个工作只和i-1系列的内容相关，因此可以降维
    //https://leetcode-cn.com/problems/profitable-schemes/solution/ying-li-ji-hua-by-leetcode-solution-3t8o/
    //
    int profitableSchemes2(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        vector<vector<int>> dp(n + 1, vector<int>(minProfit + 1));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        int len = group.size(), MOD = (int)1e9 + 7;
        for (int i = 1; i <= len; i++) {
            int members = group[i - 1], earn = profit[i - 1];
            for (int j = n; j >= members; j--) {
                for (int k = minProfit; k >= 0; k--) {
                    dp[j][k] = (dp[j][k] + dp[j - members][max(0, k - earn)]) % MOD;
                }
            }
        }
        return dp[n][minProfit];
    }
};
