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
    //  https://leetcode.com/problems/merge-two-sorted-lists/
    // 2 pointer.
    // Using dummy node to go next everytime.
    // return dummy -> next;
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL && list2 == NULL)
            return NULL;
        else if( list1 == NULL)
            return list2;
        else if(list2 == NULL)
            return list1;
        auto dummy = new ListNode();
        auto temp = dummy;
        while(list1 && list2){
            if(list1 -> val == list2 -> val){
                temp -> next = new ListNode(list1 -> val);
                temp -> next -> next = new ListNode(list2 -> val);
                temp = temp -> next -> next;
                list1 = list1 -> next;
                list2 = list2 -> next;
            }
            else if(list1 -> val < list2 -> val){
                temp -> next = new ListNode(list1 -> val);
                temp = temp -> next;
                list1 = list1 -> next;
            }
            else {
                temp -> next = new ListNode(list2 -> val);
                temp = temp -> next;
                list2 = list2 -> next;
            }
        }
        while(list1){
            temp -> next = new ListNode(list1 -> val);
                temp = temp -> next;
                list1 = list1 -> next;
        }
        while(list2){
            temp -> next = new ListNode(list2 -> val);
                temp = temp -> next;
                list2 = list2 -> next;
        }
        return dummy -> next;
    }
};
