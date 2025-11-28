// Last updated: 11/28/2025, 12:48:49 PM
class Solution {
public:
    string generateTag(string c) {
        string r = "#";
        string w = "";
        bool f = true;
        
        for (char ch : c) {
            if (ch == ' ') {
                if (!w.empty()) {
                    for (int i = 0; i < w.size(); ++i)
                        w[i] = tolower(w[i]);
                    if (!f)
                        w[0] = toupper(w[0]);
                    r += w;
                    w = "";
                    f = false;
                }
            } else {
                w += ch;
            }
        }

        if (!w.empty()) {
            for (int i = 0; i < w.size(); ++i)
                w[i] = tolower(w[i]);
            if (!f)
                w[0] = toupper(w[0]);
            r += w;
        }

        string t = "#";
        for (int i = 1; i < r.size(); ++i) {
            if (isalpha(r[i]))
                t += r[i];
        }

        if (t.size() > 100)
            t = t.substr(0, 100);

        return t;
    }
};
