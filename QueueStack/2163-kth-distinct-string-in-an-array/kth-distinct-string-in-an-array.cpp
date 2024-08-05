class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map <string,int> mp;
        // for(int i=0;i<arr.size();i++){
        //     mp[arr[i]]++;
        // }
        for (const auto& str : arr) {
            mp[str]++;
        }
        int cnt = 0;
        for (const auto& str : arr) {
            if (mp[str] == 1) { 
                cnt++;
                if (cnt == k) { 
                    return str;
                }
            }
        }
        return "";
    }
};