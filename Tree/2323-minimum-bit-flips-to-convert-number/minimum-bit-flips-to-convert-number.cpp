class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt=0;
        int ans=start^goal;
        while(ans>1){
            if(ans%2==1) cnt++;
            ans=ans/2;
        }
        if(ans==1) cnt++;
        return cnt;
    }
};