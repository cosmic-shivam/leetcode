# Write your MySQL query statement below

SELECT t2.product_name,t1.year,t1.price FROM Sales AS t1 INNER JOIN Product AS t2 ON t1.product_id=t2.product_id;