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
    static int count(ListNode* head){
        auto t = head;
        int c =0;
        while(t){
            t = t-> next;
            c++;
        }
        return c;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int c = count(head);
        int pos = c - n;
        if(pos == 0)
            return head -> next;
        auto prev = head;
        auto curr = head -> next;
        c = 1;
        while(c < pos){
            c++;
            prev= curr;
            curr = curr -> next;
        }
        auto temp = curr;
        prev -> next = curr -> next;
        delete temp;
        return head;
    }
};
