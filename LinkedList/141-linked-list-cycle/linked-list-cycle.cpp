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
        ListNode* temp=head;
        map<ListNode*,int> mp;

        while(temp!=NULL){
            if(mp.find(temp)!=mp.end()){
                return true;
            }
            mp[temp]++;
            temp=temp->next;
        }
        return false;
    }
};