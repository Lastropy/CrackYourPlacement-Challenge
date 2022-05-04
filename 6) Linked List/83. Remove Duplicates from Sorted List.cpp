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
    // https://leetcode.com/problems/remove-duplicates-from-sorted-list/submissions/
    // 1 pointers -> skip till duplicates found
    // free memory at end
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head -> next == NULL)
            return head;
        ListNode* start = head;
        while(start){
            while(start -> next && start -> val == start -> next -> val){
                start -> next = start -> next -> next;
            }
            start = start -> next;
        }
        delete start;
        return head;
    }
};
