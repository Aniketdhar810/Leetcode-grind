class Solution {
    bool place(vector<int>&stalls,int dist,int cows){
    int cntcows=1,lastcow=stalls[0];
    for(int j=1;j<stalls.size();j++){
        if(stalls[j]-lastcow>=dist){
            cntcows++;
            lastcow=stalls[j];
        }
        if(cntcows>=cows){
            return true;
        }
    }
    return false;
}
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
    int n=position.size();
    int low=1,high=position[n-1]-position[0];
    while(low<=high){
        int mid=(low+high)/2;
        if(place(position,mid,m)==true){
            low=mid+1;
        } else {
            high =mid-1;
        }
    }
    return high;
    }
};