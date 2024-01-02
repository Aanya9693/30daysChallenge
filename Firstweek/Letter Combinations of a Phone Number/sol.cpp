class Solution {
public:

    void dfs(string digits, int pos, string& path, vector<string>& res, vector<string>& letter){
        if(pos == digits.size()){
            res.push_back(path);
            return;
        }
        for(auto c: letter[digits[pos] - '0']){ //convert it to int to get the respective string from that index
            path.push_back(c); //take it
            dfs(digits, pos+1, path, res, letter);
            path.pop_back(); //leave it
        }

    }

    vector<string> letterCombinations(string digits) {
        vector<string>res;
        if(digits.empty()) return res;
        vector<string>letter({"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"});
        string path = "";
        dfs(digits, 0, path, res, letter);
        return res;
    }
};
