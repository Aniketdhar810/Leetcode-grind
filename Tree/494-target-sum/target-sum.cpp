class Solution {
public:
    int ans=0;
    void rec(vector<int>& nums,int target,int index,int sum){
        if(index==nums.size() && sum==target){ans++; return;}
        else if(index==nums.size()) return;
        rec(nums,target,index+1,sum+nums[index]);
        rec(nums,target,index+1,sum-nums[index]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        rec(nums,target,0,0);
        return ans;
    }
};