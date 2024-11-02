class Solution {
public:
    bool isCircularSentence(string sentence) {
        // Check if sentence is a single word
        if (sentence.front() != sentence.back()) {
            return false;
        }

        for (int i = 0; i < sentence.size(); i++) {
            if (sentence[i] == ' ' && sentence[i - 1] != sentence[i + 1]) {
                return false;
            }
        }
        return true;
    }
};
