// https://leetcode.com/problems/balanced-binary-tree/description/?envType=daily-question&envId=2026-02-08

class Solution {
private:
    int balanceHeight(TreeNode *root) {
        if(!root)   return 0;

        int left = balanceHeight(root->left);
        int right = balanceHeight(root->right);

        if(left == -1 || right == -1)   return -1;

        if(abs(left - right) > 1)   return -1;

        return 1 + max(left, right);
    }
public:
    bool isBalanced(TreeNode* root) {
        return balanceHeight(root) != -1;
    }
};