class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        long long l=min(a,b);
        long long h=n*l;
        long long hcf=__gcd(a,b);
        long long lcm=(a*b)/hcf;
        while(l<h){
            long long mid=l+(h-l)/2;
            long long factors=mid/a+mid/b-mid/lcm;
            if(factors<n){
                l=mid+1;
            }
            else h=mid;
        }
        long long mod=1e9+7;
        return l%mod;
    }
};