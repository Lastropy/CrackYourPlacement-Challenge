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
    static ListNode* rev(ListNode* head){
        if(head == NULL || head -> next == NULL)
            return head;
        auto curr = head;
        ListNode* prev = NULL;
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
    static ListNode* mid(ListNode* head){
        if(head == NULL || head -> next == NULL)\
            return head;
        auto slow = head;
        auto fast = head;
        ListNode* prev = NULL;
        while(fast && fast -> next){
            prev = slow;
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        prev -> next = NULL;
        return slow;
    }
    static void append(ListNode* head, ListNode* mi){
        auto temp = head;
        while(temp -> next)
            temp = temp -> next;
        temp -> next = mi;
    }
    void reorderList(ListNode* head) {
      
        if(head == NULL || head -> next == NULL)
            return;
        auto mi = rev(mid(head));
        auto curr = head;
        while(mi && curr)
        {
            auto temp = curr -> next;
            auto temp2 = mi -> next;
            curr -> next = mi;
            mi -> next = temp;
            mi = temp2;
            curr = temp;
        }
        if(mi)
            append(head,mi);
    }
};
