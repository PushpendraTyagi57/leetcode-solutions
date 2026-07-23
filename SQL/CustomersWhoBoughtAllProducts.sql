# Write your MySQL query statement below
SELECT Customer.customer_id
FROM Customer, Product
GROUP BY Customer.customer_id
HAVING COUNT(DISTINCT Customer.product_key) = COUNT(DISTINCT Product.product_key);
