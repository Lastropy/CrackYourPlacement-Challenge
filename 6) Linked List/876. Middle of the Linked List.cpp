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
    //https://leetcode.com/problems/middle-of-the-linked-list/
    // two pass traversal
    ListNode* middleNode(ListNode* head) {
        int n = 0;
        ListNode* start = head;
        while(start != NULL)
        {
            start = start -> next;
            n++;
        }
        n /= 2;
        start = head;
        while(n--){
            start = start -> next;
        }
        return start;
    }
};
