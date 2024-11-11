class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int n=nums.size();
        int m=*max_element(nums.begin(),nums.end());
        vector<bool>is_primes(m+1,true);
        set<int>primes;
        is_primes[0]=false,is_primes[1]=false;
        //seive of erasthoneses
        for(int i=2;i<=m;i++){
            if(is_primes[i]){
                primes.insert(i);
                //making all factors of prime, not prime
                for(int j=i+i;j<=m;j+=i){
                    is_primes[j]=false;
                }
            }
        }
        for(int i=n-2;i>=0;i--){
            if(nums[i]>=nums[i+1]){
                int diff=nums[i]-nums[i+1]+1;
                auto it=primes.lower_bound(diff);
                if(it==primes.end()||*it>=nums[i]){
                    return false;
                }
                nums[i]-=*it;
            }
        }
        return true;
    }
};