/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        // https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
        // bit manipulation
        int ans = 0;
        ListNode* start = head;
        while(start)
        {
            ans = (ans << 1)+(start -> val);
            start = start -> next;
        }
        return ans;
    }
};
