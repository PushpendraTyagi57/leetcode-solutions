#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();
        vector<vector<int>> sortCourses;
        for (auto& course : courses) {
            int duration = course[0];
            int lastDay = course[1];
            sortCourses.push_back({lastDay, duration});
        }
        sort(sortCourses.begin(), sortCourses.end());
        priority_queue<int> pq;
        int timeElapsed = 0;
        int coursesTaken = 0;
        for (auto& course : sortCourses) {
            int duration = course[1];
            int deadline = course[0];
            if (timeElapsed + duration <= deadline) {
                timeElapsed += duration;
                pq.push(duration);
                coursesTaken++;
            }
            else if (!pq.empty() && pq.top() > duration) {
                timeElapsed = timeElapsed - pq.top();
                pq.pop();
                timeElapsed = timeElapsed + duration;
                pq.push(duration);
            }
        }
        return coursesTaken;
    }
};

int main() {
    int n; cin >> n;
    vector<vector<int>> courses(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> courses[i][0] >> courses[i][1];
    }
    Solution obj;
    cout << obj.scheduleCourse(courses) << endl;
    return 0;
}