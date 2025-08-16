class Solution {
public:
    int maximum69Number (int num) {
        vector<int> temp;
        while(num){
            int rem=num%10;
            num/=10;
            temp.push_back(rem);
        }
        int n=temp.size();
        for(int i=n-1;i>=0;i--){
            if(temp[i]==6){
                temp[i]=9;
                break;
            }
        }
        int ans=temp[n-1];
        for(int i=n-2;i>=0;i--){
            ans*=10;
            ans+=temp[i];
        }
        return ans;
    }
};