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
    int maxDepth(TreeNode* root) {
        /* //bfs
        if(root == nullptr) {
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        count = 1;
        while(!q.empty()) {
            TreeNode* current = q.pop();
            if(current->left != nullptr) {
                q.push(current->left);
            }
            if(current->right != nullptr) {
                q.push(current->right);
            }
        }
        
        return count; */
        
        //recursive method 
        if(root == nullptr) {
            return 0;
        }
        return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
    }
};
