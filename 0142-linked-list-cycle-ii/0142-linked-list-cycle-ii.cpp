/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow) break;
        }
        if(fast==NULL or fast->next==NULL) return NULL;
        ListNode *curr=head;
        while(curr!=slow){
            curr=curr->next;
            slow=slow->next;
        }
        return slow;
    }
};