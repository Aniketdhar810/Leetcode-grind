class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        int slow=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=nums[slow]){
                slow++;
                nums[slow]=nums[i];
            }
        }
        return slow+1;
    }
};