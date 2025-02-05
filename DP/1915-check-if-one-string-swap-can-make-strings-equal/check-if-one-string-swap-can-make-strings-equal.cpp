class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int>mp1(26,0);
        vector<int>mp2(26,0);
        if(s1==s2) return true;
        int n=s1.size(),m=s2.size();
        if(n!=m) return false;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]) {cnt++;if(cnt>2) return false;}
            mp1[s1[i]-'a']++;
            mp2[s2[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(mp1[i]!=mp2[i]) return false;
        }
        return true;
    }
};