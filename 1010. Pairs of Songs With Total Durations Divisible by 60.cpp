class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int count = 0;
        unordered_map<int, int> mp;
        
        for (int i = 0; i < time.size(); i++) {
            int mod = time[i] % 60;  
            int complement = (60 - mod) % 60; 

            if (mp.find(complement) != mp.end()) {
                count += mp[complement]; 
            }

            mp[mod]++; 
        }
        
        return count;
    }
};