#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
	public:
	 vector<int> pathInZigZagTree(int label)
	 {
		 vector<int> ans;
		 while(label){
			 ans.push_back(label);
			 label>>=1;
		 }
		 reverse(ans.begin(),ans.end());
		 int left,right,deep=ans.size();
		 for(int i=0;i<deep;i++)
		 {
			 if((deep&1) != (i&1))continue;
			 left=(1<<i);
			 right=left+left-1;
			 ans[i]=right-ans[i]+left;
		 }
		 return ans;
	 }
};