# studentrecord
A C program to implement a student-record management system.

Each student's record contains the following information:
1. Entry_number: integer (automatically generated at the time of addition)
2. Name: String of alphabets (no length restriction)
3. Mobile no: String of numeric (no length restriction)
4. Percentage: Float


### System provides following functionality (operations):
1. Search details of a student.
INPUT: (Entry_number)
Search if any student record with the given entry_number is found. If yes, print all the
details as given in the sample test case. Else print NO SUCH RECORD FOUND.

2. Add a student record .
INPUT: ( Name, Mobile no, Percentage )
Add student record to the current database with the details given in the input at the end in
the record list. Initialize the pointer attribute to Null pointer. Assign entry number as
entry_number of the last added record + 1. If it is a first record, assign entry number as 1.
Point the last record in the list to this newly created record. Print RECORD ADDED
SUCCESSFULLY.

3. Delete a student-record.
INPUT: (Entry_number)
First search. If a record found, remove the pointer link to it and change the pointer link of
the previous entry from this, to the next record entry. Free the allocated memory to this
record. Print RECORD DELETED SUCCESSFULLY. Else print NO SUCH RECORD
FOUND.

4. Modify details of a student.
Input:(Entry_number, Updated_name, Updated_mobile_no, Updated Percentage)
First search, If a record found with the given entry_number, update the informations without
changing any pointers. Print RECORD MODIFIED SUCCESSFULLY. Else print NO
SUCH RECORD FOUND.

5. Show List
Input:()
Show all the entries in the student record with all the information in tabular format sorted in
the ascending order on entry numbers as shown in sample test cases. If empty record list,
print NO RECORDS.

Takes input at run time as follows:
./record 'input1' 'input2' 'input3' 'input4' … 'input k'
where each input is a operation that needs to be performed in the order as given in the command.
Each input follows following syntax:
'Operation_number Argument1 Argument2...'
Operation_number varies from 1-5 as given above. Arguments are the parameters that are needed
to be passed as input parameters for the operation.
