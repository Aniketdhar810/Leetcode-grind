class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=-1;
        int sum=0;
        if(nums.size()==1) return nums[0];
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum<0) sum=0;
            ans=max(sum,ans);
        }
        if(ans==0) return *max_element(nums.begin(),nums.end());
        return ans;
    }
};