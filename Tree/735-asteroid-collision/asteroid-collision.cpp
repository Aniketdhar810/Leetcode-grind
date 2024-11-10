class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>temp; 
        for (int it:asteroids) {
            bool pathak= false;
            while (!temp.empty() && temp.back()>0 && it<0) {
                if (temp.back()<-it) {  
                    temp.pop_back();
                    continue;  
                } 
                else if(temp.back()==-it) {  
                    temp.pop_back();
                    pathak= true;
                    break;
                } 
                else { 
                    pathak=true;
                    break;
                }
            }
            if(!pathak){
                temp.push_back(it);
            }
        }
        return temp;
    }
};
