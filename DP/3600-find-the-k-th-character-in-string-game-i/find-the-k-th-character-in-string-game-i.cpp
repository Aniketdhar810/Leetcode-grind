class Solution {
public:
    char kthCharacter(int k) {
        string s="a";
        while(s.size()<k){
            string word="";
            for(int i=0;i<s.size();i++){
                char ch;
                if(s[i]=='z') ch='a';
                else ch=s[i]+1;
                word+=ch;
            }
            s+=word;
        }
        return s[k-1];
    }
};