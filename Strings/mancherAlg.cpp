string getStringAtIdx(const string &s, int idx, int ansLen) {
    string tmp;
    int n = s.size();
    for (int i = idx - ansLen + 1, counter = 0; counter < ansLen; counter++, i += 2) {
        tmp.push_back(s[i]);
    }
    return tmp;
}

int mancherAlg(const string &s) {
    if (s.empty())
        return 0;

    string t = "#";
    for (auto &ch:s)t.push_back(ch), t.push_back('#');

    int n = t.size();
    vector<int> ans(n);

    int C = 0, R = 0;
    for (int i = 1; i < n - 1; i++) {
        int mirror = 2 * C - i;
        int rad = (i < R) ? min(ans[mirror], R - i) : 0;
        while (i + 1 + rad < n && i + 1 + rad > -1 && t[i + 1 + rad] == t[i - rad - 1])
            rad++;

        ans[i] = rad;
        if (i + ans[i] > R) {
            C = i;
            R = i + ans[i];
        }
    }

    //uncomment to print longest palindromic substring
//    int idx = max_element(ans.begin(), ans.end()) - ans.begin();
//    return getStringAtIdx(t, idx, ans[idx]);
    return *max_element(ans.begin(), ans.end());
}
