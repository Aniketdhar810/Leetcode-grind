class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum=0;
        for(long long i=0;i<chalk.size();i++){
            sum+=chalk[i];
        }
        k%=sum;
        int i=0;
        while(1){
            k =k-chalk[i];
            if(k<0){
                return i;
            }
            if(i==chalk.size()-1){
                i=0;
                continue;
            }
            i++;
        }
    }
};