class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxi=-1;
        int n=nums.size();
        int loc=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]>loc) maxi=max(maxi,nums[i]-loc);
            else loc=nums[i];
        }
        return maxi;
    }
};