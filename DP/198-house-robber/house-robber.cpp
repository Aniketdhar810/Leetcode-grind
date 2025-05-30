class Solution {
public:
    int rec(vector<int>& arr,vector<int>& dp, int index){
        if(index<0) return 0;
        if(index==0) return arr[index];
        if(dp[index]!=-1) return dp[index];
        int pick=arr[index]+rec(arr,dp,index-2);
        int notpick=rec(arr,dp,index-1);
        return dp[index]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return rec(nums,dp,n-1);
    }
};