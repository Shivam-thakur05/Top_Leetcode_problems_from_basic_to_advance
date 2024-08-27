class Solution {
  public:
    int findMaxDiff(vector<int> &arr) {
        stack<int> st;
        int n = arr.size();
        
        vector<int> leftSmaller(n, 0);
        vector<int> rightSmaller(n, 0);
        
        // Store the left smaller elements in the vector
        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top() >= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                leftSmaller[i] = st.top();
            }
            st.push(arr[i]);
        }
        
        // Clear the stack for rightSmaller processing
        while (!st.empty()) {
            st.pop();
        }
        
        // Store the right smaller elements in the vector
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() >= arr[i]) {  // Change condition to `>=`
                st.pop();
            }
            if (!st.empty()) {
                rightSmaller[i] = st.top();
            }
            st.push(arr[i]);
        }
        
        // Calculate the maximum difference
        int maxDiff = 0;
        for (int i = 0; i < n; i++) {
            int diff = std::abs(leftSmaller[i] - rightSmaller[i]);
            if (diff > maxDiff) {
                maxDiff = diff;
            }
        }
        return maxDiff;
    }
};
