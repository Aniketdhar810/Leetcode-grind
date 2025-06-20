class Solution {
public:
    // int func(vector<int>& coins,int amt){
    //     if(amt==0) return 0;
    //     int ans=INT_MAX;
    //     for(int coin:coins)
    //         if(amt-coin>=0)
    //         ans=min(func(coins,amt-coin)+1,ans);
    //     return ans;
    //   }

    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,amount+1);
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<coins.size();j++){
                if(i-coins[j]>=0){
                    dp[i]=min(dp[i],1+dp[i-coins[j]]);
                }
            }
        }
        return dp[amount]==amount+1 ? -1: dp[amount];
    }
};