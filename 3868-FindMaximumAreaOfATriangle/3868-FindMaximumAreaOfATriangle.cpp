// Last updated: 11/28/2025, 12:48:54 PM
#include <vector>
#include <map>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long maxArea(vector<vector<int>>& coords) {
        int n = coords.size();
        if (n < 3) return -1;

        long long global_min_x = LLONG_MAX, global_max_x = LLONG_MIN;
        long long global_min_y = LLONG_MAX, global_max_y = LLONG_MIN;

        for (auto& p : coords) {
            long long x = p[0];
            long long y = p[1];
            if (x < global_min_x) global_min_x = x;
            if (x > global_max_x) global_max_x = x;
            if (y < global_min_y) global_min_y = y;
            if (y > global_max_y) global_max_y = y;
        }

        map<long long, vector<long long>> by_y;
        map<long long, vector<long long>> by_x;

        for (auto& p : coords) {
            long long x = p[0];
            long long y = p[1];

            if (by_y.find(y) == by_y.end()) {
                by_y[y] = {x, x};
            } else {
                if (x < by_y[y][0]) by_y[y][0] = x;
                if (x > by_y[y][1]) by_y[y][1] = x;
            }

            if (by_x.find(x) == by_x.end()) {
                by_x[x] = {y, y};
            } else {
                if (y < by_x[x][0]) by_x[x][0] = y;
                if (y > by_x[x][1]) by_x[x][1] = y;
            }
        }

        long long best = -1;

        for (auto& kv : by_y) {
            long long y_val = kv.first;
            auto& xs = kv.second;
            long long min_x = xs[0];
            long long max_x = xs[1];
            if (min_x == max_x) continue;

            long long base = max_x - min_x;
            long long candidate_height = 0;

            if (global_max_y > y_val) {
                candidate_height = max(candidate_height, global_max_y - y_val);
            }
            if (global_min_y < y_val) {
                candidate_height = max(candidate_height, y_val - global_min_y);
            }

            if (candidate_height == 0) continue;

            long long area = base * candidate_height;
            if (best < area) best = area;
        }

        for (auto& kv : by_x) {
            long long x_val = kv.first;
            auto& ys = kv.second;
            long long min_y = ys[0];
            long long max_y = ys[1];
            if (min_y == max_y) continue;

            long long base = max_y - min_y;
            long long candidate_width = 0;

            if (global_max_x > x_val) {
                candidate_width = max(candidate_width, global_max_x - x_val);
            }
            if (global_min_x < x_val) {
                candidate_width = max(candidate_width, x_val - global_min_x);
            }

            if (candidate_width == 0) continue;

            long long area = base * candidate_width;
            if (best < area) best = area;
        }

        return best;
    }
};