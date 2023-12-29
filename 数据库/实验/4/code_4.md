```sql
-- 4.1 1)
SELECT dno, AVG(salary)
FROM EMP
GROUP BY dno;
```



```sql
-- 2)
SELECT pno, COUNT(*) AS cnt
FROM WORKS
GROUP BY pno;
```



```sql
-- 3)
SELECT dno
FROM EMP
GROUP BY dno
HAVING AVG(salary) < 30000;
```



```sql
-- 4)
SELECT pno
FROM WORKS
GROUP BY pno
HAVING COUNT(eno) < 9;
```



```sql
-- 5)
SELECT DISTINCT dno
FROM EMP;
```



```sql
-- 6)
SELECT dno, COUNT(eno) AS number
FROM EMP
GROUP BY dno;
```



```sql
-- 7)
SELECT dno 
FROM EMP
GROUP BY dno
HAVING SUM(salary) > 300000;
```



```sql
-- 8)
SELECT COUNT(eno)
FROM EMP
WHERE salary IN (20000, 25000)
GROUP BY eno;
```



```sql
-- 4.2 1)
INSERT INTO EMP
VALUES
	( 'e51', 'mallon', 26000, 32, 'e17', 'd2');
```



```sql
-- 4.2 2)
DELETE FROM EMP
WHERE eno = 'e51';
```



```sql
-- 3)
DELETE FROM EMP
WHERE eno = 'e19';
/**
DELETE FROM EMP
WHERE eno = 'e19';
> Msg 547, Level 16, State 1, Server golitter\SQLEXPRESS, Procedure , Line 0
DELETE 语句与 REFERENCE 约束"FK__WORKS__eno__46E78A0C"冲突。该冲突发生于数据库"projemp"，表"dbo.WORKS", column 'eno'。
> 语句已终止。
> [23000] [Microsoft][SQL Server Native Client 10.0][SQL Server]DELETE 语句与 REFERENCE 约束"FK__WORKS__eno__46E78A0C"冲突。该冲突发生于数据库"projemp"，表"dbo.WORKS", column 'eno'。 (547)
[01000] [Microsoft][SQL Server Native Client 10.0][SQL Server]语句已终止。 (3621)
**/

/**
外键约束是用于维护表之间关系完整性的一种约束。在这种情况下，"dbo.WORKS"表的"eno"列是一个外键，它引用了另一个表的主键，即"EMP"表的"eno"列。

当你试图从"EMP"表中删除一个具有相关记录的行时，由于外键约束，数据库会阻止该操作，因为它可能会违反关系完整性。换句话说，"EMP"表中的某些行与"dbo.WORKS"表中的行存在关联，因此无法直接删除"EMP"表中的这些行。

解决这个问题的方法有几种：

首先，你可以查找并删除与该员工相关的所有行，包括外键约束所涉及的其他表。例如，在删除"EMP"表中的行之前，可能需要先删除与该行相关的"dbo.WORKS"表中的行。
如果你确定要删除"EMP"表中的行以及与其相关的所有行，你可以考虑禁用外键约束。在删除完相关行之后，再启用约束。
如果你不再需要该外键约束，并且确定删除该约束不会对数据完整性产生负面影响，你可以通过ALTER TABLE语句来删除该外键约束。例如，使用以下命令删除名为"FK__WORKS__eno__46E78A0C"的外键约束
**/
```



```sql
-- 4)
UPDATE PROJ
SET budget = 65000
WHERE pno = 'p13';
```



```sql
-- 5)
UPDATE EMP
SET ename = 'pearson'
WHERE ename = 'oliver';
```



```sql
-- 6)
INSERT INTO EMP(eno, ename, age, salary, supno, dno)
VALUES
	('e60', 'young', 51, 60000, 'e1', 'd1');

```



```sql
-- 7)
DELETE FROM EMP
WHERE eno = 'e60' AND ename = 'young' AND age = 51 AND salary = 60000 AND supno = 'e1' AND dno = 'd1';
```

