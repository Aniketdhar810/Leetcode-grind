class Solution {
public:
    int max_sub(vector<int>dif){
        int ans=dif[0];
        int end=dif[0];
        for(int i=1;i<dif.size();i++){
            end=max(dif[i],end+dif[i]);
            ans=max(end,ans);
        }
        return ans;
    }
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<int>diff1(n),diff2(n);
        int sum1=0,sum2=0;
        for(int i=0;i<n;i++){
            sum1+=nums1[i];
            sum2+=nums2[i];
            diff1[i]=nums2[i]-nums1[i];
            diff2[i]=nums1[i]-nums2[i];
        }
        int res1=max_sub(diff1);
        int res2=max_sub(diff2);
        return max(res1+sum1,res2+sum2);
    }
};