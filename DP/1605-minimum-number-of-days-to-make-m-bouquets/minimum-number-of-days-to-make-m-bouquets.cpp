class Solution {
public:
    bool check(vector<int>& a,int m, int k,int val){
        int bouq=0;
        int flow=0;
        for(int num:a){
            if(num<=val){
                flow++;
                if(flow==k){
                    bouq++;
                    flow=0;
                }
            }
            else flow=0;
        }
        if(bouq>=m) return true;
        else return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m*k>bloomDay.size()) return -1;
        int l=*min_element(bloomDay.begin(),bloomDay.end());
        int h=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(check(bloomDay,m,k,mid)){
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};