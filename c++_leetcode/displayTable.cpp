#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cstring>
#include<string>

using namespace std;

//https://leetcode-cn.com/problems/display-table-of-food-orders-in-a-restaurant/
//字符串比较大小容易产生的错误 https://blog.csdn.net/jason_cuijiahui/article/details/79038468
//多参数sort使用 https://blog.csdn.net/w_linux/article/details/76222112
//二维map的使用 https://blog.csdn.net/qq_38289815/article/details/106022456
bool cmpbyNumber(string i,string j){return (stoi(i)<stoi(j));}	
class Solution {
public:
    
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        set<string> tables,fooditem;
		map<string,map<string,int>> temp_display;
		for(auto order:orders)
		{
			string table=order[1];
            string food=order[2];
            tables.emplace(table);
			fooditem.emplace(food);
			if(temp_display.count(table))
			{
				if(temp_display[table].count(food))temp_display[table][food]++;
				else{temp_display[table].emplace(food,1);}
			}
			else{
				temp_display[table][food]=1;
			}
		}
		int columns=tables.size();
		int rows=fooditem.size();
		vector<vector<string>> display_result(columns+1,vector<string>(rows+1));
		vector<string> v_fooditem(fooditem.begin(),fooditem.end());
		vector<string> v_tables(tables.begin(),tables.end());
		sort(v_tables.begin(),v_tables.end(),cmpbyNumber);
		v_fooditem.insert(v_fooditem.begin(),"Table");
		display_result[0]=v_fooditem;
		string final_table,final_food;
		for(int i=1;i<=columns;i++)
		{
			final_table=v_tables[i-1];
			display_result[i][0]=final_table;
			for(int j=1;j<=rows;j++)
			{
				final_food=v_fooditem[j];
				display_result[i][j]=to_string(temp_display[final_table][final_food]);
			}
		}
		return display_result;
		
    }
};