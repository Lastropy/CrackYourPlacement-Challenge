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
    ListNode* deleteDuplicates(ListNode* head) {
        auto curr = head;
        ListNode* prev = NULL;
        while(curr && curr -> next){
            if(curr -> val == curr -> next -> val)
            {
                while(curr && curr -> next && curr -> val == curr -> next -> val){
                    auto temp1 = curr;
                    curr = curr -> next;
                    delete temp1;
                }
                if(curr){
                    auto temp1 = curr;
                    curr = curr -> next;
                    delete temp1;
                }
            }
            else{
                prev = curr;
                curr = curr -> next; 
            }
            if(prev)
                prev -> next = curr;
            else
                head = curr;
           
        }
        return head;
    }
};
