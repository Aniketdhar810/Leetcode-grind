class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n=points.size();
        int ans=0;
        for(int i=0;i<n;i++){
            vector<int>a=points[i];
            for(int j=0;j<n;j++){
                if(i==j) continue;
                vector<int>b=points[j];
                if(a[0]>b[0] || a[1]<b[1]) continue;
                bool flag=true;
                for(int k=0;k<n;k++){
                    if(k==i || k==j) continue;
                    vector<int>c=points[k];
                    if(c[0]>=a[0] && c[0]<=b[0]&& c[1]<=a[1] && c[1]>=b[1]){
                        flag=false;
                        break;
                    }
                }
                if(flag) ans++;
            }
        }
        return ans;
    }
};