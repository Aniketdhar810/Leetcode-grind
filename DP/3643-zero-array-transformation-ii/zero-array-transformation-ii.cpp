class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();
        int l = 0, r = m;
        int ans = -1;
        auto check = [&](int k)->bool{
            vector<int> pref(n,0);
            for(int i=0;i<k;i++){
                int l = queries[i][0], r = queries[i][1], val = queries[i][2];
                pref[l] -= val;
                if(r+1 < n)pref[r+1] += val;
            }
            for(int i=1;i<n;i++){
                pref[i] += pref[i-1];
            }
            for(int i=0;i<n;i++){
                if(nums[i] + pref[i] > 0){
                    return false;
                }
            }
            return true;

        };
        while(l <= r){
            int mid = (l+r)/2;
            if(check(mid)){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};