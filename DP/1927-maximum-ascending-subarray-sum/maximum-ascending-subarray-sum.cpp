class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        if(n==1) return nums[0];
        for(int i=0;i<n;i++){
            int j=i;
            int temp=0;
            while(j<n-1 &&nums[j]<nums[j+1]){
                temp+=nums[j];
                j++;
            }
            temp+=nums[j];
            i=j;
            ans=max(ans,temp);
        }
        return ans;
    }
};