// Last updated: 11/27/2025, 5:16:06 PM
class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";
        while(word.size()<k){
            string s = "";
            for(int i=0;i<word.size();i++){
                char ch = word[i];
                ch++;
                s += ch;
            }
            word += s;
        }
        return word[k-1];
    }
};