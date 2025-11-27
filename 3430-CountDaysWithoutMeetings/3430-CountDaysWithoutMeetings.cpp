// Last updated: 11/27/2025, 5:16:35 PM
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        if (meetings.empty()) return days; 

        sort(meetings.begin(), meetings.end());

        int result = 0; 
        int end = 0;    

        for (auto& meeting : meetings) {
            int start = meeting[0];
            if (start > end + 1) {
                result += (start - end - 1);
            }
            end = max(end, meeting[1]);
        }
        if (end < days) {
            result += (days - end);
        }

        return result;
    }
};
