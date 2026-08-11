# Write your MySQL query statement below
SELECT Department, Employee, Salary
FROM (
    SELECT d1.name AS Department, e1.name AS Employee, e1.salary AS Salary,
    DENSE_RANK() OVER(PARTITION BY d1.name ORDER BY e1.salary DESC) as rnk
    FROM Employee AS e1
    LEFT JOIN Department AS d1
    ON e1.departmentId = d1.id
) AS t
WHERE rnk <= 3;
