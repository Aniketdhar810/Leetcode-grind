/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 #include<bits/stdc++.h>
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // ListNode* temp=head;
        // map<ListNode*,int> mp;

        // while(temp!=NULL){
        //     if(mp.find(temp)!=mp.end()){
        //         return true;
        //     }
        //     mp[temp]++;
        //     temp=temp->next;
        // }
        // return false;
        ListNode* slowp=head;
        ListNode* fastp=head;
        while(fastp!=NULL && fastp->next!=NULL){
            slowp=slowp->next;
            fastp=fastp->next->next;
            if(slowp==fastp){
                return true;
            }
        }
        return false;
    }
};