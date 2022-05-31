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
        int c = 0;
        while(t){
            t = t -> next; 
            c++;
        }
        return c;
    }
    static void print(ListNode* a){
        auto t = a;
        while(t){
            cout << t-> val << ",";
            t = t -> next;
        }
        cout << endl;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head -> next == NULL || k == 1 )
            return head;
        auto curr = head-> next;
        auto next = head -> next -> next;
        ListNode* prev = head;
        ListNode* newstart = NULL;
        int number_of_times = count(head)/k;
        while(number_of_times--){
            for(int i = 1; curr && i <= k-1; i++){
                curr -> next = prev;
                prev = curr;
                curr = next;
                if(next)
                    next = next -> next;
            }
            if(newstart){
                auto temp = newstart -> next;
                newstart -> next -> next = curr;
                newstart -> next = prev;
                newstart = temp;
            }
            else{
                head -> next = curr;
                newstart = head;
                head = prev;
            }
            prev = curr;
            curr = next;
            if(next)
                next = next -> next;
        }
        return head;
    }
};
