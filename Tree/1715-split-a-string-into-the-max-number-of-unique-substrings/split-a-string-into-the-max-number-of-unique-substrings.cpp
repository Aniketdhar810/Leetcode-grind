class Solution {
public:
    int maxUniqueSplit(string s) {
        int n = s.size();
        int ans = 1;
        string curr;
        set<string> have;
        function<void(int)> solve = [&](int i)->void{
            if(i >= n){
                if(curr == ""){
                    ans = max(ans,(int)have.size());
                }
                return;
            }
            curr.push_back(s[i]);
            if(!have.contains(curr)){
                have.insert(curr);
                string copy = curr;
                curr = "";
                solve(i+1);
                curr = copy;
                have.erase(curr);

            }
            solve(i+1);
        };
        solve(0);
        return ans;
    }
};