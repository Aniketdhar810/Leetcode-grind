class Solution {
public:
    int minChanges(string s) {
        int cnt=0;
        for(int i=0;i<s.size();i=i+2){
            if(s[i]!=s[i+1]){
                s[i]=s[i+1];
                cnt++;
            }
        }
        return cnt;
    }
};