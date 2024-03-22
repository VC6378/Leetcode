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
    ListNode *rev(ListNode *head){
        ListNode *p=NULL, *c=head, *n=head->next;
        while(c!=NULL){
            c->next=p;
            p=c;
            c=n;
            if(n!=NULL){
                n=n->next;
            }
        }
        return p;
    }

    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode *slow=head, *fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *nextHead = rev(slow->next);
        slow->next=nextHead;
        ListNode *start=head;
        ListNode *mid=nextHead;
        while(mid!=NULL){
            if(start->val != mid->val){
                return false;
                // break;
            }
            else{
                start=start->next;
                mid=mid->next;
            }
        }
        return true;
    }
};