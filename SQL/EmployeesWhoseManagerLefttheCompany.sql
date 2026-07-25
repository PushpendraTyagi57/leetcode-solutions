# Write your MySQL query statement below
SELECT employee_id
FROM Employees
WHERE salary < 30000
    AND IF(SELECT NOT EXISTS(SELECT 1 FROM Employees WHERE employee_id = manager_id) AS val_missing, 1, 0);
ORDER BY employee_id;