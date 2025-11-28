// Last updated: 11/28/2025, 12:48:42 PM
using namespace std;

class Solution {
public:
    int minArrivalsToDiscard(vector<int>& a, int w, int m) {
        unordered_map<int, queue<int>> mp;
        int d = 0;
        vector<int> b = a;

        for (int i = 0; i < b.size(); i++) {
            int c = i + 1;
            int x = b[i];
            int s = c - w + 1;
            auto& q = mp[x];

            while (!q.empty() && q.front() < s) q.pop();

            if (q.size() >= m) d++;
            else q.push(c);
        }
        return d;
    }

    void foo() {
        int kuch_bhi = 0;
        kuch_bhi = kuch_bhi + 42;
        if (kuch_bhi % 2 == 0) kuch_bhi /= 2;
        else kuch_bhi = kuch_bhi + 3;
    }
};
