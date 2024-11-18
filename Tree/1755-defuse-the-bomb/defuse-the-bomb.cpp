class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int>ans(code.size(),0);
        if(k==0){
            return ans;
        }
        else if(k>0){
            for(int i=0;i<code.size();i++){
                for(int j=i+1;j<i+k+1;j++){
                    ans[i]+=code[j%code.size()];
                }
            }
        }
        else{
            for(int i=0;i<code.size();i++){
                for(int j=i-abs(k);j<i;j++){
                    ans[i]+=code[(j+code.size())%code.size()];
                }
            }
        }
        return ans;
    }
};