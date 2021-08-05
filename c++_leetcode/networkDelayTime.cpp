#include<iostream>
#include<vector>

using namespace std;
//我的dfs写的不对，不用seen
class Solution {
public:
    unordered_map<int,int> seen;
    vector<vector<int>> mp;
    void DFS(int start,int late)
    {
        int count=0;
        int n=mp.size()-1;
        for(int j=1;j<n+1;j++)
        {
            if(mp[start][j]!=0 && !seen.count(j))
            {
                seen[j]=late+mp[start][j];
                count=1;
                DFS(j,late+mp[start][j]);
            }
        }
        if(count==0)return;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int row=0,column=0, edge=0;
        vector<vector<int>> mp_real(n+1,vector<int>(n+1,0));
        mp=mp_real;
        for(auto &line:times)
        {
            row=line[0];
            column=line[1];
            edge=line[2];
            mp[row][column]=edge;
        }
        seen[k]=0;
        DFS(k,0);
        if(seen.size()<n)return -1;
        int max_number=0;
        for(auto [point,late]:seen)
        {
            max_number=max(late,max_number);
        }
        return max_number;
    }
};
//DFS 不好用
#define MAXVALUE 0x3f3f3f3f

class Solution1 {
public:
    vector<unordered_map<int, int>> mp;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // 建图 - 邻接表
        mp.resize(n + 1);
        for (auto& edg : times) {
            mp[edg[0]][edg[1]] = edg[2];
        }
        // 记录结点最早收到信号的时间
        vector<int> r(n + 1, MAXVALUE);

        dfs(r, k, 0);

        int minT = -1;
        for (int i = 1; i <= n; ++i)
            minT = max(minT, r[i]);
        return minT == MAXVALUE ? -1 : minT;
    }

    void dfs(vector<int>& r, int i, int t) {
        if (r[i] > t) {
            r[i] = t;
            for (auto& cur : mp[i]) {
                dfs(r, cur.first, cur.second + t);
            }
        }
    }
};

//dijkstra
class Solution2 {
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k) {
        const int inf = INT_MAX / 2;
        vector<vector<int>> g(n, vector<int>(n, inf));
        for (auto &t : times) {
            int x = t[0] - 1, y = t[1] - 1;
            g[x][y] = t[2];
        }

        vector<int> dist(n, inf);
        dist[k - 1] = 0;
        vector<int> used(n);
        for (int i = 0; i < n; ++i) {
            int x = -1;
            for (int y = 0; y < n; ++y) {
                if (!used[y] && (x == -1 || dist[y] < dist[x])) {
                    x = y;
                }
            }
            used[x] = true;
            for (int y = 0; y < n; ++y) {
                dist[y] = min(dist[y], dist[x] + g[x][y]);
            }
        }

        int ans = *max_element(dist.begin(), dist.end());
        return ans == inf ? -1 : ans;
    }
};