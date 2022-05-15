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
    // https://leetcode.com/problems/remove-linked-list-elements/
    // First, if head is null, return null
    // Second, if head -> val == val, skip ahead and deallocate       // until head -> val != null ORRRR head == null
    // Third, while start and start -> next != null,
    // keep checking for duplicates. if found, skip and deallocate 
    // memory, else move ahead;
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL)
            return head;
        while(head && head -> val == val)
        {
            auto temp = head;
            head =  head -> next;
            delete temp;
        }
        auto start = head;
        while(start && start -> next){
            if(start -> next -> val == val){
                auto temp = start -> next;
                start -> next = start -> next -> next;
                delete temp;
            }
            else{
               start = start -> next;
            }
        }
        return head;
    }
};
