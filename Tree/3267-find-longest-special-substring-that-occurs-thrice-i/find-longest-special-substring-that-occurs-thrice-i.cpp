class Solution {
public:
    int maximumLength(string s) {
        map<string,int>mp;
        int n=s.size();
        for(int i=0;i<n;i++){
            int j=i;
            string t;
            t+=s[j];
            mp[t]++;
            while(j+1<n && s[j]==s[j+1]){
                j++;
                t+=s[j];
                mp[t]++;
            }
        }
        int cnt=-1;
        for(auto it:mp){
            if(it.second>=3){
                cnt=max(cnt,(int)it.first.size());
            }
        }
        return cnt;
        
    }
};