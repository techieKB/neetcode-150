class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>res;
        unordered_map<string,vector<string>>mp;
        for(int i = 0;i<strs.size();i++){
            string copy = strs[i];
            sort(copy.begin(),copy.end());
            mp[copy].push_back(strs[i]);
        }
        for(auto &[key,value] : mp){
            res.push_back(value);
        }
        return res;
    }
};