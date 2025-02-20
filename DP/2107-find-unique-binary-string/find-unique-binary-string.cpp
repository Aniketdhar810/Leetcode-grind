class Solution {
public:
    int makeDecimal(string s){
        int n=s.length();
        int p=0;
        int ans=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='1'){
                ans+=pow(2,p);
            }
            p++;
        }
        return ans;
    }
    string toBinary(int n,int x){
        string s;
        while(n){
            int val=n&1;
            char ch=val+'0';
            s.push_back(ch);
            n>>=1;
        }
        while(s.length()<x){
            s+="0";
        }
        reverse(s.begin(),s.end());
        return s;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        set<int> s;
        for(int i=0;i<n;i++){
            int val=makeDecimal(nums[i]);
            s.insert(val);
        }
        for(int i=0;i<pow(2,n);i++){
            if(s.find(i)==s.end()){
                return toBinary(i,n);
            }
        }
        return "";
    }
};