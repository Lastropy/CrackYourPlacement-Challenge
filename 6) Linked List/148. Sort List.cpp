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
    static ListNode* getMiddle(ListNode* head){
        if(head == NULL || head -> next == NULL)
            return head;
        auto slow = head;
        auto fast = head;
        auto curr = head;
        while(fast && fast -> next){
            fast = fast -> next -> next;
            curr = slow;
            slow = slow -> next;
        }
        return curr;
    }
    static ListNode* merge(ListNode* l1, ListNode* l2){
        if(l1 == NULL)
            return l2;
        else if(l2 == NULL)
            return l1;
        auto curr = new ListNode();
        auto temp = curr;
        while(l1 && l2){
            if(l1 -> val < l2 -> val)
            {
                temp -> next = new ListNode(l1 -> val);
                temp = temp -> next;
                l1 = l1 -> next;
            }
            else
            {
                temp -> next = new ListNode(l2 -> val);
                temp = temp -> next;
                l2 = l2 -> next;
            }
        }
        temp -> next = (l1 != NULL)? l1 : l2;
        return curr -> next;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head -> next == NULL)
            return head;
        auto mid = getMiddle(head);
        auto right = sortList(mid-> next);
        mid -> next = NULL;
        auto left = sortList(head);
        return merge(left,right);
    }
};
