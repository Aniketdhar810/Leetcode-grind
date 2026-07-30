// class Solution {
// public:
//     int ans=0;
//     void rec(vector<int>& nums,int target,int index,int sum){
//         if(index==nums.size() && sum==target){ans++; return;}
//         else if(index==nums.size()) return;
//         rec(nums,target,index+1,sum+nums[index]);
//         rec(nums,target,index+1,sum-nums[index]);
//     }
//     int findTargetSumWays(vector<int>& nums, int target) {
//         rec(nums,target,0,0);
//         return ans;
//     }
// };

class Solution {
public:
    vector<vector<int>> dp;

    int rec(vector<int>& nums, int target, int index, int sum) {
        if (index == nums.size()) {
            return (sum == target) ? 1 : 0;
        }

        if (dp[index][sum + 1000] != -1)
            return dp[index][sum + 1000];

        int add = rec(nums, target, index + 1, sum + nums[index]);
        int subtract = rec(nums, target, index + 1, sum - nums[index]);

        return dp[index][sum + 1000] = add + subtract;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        dp.resize(nums.size(), vector<int>(2001, -1));
        return rec(nums, target, 0, 0);
    }
};