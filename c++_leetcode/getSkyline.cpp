#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;
//https://leetcode-cn.com/problems/the-skyline-problem/
//内存溢出了，其实我的时间复杂度更低
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int column=buildings.size();
		int max_size=buildings[column-1][1];
		int left_edge=buildings[0][0];
		vector<int> sky_line(max_size+1);
		vector<vector<int>> ans;
		for(auto building:buildings)
		{
			for(int i=building[0];i<building[1];i++)
			{
				if(building[2]>sky_line[i])sky_line[i]=building[2];
			}
		}
		for(int j=left_edge;j<=max_size;j++)
		{
			if(j==0)ans.push_back(vector<int>{j,sky_line[j]});
           		 else if(sky_line[j-1]!=sky_line[j])ans.push_back(vector<int>{j,sky_line[j]});
		}
		return ans;
    }
};
//用优先队列研究编辑线，和我的思路的区别是不用研究每一个点，只研究潜在的边界，然后压入边界左边所有的建筑，弹出右边界还没摸到这个潜在边缘的建筑，队列顶就是边界点最大元素，同时只有和结果的前一项末尾不同才是真正的边界
class Solution1 {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) -> bool { return a.second < b.second; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> que(cmp);

        vector<int> boundaries;
        for (auto& building : buildings) {
            boundaries.emplace_back(building[0]);
            boundaries.emplace_back(building[1]);
        }
        sort(boundaries.begin(), boundaries.end());

        vector<vector<int>> ret;
        int n = buildings.size(), idx = 0;
        for (auto& boundary : boundaries) {
            while (idx < n && buildings[idx][0] <= boundary) {
                que.emplace(buildings[idx][1], buildings[idx][2]);
                idx++;
            }
            while (!que.empty() && que.top().first <= boundary) {
                que.pop();
            }

            int maxn = que.empty() ? 0 : que.top().second;
            if (ret.size() == 0 || maxn != ret.back()[1]) {
                ret.push_back({boundary, maxn});
            }
        }
        return ret;
    }
};