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
        ListNode* slowp=head;
        ListNode* fastp=head;
        while(fastp!=NULL && fastp->next!=NULL){
            slowp=slowp->next;
            fastp=fastp->next->next;
            if(slowp==fastp){
                slowp=head;
                while(slowp!=fastp){
                    slowp=slowp->next;
                    fastp=fastp->next;
                }
                return slowp;
            }   
        }
        return NULL;
    }
};