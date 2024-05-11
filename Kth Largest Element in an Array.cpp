class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // step 1 : push first k elements into the priority quueue
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < k; i++){
            pq.push(nums[i]);
        }
        //step 2 : push largest element and remove the smallest number
        for(int i = k; i < nums.size(); i++){
            if(pq.top() < nums[i]){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        int ans = pq.top();
        return ans;
    }
};
