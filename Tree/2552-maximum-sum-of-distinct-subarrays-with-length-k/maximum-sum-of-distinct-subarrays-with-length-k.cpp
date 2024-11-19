class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq; 
        long long max_sum = 0, current_sum = 0;
        int n = nums.size();
        
        int l = 0;
        for (int r = 0; r < n; ++r) { 
            current_sum += nums[r];
            freq[nums[r]]++;
            if (r - l + 1 > k) {
                current_sum -= nums[l];
                freq[nums[l]]--;
                if (freq[nums[l]]==0) freq.erase(nums[l]);
                l++;
            }            
            if (r-l+1==k && freq.size()==k) {
                max_sum = max(max_sum, current_sum);
            }
        }
        
        return max_sum;
    }
};
