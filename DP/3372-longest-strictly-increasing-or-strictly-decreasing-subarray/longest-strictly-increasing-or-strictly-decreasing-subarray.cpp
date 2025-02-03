class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1; 

        int cnt_inc = 1, cnt_dec = 1;
        int max_inc = 1, max_dec = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                cnt_inc++;
                cnt_dec = 1; 
            } 
            else if (nums[i] < nums[i - 1]) { 
                cnt_dec++;
                cnt_inc = 1; 
            } 
            else {  
                cnt_inc = cnt_dec = 1;
            }

            max_inc = max(max_inc, cnt_inc);
            max_dec = max(max_dec, cnt_dec);
        }
        
        return max(max_inc, max_dec);
    }
};
