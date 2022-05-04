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
        auto start = head;
        while(start -> next){
            if(start -> val == start -> next -> val){
                auto duplicate = start -> next;
                start -> next = start -> next -> next;
                delete duplicate;
            }
            else
                start = start -> next;
        }
        return head;
    }
};
