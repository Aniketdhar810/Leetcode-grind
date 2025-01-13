class Solution {
public:
    int minimumLength(string s) {
        int diff=0;
        int n=s.size();
        if(n<=2) return n;
        map<char,int>mp;
        for(auto ch:s) mp[ch]++;
        for(auto it:mp){
            int temp=it.second;
            if(temp>2){
                if(temp%2==0){
                    diff+=(temp-2);
                }
                else{
                    diff+=(temp-1);
                }
            }
        }
        n-=diff;
        return n;
    }
};