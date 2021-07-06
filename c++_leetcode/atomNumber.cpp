#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
#include<algorithm>
#include<string>
using namespace std;
//https://blog.csdn.net/qq_34802416/article/details/79307102 正则表达式的使用
//https://www.runoob.com/regexp/regexp-syntax.html正则表达式语法
//http://c.biancheng.net/view/6971.html stack的使用
//https://leetcode-cn.com/problems/number-of-atoms/
//stack+hashmap
class Solution{
	public:
	string countOfAtoms(string formula){
		int i=0, length=formula.size();
		auto parseatom=[&]()->string{
			string atom;
			atom.push_back(formula[i++]);
			while(i<length && formula[i] >= 'a' && formula[i] <= 'z')
			{
				atom.push_back(formula[i++]);
			}
			return atom;
		};
		auto parsenumber=[&]()->int{
			if(i==length||formula[i] <= '0'|| formula[i] >= '9')return 1;
			int digit_number=0;
			while(i<length && formula[i]>='0'&& formula[i] <= '9')
			{
				digit_number=digit_number*10+int(formula[i++]-'0');
			}
			return digit_number;
		};

		stack<unordered_map<string,int>> stk;
		stk.push({});
		while(i<length)
		{
			if(formula[i]=='(')
			{
				i++;
				stk.push({});
			}
			else if(formula[i]==')'){
				i++;
				auto atom_dictionary=stk.top();
				int num=parsenumber();
				stk.pop();
				for(auto &[atom,number]: atom_dictionary)
				{
					stk.top()[atom]+=number*num;
				}
			}
			else{
				string atom=parseatom();
				int num=parsenumber();
				stk.top()[atom]+=num;
			}
		}
		auto &atomNumber=stk.top();
		vector<pair<string,int>> pairs;
		for(auto&[atom,number]:atomNumber)
		{
			pairs.emplace_back(atom,number);
		}
		sort(pairs.begin(),pairs.end());
		string result;
		for(auto& p:pairs)
		{
			result+=p.first;
			if(p.second>1)result+=to_string(p.second);
		}
		return result;
	}
};
// backtrack
class Solution1 {
public:
    //定义类内全局变量，用来在跳出递归的时候防止下标i迷路，重复遍历已经遍历过的位置
    int add_pos=0;
    unordered_map<string,int> parse(string formula){
		int i=0 , len=formula.size();
		unordered_map<string,int> atom_dictionary;
		auto parseatom=[&]()->string{
			string atom;
			atom.push_back(formula[i++]);
			while(i<len && islower(formula[i]))
			{
				atom.push_back(formula[i++]);
			}
			return atom;
		};
		auto parsenumber=[&]()->int{
			if(i==len|| !isdigit(formula[i]))return 1;
			int digit_number=0;
			while(i<len && isdigit(formula[i]))
			{
				digit_number=digit_number*10+int(formula[i++]-'0');
			}
			return digit_number;
		};
		while(i<len && formula[i]!=')')
		{
			if(formula[i]=='(')
			{
				i++;
				for(auto [atom,number]:parse(formula.substr(i)))
				{
					atom_dictionary[atom]+=number;
				}
				//i重定位
                		i+=add_pos;
			}
			else
			{
				string atom=parseatom();
				int number=parsenumber();
				atom_dictionary[atom]+=number;
			}
		}
		i++;
		int multi_factor=parsenumber();
		for(auto [atom,number]:atom_dictionary)
		{
			atom_dictionary[atom]*=multi_factor;
		}
        add_pos=i;
		return atom_dictionary;

	};
	string countOfAtoms(string formula){
		auto atom_dict=parse(formula);
		string result;
        vector<pair<string,int>> pairs;
		for(auto&[atom,number]:atom_dict)
		{
			pairs.emplace_back(atom,number);
		}
		sort(pairs.begin(),pairs.end());
		for(auto& p:pairs)
		{
			result+=p.first;
			if(p.second>1)result+=to_string(p.second);
		}
		return result;
	};
};