#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int i = 0, j = 0;
        int currUnsatisfied = 0;
        int maxSatisfaction = 0;
        int lastI, lastJ;
        while (j < n) {
            if (grumpy[j] == 1)
                currUnsatisfied += customers[j];
            if (j - i + 1 > minutes) {
                if (grumpy[i] == 1) currUnsatisfied -= customers[i];
                i++;
            }
            if (currUnsatisfied > maxSatisfaction) {
                maxSatisfaction = currUnsatisfied;
                lastI = i;
                lastJ = j;
            }
            j++;
        }
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (i >= lastI && i <= lastJ) {
                sum += customers[i];
            }
            else if (grumpy[i] == 0)
                sum += customers[i];
        }
        return sum;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> customers(n), grumpy(n);
    for (int i = 0; i < n; i++)
        cin >> customers[i];
    for (int i = 0; i < n; i++)
        cin >> grumpy[i];
    int minutes;
    cin >> minutes;
    Solution obj;
    cout << obj.maxSatisfied(customers, grumpy, minutes) << endl;
    return 0;
}