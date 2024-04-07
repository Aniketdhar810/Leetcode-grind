class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int> max;
        int index=-1;
        int maxCount=-1;
        for(int i=0;i<mat.size();i++){
            int countRows=0;
            for(int j=0;j<mat[0].size();j++){
                countRows+=mat[i][j];
            }
            if(countRows>maxCount){
                maxCount=countRows;
                index=i;
            }
        }
        max.push_back(index);
        max.push_back(maxCount);
        return max;
    }
};