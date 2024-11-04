class Solution {
public:

    int cap(int mid,int m,int n){
        int cnt=0;
        for(int i=1;i<=m;i++){
            int temp=min(mid/i,n);
            cnt+=temp;
        }
        return cnt;
    }

    int findKthNumber(int m, int n, int k) {
        int ans=0;
        int l=1,r=n*m;
        while(l<r){
            int mid=l+(r-l)/2;
            int capacity=cap(mid,m,n);
            if(capacity>=k) r=mid;
            else l=mid+1;
        }
        return l;
    }
};