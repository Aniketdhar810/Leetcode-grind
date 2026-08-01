class Solution {
public:  
    int lcs(int idx1,int idx2, string & s1,string & s2,vector<vector<int>>& dp){
        if(idx1<0 || idx2<0) return 0;
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        int ans=lcs(idx1-1,idx2,s1,s2,dp);
        ans=max(ans,lcs(idx1,idx2-1,s1,s2,dp));
        ans=max(ans,lcs(idx1-1,idx2-1,s1,s2,dp)+(s1[idx1]==s2[idx2]));
        return dp[idx1][idx2]=ans;

    }
    int longestPalindromeSubseq(string s) {
        vector<vector<int>>dp(1001,vector<int>(1001,-1));
        string s1=s;
        reverse(s.begin(),s.end());
        string s2=s;
        return lcs(s1.length()-1,s1.length()-1,s1,s2,dp); 
    }
};