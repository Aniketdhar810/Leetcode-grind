class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n=queries.size();
        unordered_map<int,int>mp1,mp2;
        //mp1 ball 
        //mp2 colour
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            int key=queries[i][0];
            int val=queries[i][1];

            //colour exists 

            if(mp1.count(key))
            {
                int prev=mp1[key];
                mp2[prev]--;
                if(mp2[prev]==0)
                {
                    mp2.erase(prev);

                }
            }
            //colour doesnt exits
            mp1[key]=val;
            mp2[val]++;
            ans[i]=mp2.size();
            
           
        }
        return ans;
    }
};