// Last updated: 11/28/2025, 12:48:39 PM
class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int min_time = INT_MAX;
      int n=landStartTime.size();
      int m=waterStartTime.size();

        for (int i = 0; i < n;i++) {
            for (int j = 0; j < m ;j++) {
              
                int l_s = landStartTime[i];
                int l_e= l_s + landDuration[i];

                int w_s = max(l_e, waterStartTime[j]);
                int w_e = w_s + waterDuration[j];

                min_time = min(min_time, w_e);
            }
        }

        for (int j = 0; j < m; ++j) {
            for (int i = 0; i<n; ++i) {

                int w_s = waterStartTime[j];
                int w_e = w_s + waterDuration[j];
                int l_s = max(w_e, landStartTime[i]);
                int l_e = l_s + landDuration[i];

                min_time = min(min_time, l_e);
            }
        }

        return min_time;
    }
};
