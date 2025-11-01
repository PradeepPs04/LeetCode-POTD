// https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/?envType=daily-question&envId=2025-11-01

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int, int>mpp;
        for(auto it:nums)   mpp[it] = 1;

        ListNode *itr = head;
        ListNode *dummy = new ListNode(-1);
        ListNode *ans = dummy;
        while(itr) {
            if(!mpp[itr->val])  {
                ans->next = new ListNode(itr->val);
                ans = ans->next;
            }
            itr = itr->next;
        }

        ans = dummy->next;
        delete dummy;

        return ans;
    }
};