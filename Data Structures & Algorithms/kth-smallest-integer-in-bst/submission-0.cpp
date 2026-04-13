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
    int kthSmallest(TreeNode* root, int k) {
        std::vector<int> v;
        std::set<int> s;
        stack<TreeNode*> t; //used for traversal
        t.push(root);
        s.insert(root->val);
        while(!t.empty()) {
            root = t.top();
            t.pop();
            v.push_back(root->val);
            if(root->right) {
                if(!s.contains(root->right->val)) {
                    t.push(root->right);
                    s.insert(root->right->val);
                }
            }
            if(root->left) {
                if(!s.contains(root->left->val)) {
                    t.push(root->left);
                    s.insert(root->left->val);
                }
            }
        }
        sort(v.begin(), v.end());
        for(int i : v) {
            std::cout << i << "\n";
        }
        if(v.size() >= k) {
            return v[k-1];
        }
        return -1;

        //can do this recusively instead and after the root subtract one from k each time 
        /*
        if(!root) {
            return 0;
        }
        if(!root->left && !root->right) {
            if(k == 1 && root) {
                k--;
                return root->val;
            }
            else {
                k--;
                return 0;
            }
        }
        return kthSmallest(root->left, k) + kthSmallest(root->right, k); */
    }
};
