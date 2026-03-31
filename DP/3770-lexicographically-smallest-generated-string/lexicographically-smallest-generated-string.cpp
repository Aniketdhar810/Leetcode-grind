class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        int si = n + m - 1;
        string ans(si, '#');
        vector<bool> change(si, false);
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                int idx = i;
                for (int j = 0; j < m; j++) {
                    if (ans[idx] != '#' && ans[idx] != str2[j])
                        return "";
                    ans[idx] = str2[j];
                    idx++;
                }
            }
        }
        for (int i = 0; i < si; i++) {
            if (ans[i] == '#') {
                ans[i] = 'a';
                change[i] = true;
            }
        }
        for (int i =0; i<n; i++) {
            if (str1[i] == 'F' && ans.substr(i, m) == str2) {
                bool fixed = false;
                for (int j = m - 1; j >= 0; j--) {
                    if (change[j+i]) {
                        for (char c = 'a'; c <= 'z'; c++) {
                            if (c != str2[j]) {
                                ans[j+i] = c;
                                fixed = true;
                                break;
                            }
                        }
                        if (fixed)
                            break;
                    }
                }
                if (!fixed)
                    return "";
            }
        }
        return ans;
    }
};