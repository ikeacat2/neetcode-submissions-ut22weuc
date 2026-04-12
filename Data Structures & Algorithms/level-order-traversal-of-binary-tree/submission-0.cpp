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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levels;
        //null root safety check 
        if(!root) {
            return levels;
        }

        stack<pair<TreeNode*, int>> s;
        vector<pair<TreeNode*, int>> nodes;

        s.push({root, 0});

        //number all roots by level
        while(!s.empty()) {
            pair<TreeNode*, int> c = s.top();
            s.pop();
            nodes.push_back(c);
            TreeNode* current = c.first;
            int count = c.second;
            if(current->right) {
                s.push({current->right, count+1});
            }
            if(current->left) {
                s.push({current->left, count+1});
            }
        }
        //traverse list of roots and sort by level 
        for(int i = 0; i < nodes.size(); i++) {
            TreeNode* current = nodes[i].first;
            int level = nodes[i].second;
            //add to levels based on level index 
            //make sure vector is big enough 
            if(levels.size() == level) {
                levels.push_back({});
            }
            levels[level].push_back(current->val);
        }
        return levels;
        
    }
};

