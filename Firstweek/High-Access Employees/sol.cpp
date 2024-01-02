class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        unordered_map<string, vector<string>> maps;
        for (auto each : access_times) {
            maps[each[0]].push_back(each[1]);
        }
        
        vector<string>ans;
        int cnt=0;
        for(auto each : maps){
            vector<string>time=each.second;
            sort(time.begin(), time.end());
            for(int i=2; i<time.size(); i++){
                if(stoi(time[i])-stoi(time[i-2]) < 100){
                    ans.push_back(each.first);
                    break;
                }
            }
        }
        return ans;
    }
};
