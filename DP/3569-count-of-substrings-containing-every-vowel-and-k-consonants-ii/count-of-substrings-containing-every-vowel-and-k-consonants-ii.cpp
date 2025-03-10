class Solution {
public:
    long long valid(string word,int k){
        int l=0,r=0,n=word.size();
        long long ans=0;
        map<char,int>mp;
        int n_cnst=0;
        while(r<n){
            if(word[r]=='a'||word[r]=='e'||word[r]=='i'||word[r]=='o'||word[r]=='u') mp[word[r]]++;
            else n_cnst++;
            while(mp.size()==5 && n_cnst>=k){
                ans+=word.size()-r;
                if(mp.find(word[l])!=mp.end()){
                    mp[word[l]]--;
                    if(mp[word[l]]==0) mp.erase(word[l]);
                }
                else n_cnst--;
                l++;
            }
            r++;
        }
        return ans;
    }
    long long countOfSubstrings(string word, int k) {
            return valid(word,k)-valid(word,k+1);
    }
};