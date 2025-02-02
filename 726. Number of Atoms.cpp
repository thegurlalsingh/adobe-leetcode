class Solution {
public:
    string countOfAtoms(string formula) {
        map<string, int> m; 
        stack<pair<map<string, int>, int>> s; 
        int n = formula.size();
        for (int i = 0; i < n; ) {
            if (formula[i] == '(') {
                s.push({{}, 1}); 
                i++;
            } 
            else if (formula[i] == ')') {
                i++;
                int multiplier = 1; 
                int j = i;
                while (j < n && isdigit(formula[j])) j++;
                if (j > i) multiplier = stoi(formula.substr(i, j - i));
                i = j;

                auto top = s.top(); 
                s.pop();
                for (auto& pair : top.first) {
                    pair.second *= multiplier;
                    if (!s.empty()) {
                        s.top().first[pair.first] += pair.second;
                    } else {
                        m[pair.first] += pair.second;
                    }
                }
            } 
            else {
                int j = i + 1;
                while (j < n && islower(formula[j])) j++;
                string element = formula.substr(i, j - i);
                i = j;

                int count = 1;
                while (j < n && isdigit(formula[j])) j++;
                if (j > i) count = stoi(formula.substr(i, j - i));
                i = j;

                if (!s.empty()) {
                    s.top().first[element] += count;
                } else {
                    m[element] += count;
                }
            }
        }

        string res = "";
        for (auto& pair : m) {
            res += pair.first;
            if (pair.second > 1) res += to_string(pair.second);
        }
        return res;
    }
};


