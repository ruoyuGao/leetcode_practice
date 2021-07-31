#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
class Solution {
public:
    map<int,map<int,vector<int>>> mp;
    void DFS(TreeNode* node,int column,int row){
        if(node==nullptr)return;
        mp[column][row].push_back(node->val);
        DFS(node->left,column-1,row+1);
        DFS(node->right,column+1,row+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        DFS(root,0,0);
        vector<vector<int>> result;
        for(auto &from_column:mp)
        {
            vector<int> temp;
            for(auto &from_row:from_column.second)
            {
                sort(from_row.second.begin(),from_row.second.end());
                temp.insert(temp.end(),from_row.second.begin(),from_row.second.end());
            }
            result.push_back(temp);
            temp.clear();
        }
        return result;
    }
};