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
/*
Idea

If we remove any edge of the Binary Tree, we can forms: a sub-tree and its complement.
Firstly, we dfs to calculate the total sum of all nodes in the Binary Tree.
Then, we dfs in post order to calculate sum of each sub-tree in the Binary Tree.
If the sum of current sub-tree is currSum, then its complement is totalSum - currSum.
We update the answer if currSum * (totalSum - currSum) is greater than current answer.
*/

class Solution {
public:
    long long ans = 0, totalSum = 0;
    int maxProduct(TreeNode* root) {
        totalSum = dfs(root); // Firstly, get total sum of all nodes in the Binary Tree
        dfs(root); // Then dfs in post order to calculate sum of each subtree and its complement
        return ans % int(1e9+7);
    }
    
    int dfs(TreeNode* root) {
        if (root == nullptr) return 0;
        int currSum = dfs(root->left) + dfs(root->right) + root->val;
        ans = max(ans, (totalSum - currSum) * currSum);
        return currSum;
    }
};