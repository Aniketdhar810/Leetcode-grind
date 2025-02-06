class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int mult=nums[i]*nums[j];
                mp[mult]++;
            }
        }
        int cnt=0;
        for(auto &it : mp) {
            int freq = it.second;
            if(freq > 1) {
                cnt += (freq * (freq - 1) / 2) * 8; 
            }
        }
        return cnt;
    }
};