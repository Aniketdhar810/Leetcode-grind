class Solution {
public:
    int rec(vector<int>& arr,map<int,int>& mp,vector<int>& dp,int index){
        if(index<0) return 0;
        if(dp[index]!=-1) return dp[index];
        int idx;
        if(index!=0 && arr[index-1]==arr[index]-1) idx=index-2;
        else idx=index-1;
        int pick=arr[index]*mp[arr[index]] +rec(arr,mp,dp,idx);
        int skip=rec(arr,mp,dp,index-1);
        return dp[index]=max(pick,skip);
    }
    int deleteAndEarn(vector<int>& nums) {
        vector<int>arr;
        set<int>st(nums.begin(),nums.end());
        for(auto it:st) arr.push_back(it);
        map<int,int>mp;
        for(int i=0;i<nums.size();i++) mp[nums[i]]++;
        int n=arr.size();
        vector<int>dp(n,-1);
        return rec(arr,mp,dp,n-1);
    }
};