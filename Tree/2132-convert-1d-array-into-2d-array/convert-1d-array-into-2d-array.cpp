class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int size=m*n;
        vector<vector<int>>a;
        if(m*n==original.size()){
            for(int i=0;i<m;i++){
                vector<int>temp;
                for(int j=0;j<n;j++){
                    temp.push_back(original[i*n+j]);
                }
                a.push_back(temp);
            }
        }
        return a;
    }
};