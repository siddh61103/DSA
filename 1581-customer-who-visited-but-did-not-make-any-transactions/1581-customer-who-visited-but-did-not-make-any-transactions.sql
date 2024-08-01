SELECT customer_id, COUNT(visit_id) as count_no_trans 
FROM visits
where visit_id NOT IN ( SELECT visit_id FROM transactions)
GROUP BY customer_id