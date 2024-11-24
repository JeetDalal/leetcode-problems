class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long> prefixSum(n + 1, 0);  // Prefix sum array
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        deque<int> dq;  // Monotonic deque
        int min_len = INT_MAX;

        for (int i = 0; i <= n; i++) {
            // Check if the current prefix sum minus the oldest prefix sum is >= k
            while (!dq.empty() && prefixSum[i] - prefixSum[dq.front()] >= k) {
                min_len = min(min_len, i - dq.front());
                dq.pop_front();
            }

            // Maintain monotonicity by removing indices with larger prefix sums
            while (!dq.empty() && prefixSum[i] <= prefixSum[dq.back()]) {
                dq.pop_back();
            }

            // Add the current index to the deque
            dq.push_back(i);
        }

        return (min_len == INT_MAX) ? -1 : min_len;
    }
};
