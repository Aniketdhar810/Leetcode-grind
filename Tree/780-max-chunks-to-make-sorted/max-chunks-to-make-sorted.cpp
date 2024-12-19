class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int>prefix;
        int n=arr.size();
        int sum=0;
        int ans=0;
        int temp=0;
        for(int i=0;i<n;i++){
            temp+=i;
            sum+=arr[i];
            if(temp==sum){
                ans++;
            }
        }
        return ans;
    }
};