class Solution {
public:
    bool divideArray(vector<int>& nums) {
        map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int flag=1;
        for(auto it:mp){
            if(it.second%2!=0) {flag=0;break;}
        }
        if(mp.size()<=n/2 && flag) return true;
        else return false;

    }
};