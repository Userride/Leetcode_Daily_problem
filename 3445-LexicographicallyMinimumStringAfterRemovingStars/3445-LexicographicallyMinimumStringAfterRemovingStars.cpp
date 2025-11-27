// Last updated: 11/27/2025, 5:16:31 PM
class Solution {
public:
    using alphabet = pair<char, int>;
    static string clearStars(string& s) {
        const int n = s.size();
        auto cmp=[](alphabet& x, alphabet& y) {
            if (x.first == y.first)
                return x.second < y.second;
            return x.first > y.first;
        };
        priority_queue<alphabet, vector<alphabet>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c == '*') {
                auto [x, j] = pq.top();
                pq.pop();
                s[j] = ' ';
            } 
            else
                pq.emplace(c, i);
        }
        int j = 0;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c >= 'a')
                s[j++] = c;
        }
        s.resize(j);
        return s;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();