// -----Backtracking------- O(2^n), O(k)----------

class Solution {
private:
    void solve(vector<vector<int>>&ans, vector<int>&temp, int startIndex, int k, int n, int &sum, int arr[]){
        if(k==0){
            if(sum==n){
                sort(temp.begin(), temp.end());
                ans.push_back(temp);
            }
            return;
        }
        for(int i=startIndex; i<9; i++){
            sum += arr[i]; //take it
            temp.push_back(arr[i]);
            solve(ans, temp, i+1, k-1, n, sum, arr);
            sum -= arr[i]; //leave it
            temp.pop_back();
        }
        return;
    }


public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        int arr[9]={1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int>temp;
        int sum=0;
        solve(ans, temp, 0, k, n, sum, arr);
        return ans;
    }
};

// -----Recursion------ O(k*n), O(k)----------
class Solution {
public:
    set<vector<int>>st;  //using set because it only stores unique value;
    void solve(int k, int n, vector<int>temp, int idx){
        if(k==0 && n!=0) return;
        if(n==0 && k!= 0) return;
        if(n==0 && k==0){
            st.insert(temp);
            return;
        }

        for(int i=idx+1; i<=9; i++){
            if(i<=n){
                temp.push_back(i);
                solve(k-1, n-i, temp, i);
                temp.pop_back();
            }else{
                break;
            }
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        if(n>45 || n==0) return ans;
        
        for(int i=1; i<=9; i++){
            vector<int>temp;
            if(i<=n){
                temp.push_back(i);
                solve(k-1, n-i, temp, i);
                temp.pop_back();
            }else{
                break;
            }
        }
        for(auto itr : st){
            ans.push_back(itr);
        }
        return ans;
    }

};
