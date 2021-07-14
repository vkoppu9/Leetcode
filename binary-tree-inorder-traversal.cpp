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
    /*vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        
        stack<TreeNode*> st;
        TreeNode* curr = root;
        
        while(curr != NULL || !st.empty()) {
            
            while(curr != NULL) {
                st.push(curr);
                curr = curr->left;
            }
            
            curr = st.top();
            st.pop();
            v.push_back(curr->val);
            
            curr = curr->right;
        }
        return v;
    }*/
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
        inorder(root, nodes);
        return nodes;
    }

    void inorder(TreeNode* root, vector<int>& nodes) {
        if (root == NULL)
            return;
        
        inorder(root->left, nodes);
        nodes.push_back(root->val);
        inorder(root->right, nodes);
    }
};