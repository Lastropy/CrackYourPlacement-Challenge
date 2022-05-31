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
    static int count(ListNode* a){
        int c = 0;
        while(a){
            c++;
            a = a -> next;
        }
        return c;
    }
    static ListNode* BubbleSort(ListNode* head,int c){
        if(head ==  NULL || head -> next == NULL)
            return head;
        ListNode* prev = NULL;
        auto f = head;
        auto s = head -> next;
        auto forw = head -> next -> next;
        while(--c){
            if(f-> val > s -> val){
                    s -> next = f ;
                    f-> next = forw; 
                    if(prev != NULL)
                        prev -> next= s;
                    else
                        head = s;
                    auto temp = s;
                    s = f;
                    f = temp;
            }
            prev = f;
            f = f -> next;
            s = s -> next;
            if(s)
                forw = s -> next;
        }
        return head;
    }
    ListNode* sortList(ListNode* head) {
        int c = count(head);
        while(c--)
            head = BubbleSort(head,c+1);
        return head;
    }
};
