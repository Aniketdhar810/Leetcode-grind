class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int>pq;
        map<char,int>mp;
        for(auto it:tasks){
            mp[it]++;
        }
        for(auto it:mp){
            pq.push(it.second);
        }
        int ans=0;
        while(!pq.empty()){
            int tt=n+1;
            vector<int>temp;
            for(int i=0;i<tt;i++){
                if(!pq.empty()){
                    temp.push_back(pq.top()-1);
                    pq.pop();
                }
            }
            for(int rem:temp){
                if(rem>0) pq.push(rem);
            }
            ans+=pq.empty()?temp.size():tt;
        }
        return ans;
    }
};