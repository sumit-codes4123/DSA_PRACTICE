class Solution {
public:
    int minimumOperations(string num) {
        const int n = num.length();
        bool zero = false, five = false;
        for(int i = n - 1; i >= 0; --i){
            char digit = num[i];
            if(zero && (digit == '0' || digit == '5')) return n - 2 - i;
            if(five && (digit == '2' || digit == '7')) return n - 2 - i;
            if(digit == '5') five = true;
            if(digit == '0') zero = true; 
        }
        return n - zero;
    }
};