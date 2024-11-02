class Solution {
public:
    bool isCircularSentence(string sentence) {
        vector<string>a;
        string s;
        stringstream ss(sentence);
        while(getline(ss,s,' ')){
            a.push_back(s);
        }
        int size=a.size();
        if(size==1){
            int l=a[0].size()-1;
            if(a[0][0]!=a[0][l]){
                return false;
            }
            else{
                return true;
            }
        }
        for(int i=0;i<size-1;i++){
            int n=a[i].size()-1;
            if(a[i][n]!=a[i+1][0]){
                return false;
            }
            if(i==size-2){
                int m=a[size-1].size()-1;
                if(a[size-1][m]!=a[0][0]){
                    return false;
                }
            }
        }
        return true;
    }
};