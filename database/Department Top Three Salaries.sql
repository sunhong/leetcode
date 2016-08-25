SELECT d.Name as Department, e.Name as Employee, e.Salary
FROM Employee e, Department d
WHERE (SELECT COUNT(DISTINCT Salary)
        FROM Employee
        WHERE DepartmentId = e.DepartmentId AND Salary>e.Salary)<3
        AND e.DepartmentId = d.Id