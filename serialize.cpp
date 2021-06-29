#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;
//垃圾题目：https://leetcode-cn.com/problems/xu-lie-hua-er-cha-shu-lcof/
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Codec{
	public:
	string serialize(TreeNode* root){
		string tree;
		string temp1("");
		queue<TreeNode*> q;
		q.emplace(root);
		while(!q.empty()){
			auto temp=q.front();
			int node=temp->val;
			tree.push_back(char(node+'0'));
			tree.push_back(',');
			q.pop();
			if((temp->left!=nullptr || temp->right!=nullptr) && q.empty()) tree+=temp1;
			if(temp->left==nullptr)
			{
				temp1+="null,";
			}
			else
			{
				auto leftNode=temp->left;
				q.emplace(leftNode);
			}
			if(temp->right==nullptr)
			{
				temp1+="null,";
			}
			else
			{
				auto rightNode=temp->right;
				q.emplace(rightNode);
			}
			
		}
		return tree;
	}
	
};
//究极逃课绝了
class Codec2 {
public:
    string serialize(TreeNode* root) {
        return to_string((unsigned long)root);
    }

    TreeNode* deserialize(string data) {
        return (TreeNode*)stol(data);
    }
};