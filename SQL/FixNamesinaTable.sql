# Write your MySQL query statement below
SELECT user_id, CONCAT(UPPER(SUBSTRING(name, 1, 1)), LOWER(SUBSTRING(name, 2))) AS name
FROM Users
GROUP BY user_id
ORDER BY user_Id;