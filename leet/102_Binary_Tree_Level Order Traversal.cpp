#include <bits/stdc++.h>
using namespace std;

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>output;
        setLevelOrder(root,output);
        return output;
    }

    void setLevelOrder(TreeNode*node,vector<vector<int>>&output){
        vector<int>levelValue;
        preorder(node,levelValue);
        output.push_back(levelValue);
    }

    void preorder(TreeNode*node,vector<int>&output){
        if(node==nullptr) return;

        output.push_back(node->val);
        preorder(node->left,output);
        preorder(node->right,output);
    }
};