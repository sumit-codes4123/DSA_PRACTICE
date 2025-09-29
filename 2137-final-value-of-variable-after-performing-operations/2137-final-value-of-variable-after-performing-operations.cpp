class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int X = 0;
        for (const string& c : operations) {
        if (c == "--X" || c == "X--"){
                X--;
        }
            else{
                X++;
            }
        }
        return X;
    }
};