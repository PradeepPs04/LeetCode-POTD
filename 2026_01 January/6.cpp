// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/?envType=daily-question&envId=2026-01-06

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode *>q;
        q.push(root);

        int maxiSum = INT_MIN;
        int level = 1;
        int ans = 1;

        while(!q.empty()) {
            int sum = 0;
            int size = q.size();
            for(int i = 0; i < size; i++) {
                TreeNode *node = q.front();
                q.pop();

                sum += node->val;
                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
            }

            if(sum > maxiSum) {
                maxiSum = sum;
                ans = level;
            }

            level++;
        }

        return ans;
    }
};