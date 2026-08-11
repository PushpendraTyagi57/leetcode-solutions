# Write your MySQL query statement below
SELECT p1.product_name,
        SUM(o1.unit) AS unit
FROM Products AS p1
LEFT JOIN Orders AS o1
ON p1.product_id = o1.product_id
WHERE order_date BETWEEN '2020-02-01' AND '2020-02-29'
GROUP BY p1.product_id
HAVING SUM(o1.unit) >= 100;