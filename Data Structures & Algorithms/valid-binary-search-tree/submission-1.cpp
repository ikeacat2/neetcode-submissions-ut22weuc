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

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        //recursive solution 
        //base case: current pointer = null (end of subtree)
        return helperFunct(root, LLONG_MIN, LLONG_MAX);
    }
    bool helperFunct(TreeNode* root, long long minV, long long maxV) {
        if(!root) {
            return true;
        }
        if (root->val <= minV || root->val >= maxV)
            return false;
        
        return helperFunct(root->left, minV, root->val) && helperFunct(root->right, root->val, maxV);
    }
};
