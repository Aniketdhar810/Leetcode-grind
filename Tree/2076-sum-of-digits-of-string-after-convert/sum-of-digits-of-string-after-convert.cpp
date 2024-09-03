class Solution {
public:
    int conversion(string s,int k){
        string newS;
        for(int i=0;i<s.size();i++){
            int val=(s[i]-'a')+1;//conver char to int
            newS+=to_string(val);
        }
        int sum=0;
        while(k--){
            sum=0;
            for(int i=0;i<newS.size();i++){
                sum+=(newS[i]-'0');//convert char to integer
            }
            newS=to_string(sum);
        }
        return sum;
    }
    int getLucky(string s, int k) {
        int ans=conversion(s,k);
        return ans;
    }
};