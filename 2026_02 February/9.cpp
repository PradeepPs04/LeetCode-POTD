// https://leetcode.com/problems/balance-a-binary-search-tree/?envType=daily-question&envId=2026-02-09

class Solution {
private:
    void inorder(TreeNode* root, vector<int>& arr) {
        if(!root)   return;

        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }

    TreeNode* buildBalanceBST(int left, int right, vector<int>& arr) {
        // no nodes remaining
        if(left > right)    return nullptr;
        
        // only one node remaining
        if(left == right)   return new TreeNode(arr[left]);

        // create root using middle value
        int mid = left + (right - left) / 2;
        TreeNode *root = new TreeNode(arr[mid]);

        // build left sub-tree using values from left to mid-1
        root->left = buildBalanceBST(left, mid - 1, arr);

        // build right sub-tree using values from mid+1 to right
        root->right = buildBalanceBST(mid + 1, right, arr); 

        // return root
        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        // get sorted array using inroder traversal
        vector<int>arr;
        inorder(root, arr);

        // recursively build balanc BST
        return buildBalanceBST(0, arr.size()-1, arr);
    }
};