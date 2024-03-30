class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>nums3;
        int m=nums1.size();
        int n=nums2.size();
        int i=0,j=0;
        while(i<m&&j<n){
            if(nums1[i]<nums2[j]){
                nums3.push_back(nums1[i]);
                i++;
            }
            else{
                nums3.push_back(nums2[j]);
                j++;
            }
        }
        while(i<m){
            nums3.push_back(nums1[i]);
            i++;
        }
        while(j<n){
            nums3.push_back(nums2[j]);
            j++;
        }
        if(nums3.size()%2==0){
            int t=nums3.size();
            float median = (nums3[t / 2 - 1] + nums3[t / 2]) / 2.0;
            return median;
        }
        else{
            int t=nums3.size();
            float median=nums3[t/2];
            return median;
        }
        return -1;
    }
};