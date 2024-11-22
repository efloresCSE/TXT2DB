# Name: Edgar Flores

# Description
Built a relational database that can be used with SQL‑like commands entirely from scratch using C++ (about 4,500 lines of code).

# How does it work
Can be used with the command line. You can use a command like "make table employee fields last, first, dep, salary, year" followed by "insert into employee values Blow, Joe, CS, 100000, 2018" and so on. 
Alternatively, can use a batch file and read commands from a file in csv format. Example:

## File Example
make table employee fields  last, 		first, 			dep,  		salary, 	year\
insert into employee values Blow, 		Joe, 			CS,		 	100000, 	2018\
insert into employee values Blow, 		JoAnn,			Physics, 	200000, 	2016\
insert into employee values Johnson, 	Jack, 			HR, 		150000, 	2014\
insert into employee values Johnson, 	"Jimmy", 		Chemistry,	140000, 	2018\
insert into employee values Yao,	 	Jimmy, 			Math,		145000, 	2014\
insert into employee values "Yao", 		Flo, 			CS,			147000, 	2012\
insert into employee values Yang, 		Bo, 			CS,			160000, 	2013\
insert into employee values Jackson,	"Flo", 			Math,		165000, 	2017\
insert into employee values Jackson,	Bo,	 			Chemistry,	130000, 	2011\
insert into employee values "Jackson",	Billy, 			Math,	 	170000, 	2017\
insert into employee values Johnson,	"Mary Ann", 	Math,		165000, 	2014\
insert into employee values Johnson,	"Billy Bob", 	Physics,	142000, 	2014\
insert into employee values Johnson,	Billy, 			"Phys Ed",	102000, 	2014\
insert into employee values "Van Gogh",	Vincent, 		Art,		240000, 	2015\
insert into employee values "Van Gogh",	Vincent, 		CS,			245000, 	2015\
insert into employee values "Van Gogh",	"Jim Bob", 		"Phys Ed",	230000, 	2010\
select * from employee 

make table student fields fname, lname, major, age, company\
insert into student values Flo, 			Yao, 		CS, 				20, 	Google\
insert into student values Bo, 				Yang, 		CS, 				28,		Microsoft\
insert into student values "Sammuel L.", 	Jackson, 	CS, 				40,		Uber\
insert into student values "Flo", 			"Jackson", 	Math,	 			21,		Google\
insert into student values "Greg", 			"Pearson", 	Physics,			20,		Amazon\
insert into student values "Jim Bob", 		Smith, 		Math,	 			23,		Verizon\
insert into student values Calvin, 			Woo, 		Physics,			22,		Uber\
insert into student values "Anna Grace", 	"Del Rio", 	CS,	 				22,		USAF\
insert into student values "Teresa Mae", 	Gowers, 	Chemistry,			22,		Verizon\
insert into student values Alex,			Smith,		"Gender Studies", 	53,		Amazon\
select * from student

### Program Returns (for select *)
[177] select * from employee 

Table name: employee_temp_177, records: 16
record           last          first            dep         salary           year

     0           Blow            Joe             CS         100000           2018
     1           Blow          JoAnn        Physics         200000           2016
     2        Johnson           Jack             HR         150000           2014
     3        Johnson          Jimmy      Chemistry         140000           2018
     4            Yao          Jimmy           Math         145000           2014
     5            Yao            Flo             CS         147000           2012
     6           Yang             Bo             CS         160000           2013
     7        Jackson            Flo           Math         165000           2017
     8        Jackson             Bo      Chemistry         130000           2011
     9        Jackson          Billy           Math         170000           2017
    10        Johnson       Mary Ann           Math         165000           2014
    11        Johnson      Billy Bob        Physics         142000           2014
    12        Johnson          Billy        Phys Ed         102000           2014
    13       Van Gogh        Vincent            Art         240000           2015
    14       Van Gogh        Vincent             CS         245000           2015
    15       Van Gogh        Jim Bob        Phys Ed         230000           2010


SQL: DONE.

[189] select * from student

Table name: student_temp_120, records: 10
record          fname          lname          major            age        company

     0            Flo            Yao             CS             20         Google
     1             Bo           Yang             CS             28      Microsoft
     2     Sammuel L.        Jackson             CS             40           Uber
     3            Flo        Jackson           Math             21         Google
     4           Greg        Pearson        Physics             20         Amazon
     5        Jim Bob          Smith           Math             23        Verizon
     6         Calvin            Woo        Physics             22           Uber
     7     Anna Grace        Del Rio             CS             22           USAF
     8     Teresa Mae         Gowers      Chemistry             22        Verizon
     9           Alex          Smith Gender Studies             53         Amazon


SQL: DONE.

# What else can it do?
Aside from simple select, it can also do relational operators and logical operators

## File Example: Relational Operators
select * from student where lname >= Yang\
select * from student where age >= 40\
select * from employee where last >= Jack\
select * from employee where salary >= 235000\

### Program Returns
[221] select * from student where lname >= Yang

Table name: student_temp_23, records: 2
record          fname          lname          major            age        company

     0             Bo           Yang             CS             28      Microsoft
     1            Flo            Yao             CS             20         Google


SQL: DONE.

[222] select * from student where age >= 40

Table name: student_temp_110, records: 2
record          fname          lname          major            age        company

     0     Sammuel L.        Jackson             CS             40           Uber
     1           Alex          Smith Gender Studies             53         Amazon


SQL: DONE.

[223] select * from employee where last >= Jack

Table name: employee_temp_44, records: 14
record           last          first            dep         salary           year

     0        Jackson            Flo           Math         165000           2017
     1        Jackson             Bo      Chemistry         130000           2011
     2        Jackson          Billy           Math         170000           2017
     3        Johnson           Jack             HR         150000           2014
     4        Johnson          Jimmy      Chemistry         140000           2018
     5        Johnson       Mary Ann           Math         165000           2014
     6        Johnson      Billy Bob        Physics         142000           2014
     7        Johnson          Billy        Phys Ed         102000           2014
     8       Van Gogh        Vincent            Art         240000           2015
     9       Van Gogh        Vincent             CS         245000           2015
    10       Van Gogh        Jim Bob        Phys Ed         230000           2010
    11           Yang             Bo             CS         160000           2013
    12            Yao          Jimmy           Math         145000           2014
    13            Yao            Flo             CS         147000           2012


SQL: DONE.

[224] select * from employee where salary >= 235000

Table name: employee_temp_192, records: 2
record           last          first            dep         salary           year

     0       Van Gogh        Vincent            Art         240000           2015
     1       Van Gogh        Vincent             CS         245000           2015


SQL: DONE.

## File Example: Logical Operators
select * from student where lname = Yang or major = CS and age < 23 or company = Google \
select * from student where major = Physics or major = Math and company = Google or lname = Jackson\
select * from employee where dep = CS or year >2014 and year < 2018 or salary >= 265000\

### Program Returns
[268] select * from student where lname = Yang or major = CS and age < 23 or company = Google 

Table name: student_temp_22, records: 4
record          fname          lname          major            age        company

     0            Flo            Yao             CS             20         Google
     1             Bo           Yang             CS             28      Microsoft
     2            Flo        Jackson           Math             21         Google
     3     Anna Grace        Del Rio             CS             22           USAF


SQL: DONE.

[269] select * from student where major = Physics or major = Math and company = Google or lname = Jackson

Table name: student_temp_191, records: 4
record          fname          lname          major            age        company

     0     Sammuel L.        Jackson             CS             40           Uber
     1            Flo        Jackson           Math             21         Google
     2           Greg        Pearson        Physics             20         Amazon
     3         Calvin            Woo        Physics             22           Uber


SQL: DONE.

[270] select * from employee where dep = CS or year >2014 and year < 2018 or salary >= 265000

Table name: employee_temp_78, records: 8
record           last          first            dep         salary           year

     0           Blow            Joe             CS         100000           2018
     1           Blow          JoAnn        Physics         200000           2016
     2            Yao            Flo             CS         147000           2012
     3           Yang             Bo             CS         160000           2013
     4        Jackson            Flo           Math         165000           2017
     5        Jackson          Billy           Math         170000           2017
     6       Van Gogh        Vincent            Art         240000           2015
     7       Van Gogh        Vincent             CS         245000           2015


SQL: DONE.
