#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
//方法错误，应该改进为建图之后DFS或BFS
struct TreeNode {

     int val;
     TreeNode *left;
     reeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution{
	int layer=0;
   	vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        	queue<pair<TreeNode*,int>> q;
		unordered_map<int,vector<int>> mp;
		vector<int> result;
		int target_layer=INT_MAX-100;
        	q.push({root,layer});
		while(!q.empty())
		{
			std::tie(root,layer)=q.front();
			q.pop();
			if(root==target)target_layer=layer;
			if(layer>target_layer+k)break;
			mp[layer].push_back(root->val);
			if(root->left!=nullptr)q.push({root->left,layer+1});
			if(root->right!=nullptr)q.push({root->right,layer+1});
		}
		if(mp.count(target_layer-k))result.insert(result.end(),mp[target_layer-k].begin(),mp[target_layer-k].end());
		if(mp.count(target_layer+k))result.insert(result.end(),mp[target_layer+k].begin(),mp[target_layer+k].end());
		return result;
    }

};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//DFS建图+BFS行走
class Solution1 
{
public:
    unordered_map<TreeNode *, TreeNode *> node_parent;

    //---------- 找到每个非空结点的父节点。本质是完善 邻接表
    void dfs_find_node_parent(TreeNode * node)
    {
        if (node)
        {
            if (node->left)
                node_parent[node->left] = node;
            if (node->right)
                node_parent[node->right] = node;
            dfs_find_node_parent(node->left);
            dfs_find_node_parent(node->right);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        dfs_find_node_parent(root);

        if (k == 0)
            return vector<int> {target->val};
        
        vector<int> res;
        //------------------------- bfs波纹法。先visit和先判只适应于0 < k的情况
        queue<TreeNode *> Q;
        unordered_set<TreeNode *> visited;
        Q.push(target);
        visited.insert(target);
        int level = 0;
        while (!Q.empty() && level < k)
        {
            level ++;
            int cur_len = (int)Q.size();
            for (int _ = 0; _ < cur_len; _ ++)
            {
                TreeNode * x = Q.front();    Q.pop();
                for (TreeNode* y : vector<TreeNode*> {node_parent[x], x->left, x->right})
                {
                    if (y && visited.find(y) == visited.end())
                    {
                        if (level == k)
                            res.push_back(y->val);
                        visited.insert(y);
                        Q.push(y);
                    }
                }
            }
        }
        
        return res;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//2*DFS, DFS开图+DFS检索
class Solution2 
{
public:
    int k;
    unordered_map<TreeNode *, TreeNode *> node_parent;
    vector<int> res;

    //---------- 找到每个非空结点的父节点。本质是完善 邻接表
    void dfs_find_node_parent(TreeNode * node)
    {
        if (node)
        {
            if (node->left)
                node_parent[node->left] = node;
            if (node->right)
                node_parent[node->right] = node;
            dfs_find_node_parent(node->left);
            dfs_find_node_parent(node->right);
        }
    }

    void dfs_get_res(TreeNode * node, TreeNode * prev, int cur_dist)
    {
        if (node)
        {
            if (cur_dist == k)
            {
                res.push_back(node->val);
                return;
            }
            if (node_parent[node] != prev)
                dfs_get_res(node_parent[node], node, cur_dist + 1);
            if (node->left != prev)
                dfs_get_res(node->left, node, cur_dist + 1);
            if  (node->right != prev)
                dfs_get_res(node->right, node, cur_dist + 1);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        this->k = k;
        dfs_find_node_parent(root);
        dfs_get_res(target, NULL, 0);
        return res;
    }
};
