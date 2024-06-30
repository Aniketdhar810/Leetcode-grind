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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        // vector<int> arr;
        // ListNode* temp=head;
        // // even indices
        // while(temp!=NULL && temp->next!=NULL){
        //     arr.push_back(temp->val);
        //     temp=temp->next->next;
        // }
        // //leftover elements
        // if(temp) arr.push_back(temp->val);
        // //odd indices
        // temp=head->next;
        // while(temp!=NULL && temp->next!=NULL){
        //     arr.push_back(temp->val);
        //     temp=temp->next->next;
        // }
        // if(temp) arr.push_back(temp->val);
        // //pushing it to LL from arr
        // temp=head;
        // for(int i=0;i<arr.size();i++){
        //     temp->val=arr[i];
        //     temp=temp->next;
        // }
        // return head;
        ListNode* odd=head;
        ListNode* even=head->next;
        ListNode* evenhead=head->next;
        while(even!=NULL && even->next!=NULL){
            odd->next=odd->next->next;
            even->next=even->next->next;

            odd=odd->next;
            even=even->next;
        }
        odd->next=evenhead;
        return head;
    }
};