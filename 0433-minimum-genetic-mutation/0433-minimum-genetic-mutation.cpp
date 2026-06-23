class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<pair<string, int>> q;
        char genes[4]={'A','C','G','T'};
        q.push({startGene, 0});
        set<string> st(bank.begin(), bank.end());
        st.erase(startGene);
        while (!q.empty()) {
            string word = q.front().first;
            int step = q.front().second;
            q.pop();
            if (word == endGene)
                return step;
            for (int i = 0; i < word.size(); i++) {
                char original=word[i];
                for (int j=0;j<4;j++) {
                    word[i]=genes[j];
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        q.push({word,step+1});
                    }
                }
                word[i]=original;
            }
        }
        return -1;
    }
};
