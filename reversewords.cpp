class Solution {
public:
    string reverseWords(string s) {
        int i = 0, j = 0;
        while (j != s.size()) {
            cout << "i" << "" << j << endl;
            if (s[j] == ' ' || j == s.size() - 1) {
                int m = i, n;
                if (j == s.size() - 1) {
                    n = j;
                } else {
                    n = j - 1;
                }
                while (m < n) {
                    swap(s[m++], s[n--]);
                }
                i = j + 1;
            }
            j++;
        }
        return s;
    }
};
