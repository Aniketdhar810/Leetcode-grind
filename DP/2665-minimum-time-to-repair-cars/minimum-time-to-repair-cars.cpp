class Solution {
public:
    long long count_rep(vector<int>& ranks,long long mid){
        long long cnt=0;
        for(int i=0;i<ranks.size();i++){
            long long temp=(long long) sqrt(mid/ranks[i]);
            cnt+=temp;
        }
        return cnt;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long l=1;
        long long h=1LL*(*min_element(ranks.begin(),ranks.end()))*cars*cars;
        long long res=-1;
        long long mid;
        while(l<=h){
            mid=(l+h)/2;
            long long rep=count_rep(ranks,mid);
            if(rep>=cars){
                res=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return res;
    }
};