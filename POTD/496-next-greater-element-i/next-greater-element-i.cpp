class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //first approach is compare every element to right
        //using stack
        stack<int>st;
        map<int,int>mp;
        for(int i=nums2.size()-1;i>=0;i--){
            while (!st.empty() && nums2[i] >= st.top()) {
                st.pop();
            }
            if (st.empty()) {
                mp[nums2[i]] = -1;
            } else {
                mp[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }
        vector<int> result;
        for (int num : nums1) {
            result.push_back(mp[num]);
        }
        return result;
    }
};