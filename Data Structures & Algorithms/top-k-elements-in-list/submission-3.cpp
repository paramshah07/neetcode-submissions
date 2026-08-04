class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for(int i: nums) {
            count[i] += 1;
        }
        int n = nums.size();
        vector<vector<int>> bucket(n+1);
        for(const auto& [key, value]: count) {
            bucket[value].push_back(key);
        }
        vector<int> result;
        for(int i = bucket.size() - 1; i >= 1; --i) {
            for(const auto& j: bucket[i]) {
                result.push_back(j);
                if(result.size() == k) {
                    return result;
                }
            }
        }
    }
};