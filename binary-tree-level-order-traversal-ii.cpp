/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode *> q;
        if(root == NULL) 
            return res;
        q.push(root);
        while(!q.empty()) {
            int s = q.size();
            vector<int> temp;
            for(int i = 1; i <= s; i++) {
                TreeNode *curr = q.front();    
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
                temp.push_back(curr->val);
                q.pop();
            }
            res.push_back(temp);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};