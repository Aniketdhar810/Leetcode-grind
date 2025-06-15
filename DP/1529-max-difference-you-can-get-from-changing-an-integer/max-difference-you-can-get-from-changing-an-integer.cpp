class Solution {
public:
    int maxDiff(int num) {
        string n=to_string(num);
        string maxi=n;
        char temp1=' ';
        for(char c:n){
            if(c!='9'){
                temp1=c;
                break;
            }
        }
        if(temp1!=' '){
            for(char &c:maxi){
                if(c==temp1) c='9';
            }
        }
        string mini = n;
        char temp2 = ' ';
        if (n[0] != '1') {
            temp2 = n[0];
            for (char &c : mini) {
                if (c == temp2) c = '1';
            }
        } else {
            // Only replace digits other than '0' and '1' (to avoid leading zero)
            for (int i = 1; i < n.size(); i++) {
                if (n[i] != '0' && n[i] != '1') {
                    temp2 = n[i];
                    for (char &c : mini) {
                        if (c == temp2) c = '0';
                    }
                    break;
                }
            }
        }
        return stoi(maxi)-stoi(mini);
    }
};