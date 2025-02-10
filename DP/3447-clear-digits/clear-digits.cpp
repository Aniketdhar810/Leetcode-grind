class Solution {
public:
    string clearDigits(string s) {
        int n=s.length();
        stack<char>st;
        st.push(s[0]);
        for(int i=1;i<n;i++){
            if(isdigit(s[i])){
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                st.push(s[i]);
            }
        }
        string ans="";
        while(!st.empty()){
            char temp=st.top();
            st.pop();
            ans+=temp;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};