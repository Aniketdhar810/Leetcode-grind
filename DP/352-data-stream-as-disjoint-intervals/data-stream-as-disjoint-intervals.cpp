class SummaryRanges {
public:
    set<int>st;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        st.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>>ans;
        if (st.empty()) return ans;
        vector<int>arr(st.begin(),st.end());
        int l=arr[0],r=arr[0];
        for(int i=1;i<arr.size();i++){
            if(arr[i]==r+1){
                r=arr[i];
            }
            else{
                ans.push_back({l,r});
                l=r=arr[i];
            }
        }
        ans.push_back({l,r});
        return ans;   
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */