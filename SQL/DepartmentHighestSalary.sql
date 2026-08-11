# Write your MySQL query statement below
WITH cte AS (
    SELECT d1.name AS Department, 
            e1.name AS Employee,
            e1.salary AS Salary,
            DENSE_RANK() OVER (PARTITION BY d1.name ORDER BY e1.salary DESC) AS rnk
    FROM Employee AS e1
    INNER JOIN Department AS d1
    ON e1.departmentId = d1.id
)

SELECT Department, Employee, Salary
FROM cte
WHERE rnk = 1;