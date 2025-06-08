class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        map<int,int>mp;
        int n=x.size();
        for(int i=0;i<n;i++){
            mp[x[i]]=max(mp[x[i]],y[i]);
        }
        if(mp.size()<3) return -1;
        vector<int>ans;
        for(auto it:mp) ans.push_back(it.second);
        sort(ans.rbegin(),ans.rend());
        return ans[0]+ans[1]+ans[2];

    }
};