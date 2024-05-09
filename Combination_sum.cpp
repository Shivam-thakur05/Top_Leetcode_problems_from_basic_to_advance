class Solution {
public:
    void findCombination(int idx,vector<int>& candidates, int target,vector<vector<int>>&ans,vector<int>&ds){
        //base case
        if(idx == candidates.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }
        //pick up the element
        if(candidates[idx] <= target){
            ds.push_back(candidates[idx]);
            findCombination(idx,candidates,target-candidates[idx],ans,ds);
            //make sure to remove element from ds when recursive cll backtrack 
            ds.pop_back();
        }
        //not pickup the element
        findCombination(idx+1,candidates,target,ans,ds);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        findCombination(0,candidates,target,ans,ds);
        return ans;
    }
};
