class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;
        int ans=0;
        while(i<j){
            int a=height[i],b=height[j];
            ans=max(ans,min(a,b)*(j-i));
            if(a<b) i++;
            else j--;
        }
        return ans;
    }
};