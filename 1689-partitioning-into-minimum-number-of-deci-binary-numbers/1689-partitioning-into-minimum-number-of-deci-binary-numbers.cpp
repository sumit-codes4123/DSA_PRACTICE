class Solution {
public:
    int minPartitions(string n) {
        int a=0;
        for(char c:n) a=max(a,c-'0');
        return a;
    }
};