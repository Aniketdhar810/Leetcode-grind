class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        vector<bool>allowed(n+1,true);
        for(int i=0;i<banned.size();i++){
            if(banned[i]<=n){
                allowed[banned[i]]=false;
            }
        }
        int ans=0;
        int sum=0;
        for(int j=1;j<=n;j++){
            if(sum>maxSum){
                break;
            }
            if(allowed[j]==true){
                sum+=j;
                if(sum>maxSum) break;
                ans++;
            }
        }
        return ans;
    }
};