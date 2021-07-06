#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
//https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/
using namespace std;
class Solution{
	//全部解出来后再去重，效率太低了，直接垫底
	public:
	vector<int> label;
	vector<string> result;
	void backtrack(const string& pool, int start, int max, string& perm)
	{
		if(start==max)
		{
			result.push_back(perm);
			return ;
		}
		for(int j=0;j<max;j++)
		{
			if(label[j])continue;
			label[j]=true;
			//if (vis[j] || (j > 0 && !vis[j - 1] && s[j - 1] == s[j])) continue; 一种判断方法，每个位置确保填入的该字符是第一个
			//string也可以用push_back和pop
			perm.push_back(pool[j]);
			backtrack(pool,start+1,max,perm);
			perm.pop_back();
			label[j]=false;
			
		}
	}
	vector<string>permutation(string s){
		int length=s.size();
		sort(s.begin(),s.end());
		label.resize(length,0);
		string perm;
		backtrack(s,0,length,perm);
		set<string> shuffle(result.begin(),result.end());
		result.assign(shuffle.begin(),shuffle.end());
		return result;
	}
};
//下一个队列排序，根据字典序，不停的找更大的字典序，并直到找不到为止
//对于本题效率更高
class Solution2 {
public:
    bool nextPermutation(string& s) {
        int i = s.size() - 2;
        while (i >= 0 && s[i] >= s[i + 1]) {
            i--;
        }
        if (i < 0) {
            return false;
        }
        int j = s.size() - 1;
        while (j >= 0 && s[i] >= s[j]) {
            j--;
        }
        swap(s[i], s[j]);
        reverse(s.begin() + i + 1, s.end());
        return true;
    }

    vector<string> permutation(string s) {
        vector<string> ret;
	//默认从小到大牌，所以我们在next函数里逐渐进行从大到小的寻找
        sort(s.begin(), s.end());
        do {
            ret.push_back(s);
        } while (nextPermutation(s));
        return ret;
    }
};