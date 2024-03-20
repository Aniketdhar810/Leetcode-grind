#include <bits/stdc++.h>

class Solution {
    int day(vector<int> &weights,int c){
    int days=1,load=0;
    int n=weights.size();
    for(int i=0;i<n;i++){
        if(load+weights[i]>c){
            days++;
            load=weights[i];
        }
        else{
            load+=weights[i];
        }
    }
    return days;
}
int s(vector<int>&weights){
    int n=weights.size(),sum=0;
    for(int i=0;i<n;i++){
        sum+=weights[i];
    }
    return sum;
}
public:


    int shipWithinDays(vector<int>& weights, int days) {
    // Write your code here.
    int low=*max_element(weights.begin(),weights.end());
    int high=s(weights);
    while(low<=high){
        int mid=(low+high)/2;
        int dayReq=day(weights,mid);
        if(dayReq<=days){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return low;
}
};