class Solution {
  //题目；https://leetcode-cn.com/problems/ones-and-zeroes/
  //&&的作用：https://stackoverflow.com/questions/4549151/c-double-address-operator
  //解题思路：动态规划，到第i个字符串为止，最多有j个0和k个1的情况下，dp（i，j,k)表示最多的子集包含的元素数量
  //背包问题不能使用贪心，这可能导致结果出错，但是考虑遗传算法。。但我认为本题遗传算法复杂度太高可能，不合适
  //网友推荐回朔剪枝来大大提高效率（尚未尝试，改日试试）
  //回朔法解决装载问题：https://blog.csdn.net/liufeng_king/article/details/8762073?utm_medium=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7EBlogCommendFromMachineLearnPai2%7Edefault-1.baidujs&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7EBlogCommendFromMachineLearnPai2%7Edefault-1.baidujs
public:
    vector<int> getZerosOnes(string& str) {
      //注意开创该数组要初始化，不然会报错：applying non-zero offset 4 to null pointer
        vector<int> zerosOnes(2);
        int length = str.length();
        for (int i = 0; i < length; i++) {
            zerosOnes[str[i] - '0']++;
        }
        return zerosOnes;
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        int length = strs.size();
        vector<vector<vector<int>>> dp(length + 1, vector<vector<int>>(m + 1, vector<int>(n + 1)));
        for (int i = 1; i <= length; i++) {
            vector<int>&& zerosOnes = getZerosOnes(strs[i - 1]);
            int zeros = zerosOnes[0], ones = zerosOnes[1];
            for (int j = 0; j <= m; j++) {
                for (int k = 0; k <= n; k++) {
                  //因为动态规划需要先对边线的数值进行一个传递，不然最后规划的时候结果会出错
                    dp[i][j][k]=dp[i-1][j][k];
                    dp[i][j][k] =(j >= zeros && k >= ones)? max(dp[i][j][k], dp[i - 1][j - zeros][k - ones] + 1):dp[i][j][k] = dp[i - 1][j][k];
                }
            }
        }
        return dp[length][m][n];
    }
};
