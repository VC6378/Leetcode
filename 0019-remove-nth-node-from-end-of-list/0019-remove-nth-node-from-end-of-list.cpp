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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL || head->next==NULL) return NULL;
        int cnt=0;
        ListNode *curr=head;
        while(curr){
            cnt++;
            curr=curr->next;
        }
        int front = cnt-n+1;
        curr=head;
        ListNode *prev=NULL;
        int i=1;
        if(cnt-n<0) return NULL;
        if(cnt-n==0) return head->next;


        while(i<front){
            i++;
            prev=curr;
            curr=curr->next;
        }

        if(curr->next){
            prev->next=curr->next;
        }
        else prev->next=NULL;
        delete(curr);
        return head;
    }
};