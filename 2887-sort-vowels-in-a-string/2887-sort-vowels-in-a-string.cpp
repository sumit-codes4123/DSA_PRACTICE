class Solution {
public:
    string sortVowels(string s) {
        vector<char> temp;
        for (int i = 0; i < s.size(); i++) {
            if (tolower(s[i]) == 'a' || tolower(s[i]) == 'e' ||
                tolower(s[i]) == 'i' || tolower(s[i]) == 'o' ||
                tolower(s[i]) == 'u')
                temp.push_back(s[i]);
        }
        int j = 0;
        sort(temp.begin(), temp.end());
        for (int i = 0; i < s.size(); i++) {
            if (tolower(s[i]) == 'a' || tolower(s[i]) == 'e' ||
                tolower(s[i]) == 'i' || tolower(s[i]) == 'o' ||
                tolower(s[i]) == 'u') {
                s[i] = temp[j];
                j++;
            }
        }
        return s;
    }
};