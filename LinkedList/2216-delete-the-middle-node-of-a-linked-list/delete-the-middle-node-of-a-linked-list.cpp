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
    // ListNode* deleteNode(ListNode* node,ListNode* head){
    //     ListNode* temp=head;
    //     ListNode* prev=NULL;
    //     while(temp!=NULL){
    //         if(node==temp){
    //             prev->next=temp->next;
    //             node->next=NULL;
    //             delete(node);
    //             return head;
    //         }
    //         prev=temp;
    //         temp=temp->next;
    //     }
    //     return 0;
    // }

    ListNode* deleteMiddle(ListNode* head) {
        if(head==nullptr){
            return nullptr;
        }
        if(head->next==nullptr ||head==nullptr){
            return NULL;
        }
        ListNode* fastp=head;
        ListNode* slowp=head;
        fastp = head->next->next;
        while(fastp!=nullptr && fastp->next!=nullptr){
            slowp=slowp->next;
            fastp=fastp->next->next;
        }
        slowp->next=slowp->next->next;
        return head;
    }
};