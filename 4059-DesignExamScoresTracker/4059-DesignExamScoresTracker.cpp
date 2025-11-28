// Last updated: 11/28/2025, 12:48:24 PM
#include <vector>
#include <algorithm>
using namespace std;

class ExamTracker {
public:
    vector<int> t;
    vector<long long> s; 

    ExamTracker() {}

    void record(int time, int score) {
        t.push_back(time);
        if(s.empty())
            s.push_back(score);
        else
            s.push_back(s.back() + score);
    }

    long long totalScore(int startTime, int endTime) {
        auto it1 = lower_bound(t.begin(), t.end(), startTime);
        auto it2 = upper_bound(t.begin(), t.end(), endTime);

        if(it1 == t.end() || it1 >= it2) return 0;

        int l = it1 - t.begin();
        int r = it2 - t.begin() - 1;

        if(l == 0) return s[r];
        return s[r] - s[l - 1];
    }
};
