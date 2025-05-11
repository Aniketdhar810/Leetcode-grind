class Solution {
    #define ll long long
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        ll lo=1;
        ll hi=*max_element(piles.begin(),piles.end());
        while(lo<hi){
            ll mid=lo+(hi-lo)/2;
            ll hrs=0;
            for(int pile:piles){
                hrs+=(pile+mid-1)/mid;
            }
            if(hrs<=h){
                hi=mid;
            }
            else lo=mid+1;
        }
        return hi;
    }
};