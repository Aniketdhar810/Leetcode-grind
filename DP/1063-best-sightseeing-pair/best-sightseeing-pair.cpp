class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans=0,cur=0;
        for(int it:values){
            ans=max(ans,cur+it);
            cur=max(cur,it)-1;
        }
        return ans;
    }
};