# Notes
Individual independent project written in C++ on Sublime Text, attempting to simulate a bookstore's database of book wares, employees, suppliers, members, and sales

Book Attributes
1. title - The name of the book
2. price - How much for 1 copy of the book the bookstore is selling for
3. stock - How many copies of the book that bookstore currently has in its wares

Employee Attributes
1. name - The name of the employee
2. address - The address of the employee
3. position - The job that the employee is working at the bookstore
4. salary - How much money the employee is being paid for their work

Supplier Attributes
1. name - The name of the supplier
2. address - The address of the supplier
3. books - The list of books that the supplier has sold copies to the bookstore

Member Attributes
1. name - The name of the member
2. address - The address of the member
3. books_bought - The list of books that the member has bought from the bookstore; each book string is associated with a Purchase struct of 4 attributes
	3a. copies - How many copies of the book the member bought
	3b. price - The price for 1 copy at the time of the purchase
	3c. year - The year that the purchase was made
	3d. total_days - How many days into the year when the purchase was made. E.g. Jan 1st = 1, Jan 2nd = 2, Feb 1st = 32
4. books_returned - The list of books that the member has returned

Main Menu Options
1. Manage the bookstore - Go to the menu for managing the bookstore and interacting with Book objects, as well as Supplier and Member objects to a degree
2. Employee Database - Go to the menu for interacting with Employee objects
3. Supplier Database - Go to the menu for interacting with Supplier objects
4. Member Database - Go to the menu for interacting with Member objects
5. Sales Records - Go to the menu for seeing total profits and total losses over the course of the current run

Manage the Bookstore Options
1. View book list - Displays every book's title, the price of 1 copy, and how many are in stock
 	-If the bookstore has yet to stock any books, the user is informed of the fact and redirected to the "Manage the bookstore" menu
2. Buy books from supplier - Buy stock from a supplier (Makes a new Book object if it didn't exist before)
 	-If the bookstore has no supplier records, the user is informed of the fact and redirected to the "Manage the bookstore" menu
	-User is asked for the title of the book, how much for 1 copy charged by the supplier, and how many copies to buy
	-If the bookstore has never stocked the book before, set the price for 1 copy
	-If this is the first time a supplier has sold stock of this book to the bookstore, add the book's title to their list of books supplied
	-Total losses are increased by the amount paid for buying stock
3. Sell books to customers - 
 	-If the bookstore has yet to stock any books, the user is informed of the fact and redirected to the "Manage the bookstore" menu
	-The user is asked which book is being sold, how many copies are being sold, and the name of the customer
	-If the bookstore does not stock the book, the user is informed of the fact and redirected to the "Manage the bookstore" menu
	-If the bookstore no has no remaining stock of the book, the user is informed of the fact and redirected to the "Manage the bookstore" menu
	-If the customer has a Member record, then their books_bought attribute is updated with details of their purchase
	-Total profits are increased by the amount made by selling stock
4. Manage book prices - Alloes the user to set a new price for a book
 	-If the bookstore has yet to stock any books, the user is informed of the fact and redirected to the "Manage the bookstore" menu
5. Receive a returned book - The bookstore is returned at least 1 copy of a book by a member, as long as the return is within 30 days of purchase
 	-If the bookstore has yet to stock any books or has no member records, the user is informed of the fact and redirected to the "Manage the bookstore" menu
	-User is asked the name of the person who wishes to return a book, which book, and how many
	-If the person is not a member, the user is informed of the fact and redirected to the "Manage the bookstore" menu
	-If the book that the member wishes to return was never stocked by the bookstore, the user is informed of the fact and redirected to the "Manage the bookstore" 	menu
	-If the number of books to be returned exceeds how many were actually bought, then all of the bought books are returned
	-If the return is attempted 30 days after purchase, the user is informed of the fact and redirected to the "Manage the bookstore" menu
	-If the return goes through, the member is paid an amount equal to how much they paid for the books during their purchase. The returned copies are then added 		to the bookstore's wares, and the total sales goes down by how much the bookstore refunded the member

Employee DB Options
1. View employee records - Displays every employee's name, address, job, and salary
 	-If the bookstore has no employee records, the user is informed of the fact and redirected to the "Employee Database" menu
2. Add employee record - Make a new Employee object
 	-The user is asked the employee's name, their address, what their position will be, and what will be their salary
	-If the bookstore already has an employee records of the inputted name, the user is informed of the fact and redirected to the "Employee Database" menu
3. Remove employee record - Delete an Employee object
 	-The user is asked the name of the employee whose record is being deleted
	-If the bookstore has no employee record of the inputted name, the user is informed of the fact and redirected to the "Employee Database" menu
4. Modify employee record - Allows the user to change an Employee's attributes
 	-

Supplier DB Options
1. View supplier records - Displays every supplier's name and address
 	-If the bookstore has no supplier records, the user is informed of the fact and redirected to the "Supplier Database" menu
2. View a supplier's list of books supplied - Outputs a list of book titles, which are the books that the user-selected supplier has given stock to the bookstore
 	-The user is asked the supplier's name whom they wish to view
	-If the bookstore has no supplier records of the inputted name, the user is informed of the fact and redirected to the "Supplier Database" menu
3. Add supplier record - Make a new Supplier object
 	-The user is asked the supplier's name and their address
	-If the bookstore already has a supplier record of the inputted name, the user is informed of the fact and redirected to the "Supplier Database" menu
4. Remove supplier record - Delete a Supplier object
 	-The user is asked the name of the supplier whose record is being deleted
	-If the bookstore has no supplier records of the inputted name, the user is informed of the fact and redirected to the "Supplier Database" menu
5. Modify supplier record - Allows a user to change a Supplier's name and addrees
 	-

Member DB Options
1. View member records - Displays every member's name and address
 	-If the bookstore has no member records, the user is informed of the fact and redirected to the "Member Database" menu
2. View list of books bought by a member - Outputs a list of book titles, which are the books that the member has bought from the bookstore
 	-The user is asked the member's name whom they wish to view
	-If the bookstore has no member records of the inputted name, the user is informed of the fact and redirected to the "Member Database" menu
3. View list of books returned by a member - Outputs a list of book titles, which are the books that the member has returned to the bookstore
 	-The user is asked the member's name whom they wish to view
	-If the bookstore has no member records of the inputted name, the user is informed of the fact and redirected to the "Member Database" menu
4. Add member record - Make a new Member object
 	-The user is asked the member's name and their address
	-If the bookstore already has a member record of the inputted name, the user is informed of the fact and redirected to the "Member Database" menu
5. Remove member record - Delete a Member object
 	-The user is asked the name of the member whose record is being deleted
	-If the bookstore has no member records of the inputted name, the user is informed of the fact and redirected to the "Member Database" menu
6. Modify member record - Allows a user to change a Member's name and address
 	-

Sales Records Options
1. See total profits - How much money was made selling books
2. See total losses - How much money was lost buying stock
