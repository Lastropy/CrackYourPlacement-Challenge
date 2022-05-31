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
    static ListNode* reverseList(ListNode* head) {
        if(head == NULL || head -> next == NULL)
            return head;
        ListNode* prev = NULL;
        auto curr = head;
        auto nxt = head -> next;
        while(curr){
            curr -> next = prev;
            prev = curr;
            curr = nxt;
            if(nxt)
                nxt = nxt -> next;
        }
        return prev;
    }
    static ListNode* getNode(ListNode* a, int c){
        auto temp = a;
        for(int i  = 1; i < c; i++)
            temp = temp -> next;
        return temp;
    }
    ListNode* reverseBetween(ListNode* head, int l, int r) {
        if(l == r || head -> next == NULL)
            return head;
        auto left = getNode(head,l);
        auto right = getNode(head,r);
        ListNode* prev = NULL;
        auto curr = head;
        while(curr != left){
            prev = curr;
            curr = curr -> next;
        }
        auto end = right -> next;
        right -> next = NULL;
        if(prev)
            prev -> next = reverseList(left);
        else
            head = reverseList(left);
        left -> next = end;
        return head;
    }
};
