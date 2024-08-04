class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> sub_Sum;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                sub_Sum.push_back(sum);
            }
        }
    sort(sub_Sum.begin(),sub_Sum.end());
    int sum_Sub=0, mod=1e9+7;
    for(int i=left-1;i<right;i++){
        sum_Sub=(sum_Sub + sub_Sum[i]) % mod ;
    }
    return sum_Sub;
    }
};