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
    ListNode* insert_Node(ListNode* temp,ListNode*newNode){
        newNode->next=temp->next;
        temp->next=newNode;
        return newNode->next;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp=head;
        if(temp==NULL||temp->next==NULL){
            return head;
        }
        while(temp!=NULL&&temp->next!=NULL){
            ListNode* newNode=new ListNode();
            newNode->val=__gcd(temp->val,temp->next->val);
            temp=insert_Node(temp,newNode);
        }
        return head;
    }
};