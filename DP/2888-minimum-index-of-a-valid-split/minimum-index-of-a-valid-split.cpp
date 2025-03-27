class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        //moores voting algo for majority elements
        //bit manipulation
        map<int,int>lmap;
        map<int,int>rmap;
        for(int num:nums)rmap[num]++;
        for(int i=0;i<nums.size();i++){
            lmap[nums[i]]++;
            rmap[nums[i]]--;
            int llen=i+1;
            int rlen=nums.size()-i-1;
            if(2*lmap[nums[i]]>llen &&2*rmap[nums[i]]>rlen) return i;
        }
        return -1;
    }
};