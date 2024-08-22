SELECT visit.customer_id, COUNT(visit.customer_id) AS count_no_trans 
FROM Visits visit 
LEFT JOIN Transactions trans ON visit.visit_id = trans.visit_id 
WHERE trans.transaction_id IS NULL 
GROUP BY visit.customer_id;
