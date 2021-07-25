#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;
//value 是数组的一种map用法，很好用 码住
//https://leetcode-cn.com/problems/restore-the-array-from-adjacent-pairs/
class Solution{
	public:
	vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
       unordered_map<int,vector<int>> mp;
       for(auto& adj:adjacentPairs)
       {
	       mp[adj[0]].push_back(adj[1]);
	       mp[adj[1]].push_back(adj[0]);
       }
       int lenth=adjacentPairs.size()+1;
       vector<int> result(lenth);
       for(auto& [first,second]:mp)
       {
	       if(mp[first].size()==1)
	       {
		       result[0]=first;
		       break;
	       }
       }
       result[1]=mp[result[0]][0];
       for(int i=2;i<lenth;i++)    
       {
	       auto& pair=mp[result[i-1]];
	       result[i]= result[i-2]==pair[0]? pair[1]:pair[0];
       }
       return result;
   }
};