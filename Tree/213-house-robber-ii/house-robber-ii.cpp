class Solution {
public:
    int rec1(vector<int>& arr,vector<int>& dp, int index){
        if(index<1) return 0;
        if(index==0) return arr[index];
        if(dp[index]!=-1) return dp[index];
        int pick=arr[index]+rec1(arr,dp,index-2);
        int notpick=rec1(arr,dp,index-1);
        return dp[index]=max(pick,notpick);
    }
    int rec2(vector<int>& arr,vector<int>& dp, int index){
        if(index<0) return 0;
        if(index==0) return arr[index];
        if(dp[index]!=-1) return dp[index];
        int pick=arr[index]+rec2(arr,dp,index-2);
        int notpick=rec2(arr,dp,index-1);
        return dp[index]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> dp1(n,-1);
        vector<int> dp2(n,-1);
        int ans1=rec1(nums,dp1,n-1);
        int ans2=rec2(nums,dp2,n-2);
        return max(ans1,ans2);
    }
};