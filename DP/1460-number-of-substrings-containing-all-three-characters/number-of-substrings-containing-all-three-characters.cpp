class Solution {
public:
    int numberOfSubstrings(string s) {
        map<char,int>mp;
        int ans=0;
        int l=0,r=0,n=s.length();
        while(r<n){
            mp[s[r]]++;
            while(mp.size()==3) {
                ans+=(n-r);
                mp[s[l]]--;
                if(mp[s[l]]==0) mp.erase(s[l]);
                l++;
            }
            r++;
        }
        return ans;
    }
};