class Solution {
public:
    // recursive
    // bool rec(string& s,vector<string>& wordDict,int index){
    //     if(index==s.length()) return true;
    //     for(string word:wordDict){
    //         if(s.substr(index,word.size())==word){
    //             if(rec(s,wordDict,index+word.size())) return true;
    //         }
    //     }
    //     return false;
    // }
    bool rec(string& s,vector<string>& wordDict,int index,vector<int>& dp){
        if(index==s.length()) return true;
        if(dp[index]!=-1) return dp[index];
        for(string word:wordDict){
            if(index + word.size() <= s.length() && s.substr(index,word.size())==word){
                if(rec(s,wordDict,index+word.size(),dp)){
                    return dp[index]=1;
                }
            }
        }
        return dp[index]=0;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        vector<int>dp(n+1,-1);
        return rec(s,wordDict,0,dp);
    }
};