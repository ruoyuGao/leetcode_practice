#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<queue>
using namespace std;
typedef pair<char,int> P;
//struct cmp{
//	bool operator()(const P p1,const P p2)
//	{
//		return p1.second<p2.second;// second 的大值优先
//	}
//};
//pair放入优先队列 https://blog.csdn.net/potential1/article/details/73195172 但是本题不合适，遍历的太多了
//https://blog.csdn.net/a3192048/article/details/83019944对map key和value排序
//https://leetcode-cn.com/problems/sort-characters-by-frequency/
typedef pair<char, int> PAIR;
 
struct CmpByValue {
	bool operator()(const PAIR& lhs, const PAIR& rhs) {
		return lhs.second > rhs.second;
	}
};

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
		for(int i=0;i<s.size();i++)
		{
			if(mp.count(s[i]))
			{
				mp.at(s[i])++;
			}
			else
			{
				mp.emplace(make_pair(s[i],1));
			}	
		}
		vector<PAIR> freq_s(mp.begin(),mp.end());
		sort(freq_s.begin(),freq_s.end(),CmpByValue());
		string result;
		for(auto & freq: freq_s)
		{
			for(int i=0;i<freq.second;i++)
			{
				result.push_back(freq.first);
			}
		}
		return result;
    }
};