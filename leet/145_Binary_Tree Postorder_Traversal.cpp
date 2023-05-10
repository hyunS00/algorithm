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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> output;
        postorder(root,output);
        return output;
    }

    void postorder(TreeNode*node,vector<int>&output){
        if(node==nullptr) return;
        postorder(node->left,output);
        postorder(node->right,output);
        output.push_back(node->val);
    }
};