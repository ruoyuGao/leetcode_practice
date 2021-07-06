#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>

using namespace std;
//BFS 
//https://leetcode-cn.com/problems/snakes-and-ladders/
class Solution{
	public:
	vector<int> one_dimension_board;
	int snameAndladder(vector<vector<int>> board){
		int n=0;
		for(int i=board.size()-1;i>=0;i--)
		{	if(n%2)
			{
				for(int j=board[0].size()-1;j>=0;j--)one_dimension_board.push_back(board[i][j]);
			}
			else
			{
				for(int j=0;j<board[0].size();j++)one_dimension_board.push_back(board[i][j]);
			}
			n++;
		}
		auto get_next_status=[&](int x)->vector<int>{
			vector<int> next_status;
			for(int i=1;i<=6;i++)
			{
				int temp=x+i;
				if(temp>one_dimension_board.size()+1) break;
				if(one_dimension_board[temp-1]!=-1)temp=one_dimension_board[temp-1];
				next_status.push_back(temp);
			}
			return next_status;
		};
		queue<pair<int,int>> q;
		unordered_set<int> seen;
		q.emplace(1,0);
		seen.emplace(1);
		while(!q.empty())
		{
			auto[state,count]=q.front();
			q.pop();
			if(state==one_dimension_board.size()) return count;
			
			for(auto& next_state: get_next_status(state))
			{
				if(!seen.count(next_state))
				{
					q.emplace(next_state,count+1);
					seen.emplace(next_state);
					if(next_state==one_dimension_board.size())return count+1;
				}
			}
			
		}
		return -1;


	}
};
class Solution2{

};