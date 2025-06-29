class Solution {
public:
    int dp[501][501];
    int dist(int i,int j, string s1, string s2){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) return dist(i-1,j-1,s1,s2);
        int ans=dist(i-1,j,s1,s2)+1;
        ans=min(ans,dist(i,j-1,s1,s2)+1);
        ans=min(ans,dist(i-1,j-1,s1,s2)+1);
        return dp[i][j]=ans;
    }
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        return dist(word1.length()-1,word2.length()-1,word1,word2);
    }
};