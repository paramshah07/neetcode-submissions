class Solution {
private:
    string bucketSort(string s) {
        int map[26] = {0}; // To store the information about freq of the characters
        for(const char &c:s) { // we do const reference because it saves compute time
            map[c - 'a']++;
        }
        string res;
        for(int i = 0; i<26;++i) {
            res += string(map[i], i - 'a');
        }
        return res;
    }
public:
    

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> maps;
        vector<vector<string>> res;
        for(string s: strs) {
            maps[bucketSort(s)].push_back(s);
        }

        for(auto x:maps) {
            res.push_back(x.second);
        }

        return res;
        
    }
};
