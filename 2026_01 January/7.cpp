// https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/description/?envType=daily-question&envId=2026-01-07

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
private:
    int getSum(TreeNode* root) {
        if(!root)   return 0;
        
        int left = getSum(root->left);
        int right = getSum(root->right);
        return left + right + root->val;
    }

    int dfs(TreeNode *root, int tree_sum, long long &ans) {
        if(!root)   return 0;

        int left = dfs(root->left, tree_sum, ans);
        int right = dfs(root->right, tree_sum, ans);

        int sub_tree_sum = left + right + root->val;
        int remaining_tree_sum = tree_sum - sub_tree_sum;

        long long product = (long long)sub_tree_sum  * (long long)remaining_tree_sum;

        ans = max(product, ans);

        return sub_tree_sum;
    }
public:
    int maxProduct(TreeNode* root) {
        int tree_sum = getSum(root);
        long long ans = 0;
        dfs(root, tree_sum, ans);

        int modd = 1e9 + 7;
        return (int)(ans % modd);
    }
};