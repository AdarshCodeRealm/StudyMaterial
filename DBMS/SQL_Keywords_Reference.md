# SQL Keywords Reference Guide

A comprehensive guide to SQL keywords, functions, and operators used in the SQL 50 LeetCode problems.

## 📋 Table of Contents
- [Basic Query Keywords](#basic-query-keywords)
- [Join Operations](#join-operations)
- [Aggregate Functions](#aggregate-functions)
- [Window Functions](#window-functions)
- [Date & Time Functions](#date--time-functions)
- [String Functions](#string-functions)
- [Conditional Logic](#conditional-logic)
- [Advanced Concepts](#advanced-concepts)
- [Operators & Comparisons](#operators--comparisons)

---

## Basic Query Keywords

### **SELECT**
- **Purpose**: Retrieves data from database tables
- **Usage**: `SELECT column1, column2 FROM table`
- **Example**: `SELECT name, age FROM users`

### **FROM**
- **Purpose**: Specifies the source table(s) for the query
- **Usage**: `SELECT * FROM table_name`
- **Example**: `SELECT * FROM employees`

### **WHERE**
- **Purpose**: Filters rows based on specified conditions
- **Usage**: `SELECT * FROM table WHERE condition`
- **Example**: `SELECT * FROM products WHERE price > 100`

### **ORDER BY**
- **Purpose**: Sorts the result set by one or more columns
- **Usage**: `ORDER BY column [ASC|DESC]`
- **Example**: `SELECT * FROM users ORDER BY age DESC, name ASC`

### **GROUP BY**
- **Purpose**: Groups rows with same values into summary rows
- **Usage**: `SELECT column, COUNT(*) FROM table GROUP BY column`
- **Example**: `SELECT department, COUNT(*) FROM employees GROUP BY department`

### **HAVING**
- **Purpose**: Filters groups created by GROUP BY (like WHERE for groups)
- **Usage**: `GROUP BY column HAVING condition`
- **Example**: `SELECT department, COUNT(*) FROM employees GROUP BY department HAVING COUNT(*) > 5`

### **DISTINCT**
- **Purpose**: Returns only unique/different values
- **Usage**: `SELECT DISTINCT column FROM table`
- **Example**: `SELECT DISTINCT country FROM customers`

### **LIMIT**
- **Purpose**: Limits the number of rows returned
- **Usage**: `SELECT * FROM table LIMIT number`
- **Example**: `SELECT * FROM products LIMIT 10`

### **OFFSET**
- **Purpose**: Skips specified number of rows before returning results
- **Usage**: `SELECT * FROM table LIMIT 10 OFFSET 5`
- **Example**: `SELECT * FROM users ORDER BY id LIMIT 1 OFFSET 1` (second highest)

---

## Join Operations

### **INNER JOIN**
- **Purpose**: Returns records that have matching values in both tables
- **Usage**: `SELECT * FROM table1 INNER JOIN table2 ON condition`
- **Example**: `SELECT * FROM orders INNER JOIN customers ON orders.customer_id = customers.id`

### **LEFT JOIN (LEFT OUTER JOIN)**
- **Purpose**: Returns all records from left table, matched records from right table
- **Usage**: `SELECT * FROM table1 LEFT JOIN table2 ON condition`
- **Example**: `SELECT * FROM customers LEFT JOIN orders ON customers.id = orders.customer_id`

### **RIGHT JOIN (RIGHT OUTER JOIN)**
- **Purpose**: Returns all records from right table, matched records from left table
- **Usage**: `SELECT * FROM table1 RIGHT JOIN table2 ON condition`
- **Example**: `SELECT * FROM orders RIGHT JOIN customers ON orders.customer_id = customers.id`

### **FULL OUTER JOIN**
- **Purpose**: Returns all records when there's a match in either table
- **Usage**: `SELECT * FROM table1 FULL OUTER JOIN table2 ON condition`
- **Example**: `SELECT * FROM customers FULL OUTER JOIN orders ON customers.id = orders.customer_id`

### **CROSS JOIN**
- **Purpose**: Returns Cartesian product of both tables
- **Usage**: `SELECT * FROM table1 CROSS JOIN table2`
- **Example**: `SELECT * FROM colors CROSS JOIN sizes`

### **Self JOIN**
- **Purpose**: Joins a table with itself
- **Usage**: `SELECT * FROM table1 a, table1 b WHERE condition`
- **Example**: `SELECT e1.name, e2.name FROM employees e1, employees e2 WHERE e1.manager_id = e2.id`

---

## Aggregate Functions

### **COUNT()**
- **Purpose**: Returns the number of rows
- **Usage**: `COUNT(column)` or `COUNT(*)`
- **Example**: `SELECT COUNT(*) FROM users`, `SELECT COUNT(DISTINCT country) FROM customers`

### **SUM()**
- **Purpose**: Returns the sum of numeric values
- **Usage**: `SUM(column)`
- **Example**: `SELECT SUM(salary) FROM employees`

### **AVG()**
- **Purpose**: Returns the average value
- **Usage**: `AVG(column)`
- **Example**: `SELECT AVG(price) FROM products`

### **MIN()**
- **Purpose**: Returns the minimum value
- **Usage**: `MIN(column)`
- **Example**: `SELECT MIN(age) FROM users`

### **MAX()**
- **Purpose**: Returns the maximum value
- **Usage**: `MAX(column)`
- **Example**: `SELECT MAX(salary) FROM employees`

### **GROUP_CONCAT()**
- **Purpose**: Concatenates values from multiple rows into a single string
- **Usage**: `GROUP_CONCAT(column [ORDER BY column] [SEPARATOR 'sep'])`
- **Example**: `SELECT GROUP_CONCAT(product_name) FROM products`

---

## Window Functions

### **ROW_NUMBER()**
- **Purpose**: Assigns a unique sequential integer to each row
- **Usage**: `ROW_NUMBER() OVER (ORDER BY column)`
- **Example**: `SELECT *, ROW_NUMBER() OVER (ORDER BY salary DESC) as rn FROM employees`

### **RANK()**
- **Purpose**: Assigns rank with gaps for tied values
- **Usage**: `RANK() OVER (ORDER BY column)`
- **Example**: `SELECT *, RANK() OVER (ORDER BY score DESC) as rank FROM students`

### **DENSE_RANK()**
- **Purpose**: Assigns rank without gaps for tied values
- **Usage**: `DENSE_RANK() OVER (ORDER BY column)`
- **Example**: `SELECT *, DENSE_RANK() OVER (ORDER BY salary DESC) as dense_rank FROM employees`

### **LEAD()**
- **Purpose**: Accesses data from next row
- **Usage**: `LEAD(column, offset, default) OVER (ORDER BY column)`
- **Example**: `SELECT *, LEAD(salary, 1, 0) OVER (ORDER BY hire_date) as next_salary FROM employees`

### **LAG()**
- **Purpose**: Accesses data from previous row
- **Usage**: `LAG(column, offset, default) OVER (ORDER BY column)`
- **Example**: `SELECT *, LAG(temperature) OVER (ORDER BY date) as prev_temp FROM weather`

### **FIRST_VALUE()**
- **Purpose**: Returns the first value in ordered partition
- **Usage**: `FIRST_VALUE(column) OVER (PARTITION BY col ORDER BY col2)`
- **Example**: `SELECT *, FIRST_VALUE(salary) OVER (PARTITION BY department ORDER BY hire_date) FROM employees`

### **LAST_VALUE()**
- **Purpose**: Returns the last value in ordered partition
- **Usage**: `LAST_VALUE(column) OVER (PARTITION BY col ORDER BY col2)`
- **Example**: `SELECT *, LAST_VALUE(salary) OVER (PARTITION BY department ORDER BY hire_date) FROM employees`

### **OVER()**
- **Purpose**: Defines the window for window functions
- **Usage**: `OVER (PARTITION BY column ORDER BY column)`
- **Example**: `SUM(amount) OVER (PARTITION BY customer_id ORDER BY date)`

---

## Date & Time Functions

### **DATE_FORMAT()**
- **Purpose**: Formats date values
- **Usage**: `DATE_FORMAT(date, format)`
- **Example**: `SELECT DATE_FORMAT(birth_date, '%Y-%m') FROM users`

### **DATEDIFF()**
- **Purpose**: Returns difference between two dates
- **Usage**: `DATEDIFF(date1, date2)`
- **Example**: `SELECT DATEDIFF(end_date, start_date) as days_diff FROM projects`

### **DATE_ADD()**
- **Purpose**: Adds time interval to date
- **Usage**: `DATE_ADD(date, INTERVAL value unit)`
- **Example**: `SELECT DATE_ADD('2023-01-01', INTERVAL 30 DAY)`

### **DATE_SUB()**
- **Purpose**: Subtracts time interval from date
- **Usage**: `DATE_SUB(date, INTERVAL value unit)`
- **Example**: `SELECT DATE_SUB(NOW(), INTERVAL 30 DAY)`

### **INTERVAL**
- **Purpose**: Specifies time interval for date calculations
- **Usage**: `INTERVAL value unit`
- **Example**: `SELECT * FROM orders WHERE order_date >= NOW() - INTERVAL 7 DAY`

### **EXTRACT()**
- **Purpose**: Extracts part of date/time
- **Usage**: `EXTRACT(unit FROM date)`
- **Example**: `SELECT EXTRACT(YEAR FROM birth_date) FROM users`

### **YEAR(), MONTH(), DAY()**
- **Purpose**: Extract year, month, or day from date
- **Usage**: `YEAR(date)`, `MONTH(date)`, `DAY(date)`
- **Example**: `SELECT YEAR(order_date), MONTH(order_date) FROM orders`

### **NOW(), CURDATE(), CURTIME()**
- **Purpose**: Returns current datetime, date, or time
- **Usage**: `NOW()`, `CURDATE()`, `CURTIME()`
- **Example**: `SELECT NOW() as current_timestamp`

---

## String Functions

### **CONCAT()**
- **Purpose**: Concatenates two or more strings
- **Usage**: `CONCAT(string1, string2, ...)`
- **Example**: `SELECT CONCAT(first_name, ' ', last_name) as full_name FROM users`

### **LEFT()**
- **Purpose**: Returns leftmost characters from string
- **Usage**: `LEFT(string, length)`
- **Example**: `SELECT LEFT(product_name, 3) FROM products`

### **RIGHT()**
- **Purpose**: Returns rightmost characters from string
- **Usage**: `RIGHT(string, length)`
- **Example**: `SELECT RIGHT(phone_number, 4) as last_four FROM customers`

### **LENGTH()**
- **Purpose**: Returns length of string
- **Usage**: `LENGTH(string)`
- **Example**: `SELECT * FROM posts WHERE LENGTH(content) > 100`

### **UPPER()**
- **Purpose**: Converts string to uppercase
- **Usage**: `UPPER(string)`
- **Example**: `SELECT UPPER(name) FROM users`

### **LOWER()**
- **Purpose**: Converts string to lowercase
- **Usage**: `LOWER(string)`
- **Example**: `SELECT LOWER(email) FROM users`

### **SUBSTRING()**
- **Purpose**: Extracts substring from string
- **Usage**: `SUBSTRING(string, start, length)`
- **Example**: `SELECT SUBSTRING(product_code, 1, 3) FROM products`

### **LIKE**
- **Purpose**: Pattern matching in WHERE clause
- **Usage**: `column LIKE pattern`
- **Example**: `SELECT * FROM users WHERE name LIKE 'John%'`

### **REGEXP / RLIKE**
- **Purpose**: Regular expression pattern matching
- **Usage**: `column REGEXP pattern`
- **Example**: `SELECT * FROM emails WHERE email REGEXP '^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}$'`

---

## Conditional Logic

### **CASE WHEN**
- **Purpose**: Conditional logic in SELECT statements
- **Usage**: `CASE WHEN condition THEN result ELSE default END`
- **Example**: 
```sql
SELECT name, 
CASE 
    WHEN age < 18 THEN 'Minor'
    WHEN age >= 65 THEN 'Senior'
    ELSE 'Adult'
END as category
FROM users
```

### **IF()**
- **Purpose**: Simple conditional function (MySQL)
- **Usage**: `IF(condition, true_value, false_value)`
- **Example**: `SELECT name, IF(age >= 18, 'Adult', 'Minor') FROM users`

### **COALESCE()**
- **Purpose**: Returns first non-NULL value from list
- **Usage**: `COALESCE(value1, value2, ..., default)`
- **Example**: `SELECT COALESCE(phone, email, 'No contact') FROM users`

### **NULLIF()**
- **Purpose**: Returns NULL if two expressions are equal
- **Usage**: `NULLIF(expr1, expr2)`
- **Example**: `SELECT NULLIF(division_result, 0) FROM calculations`

### **IS NULL / IS NOT NULL**
- **Purpose**: Tests for NULL values
- **Usage**: `column IS NULL` or `column IS NOT NULL`
- **Example**: `SELECT * FROM users WHERE phone IS NOT NULL`

---

## Advanced Concepts

### **WITH (CTE)**
- **Purpose**: Creates temporary named result set (Common Table Expression)
- **Usage**: `WITH cte_name AS (SELECT ...) SELECT ... FROM cte_name`
- **Example**: 
```sql
WITH high_earners AS (
    SELECT * FROM employees WHERE salary > 100000
)
SELECT department, COUNT(*) FROM high_earners GROUP BY department
```

### **UNION**
- **Purpose**: Combines results from two or more SELECT statements (removes duplicates)
- **Usage**: `SELECT ... UNION SELECT ...`
- **Example**: `SELECT name FROM customers UNION SELECT name FROM suppliers`

### **UNION ALL**
- **Purpose**: Combines results including duplicates
- **Usage**: `SELECT ... UNION ALL SELECT ...`
- **Example**: `SELECT product_id FROM orders UNION ALL SELECT product_id FROM returns`

### **EXISTS**
- **Purpose**: Tests for existence of rows in subquery
- **Usage**: `WHERE EXISTS (SELECT ... FROM ... WHERE ...)`
- **Example**: `SELECT * FROM customers WHERE EXISTS (SELECT 1 FROM orders WHERE orders.customer_id = customers.id)`

### **NOT EXISTS**
- **Purpose**: Tests for non-existence of rows in subquery
- **Usage**: `WHERE NOT EXISTS (SELECT ... FROM ... WHERE ...)`
- **Example**: `SELECT * FROM customers WHERE NOT EXISTS (SELECT 1 FROM orders WHERE orders.customer_id = customers.id)`

### **IN**
- **Purpose**: Tests if value exists in list or subquery
- **Usage**: `column IN (value1, value2, ...)` or `column IN (SELECT ...)`
- **Example**: `SELECT * FROM products WHERE category_id IN (1, 2, 3)`

### **NOT IN**
- **Purpose**: Tests if value doesn't exist in list or subquery
- **Usage**: `column NOT IN (value1, value2, ...)`
- **Example**: `SELECT * FROM users WHERE id NOT IN (SELECT user_id FROM banned_users)`

---

## Operators & Comparisons

### **Arithmetic Operators**
- `+` Addition
- `-` Subtraction
- `*` Multiplication
- `/` Division
- `%` or `MOD` Modulo (remainder)

### **Comparison Operators**
- `=` Equal
- `!=` or `<>` Not equal
- `<` Less than
- `>` Greater than
- `<=` Less than or equal
- `>=` Greater than or equal

### **Logical Operators**
- `AND` Both conditions must be true
- `OR` Either condition must be true
- `NOT` Negates the condition

### **Special Operators**
- `BETWEEN` Tests if value is within range
- `ALL` Compares value to all values in subquery
- `ANY/SOME` Compares value to any value in subquery

---

## 💡 Quick Tips

1. **Performance**: Use indexes on columns in WHERE, JOIN, and ORDER BY clauses
2. **NULL Handling**: Always consider NULL values in conditions
3. **Data Types**: Be aware of implicit type conversions
4. **Subqueries**: Correlated subqueries can be slower than JOINs
5. **Window Functions**: More efficient than self-joins for ranking operations

---

**Reference Complete! 📚**

*Use this guide alongside the SQL 50 solutions for maximum learning efficiency.*