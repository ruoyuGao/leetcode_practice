#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char,int> mp;
        unordered_map<char,int> mp_count;
        unordered_set<string> substring;
        int gap=0;
        int count_number=0;
        int ori;
        string temp;
        for(int i=0;i<s.size();i++)
        {
            mp_count[s[i]]++;
            if(mp.count(s[i]))
            {
                gap=i-mp[s[i]];
                ori=mp[s[i]];
                for(int j=1;j<gap;j++)
                {
                    temp.push_back(s[ori]);
                    temp.push_back(s[ori+j]);
                    temp.push_back(s[ori]);
                    substring.emplace(temp);
                    temp.clear();
                }
            }
            mp[s[i]]=i;
        }
        for(auto [_,count]:mp_count)
        {
            if(count>=3)count_number++;
        }
        return substring.size()+count_number;
    }
};

int main()
{
	string temp("aabca");
	Solution s;
	cout<<s.countPalindromicSubsequence(temp)<<endl;
	system("pause");
	return 0;
}