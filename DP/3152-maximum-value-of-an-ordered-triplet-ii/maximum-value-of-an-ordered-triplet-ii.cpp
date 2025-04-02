class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        int lmax=nums[0];
        vector<int>rmax(n,0);
        rmax[n-2]=nums[n-1];
        //find rmax for j from j+1 to n-1;
        for(int j=n-3;j>=0;j--){
            rmax[j]=max(rmax[j+1],nums[j+1]);
        }
        for(int j=1;j<n-1;j++){
            long long temp=(1LL*(lmax-nums[j])*rmax[j]);
            ans=max(ans,temp);
            if(j<n-2)lmax=max(nums[j],lmax);
        }
        return ans;
    }
};