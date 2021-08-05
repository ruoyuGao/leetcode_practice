#include<iostream>
#include<set>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;
//朴素BFS，超时了
class Solution {
public:
    unordered_map<int,vector<int>> mp;
    set<int> bad_point;
    set<int> end_point;

    void BFS(queue<vector<int>> q,int i){
        if(bad_point.count(i))return;
        if(end_point.count(i))return;
        while(!q.empty())
            {
                vector<int> line= q.front();
                q.pop();
                for(auto &to:mp[line.back()])
                {
                    if(end_point.count(to))continue;
                    else if(bad_point.count(to))
                    {
                        bad_point.emplace(line[0]);
                        return;
                    }
                    else if(count(line.begin(),line.end(),to))
                    {
                        bad_point.insert(line.begin(),line.end());
                    }
                    else
                    {
                        line.push_back(to);
                        q.push(line);
                        line.pop_back();
                    }

                }
            }
            return;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        queue<vector<int>> q;
        vector<int> result;

        for(int i=0;i<n;i++)
        {
            if(graph[i].size()>0)mp[i]=graph[i];
            else end_point.emplace(i);
        }
        for(int i=0;i<n;i++)
        {
            q.push(vector<int>{i});
            BFS(q,i);
            q=queue<vector<int>>();
        }
        
        for(int i=0;i<n;i++)
        {
            if(!bad_point.count(i))result.push_back(i);
        }
        return result;

    }
};
//拓扑排序，所有出度为0的点为安全节点，所有出度的点都是1安全节点的点为安全点，反向制作mp，即可
//也可以DFS，放进stack里搜索，如果全搜索完都没有环，就是安全的，反之如果找到环，则保留在栈中
class Solution1 {
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
        int n = graph.size();
        vector<vector<int>> rg(n);
        vector<int> inDeg(n);
        for (int x = 0; x < n; ++x) {
            for (int y : graph[x]) {
                rg[y].push_back(x);
            }
            inDeg[x] = graph[x].size();
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (inDeg[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int y = q.front();
            q.pop();
            for (int x : rg[y]) {
                if (--inDeg[x] == 0) {
                    q.push(x);
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (inDeg[i] == 0) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
//DFS 0-未标记 1-遇到但不确定是否安全或者不安全 2-确定安全的点
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
        int n = graph.size();
        vector<int> color(n);

        function<bool(int)> safe = [&](int x) {
            if (color[x] > 0) {
                return color[x] == 2;
            }
            color[x] = 1;
            for (int y : graph[x]) {
                if (!safe(y)) {
                    return false;
                }
            }
            color[x] = 2;
            return true;
        };

        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (safe(i)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};