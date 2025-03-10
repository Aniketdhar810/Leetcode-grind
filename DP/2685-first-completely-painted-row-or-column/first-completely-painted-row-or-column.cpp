class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        unordered_map<int,pair<int,int>>mp;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int temp=mat[i][j];
                mp[temp]={i,j};
            }
        }
        vector<int>row(m),col(n);
        for(int i=0;i<arr.size();i++){
            int temp=arr[i];
            auto [r,c]=mp[temp];
            row[r]++;
            col[c]++;
            if(row[r]==n || col[c]==m){
                return i;
            }
        }
        return -1;

    }
};