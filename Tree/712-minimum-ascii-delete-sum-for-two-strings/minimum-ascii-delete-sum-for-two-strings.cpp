class Solution {
public:
    int rec(string& s1,string& s2,int i, int j, vector<vector<int>>& dp){
        if (i==s1.size()) {
            int sum=0;
            while(j<s2.size()) sum+=s2[j++];
            return sum;
        }
        if (j==s2.size()) {
            int sum=0;
            while (i<s1.size()) sum+=s1[i++];
            return sum;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) return dp[i][j]=rec(s1,s2,i+1,j+1,dp);
        else{
            int ans=rec(s1,s2,i+1,j,dp)+(int)s1[i];
            ans=min(ans,rec(s1,s2,i,j+1,dp)+(int)s2[j]);
            dp[i][j]=ans;
        }
        return dp[i][j];
    }
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>>dp(s1.size(),vector<int>(s2.size(),-1));
        return rec(s1,s2,0,0,dp);
    }
};