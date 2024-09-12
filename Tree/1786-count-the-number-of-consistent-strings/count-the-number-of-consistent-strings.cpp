class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        set<int>st(allowed.begin(),allowed.end());
        int cnt=0;
        for(int i=0;i<words.size();i++){
            int found=1;
            for(int j=0;j<words[i].size();j++){
                if(st.find(words[i][j])==st.end()){
                    found=0;
                    break;
                }
            }
            if(found){
                cnt++;
            }
        }
        return cnt;
    }
};