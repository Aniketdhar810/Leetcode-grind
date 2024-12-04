class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n=str1.size(),m=str2.size();
        int i=0,j=0;
        while(i<n && j<m){
            if(str1[i]!=str2[j]){
                char ch;
                if(str1[i]=='z'){
                    ch='a';
                }
                else{
                    ch=char(str1[i]+1);
                }
                if(ch==str2[j]){
                    j++;
                    i++;
                }
                else{
                    i++;
                }
            }
            else{
                i++;
                j++;
            }
        }
        if(j==m){
            return true;
        }
        else{
            return false;
        }
    }
};