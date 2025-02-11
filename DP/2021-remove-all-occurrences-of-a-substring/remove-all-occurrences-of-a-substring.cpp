class Solution {
public:
    string removeOccurrences(string s, string part) {
        int i=0;
        while(s[i]!='\0'){
            if(s[i]==part[0]){
                bool flag=true;
                int curr=i;
                for(int j=0;j<part.size();j++){
                    if(s[curr]==part[j]){
                        curr++;
                    }
                    else{
                        i++;
                        flag=false;
                        break;
                    }
                }
                if(flag){
                    s.erase(i,part.size());
                    i=0;
                } 
            }
            else i++;
        }
        return s;
    }
};