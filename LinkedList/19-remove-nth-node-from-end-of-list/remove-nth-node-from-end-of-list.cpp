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
    ListNode* deleteHeadnode(ListNode* head){
    //empty ll
    if(head==NULL) return head;
    ListNode* temp=head;
    //new head pointing to next element
    head=head->next;
    delete temp;
    return head;
    }

    int lengthofll(ListNode* head){
    int count=0;
    ListNode* temp=head;
    while(temp){
        temp=temp->next;
        count++;
    }
    return count;
    }

    ListNode* deletek(ListNode* head,int k){
    if(head==NULL) return head;
    if(k==1){
        return deleteHeadnode(head);
    }
    int cnt=0;
    ListNode* temp=head;
    ListNode* prev=NULL;
    while(temp!=NULL){
        cnt++;
        if(cnt==k){
            prev->next=prev->next->next;
            delete(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
    
}

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count=lengthofll(head);
        count=count-n+1;
        return deletek(head,count);
    }
};