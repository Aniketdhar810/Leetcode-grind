class Solution {
public:
    string shortestPalindrome(string s) {
        const long long MOD=1e9+7;
        const long long BASE =29;
        long long prefixHash=0;
        long long suffixHash= 0;
        long long power = 1;

        int lastIndex = -1;

        for (int i = 0; i < s.size();i++) {
            int ch = s[i] - 'a' + 1;
            prefixHash = (prefixHash * BASE + ch) % MOD;
            suffixHash = (suffixHash + ch * power) % MOD;
            if (prefixHash == suffixHash) lastIndex = i;
            power = (power * BASE) % MOD;
        }

        string suffix = s.substr(lastIndex + 1);
        reverse(suffix.begin(), suffix.end());

        return suffix + s;
    }
};