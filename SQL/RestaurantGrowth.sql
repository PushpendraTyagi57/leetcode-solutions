# Write your MySQL query statement below
SELECT visited_on,
        (
            SELECT SUM(amount)
            FROM Customer
            WHERE DATEDIFF(c.visited_on, visited_on) BETWEEN 0 AND 6
        ) AS amount,
        ROUND((
            SELECT SUM(amount) / 7
            FROM Customer
            WHERE DATEDIFF(c.visited_on, visited_on) BETWEEN 0 AND 6
        ), 2) AS average_amount
FROM Customer AS c
WHERE DATEDIFF (
    c.visited_on, (SELECT MIN(visited_on) FROM Customer)
) >= 6
GROUP BY c.visited_on
ORDER BY c.visited_on;