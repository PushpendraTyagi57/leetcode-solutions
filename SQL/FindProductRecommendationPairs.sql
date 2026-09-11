# Write your MySQL query statement below
WITH cte AS (
    SELECT p1.*, p2.category
    FROM ProductPurchases AS p1
    INNER JOIN ProductInfo AS p2
    ON p1.product_id = p2.product_id
)
SELECT c1.product_id AS product1_id,
        c2.product_id AS product2_id,
        c1.category AS product1_category,
        c2.category AS product2_category,
        COUNT(DISTINCT c1.user_id) AS customer_count
FROM cte AS c1
INNER JOIN cte AS c2
ON c1.user_id = c2.user_id
    AND c1.product_id < c2.product_id
GROUP BY c1.product_id, c2.product_id, c1.category, c2.category
HAVING COUNT(DISTINCT c1.user_id) >= 3
ORDER BY customer_count DESC, product1_id ASC, product2_id ASC;