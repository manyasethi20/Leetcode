class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        int L = n + m - 1;

        string word(L, '?');

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    if (word[i + j] == '?' || word[i + j] == str2[j]) {
                        word[i + j] = str2[j];
                    } else {
                        return "";
                    }
                }
            }
        }

        for (char &c : word) {
            if (c == '?') c = 'a';
        }

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {
                bool match = true;
                for (int j = 0; j < m; j++) {
                    if (word[i + j] != str2[j]) {
                        match = false;
                        break;
                    }
                }

                if (match) {
                    bool broken = false;

                    for (int j = m - 1; j >= 0; j--) {
                        int pos = i + j;
                        char original = word[pos];

                        for (char c = 'a'; c <= 'z'; c++) {
                            if (c == original) continue;

                            word[pos] = c;

                            bool valid = true;
                            for (int k = max(0, pos - m + 1); k <= min(n - 1, pos); k++) {
                                if (str1[k] == 'T') {
                                    for (int x = 0; x < m; x++) {
                                        if (word[k + x] != str2[x]) {
                                            valid = false;
                                            break;
                                        }
                                    }
                                }
                                if (!valid) break;
                            }

                            if (valid) {
                                broken = true;
                                break;
                            }
                        }

                        if (broken) break;
                        word[pos] = original;
                    }

                    if (!broken) return "";
                }
            }
        }

        return word;
    }
};