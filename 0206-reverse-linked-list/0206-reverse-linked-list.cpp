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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL or head->next==NULL) return head;
        ListNode *curr=head;
        ListNode *nex=head->next;
        ListNode *prev=NULL;
        while(curr){
            curr->next=prev;
            prev=curr;
            curr=nex;
            if(nex){
                nex=nex->next;
            }
        }
        return prev;
    }
};