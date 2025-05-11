class Solution {
public:
    int mySqrt(int x) {
        if(x==0 || x==1) return x;
        int l=1,h=x;
        while(l<=h){
            int mid=l+(h-l)/2;
            long long temp=(long long)mid*mid;
            if(temp==x){
                return mid;
            }
            else if(temp>x) h=mid-1;
            else l=mid+1;
        }
        return h;
    }
};