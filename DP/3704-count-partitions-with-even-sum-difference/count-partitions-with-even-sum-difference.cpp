class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int total=0;
        for(int num:nums) total+=num;
        int lsum=0;
        for(int i=0;i<n-1;i++){
            lsum+=nums[i];
            int rsum=total-lsum;
            if((abs(lsum-rsum))%2==0) ans++;
        }
        return ans;
    }
};