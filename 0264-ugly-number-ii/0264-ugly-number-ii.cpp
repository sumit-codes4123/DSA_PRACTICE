class Solution {
public:
    int nthUglyNumber(int n) {
        set<long>st;
        st.insert(1);
        long cugly=1;
        for(int i=0;i<n;i++){
            cugly=*st.begin();
            st.erase(st.begin());
            st.insert(cugly*2);
            st.insert(cugly*3);
            st.insert(cugly*5);
        }return (int)cugly;
    }
};