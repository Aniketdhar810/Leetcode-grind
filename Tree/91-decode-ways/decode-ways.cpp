class Solution {
public:
    // recursive solution
    // int rec(string& s,int i){
    //     if(i==s.size()) return 1;
    //     if(s[i]=='0') return 0;
    //     int res=rec(s,i+1);
    //     if(i<s.size()-1){
    //         if(s[i]=='1'|| (s[i]=='2' && s[i+1]<'7')){
    //             res+=rec(s,i+2);
    //         }
    //     }
    //     return res;
    // }
    // top down
    // int rec(string& s,int i,vector<int>& dp){
    //     if(i==s.size()) return 1;
    //     if(s[i]=='0') return 0;
    //     if(dp[i]!=-1) return dp[i];
    //     int res=rec(s,i+1,dp);
    //     if(i<s.size()-1){
    //         if(s[i]=='1'|| (s[i]=='2' && s[i+1]<'7')){
    //             res+=rec(s,i+2,dp);
    //         }
    //     }
    //     return dp[i]=res;
    // }
    // Since dp[i] depends on larger indices, fill from right to left.
    // bottom up
    int rec(string& s,vector<int>& dp){
        int n=s.size();
        dp[n]=1;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0'){
                dp[i]=0;
                continue;
            }
            dp[i]=dp[i+1];
            if(i<n-1){
                if(s[i]=='1'|| (s[i]=='2' && s[i+1]<'7')){
                    dp[i]+=dp[i+2];
                }
            }
        }
        return dp[0];
    }
    int numDecodings(string s) {
        // vector<int>dp(s.size(),-1);
        int n=s.size();
        vector<int>dp(n+1,0);
        return rec(s,dp);
    }
};