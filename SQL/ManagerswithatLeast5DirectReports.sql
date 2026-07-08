# Write your MySQL query statement below
SELECT e1.name
FROM Employee AS e1
JOIN Employee as e2
WHERE e1.id = e2.managerId
GROUP BY e2.managerId
HAVING COUNT(e2.managerId) >= 5;