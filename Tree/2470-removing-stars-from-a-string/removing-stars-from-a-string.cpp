class Solution {
public:
    string removeStars(string s) {
        vector<char> temp;
        for(char it:s){
            if(it!='*'){
                temp.push_back(it);
            }
            else if(!temp.empty()){
                temp.pop_back();
            }
        }
        string ans(temp.begin(),temp.end());
        return ans;
    }
};