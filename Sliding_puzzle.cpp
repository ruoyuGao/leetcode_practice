#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
#include<array>
#include<stdio.h>
using namespace std;
class Solution{
	public:
	//BFS
	int slideingPuzzle(vector<vector<int>>& board){
		vector<vector<int>> neighbors={{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
		//如果不加&会找不到要迭代的对象neighbors，从而报错
		auto get_next_status=[&](string& board)->vector<string>{
			//题目要求，只能移动0
			int index=board.find('0');
			vector<string> result;
			//for的范围迭代
			for(int i: neighbors[index]){
				swap(board[index],board[i]);
				result.push_back(board);
				swap(board[index],board[i]);
			}
			return result;
		};
		queue<pair<string,int>> q;
		unordered_set<string> seen;
		string initial_state;
		for(int i=0;i<board.size();i++)
		{
			for(int j=0;j<board[0].size();j++)
			{
				initial_state+=char(board[i][j]+'0');
			}
		}
		if(initial_state=="123450") return 0;
		q.emplace(initial_state,0);
		seen.emplace(initial_state);
		while(!q.empty()){
			auto [state,step]=q.front();
			q.pop();
			for(auto && next_state: get_next_status(state))
			{
				if(!seen.count(next_state))
				{
					seen.emplace(next_state);
					q.emplace(next_state,step+1);
					if(next_state=="123450"){
						return step+1;
					}
				}
			}
		}
		return -1;
	}
};
struct AStar {
    // 曼哈顿距离 d(x,y)=|x1-x2|+|y1-y2| 我们这里用曼哈顿距离估计h，计算每个数字i到指定位置的曼哈顿距离，然后用这个和表示h
    static constexpr array<array<int, 6>, 6> dist = {{
        {0, 1, 2, 1, 2, 3},
        {1, 0, 1, 2, 1, 2},
        {2, 1, 0, 3, 2, 1},
        {1, 2, 3, 0, 1, 2},
        {2, 1, 2, 1, 0, 1},
        {3, 2, 1, 2, 1, 0}
    }};

    // 计算启发函数
    static int getH(const string& status) {
        int ret = 0;
        for (int i = 0; i < 6; ++i) {
            if (status[i] != '0') {
                ret += dist[i][status[i] - '1'];
            }
        }
        return ret;
    };

    AStar(const string& status, int g): status_{status}, g_{g}, h_{getH(status)} {
        f_ = g_ + h_;
    }
	//重载操作符从而使得堆变成最小堆
    bool operator< (const AStar& that) const {
        return f_ > that.f_;
    }

    string status_;
    int f_, g_, h_;
};
class Solution1 {
private:
    vector<vector<int>> neighbors = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};;

public:
    int slidingPuzzle(vector<vector<int>>& board) {
        // 枚举 status 通过一次交换操作得到的状态
        auto get = [&](string& status) -> vector<string> {
            vector<string> ret;
            int x = status.find('0');
            for (int y: neighbors[x]) {
                swap(status[x], status[y]);
                ret.push_back(status);
                swap(status[x], status[y]);
            }
            return ret;
        };

        string initial;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                initial += char(board[i][j] + '0');
            }
        }
        if (initial == "123450") {
            return 0;
        }

        priority_queue<AStar> q;
        q.emplace(initial, 0);
        unordered_set<string> seen = {initial};

        while (!q.empty()) {
            AStar node = q.top();
            q.pop();
            for (auto&& next_status: get(node.status_)) {
                if (!seen.count(next_status)) {
                    if (next_status == "123450") {
                        return node.g_ + 1;
                    }
                    q.emplace(next_status, node.g_ + 1);
                    seen.insert(move(next_status));
                }
            }
        }

        return -1;
    }
};
int main()
{
	vector<vector<int>> test={{4,1,2},{5,0,3}};
	Solution a;
	cout<<a.slideingPuzzle(test)<<endl;
	system("pause");
	return 0;
}