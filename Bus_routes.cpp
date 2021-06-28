#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>
#include<queue>
//https://leetcode-cn.com/problems/bus-routes/
using namespace std;
class Solution{
	public:
	//无法通过超大型判例
	int numBusesToDestination(vector<vector<int>>& routes, int source,int target)
	{
		if(source==target)return 0;
		auto get_bus_from_stop=[](int stop,vector<vector<int>> routes)->vector<int>{
			int bus_number=routes.size();
			vector<int> bus;
			for(int i=0;i<bus_number;i++)
			{
				vector<int>:: iterator it=find(routes[i].begin(),routes[i].end(),stop);
				if(it!=routes[i].end()) bus.push_back(i);
			}
			return bus;
		};

		auto get_stop_from_bus=[](int bus_number,vector<vector<int>> routes)->vector<int>{
			return routes[bus_number];
		};

		bool on_bus=false;
		queue<pair<int,int>> q;
		unordered_set<int> taken;
		unordered_set<int> seen;
		seen.emplace(source);
		for(auto &bus_number: get_bus_from_stop(source,routes))
		{
			q.emplace(bus_number,1);
			taken.emplace(bus_number);
		}
		while(!q.empty())
		{
			auto[bus_number,count]=q.front();
			q.pop();
			for(auto &stop: get_stop_from_bus(bus_number,routes))
			{
				if(!seen.count(stop))
				{
					if(stop==target)return count;
					for(auto &bus_number: get_bus_from_stop(stop,routes))
					{
						if(!taken.count(bus_number))
						{
							q.emplace(bus_number,count+1);
							taken.emplace(bus_number);
						}
					}
				}
			}
		}
		return -1;
	}
};
class Solution2 {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) {
            return 0;
        }
	//以bus为点建立图，如果两种路线有共同点，则图中两个点的距离为1，并且建立map，记录经过每个点的公交线路数量
        int n = routes.size();
        vector<vector<int>> edge(n, vector<int>(n));
        unordered_map<int, vector<int>> rec;
        for (int i = 0; i < n; i++) {
            for (int site : routes[i]) {
                for (int j : rec[site]) {
                    edge[i][j] = edge[j][i] = true;
                }
                rec[site].push_back(i);
            }
        }
	//记录两个公交线路再图里面的距离
        vector<int> dis(n, -1);
        queue<int> que;
	//从起点确定图中的起点
        for (int bus : rec[source]) {
            dis[bus] = 1;
            que.push(bus);
        }
	//对所有起点进行BFS探索，从而完善公交线路之间的距离
        while (!que.empty()) {
            int x = que.front();
            que.pop();
            for (int y = 0; y < n; y++) {
		    //y没去过，且xy有边，则更新到y的距离
                if (edge[x][y] && dis[y] == -1) {
                    dis[y] = dis[x] + 1;
                    que.push(y);
                }
            }
        }
	//如果能到达终点，即能进入能进入终点的公交线路，我们找到其和起点的最小值
        int ret = INT_MAX;
        for (int bus : rec[target]) {
            if (dis[bus] != -1) {
                ret = min(ret, dis[bus]);
            }
        }
        return ret == INT_MAX ? -1 : ret;
    }
};

int main()
{
	vector<vector<int>> test({{1,2,7},{3,6,7}});
	Solution a;
	cout<<a.numBusesToDestination(test,1,6)<<endl;
	system("pause");
	return 0;

}