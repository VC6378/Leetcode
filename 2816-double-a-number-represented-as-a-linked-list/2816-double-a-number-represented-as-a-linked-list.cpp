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
    ListNode* doubleIt(ListNode* head) {
        ListNode *curr=head;
        vector<int> temp;
        while(curr){
            temp.push_back(curr->val);
            curr=curr->next;
        }
        int carry=0;
        reverse(temp.begin(),temp.end());
        for(int i=0;i<temp.size();i++){
            int data=temp[i];
            int dou=data*2;
            dou+=carry;
            carry=dou/10;
            temp[i]=dou%10;
        }
        if(carry!=0) temp.push_back(carry);
        reverse(temp.begin(),temp.end());
        ListNode *dummy=new ListNode(-1);
        ListNode *tail=dummy;
        for(int i=0;i<temp.size();i++){
            ListNode *node=new ListNode(temp[i]);
            tail->next=node;
            tail=tail->next;
        }
        return dummy->next;
    }
};