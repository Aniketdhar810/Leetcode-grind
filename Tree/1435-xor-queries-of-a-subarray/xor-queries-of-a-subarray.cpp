class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>result;
        for(auto it:queries){
            int xor_S=0;
            for(int i=it[0];i<=it[1];i++){
                xor_S^=arr[i];
            }
            result.push_back(xor_S);
        }
        return result;
    }
};