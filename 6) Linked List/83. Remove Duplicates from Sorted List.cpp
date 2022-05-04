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
    // 2 pointers -> skip till duplicates found
    // once out of loop -> start.next = NULL as start is the last non-duplicate Node.
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head -> next == NULL)
            return head;
        ListNode* start = head;
        ListNode* move = head -> next;
        while(move){
            if(start -> val == move -> val){
                move = move -> next;
                continue;
            }
            start -> next = move;
            start = move;
            move = move -> next;
        }
        start -> next = NULL;
        return head;
    }
};
