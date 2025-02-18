class Solution {
public:
    string smallestNumber(string s) {
        string ans;
        int n = s.size();
        vector<int> avl(10,1);

        function<bool(int)> put = [&](int ind)->bool{
            if(ind == n){
                return true;
            }
            if(s[ind] == 'I'){
                char start = ans.back() + 1;
                for(char ch = start; ch <= '9'; ch++){
                    if(avl[ch-'0']){
                        ans.push_back(ch);
                        avl[ch-'0'] = 0;
                        bool res = put(ind+1);
                        if(res){
                            return true;
                        }
                        avl[ch-'0'] = 1;
                        ans.pop_back();
                    }
                }
            }
            else{
                char end = ans.back() - 1;
                for(char ch = '1'; ch <= end; ch++){
                    if(avl[ch-'0']){
                        ans.push_back(ch);
                        avl[ch-'0'] = 0;
                        bool res = put(ind+1);
                        if(res){
                            return true;
                        }
                        avl[ch-'0'] = 1;
                        ans.pop_back();
                    }
                }
            }
            return false;
        };
        
        for(char ch = '1'; ch <= '9'; ch++){
            ans.push_back(ch);
            avl[ch-'0'] = 0;
            bool res = put(0);
            if(res){
                return ans;
            }
            avl[ch-'0'] = 1;
            ans = "";
        }
        return "";
    }
};