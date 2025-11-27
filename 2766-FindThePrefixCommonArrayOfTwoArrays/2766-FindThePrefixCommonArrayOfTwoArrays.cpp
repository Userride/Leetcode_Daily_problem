// Last updated: 11/27/2025, 5:17:56 PM
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> C(n, 0);
        unordered_set<int> seenA, seenB; 
        
        for (int i = 0; i < n; ++i) {
           
            seenA.insert(A[i]);
            seenB.insert(B[i]);
            
           
            int commonCount = 0;
            for (int num : seenA) {
                if (seenB.count(num)) {
                    ++commonCount;
                }
            }
            
            
            C[i] = commonCount;
        }
        
        return C;
    }
};
