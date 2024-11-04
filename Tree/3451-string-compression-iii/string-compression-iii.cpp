class Solution {
public:
    string compressedString(string word) {
        string ans="";
        for(int i=0;i<word.size();i++){
            int temp=1;
            while(word[i]==word[i+1] && temp<9){
                i++;
                temp++;
            }
            ans+=to_string(temp)+word[i];
        }
        return ans;
    }
};