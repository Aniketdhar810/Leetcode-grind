class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            int rem=(arr[i]%k+k)%k;
            mp[rem]++;
        }
        for(int i=0;i<arr.size();i++){
            int rem=(arr[i]%k+k)%k;
            if(rem==0){
                if(mp[rem]%2==1)return false;
            }
            else if(mp[rem]!=mp[k-rem]) return false;
        }
        return true;
    }
};