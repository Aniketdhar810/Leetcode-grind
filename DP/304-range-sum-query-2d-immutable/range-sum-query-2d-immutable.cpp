class NumMatrix {
public:
    int r,c;
    vector<vector<int>>prefix;
    NumMatrix(vector<vector<int>>& matrix) {
        r=matrix.size();
        c=matrix[0].size();
        prefix=vector<vector<int>>(r,vector<int>(c,0));
        prefix[0][0]=matrix[0][0];
        for(int i=1;i<c;i++) prefix[0][i]=prefix[0][i-1]+matrix[0][i];
        for(int i=1;i<r;i++) prefix[i][0]=prefix[i-1][0]+matrix[i][0];
        for(int i=1;i<r;i++){
            for(int j=1;j<c;j++){
                prefix[i][j]=matrix[i][j]+prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans=prefix[row2][col2];
        int up=(row1>0)?prefix[row1-1][col2]:0;
        int left=(col1>0)?prefix[row2][col1-1]:0;
        int corner=(col1>0 && row1>0)?prefix[row1-1][col1-1]:0;
        return ans-up-left+corner;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */