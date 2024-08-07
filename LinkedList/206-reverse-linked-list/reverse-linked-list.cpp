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
        if(head==NULL || head->next==NULL){
            return head;
        }
        // stack<int>stk;
        // ListNode* temp=head;
        // while(temp!=NULL){
        //     stk.push(temp->val);
        //     temp=temp->next;
        // }
        // temp=head;
        // while(temp!=NULL){
        //     // temp->val=stk.pop(); does ot return anything
        //     temp->val=stk.top();
        //     stk.pop();
        //     temp=temp->next;
        // }
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp!=NULL){
            ListNode* front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;   
        } 
        return prev;
    }
};