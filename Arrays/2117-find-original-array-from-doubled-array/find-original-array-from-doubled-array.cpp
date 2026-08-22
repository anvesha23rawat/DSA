class Solution {
public:
//solution
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if(n%2 != 0){
            return {};
        }
        sort(changed.begin(),changed.end());
        map<int,int> mp;
        vector<int> result;
        for(auto &num:changed){
            mp[num]++;
        }
        for(auto &num:changed){
            int twice = num*2;
            if(mp[num] == 0) {
                continue;
            }
            if(mp.find(twice) == mp.end() || mp[twice] == 0){
                return {};
            }
            result.push_back(num);
            mp[num]--;
            mp[twice]--;
        }
        return result;
    }
};