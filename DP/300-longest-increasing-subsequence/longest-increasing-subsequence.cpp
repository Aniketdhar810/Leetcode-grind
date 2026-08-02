class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // int n=nums.size();
        // vector<int>dp(n,-1);
        // int maxi=1;
        // dp[0]=1;
        // for(int i=1;i<n;i++){
        //     int add=0;
        //     for(int j=0;j<i;j++){
        //         if(nums[j]<nums[i]){
        //             add=max(add,dp[j]);
        //         }
        //     }
        //     dp[i]=1+add;
        //     maxi=max(maxi,dp[i]);
        // }
        // return maxi;
        vector<int>fred_again;
        for(int x:nums){
            auto it=lower_bound(fred_again.begin(),fred_again.end(),x);
            if(it==fred_again.end()) fred_again.push_back(x);
            else *it=x;
        }
        return fred_again.size();
    }
};