#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>

using namespace std;
class TimeMap {
    unordered_map<string, vector<pair<int, string>>> m;
//hashmap+内置二分查找
public:
    TimeMap() {}
    void set(string key, string value, int timestamp) {
        m[key].emplace_back(timestamp, value);
    }

    string get(string key, int timestamp) {
        auto &pairs = m[key];
        // 使用一个大于所有 value 的字符串，以确保在 pairs 中含有 timestamp 的情况下也返回大于 timestamp 的位置
        pair<int, string> p = {timestamp, string({127})};
	//二分查找
        auto i = upper_bound(pairs.begin(), pairs.end(), p);
        if (i != pairs.begin()) {
            return (i - 1)->second;
        }
        return "";
    }
};
