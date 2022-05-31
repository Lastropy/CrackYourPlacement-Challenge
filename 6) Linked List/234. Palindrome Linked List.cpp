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
    static  ListNode* rev(ListNode* head){
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
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head -> next == NULL)
            return true;
        auto slow = head;
        auto fast = head;
        ListNode* prev = NULL;
        while(fast && fast -> next){
            prev = slow;
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        prev -> next = NULL;
        slow = rev(slow);
        fast = head;
        while(slow && fast)
        {
            if(slow -> val != fast -> val)
                return false;
            slow = slow -> next;
            fast = fast -> next;
        }
        return true;
    }
};
