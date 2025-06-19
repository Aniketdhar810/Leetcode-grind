class Solution {
public:
    int func(int i,vector<int>& nums,vector<int>& dp){
        if(dp[i]!=-1) return dp[i];
        int ans=1;
        for(int j=0;j<i;j++){
            if(nums[i]>nums[j])
            ans=max(ans,func(j,nums,dp)+1);
        }
        return dp[i]=ans;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        vector<int>dp(n+1,-1);
        for(int i=0;i<n;i++){
            ans=max(func(i,nums,dp),ans);
        }
        return ans;
    }
};