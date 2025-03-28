class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string row1="qwertyuiop";
        string row2="asdfghjkl";
        string row3="zxcvbnm";
        int n=words.size();
        vector<string>ans;
        for(int i=0;i<n;i++){
            string temp=words[i];
            for(auto& x:temp){
                x=tolower(x);
            }
            char ch=temp[0];
            int flag=0;
            auto res1=row1.find(ch);
            res1==string::npos? :flag=1;
            if(!flag){res1=row2.find(ch);
            res1==string::npos? :flag=2;}
            if(!flag){res1=row3.find(ch);
            res1==string::npos? :flag=3;}
            int valid=1;
            if(flag==1){
                for(char ch:temp){
                    if(row1.find(ch)==string::npos){
                        valid=0;
                        break;
                    }
                }
            }
            else if(flag==2){
                for(char ch:temp){
                    if(row2.find(ch)==string::npos){
                        valid=0;
                        break;
                    }
                }
            }
            else {
                for(char ch:temp){
                    if(row3.find(ch)==string::npos){
                        valid=0;
                        break;
                    }
                }
            }
            if(valid){
                ans.push_back(words[i]);
            }
            
        }
        return ans;
    }
};