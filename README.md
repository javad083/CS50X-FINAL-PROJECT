# STUDENT-DATABASE-MANAGEMENT
#### VIDEO DEMO  : https://youtu.be/rCHR0YcJo-k
---
#### DESCRIPTION :
  I call this project "student database management", because this program organize and save incoming student data. The data consists of the student's name, student's age, student's id, student's email address, student contact number and student's GPA. With this program the student data stored will be more flexible to view and access. Initially when the program is run, users will be given a menu layer. The menus are "Create record", "Display record", "Update record", "Delete record", "Search record" and "Exit".
  Users will be asked to choose another menu option, if the user chooses the "Create record" option, then the user will be directed to fill in the user's data form. Users are required to fill in "Name", "Age", "Student ID", "E-mail Address", "Contact number" and "GPA". If the user chooses the "Display Record" option, the user will be displayed data for each student who has entered their data. The user can also change his data, i.e. by selecting the "Update Record" option, but if the user wants to delete his data, the user can choose the "Delete Record" option. But if there is a lot of data coming in and the user wants to see his data, then the user can choose the "Search Record" option, the user will be given a "Search by Id" menu, "Search by e-mail", if the user chooses the "Search by ID" option, the user will be told to fill in the ID. After that the user's self data will be displayed. I made all of these functions in the "cs50-final-project.cpp" file.
  Usually database management that is run on cmd has a less attractive UI, so from that I add some decorations like coloring on cmd which I change to ash color, then the contents of the database are displayed in tabular form using line elements.
  The first function is called cls, this function serves to clean the page, to use this function we have to include one of the c library
called "stdlib.h". The second function is called createRecord. This function serves to give the user a prompt data which includes student's name,
student's age, student's ID, student's email address. student's contact number, and student's GPA. If the data succesfully stored, the program
will send a message "program succesfully stored". The third function is called displayRecord, this function allow the user to view anyone record
inside the program. The fourth function is called updateRecord, this function serves to update student's data if there are wrong input, when user choose this option,
they have to input their own ID in order to validate. The fifth function is called deleteRecord,this function allow the user to delete their own record,
they have to input their own ID to validate. The sixth function is called searchRecord, this function allow the user to search their record or any other student record easily without scrolling or etc.
When the user choose this option, the program will ask the user whether they want to search by id or by email.
    I understand there are still many shortcomings from the program that I made, there are still many things that can be added both in terms of UI and UX.
But I'm sure with the formation of this project can be a reference for people out there. My other hope is that the program that I created can be used by everyone.
