class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int cur_max=nums[0];
        int cur_min=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            int num=nums[i];
            int new_max=max({num,num*cur_max,num*cur_min});
            int new_min=min({num,num*cur_max,num*cur_min});
            cur_max=new_max;
            cur_min=new_min;
            ans=max(ans,cur_max);
        }
        return ans;
        
    }
};