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
    void reorderList(ListNode* head) {
        if((head==NULL) or (head->next==NULL) or (head->next->next==NULL)){
            return;
        }
        stack<ListNode *> st;
        ListNode *curr=head;
        int n=0;
        while(curr!=NULL){
            st.push(curr);
            n++;
            curr=curr->next;
        }
        ListNode *ptr=head;
        for(int i=0;i<n/2;i++){
            ListNode *ele = st.top();
            st.pop();
            ele->next=ptr->next;
            ptr->next=ele;
            ptr=ptr->next->next;
        }
        ptr->next=NULL;
    }
};