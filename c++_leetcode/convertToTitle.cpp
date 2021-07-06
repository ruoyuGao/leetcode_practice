#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//https://leetcode-cn.com/problems/excel-sheet-column-title/
class Solution {
public:
    string convertToTitle(int columnNumber) {
        vector<char> dictionary({'Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y'});
		int temp_number;
		string result;
		int count=0;
        if(columnNumber==1){
            result.push_back(dictionary[1]);
            return result;
        }
		while(columnNumber!=0){
			temp_number=columnNumber%26;
            if(temp_number==0&&columnNumber>=26)columnNumber-=26;
			columnNumber/=26;
			result.push_back(dictionary[temp_number]);
            //if(temp_number==0&&columnNumber==1)break;
		}
		reverse(result.begin(),result.end());
		return result;
    }
};