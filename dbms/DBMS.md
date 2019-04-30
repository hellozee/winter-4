**Name**: Kuntal Majumder

**Roll No**: 17/4037

**Subject**: Database Management Systems Practical

**Class**: BSc.(H) Computer Science, 2nd Year



**Question 1**

```mysql
mysql> delete from issued where ACC_NO = (select ACC_NO from inventory where TITLE="MNO");
Query OK, 1 row affected (0.16 sec)

mysql> delete from inventory where TITLE="MNO";
Query OK, 1 row affected (0.16 sec)

mysql> update inventory set DEPT="CS" where TITLE="Discrete Maths";
Query OK, 1 row affected (0.22 sec)
Rows matched: 1  Changed: 1  Warnings: 0

mysql> select * from inventory where DEPT="CS";
+--------+-----------------+--------------+------+------------+-------+
| ACC_NO | TITLE           | AUTHOR       | DEPT | P_DATE     | PRICE |
+--------+-----------------+--------------+------+------------+-------+
|      1 | ABC             | X            | CS   | 2018-09-21 |   346 |
|      2 | Discrete Maths  | Anti Monitor | CS   | 2018-05-05 |   432 |
|      4 | Data Structures | X            | CS   | 2018-07-05 |   235 |
+--------+-----------------+--------------+------+------------+-------+
3 rows in set (0.00 sec)

mysql> select * from inventory where DEPT="CS" and AUTHOR="X";
+--------+-----------------+--------+------+------------+-------+
| ACC_NO | TITLE           | AUTHOR | DEPT | P_DATE     | PRICE |
+--------+-----------------+--------+------+------------+-------+
|      1 | ABC             | X      | CS   | 2018-09-21 |   346 |
|      4 | Data Structures | X      | CS   | 2018-07-05 |   235 |
+--------+-----------------+--------+------+------------+-------+
2 rows in set (0.00 sec)

mysql> select * from inventory as v,issued as i where DEPT="CS" and i.ACC_NO = v.ACC_NO;
+--------+-------+--------+------+------------+-------+--------+----------+
| ACC_NO | TITLE | AUTHOR | DEPT | P_DATE     | PRICE | ACC_NO | BORROWER |
+--------+-------+--------+------+------------+-------+--------+----------+
|      1 | ABC   | X      | CS   | 2018-09-21 |   346 |      1 | abc      |
|      1 | ABC   | X      | CS   | 2018-09-21 |   346 |      1 | xyz      |
+--------+-------+--------+------+------------+-------+--------+----------+
2 rows in set (0.00 sec)

mysql> select * from inventory where PRICE < 400 and P_DATE between "2018-01-01" and "2018-10-10";
+--------+-----------------+--------+------+------------+-------+
| ACC_NO | TITLE           | AUTHOR | DEPT | P_DATE     | PRICE |
+--------+-----------------+--------+------+------------+-------+
|      1 | ABC             | X      | CS   | 2018-09-21 |   346 |
|      4 | Data Structures | X      | CS   | 2018-07-05 |   235 |
+--------+-----------------+--------+------+------------+-------+
2 rows in set (0.00 sec)
```



**Question 2**

```mysql
mysql> select s.ROLL_NO,s.NAME,s.DOB,s.ADDRESS from student as s, academics as a where s.ROLL_NO = a.ROLL_NO and (a.P_CODE=402 and a.ATTENDANCE > 60);
+---------+--------------------+------------+--------------+
| ROLL_NO | NAME               | DOB        | ADDRESS      |
+---------+--------------------+------------+--------------+
|       1 | Freddie Mercury Jr | 1990-04-21 | Lajpat Nagar |
|       2 | Axl Rose Jr        | 1994-02-23 | APS Colony   |
|       4 | Slash Jr           | 1993-08-17 | Yamuna Bank  |
+---------+--------------------+------------+--------------+
3 rows in set (0.00 sec)

mysql> select s.NAME from student as s, academics as a where s.ROLL_NO=a.ROLL_NO and (s.ADDRESS="Lajpat Nagar" and a.P_CODE = 401 and a.MARKS > 50);
+--------------------+
| NAME               |
+--------------------+
| Freddie Mercury Jr |
+--------------------+
1 row in set (0.00 sec)

mysql> select s.NAME, sum(a.MARKS) as total_marks, sum(a.ATTENDANCE) as total_attendence from student as s, academics as a where s.ROLL_NO=a.ROLL_NO group by(a.ROLL_NO);
+--------------------+-------------+------------------+
| NAME               | total_marks | total_attendence |
+--------------------+-------------+------------------+
| Freddie Mercury Jr |      191.00 |              234 |
| Axl Rose Jr        |      230.22 |              225 |
| Myles Kennedy Jr   |      148.75 |              245 |
| Slash Jr           |      333.00 |              217 |
| Tupac Jr           |      320.00 |              302 |
+--------------------+-------------+------------------+
5 rows in set (0.00 sec)

mysql> select s.NAME from student as s, academics as a where s.ROLL_NO = a.ROLL_NO and (a.P_CODE=402 and a.MARKS = (select max(MARKS) from academics where P_CODE=402));
+----------+
| NAME     |
+----------+
| Slash Jr |
+----------+
1 row in set (0.00 sec)

```



**Question 3**

```mysql
mysql> select c.* from Customer c,Bicyclemodel m,Bicycle b where c.CUSTID=b.CUSTID and m.MODELNO=b.MODELNO and MANUFACTURER='HERO';

+--------+-----------------+-------+---------+------------+
| CustID | Email           | Name  | Phone   | ReferrerID |
+--------+-----------------+-------+---------+------------+
|      3 | Varun@GMAIL.COM | Varun | 8858890 | C3         |
+--------+-----------------+-------+---------+------------+
1 row in set (0.00 sec)

mysql> select a.BICYCLEID, a.DATEPURCHASED, a.COLOR,a.CUSTID, a.MODELNO, m.MANUFACTURER, m.MSTYLE from BICYCLE a,BICYCLEMODEL m,CUSTOMER c where c.CUSTID=a.CUSTID and m.MODELNO=a.MODELNO and c.REFERRERID='C1';

+-----------+---------------+-------+--------+---------+--------------+--------+
| BICYCLEID | DATEPURCHASED | COLOR | CUSTID | MODELNO | MANUFACTURER | MSTYLE |
+-----------+---------------+-------+--------+---------+--------------+--------+
|       202 | 2018-01-25    | BLACK |      5 |     104 | AVON         | SIMPLE |
|       203 | 2018-02-01    | BLACK |      5 |     105 | RMX          | TREX   |
+-----------+---------------+-------+--------+---------+--------------+--------+
2 rows in set (0.00 sec)

mysql> select m.MANUFACTURER from BICYCLEMODEL m, BICYCLE a where m.MODELNO=a.MODELNO and a.COLOR='RED';

+--------------+
| MANUFACTURER |
+--------------+
| BSA          |
+--------------+
1 row in set (0.00 sec)

mysql> select m.* from SERVICE s,BICYCLEMODEL m,BICYCLE b where m.MODELNO=b.MODELNO and b.BICYCLEID=s.BICYCLEID and s.STARTDATE<CURDATE() and s.ENDDATE>CURDATE();

+---------+--------------+--------+
| MODELNO | MANUFACTURER | MSTYLE |
+---------+--------------+--------+
|     104 | AVON         | SIMPLE |
|     102 | BSA          | GEARED |
+---------+--------------+--------+
2 rows in set (0.00 sec)
```



**Question 4**

```mysql
mysql> alter table Employee add Email varchar(50);

Query OK, 5 rows affected (0.03 sec)
Records: 5  Duplicates: 0  Warnings: 0

mysql> select Manager_Name,Company_Name from Manages m,Works w where Manager_Name=w.Person_Name and Company_Name="NCB Bank" and Company_Name="Samba Bank";

Empty set (0.00 sec)

mysql> select e.Person_Name,Street,City,Salary from Employee e,Works w where e.Person_Name=w.Person_Name and Company_Name="Samba Bank" and Salary >= 10000;

+-------------+-------------+-----------+--------+
| Person_Name | Street      | City      | Salary |
+-------------+-------------+-----------+--------+
| Mark        | Nithari     | Noida     |  10000 |
| Axel        | Vasant Kunj | New Delhi |  30000 |
+-------------+-------------+-----------+--------+
2 rows in set (0.00 sec)

mysql> select e.Person_Name from Works w,Company c,Employee e where e.Person_Name=w.Person_Name and w.Company_Name=c.Company_Name and e.City=c.City;

+-------------+
| Person_Name |
+-------------+
| Mark        |
| John        |
| Ray         |
+-------------+
3 rows in set (0.01 sec)

mysql>  select Company_Name,MAX(Salary),MIN(Salary),AVG(Salary) from Works group by(Company_Name);

+--------------+-------------+-------------+-------------+
| Company_Name | MAX(Salary) | MIN(Salary) | AVG(Salary) |
+--------------+-------------+-------------+-------------+
| ABCD Bank    |       50000 |       50000 |  50000.0000 |
| NCB Bank     |       60000 |        5000 |  32500.0000 |
| Samba Bank   |       30000 |       10000 |  20000.0000 |
+--------------+-------------+-------------+-------------+
3 rows in set (0.00 sec)

mysql> select Company_Name,SUM(Salary) as "Total Salary",count(*) as "Strength" from Works group by(Company_Name);

+--------------+--------------+----------+
| Company_Name | Total Salary | Strength |
+--------------+--------------+----------+
| ABCD Bank    |        50000 |        1 |
| NCB Bank     |        65000 |        2 |
| Samba Bank   |        40000 |        2 |
+--------------+--------------+----------+
3 rows in set (0.00 sec)

mysql> select Company_Name,MAX(Salary) from Works;

+--------------+-------------+
| Company_Name | MAX(Salary) |
+--------------+-------------+
| Samba Bank   |       60000 |
+--------------+-------------+
1 row in set (0.00 sec)
```



**Question 5**

```mysql
mysql> select sno from suppliers where scity="Paris";
+-----+
| sno |
+-----+
|   1 |
|   6 |
+-----+
2 rows in set (0.00 sec)

mysql> select s.sno, s.sname, s.scity, s.status from suppliers as s,shipment as p where s.sno = p.sno and p.pno = 2;
+-----+-------+----------+--------+
| sno | sname | scity    | status |
+-----+-------+----------+--------+
|   1 | s1    | Paris    | okay   |
|   3 | s3    | New York | okay   |
|   5 | s5    | Chennai  | okay   |
+-----+-------+----------+--------+
3 rows in set (0.00 sec)

mysql> select distinct s.sname from suppliers as s,shipment as p where s.sno = p.sno and p.pno != 2;
+-------+
| sname |
+-------+
| s1    |
| s2    |
| s3    |
| s4    |
| s5    |
+-------+
5 rows in set (0.00 sec)

mysql> select s.sno, s.pno, s.jno, (p.weight * s.quantity) as total_weight from shipment as s, parts as p where s.pno = p.pno;
+------+------+------+--------------+
| sno  | pno  | jno  | total_weight |
+------+------+------+--------------+
|    1 |    1 |    1 |       460.00 |
|    1 |    1 |    2 |       240.00 |
|    1 |    1 |    3 |       500.00 |
|    1 |    1 |    4 |       100.00 |
|    1 |    1 |    5 |       140.00 |
|    3 |    1 |    2 |       420.00 |
|    4 |    1 |    3 |       100.00 |
|    1 |    2 |    3 |        70.00 |
|    3 |    2 |    4 |        80.00 |
|    5 |    2 |    5 |        70.00 |
|    2 |    3 |    1 |       160.00 |
|    2 |    3 |    4 |      1240.00 |
|    5 |    3 |    6 |       480.00 |
|    2 |    4 |    3 |        10.00 |
|    4 |    4 |    2 |        45.00 |
|    3 |    5 |    6 |        30.00 |
+------+------+------+--------------+
16 rows in set (0.00 sec)

mysql> select * from shipment where quantity >= 10 and quantity <= 30;
+------+------+------+----------+
| sno  | pno  | jno  | quantity |
+------+------+------+----------+
|    1 |    1 |    1 |       23 |
|    1 |    1 |    2 |       12 |
|    1 |    1 |    3 |       25 |
|    3 |    1 |    2 |       21 |
|    5 |    3 |    6 |       12 |
+------+------+------+----------+
5 rows in set (0.00 sec)

mysql> select distinct p.pno from parts as p, shipment as s where p.weight > 16 or s.sno="s2" and p.pno = s.sno;
+-----+
| pno |
+-----+
|   1 |
|   3 |
|   6 |
+-----+
3 rows in set, 1 warning (0.00 sec)
```



**Question 6**

```mysql
mysql> select eno, ename, job_type, hire_date from employee;
+-----+--------+-----------+------------+
| eno | ename  | job_type  | hire_date  |
+-----+--------+-----------+------------+
| 736 | Smith  | clerk     | 1980-12-17 |
| 749 | Allan  | sales_man | 1981-02-20 |
| 752 | Ward   | sales_man | 1981-02-22 |
| 756 | Jones  | manager   | 1981-04-02 |
| 765 | Martin | sales_man | 1981-04-22 |
| 769 | Blake  | manager   | 1981-05-01 |
| 778 | Clarke | manager   | 1981-06-09 |
| 783 | King   | president | 1981-11-17 |
| 784 | Turner | sales_man | 1981-09-08 |
| 787 | Adams  | clerk     | 1983-01-12 |
| 788 | Scott  | analyst   | 1982-12-09 |
| 790 | James  | clerk     | 1981-12-03 |
| 792 | Ford   | analyst   | 1981-12-03 |
| 793 | Miller | clerk     | 1982-01-23 |
+-----+--------+-----------+------------+
14 rows in set (0.00 sec)

mysql> select distinct job_type from employee;
+-----------+
| job_type  |
+-----------+
| clerk     |
| sales_man |
| manager   |
| president |
| analyst   |
+-----------+
5 rows in set (0.00 sec)

mysql> select concat(ename, ",", job_type) from employee;
+------------------------------+
| concat(ename, ",", job_type) |
+------------------------------+
| Smith,clerk                  |
| Allan,sales_man              |
| Ward,sales_man               |
| Jones,manager                |
| Martin,sales_man             |
| Blake,manager                |
| Clarke,manager               |
| King,president               |
| Turner,sales_man             |
| Adams,clerk                  |
| Scott,analyst                |
| James,clerk                  |
| Ford,analyst                 |
| Miller,clerk                 |
+------------------------------+
14 rows in set (0.00 sec)

mysql> select concat_ws(",", eno, ename, job_type, manager, hire_date, dno, commission, salary) as THE_OUTPUT from employee;
+--------------------------------------------------------+
| THE_OUTPUT                                             |
+--------------------------------------------------------+
| 736,Smith,clerk,790,1980-12-17,20,0.00,1000.00         |
| 749,Allan,sales_man,769,1981-02-20,30,300.00,2000.00   |
| 752,Ward,sales_man,769,1981-02-22,30,500.00,1300.00    |
| 756,Jones,manager,783,1981-04-02,20,0.00,2300.00       |
| 765,Martin,sales_man,778,1981-04-22,30,1400.00,1250.00 |
| 769,Blake,manager,783,1981-05-01,30,0.00,2870.00       |
| 778,Clarke,manager,783,1981-06-09,10,0.00,2900.00      |
| 783,King,president,1981-11-17,10,0.00,2950.00          |
| 784,Turner,sales_man,769,1981-09-08,30,0.00,1450.00    |
| 787,Adams,clerk,778,1983-01-12,20,0.00,1150.00         |
| 788,Scott,analyst,756,1982-12-09,20,0.00,2850.00       |
| 790,James,clerk,769,1981-12-03,30,0.00,950.00          |
| 792,Ford,analyst,756,1981-12-03,20,0.00,2600.00        |
| 793,Miller,clerk,788,1982-01-23,40,0.00,1300.00        |
+--------------------------------------------------------+
14 rows in set (0.00 sec)

mysql> select ename, salary from employee where salary+commission > 2850.00;
+--------+---------+
| ename  | salary  |
+--------+---------+
| Blake  | 2870.00 |
| Clarke | 2900.00 |
| King   | 2950.00 |
+--------+---------+
3 rows in set (0.00 sec)

mysql> select ename, dno from employee where eno=790;
+-------+------+
| ename | dno  |
+-------+------+
| James |   30 |
+-------+------+
1 row in set (0.00 sec)

mysql> select ename, salary from employee where salary not between 1500.00 and 2850.00;   
+--------+---------+
| ename  | salary  |
+--------+---------+
| Smith  | 1000.00 |
| Ward   | 1300.00 |
| Martin | 1250.00 |
| Blake  | 2870.00 |
| Clarke | 2900.00 |
| King   | 2950.00 |
| Turner | 1450.00 |
| Adams  | 1150.00 |
| James  |  950.00 |
| Miller | 1300.00 |
+--------+---------+
10 rows in set (0.00 sec)

mysql> select ename, job_type, hire_date from employee where hire_date between "1981-02-20" and "1981-05-01" order by (hire_date);
+--------+-----------+------------+
| ename  | job_type  | hire_date  |
+--------+-----------+------------+
| Allan  | sales_man | 1981-02-20 |
| Ward   | sales_man | 1981-02-22 |
| Jones  | manager   | 1981-04-02 |
| Martin | sales_man | 1981-04-22 |
| Blake  | manager   | 1981-05-01 |
+--------+-----------+------------+
5 rows in set (0.00 sec)

mysql> select ename, dno from employee where dno = 10 or dno = 30 order by(ename);
+--------+------+
| ename  | dno  |
+--------+------+
| Allan  |   30 |
| Blake  |   30 |
| Clarke |   10 |
| James  |   30 |
| King   |   10 |
| Martin |   30 |
| Turner |   30 |
| Ward   |   30 |
+--------+------+
8 rows in set (0.00 sec)

mysql> select ename, salary from employee where dno = 10 or dno = 30 and salary>1500.00;
+--------+---------+
| ename  | salary  |
+--------+---------+
| Allan  | 2000.00 |
| Blake  | 2870.00 |
| Clarke | 2900.00 |
| King   | 2950.00 |
+--------+---------+
4 rows in set (0.00 sec)

mysql> select ename, hire_date from employee where year(hire_date) = 1981;
+--------+------------+
| ename  | hire_date  |
+--------+------------+
| Allan  | 1981-02-20 |
| Ward   | 1981-02-22 |
| Jones  | 1981-04-02 |
| Martin | 1981-04-22 |
| Blake  | 1981-05-01 |
| Clarke | 1981-06-09 |
| King   | 1981-11-17 |
| Turner | 1981-09-08 |
| James  | 1981-12-03 |
| Ford   | 1981-12-03 |
+--------+------------+
10 rows in set (0.00 sec)

mysql> select ename,job_type from employee where manager is NULL;
+-------+-----------+
| ename | job_type  |
+-------+-----------+
| King  | president |
+-------+-----------+
1 row in set (0.00 sec)

mysql> select ename, salary, commission from employee where commission > 0.00 order by salary desc, commission desc;
+--------+---------+------------+
| ename  | salary  | commission |
+--------+---------+------------+
| Allan  | 2000.00 |     300.00 |
| Ward   | 1300.00 |     500.00 |
| Martin | 1250.00 |    1400.00 |
+--------+---------+------------+
3 rows in set (0.00 sec)

mysql> select ename from employee where ename like "__a%";
+--------+
| ename  |
+--------+
| Blake  |
| Clarke |
| Adams  |
+--------+
3 rows in set (0.00 sec)

mysql> select ename from employee where ename like '%r%r%' or ename like '%a%a%' and (dno=30 OR manager="788");
+--------+
| ename  |
+--------+
| Allan  |
| Turner |
+--------+
2 rows in set (0.00 sec)

mysql> select ename, job_type, salary from employee where job_type = "clerk" or job_type = "analyst" and salary not in (1000.00,3000.00,5000.00);
+--------+----------+---------+
| ename  | job_type | salary  |
+--------+----------+---------+
| Smith  | clerk    | 1000.00 |
| Adams  | clerk    | 1150.00 |
| Scott  | analyst  | 2850.00 |
| James  | clerk    |  950.00 |
| Ford   | analyst  | 2600.00 |
| Miller | clerk    | 1300.00 |
+--------+----------+---------+
6 rows in set (0.01 sec)

mysql> select ename, salary, commission from employee where commission > salary * 1.05;
+--------+---------+------------+
| ename  | salary  | commission |
+--------+---------+------------+
| Martin | 1250.00 |    1400.00 |
+--------+---------+------------+
1 row in set (0.00 sec)

mysql> select curdate();
+------------+
| curdate()  |
+------------+
| 2019-04-04 |
+------------+
1 row in set (0.00 sec)

mysql> select ename, salary, round(salary * 1.15) as new_salary from employee;
+--------+---------+------------+
| ename  | salary  | new_salary |
+--------+---------+------------+
| Smith  | 1000.00 |       1150 |
| Allan  | 2000.00 |       2300 |
| Ward   | 1300.00 |       1495 |
| Jones  | 2300.00 |       2645 |
| Martin | 1250.00 |       1438 |
| Blake  | 2870.00 |       3301 |
| Clarke | 2900.00 |       3335 |
| King   | 2950.00 |       3393 |
| Turner | 1450.00 |       1668 |
| Adams  | 1150.00 |       1323 |
| Scott  | 2850.00 |       3278 |
| James  |  950.00 |       1093 |
| Ford   | 2600.00 |       2990 |
| Miller | 1300.00 |       1495 |
+--------+---------+------------+
14 rows in set (0.00 sec)

mysql> select ename, hire_date, timestampadd(MONTH,6,hire_date)  sal_review from employee;
+--------+------------+------------+
| ename  | hire_date  | sal_review |
+--------+------------+------------+
| Smith  | 1980-12-17 | 1981-06-17 |
| Allan  | 1981-02-20 | 1981-08-20 |
| Ward   | 1981-02-22 | 1981-08-22 |
| Jones  | 1981-04-02 | 1981-10-02 |
| Martin | 1981-04-22 | 1981-10-22 |
| Blake  | 1981-05-01 | 1981-11-01 |
| Clarke | 1981-06-09 | 1981-12-09 |
| King   | 1981-11-17 | 1982-05-17 |
| Turner | 1981-09-08 | 1982-03-08 |
| Adams  | 1983-01-12 | 1983-07-12 |
| Scott  | 1982-12-09 | 1983-06-09 |
| James  | 1981-12-03 | 1982-06-03 |
| Ford   | 1981-12-03 | 1982-06-03 |
| Miller | 1982-01-23 | 1982-07-23 |
+--------+------------+------------+
14 rows in set (0.00 sec)

mysql> select * from employee where salary > (select max(salary) from employee where job_type="clerk");
+-----+--------+-----------+---------+------------+------+------------+---------+
| eno | ename  | job_type  | manager | hire_date  | dno  | commission | salary  |
+-----+--------+-----------+---------+------------+------+------------+---------+
| 749 | Allan  | sales_man | 769     | 1981-02-20 |   30 |     300.00 | 2000.00 |
| 756 | Jones  | manager   | 783     | 1981-04-02 |   20 |       0.00 | 2300.00 |
| 769 | Blake  | manager   | 783     | 1981-05-01 |   30 |       0.00 | 2870.00 |
| 778 | Clarke | manager   | 783     | 1981-06-09 |   10 |       0.00 | 2900.00 |
| 783 | King   | president | NULL    | 1981-11-17 |   10 |       0.00 | 2950.00 |
| 784 | Turner | sales_man | 769     | 1981-09-08 |   30 |       0.00 | 1450.00 |
| 788 | Scott  | analyst   | 756     | 1982-12-09 |   20 |       0.00 | 2850.00 |
| 792 | Ford   | analyst   | 756     | 1981-12-03 |   20 |       0.00 | 2600.00 |
+-----+--------+-----------+---------+------------+------+------------+---------+
8 rows in set (0.00 sec)

mysql> select ename, timestampdiff(MONTH, hire_date, CURRENT_DATE()) as tenure  from employee;
+--------+--------+
| ename  | tenure |
+--------+--------+
| Smith  |    459 |
| Allan  |    457 |
| Ward   |    457 |
| Jones  |    456 |
| Martin |    455 |
| Blake  |    455 |
| Clarke |    453 |
| King   |    448 |
| Turner |    450 |
| Adams  |    434 |
| Scott  |    435 |
| James  |    448 |
| Ford   |    448 |
| Miller |    446 |
+--------+--------+
14 rows in set (0.00 sec)

mysql> select concat(ename," earns ", salary , " monthly but wants ", 3 * salary) as dream_salary from employee;
+------------------------------------------------+
| dream_salary                                   |
+------------------------------------------------+
| Smith earns 1000.00 monthly but wants 3000.00  |
| Allan earns 2000.00 monthly but wants 6000.00  |
| Ward earns 1300.00 monthly but wants 3900.00   |
| Jones earns 2300.00 monthly but wants 6900.00  |
| Martin earns 1250.00 monthly but wants 3750.00 |
| Blake earns 2870.00 monthly but wants 8610.00  |
| Clarke earns 2900.00 monthly but wants 8700.00 |
| King earns 2950.00 monthly but wants 8850.00   |
| Turner earns 1450.00 monthly but wants 4350.00 |
| Adams earns 1150.00 monthly but wants 3450.00  |
| Scott earns 2850.00 monthly but wants 8550.00  |
| James earns 950.00 monthly but wants 2850.00   |
| Ford earns 2600.00 monthly but wants 7800.00   |
| Miller earns 1300.00 monthly but wants 3900.00 |
+------------------------------------------------+
14 rows in set (0.00 sec)

mysql> select ename, rpad(salary, 15, "$") as sal from employee;
+--------+-----------------+
| ename  | sal             |
+--------+-----------------+
| Smith  | 1000.00$$$$$$$$ |
| Allan  | 2000.00$$$$$$$$ |
| Ward   | 1300.00$$$$$$$$ |
| Jones  | 2300.00$$$$$$$$ |
| Martin | 1250.00$$$$$$$$ |
| Blake  | 2870.00$$$$$$$$ |
| Clarke | 2900.00$$$$$$$$ |
| King   | 2950.00$$$$$$$$ |
| Turner | 1450.00$$$$$$$$ |
| Adams  | 1150.00$$$$$$$$ |
| Scott  | 2850.00$$$$$$$$ |
| James  | 950.00$$$$$$$$$ |
| Ford   | 2600.00$$$$$$$$ |
| Miller | 1300.00$$$$$$$$ |
+--------+-----------------+
14 rows in set (0.00 sec)

mysql> select concat(ucase(left(ename,1)), lcase(substring(ename,2))) as name from employee where ename like "J%" or ename like "A&" or ename like "M%";
+--------+
| name   |
+--------+
| Jones  |
| Martin |
| James  |
| Miller |
+--------+
4 rows in set (0.01 sec)

mysql> select ename, hire_date, dayofweek(hire_date) as day from employee;
+--------+------------+------+
| ename  | hire_date  | day  |
+--------+------------+------+
| Smith  | 1980-12-17 |    4 |
| Allan  | 1981-02-20 |    6 |
| Ward   | 1981-02-22 |    1 |
| Jones  | 1981-04-02 |    5 |
| Martin | 1981-04-22 |    4 |
| Blake  | 1981-05-01 |    6 |
| Clarke | 1981-06-09 |    3 |
| King   | 1981-11-17 |    3 |
| Turner | 1981-09-08 |    3 |
| Adams  | 1983-01-12 |    4 |
| Scott  | 1982-12-09 |    5 |
| James  | 1981-12-03 |    5 |
| Ford   | 1981-12-03 |    5 |
| Miller | 1982-01-23 |    7 |
+--------+------------+------+
14 rows in set (0.00 sec)

mysql> select ename, if(commission = 0.00, "No Commission", commission) as comm from employee;
+--------+---------------+
| ename  | comm          |
+--------+---------------+
| Smith  | No Commission |
| Allan  | 300.00        |
| Ward   | 500.00        |
| Jones  | No Commission |
| Martin | 1400.00       |
| Blake  | No Commission |
| Clarke | No Commission |
| King   | No Commission |
| Turner | No Commission |
| Adams  | No Commission |
| Scott  | No Commission |
| James  | No Commission |
| Ford   | No Commission |
| Miller | No Commission |
+--------+---------------+
14 rows in set (0.00 sec)

mysql> select e.ename, e.dno, d.dname from employee as e, department as d where e.dno = d.dno;
+--------+------+------------+
| ename  | dno  | dname      |
+--------+------+------------+
| Clarke |   10 | Accounting |
| King   |   10 | Accounting |
| Smith  |   20 | Research   |
| Jones  |   20 | Research   |
| Adams  |   20 | Research   |
| Scott  |   20 | Research   |
| Ford   |   20 | Research   |
| Allan  |   30 | Sales      |
| Ward   |   30 | Sales      |
| Martin |   30 | Sales      |
| Blake  |   30 | Sales      |
| Turner |   30 | Sales      |
| James  |   30 | Sales      |
| Miller |   40 | Operation  |
+--------+------+------------+
14 rows in set (0.00 sec)

mysql> select distinct job_type from employee where dno = 30;
+-----------+
| job_type  |
+-----------+
| sales_man |
| manager   |
| clerk     |
+-----------+
3 rows in set (0.00 sec)

mysql> select e.ename, e.dno, d.location from employee as e, department as d where e.dno = d.dno;
+--------+------+----------+
| ename  | dno  | location |
+--------+------+----------+
| Clarke |   10 | New York |
| King   |   10 | New York |
| Smith  |   20 | Dallas   |
| Jones  |   20 | Dallas   |
| Adams  |   20 | Dallas   |
| Scott  |   20 | Dallas   |
| Ford   |   20 | Dallas   |
| Allan  |   30 | Chicago  |
| Ward   |   30 | Chicago  |
| Martin |   30 | Chicago  |
| Blake  |   30 | Chicago  |
| Turner |   30 | Chicago  |
| James  |   30 | Chicago  |
| Miller |   40 | Boston   |
+--------+------+----------+
14 rows in set (0.00 sec)

mysql> select ename, dname from employee as e, department as d where e.dno = d.dno and (e.ename like "%A%" or e.ename like "%a%");
+--------+------------+
| ename  | dname      |
+--------+------------+
| Allan  | Sales      |
| Ward   | Sales      |
| Martin | Sales      |
| Blake  | Sales      |
| Clarke | Accounting |
| Adams  | Research   |
| James  | Sales      |
+--------+------------+
7 rows in set (0.00 sec)

mysql> select ename, job_type, e.dno,dname from employee as e, department as d where e.dno = d.dno and d.location="Dallas";
+-------+----------+------+----------+
| ename | job_type | dno  | dname    |
+-------+----------+------+----------+
| Smith | clerk    |   20 | Research |
| Jones | manager  |   20 | Research |
| Adams | clerk    |   20 | Research |
| Scott | analyst  |   20 | Research |
| Ford  | analyst  |   20 | Research |
+-------+----------+------+----------+
5 rows in set (0.00 sec)

mysql> select ename, eno, (select ename from employee as e2 where  e1.manager = e2.eno) as mname, manager from employee as e1 where e1.manager is not null;
+--------+-----+--------+---------+
| ename  | eno | mname  | manager |
+--------+-----+--------+---------+
| Smith  | 736 | James  | 790     |
| Allan  | 749 | Blake  | 769     |
| Ward   | 752 | Blake  | 769     |
| Jones  | 756 | King   | 783     |
| Martin | 765 | Clarke | 778     |
| Blake  | 769 | King   | 783     |
| Clarke | 778 | King   | 783     |
| Turner | 784 | Blake  | 769     |
| Adams  | 787 | Clarke | 778     |
| Scott  | 788 | Jones  | 756     |
| James  | 790 | Blake  | 769     |
| Ford   | 792 | Jones  | 756     |
| Miller | 793 | Scott  | 788     |
+--------+-----+--------+---------+
13 rows in set (0.01 sec)

mysql> select ename, eno, (select ename from employee as e2 where  e1.manager = e2.eno) as mname, manager from employee as e1;
+--------+-----+--------+---------+
| ename  | eno | mname  | manager |
+--------+-----+--------+---------+
| Smith  | 736 | James  | 790     |
| Allan  | 749 | Blake  | 769     |
| Ward   | 752 | Blake  | 769     |
| Jones  | 756 | King   | 783     |
| Martin | 765 | Clarke | 778     |
| Blake  | 769 | King   | 783     |
| Clarke | 778 | King   | 783     |
| King   | 783 | NULL   | NULL    |
| Turner | 784 | Blake  | 769     |
| Adams  | 787 | Clarke | 778     |
| Scott  | 788 | Jones  | 756     |
| James  | 790 | Blake  | 769     |
| Ford   | 792 | Jones  | 756     |
| Miller | 793 | Scott  | 788     |
+--------+-----+--------+---------+
14 rows in set (0.00 sec)

mysql> select eno, ename, salary from employee where salary > (select avg(salary) from employee)  and dno in (select dno from employee where ename like "%t%" or ename like "%T%");
+-----+-------+---------+
| eno | ename | salary  |
+-----+-------+---------+
| 756 | Jones | 2300.00 |
| 788 | Scott | 2850.00 |
| 792 | Ford  | 2600.00 |
| 749 | Allan | 2000.00 |
| 769 | Blake | 2870.00 |
+-----+-------+---------+
5 rows in set (0.00 sec)

mysql> select ename, dno, salary from employee where dno in (select dno from employee where commission > 0.00) and salary in (select salary from employee where commission > 0.00);
+--------+------+---------+
| ename  | dno  | salary  |
+--------+------+---------+
| Allan  |   30 | 2000.00 |
| Ward   |   30 | 1300.00 |
| Martin |   30 | 1250.00 |
+--------+------+---------+
3 rows in set (0.00 sec)

mysql> select ename, hire_date from employee where hire_date > (select hire_date from employee where ename="Blake");
+--------+------------+
| ename  | hire_date  |
+--------+------------+
| Clarke | 1981-06-09 |
| King   | 1981-11-17 |
| Turner | 1981-09-08 |
| Adams  | 1983-01-12 |
| Scott  | 1982-12-09 |
| James  | 1981-12-03 |
| Ford   | 1981-12-03 |
| Miller | 1982-01-23 |
+--------+------------+
8 rows in set (0.00 sec)

mysql> select e1.ename, e1.hire_date, (select e2.ename from employee as e2 where e1.manager = e2.eno) as manager, (select e2.hire_date from employee as e2 where e1.manager = e2.eno)as m_hire_date  from employee as e1 where e1.hire_date < (select e2.hire_date from employee as e2 where e1.manager = e2.eno);
+--------+------------+---------+-------------+
| ename  | hire_date  | manager | m_hire_date |
+--------+------------+---------+-------------+
| Smith  | 1980-12-17 | James   | 1981-12-03  |
| Allan  | 1981-02-20 | Blake   | 1981-05-01  |
| Ward   | 1981-02-22 | Blake   | 1981-05-01  |
| Jones  | 1981-04-02 | King    | 1981-11-17  |
| Martin | 1981-04-22 | Clarke  | 1981-06-09  |
| Blake  | 1981-05-01 | King    | 1981-11-17  |
| Clarke | 1981-06-09 | King    | 1981-11-17  |
| Miller | 1982-01-23 | Scott   | 1982-12-09  |
+--------+------------+---------+-------------+
8 rows in set (0.01 sec)

mysql> select ename, rpad('',floor(salary/100),"*") as sal from employee;
+--------+-------------------------------+
| ename  | sal                           |
+--------+-------------------------------+
| Smith  | **********                    |
| Allan  | ********************          |
| Ward   | *************                 |
| Jones  | ***********************       |
| Martin | ************                  |
| Blake  | ****************************  |
| Clarke | ***************************** |
| King   | ***************************** |
| Turner | **************                |
| Adams  | ***********                   |
| Scott  | ****************************  |
| James  | *********                     |
| Ford   | **************************    |
| Miller | *************                 |
+--------+-------------------------------+
14 rows in set (0.00 sec)

mysql> select avg(salary) as average, max(salary) as highest, min(salary) as lowest, sum(salary) as sum from employee;
+-------------+---------+--------+----------+
| average     | highest | lowest | sum      |
+-------------+---------+--------+----------+
| 1919.285714 | 2950.00 | 950.00 | 26870.00 |
+-------------+---------+--------+----------+
1 row in set (0.00 sec)

mysql> select avg(salary) as average, max(salary) as highest, min(salary) as lowest, sum(salary) as sum, job_type from employee group by(job_type);
+-------------+---------+---------+---------+-----------+
| average     | highest | lowest  | sum     | job_type  |
+-------------+---------+---------+---------+-----------+
| 2725.000000 | 2850.00 | 2600.00 | 5450.00 | analyst   |
| 1100.000000 | 1300.00 |  950.00 | 4400.00 | clerk     |
| 2690.000000 | 2900.00 | 2300.00 | 8070.00 | manager   |
| 2950.000000 | 2950.00 | 2950.00 | 2950.00 | president |
| 1500.000000 | 2000.00 | 1250.00 | 6000.00 | sales_man |
+-------------+---------+---------+---------+-----------+

mysql> select count(eno), job_type from employee group by job_type;
+------------+-----------+
| count(eno) | job_type  |
+------------+-----------+
|          2 | analyst   |
|          4 | clerk     |
|          3 | manager   |
|          1 | president |
|          4 | sales_man |
+------------+-----------+
5 rows in set (0.00 sec)

mysql> select count(eno) as no_of_managers from employee where job_type="manager";
+----------------+
| no_of_managers |
+----------------+
|              3 |
+----------------+
1 row in set (0.01 sec)

mysql> select max(salary) - min(salary) as diff from employee;
+---------+
| diff    |
+---------+
| 2000.00 |
+---------+
1 row in set (0.01 sec)

mysql> select manager, min(salary) as min_sal from employee as e1 where manager is not null and (select min(salary) from employee as e2 where e1.manager = e2.manager group by manager) > 1000.00 group by manager;
+---------+---------+
| manager | min_sal |
+---------+---------+
| 756     | 2600.00 |
| 778     | 1150.00 |
| 783     | 2300.00 |
| 788     | 1300.00 |
+---------+---------+
4 rows in set (0.00 sec)

mysql> select d.dname, d.location, count(e.eno) as no_emp, avg(e.salary) as avg_sal  from employee as e, department as d where e.dno = d.dno group by e.dno;
+------------+----------+--------+-------------+
| dname      | location | no_emp | avg_sal     |
+------------+----------+--------+-------------+
| Accounting | New York |      2 | 2925.000000 |
| Research   | Dallas   |      5 | 1980.000000 |
| Sales      | Chicago  |      6 | 1636.666667 |
| Operation  | Boston   |      1 | 1300.000000 |
+------------+----------+--------+-------------+
4 rows in set (0.00 sec)

mysql> select ename, hire_date from employee where dno = (select dno from employee where ename="Blake");
+--------+------------+
| ename  | hire_date  |
+--------+------------+
| Allan  | 1981-02-20 |
| Ward   | 1981-02-22 |
| Martin | 1981-04-22 |
| Blake  | 1981-05-01 |
| Turner | 1981-09-08 |
| James  | 1981-12-03 |
+--------+------------+
6 rows in set (0.00 sec)

mysql> select eno, ename from employee where salary > (select avg(salary) from employee);
+-----+--------+
| eno | ename  |
+-----+--------+
| 749 | Allan  |
| 756 | Jones  |
| 769 | Blake  |
| 778 | Clarke |
| 783 | King   |
| 788 | Scott  |
| 792 | Ford   |
+-----+--------+
7 rows in set (0.00 sec)

mysql> select ename, salary from employee where dno in (select dno from employee where ename like "%t%" or ename like "%T%"); +--------+---------+
| ename  | salary  |
+--------+---------+
| Smith  | 1000.00 |
| Allan  | 2000.00 |
| Ward   | 1300.00 |
| Jones  | 2300.00 |
| Martin | 1250.00 |
| Blake  | 2870.00 |
| Turner | 1450.00 |
| Adams  | 1150.00 |
| Scott  | 2850.00 |
| James  |  950.00 |
| Ford   | 2600.00 |
+--------+---------+
11 rows in set (0.00 sec)

mysql> select ename, salary from employee where manager = (select eno from employee where ename="King");
+--------+---------+
| ename  | salary  |
+--------+---------+
| Jones  | 2300.00 |
| Blake  | 2870.00 |
| Clarke | 2900.00 |
+--------+---------+
3 rows in set (0.00 sec)

mysql> select e.dno, e.ename, e.job_type from employee as e, department as d where d.dno = e.dno and e.dno = (select dno from department where dname = "Sales");
+------+--------+-----------+
| dno  | ename  | job_type  |
+------+--------+-----------+
|   30 | Allan  | sales_man |
|   30 | Ward   | sales_man |
|   30 | Martin | sales_man |
|   30 | Blake  | manager   |
|   30 | Turner | sales_man |
|   30 | James  | clerk     |
+------+--------+-----------+
6 rows in set (0.00 sec)

mysql> select ename from employee as e1 where salary > (select avg(salary) from employee as e2 where e1.dno = e2.dno);
+-------+
| ename |
+-------+
| Allan |
| Jones |
| Blake |
| King  |
| Scott |
| Ford  |
+-------+
6 rows in set (0.00 sec)
```

