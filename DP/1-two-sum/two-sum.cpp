class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        map<int,int> mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]=i;
        }
        for(int i=0;i<n;i++){
            if(mp.find(target-nums[i])!=mp.end() && mp[target-nums[i]]!=i){
                ans.push_back(i);
                ans.push_back(mp[target-nums[i]]);
                return ans;
            }       
        }
        return ans;
    }
};