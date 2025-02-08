class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size(), m = words.size();
        unordered_map<string, int> mp;

        for (int i = 0 ;  i < m ; i++) {
            mp[words[i]]++;
        }

        int len = words[0].size();
        int totalLen = m * len;
        vector<int> ans;

        for (int i = 0; i < len; i++) {
            unordered_map<string, int> pp;
            int left = i, count = 0;

            for (int j = i; j <= n - len; j += len) {
                string temp = s.substr(j, len);

                if (mp.find(temp) != mp.end()) {
                    pp[temp]++;
                    count++;

                    while (pp[temp] > mp[temp]) {
                        string leftWord = s.substr(left, len);
                        pp[leftWord]--;
                        count--;
                        left += len;
                    }

                    if (count == m) {
                        ans.push_back(left);
                    }
                } else {
                    pp.clear();
                    count = 0;
                    left = j + len;
                }
            }
        }

        return ans;
    }
};