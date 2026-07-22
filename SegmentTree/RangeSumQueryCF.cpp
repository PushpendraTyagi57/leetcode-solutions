#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    long long sumQuery(int left, int right, vector<long long> &prefixSum)
    {
        if (left == 0)
            return prefixSum[right];
        return prefixSum[right] - prefixSum[left - 1];
    }
};

int main()
{
    int N, Q;
    cin >> N >> Q;
    vector<int> nums(N);
    for (int i = 0; i < N; i++)
        cin >> nums[i];
    vector<vector<int>> queries(Q, vector<int>(2));
    for (int i = 0; i < Q; i++)
    {
        cin >> queries[i][0] >> queries[i][1];
    }
    vector<long long> prefixSum(N);
    prefixSum[0] = nums[0];
    for (int i = 1; i < N; i++)
        prefixSum[i] = prefixSum[i - 1] + nums[i];
    Solution obj;
    for (int i = 0; i < Q; i++)
    {
        int first = queries[i][0];
        int second = queries[i][1];
        cout << obj.sumQuery(first - 1, second - 1, prefixSum) << "\n";
    }
    return 0;
}