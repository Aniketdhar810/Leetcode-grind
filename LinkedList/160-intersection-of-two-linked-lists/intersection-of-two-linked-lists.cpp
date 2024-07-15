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
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode* ,int>mp;
        ListNode* temp=headA;
        while(temp!=NULL){
            mp[temp]++;
            temp=temp->next;
        }
        ListNode* temp2=headB;
        while(temp2!=NULL){
            if(mp.find(temp2)!=mp.end()){
                return temp2;
            }
            temp2=temp2->next;
        }
        return NULL;
    }
};