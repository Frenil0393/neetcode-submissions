class StockSpanner {
public:
    vector<pair<int,int>> st;
    StockSpanner() { st.reserve(10000); }
    
    int next(int price) {
        int span = 1;
        while (!st.empty() && st.back().first <= price) {
            span += st.back().second;
            st.pop_back();
        }
        st.push_back({price, span});
        return span;
    }
};
