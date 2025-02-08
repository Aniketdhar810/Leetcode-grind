class NumberContainers {
public:
    map<int, int> mp; 
    map<int,set<int>> numMap;  

    NumberContainers() {}

    void change(int index, int number) {
        if (mp.find(index) != mp.end()) {
            int oldNumber = mp[index];
            numMap[oldNumber].erase(index);
            if (numMap[oldNumber].empty()) {
                numMap.erase(oldNumber);
            }
        }
        
        mp[index] = number;
        numMap[number].insert(index);
    }

    int find(int number) {
        if (numMap.find(number) == numMap.end() || numMap[number].empty()) {
            return -1;
        }
        return *numMap[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
