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
1. Manage the bookstore - 
2. Employee Database - 
3. Supplier Database - 
4. Member Database - 
5. Sales Records - 

Manage the Bookstore Options
1. View book list - 
2. Buy books from supplier - 
3. Sell books to customers - 
4. Manage book prices - 
5. Receive a returned book - 

Employee DB Options
1. View employee records - 
2. Add employee record - 
3. Remove employee record - 
4. Modify employee record - 

Supplier DB Options
1. View supplier records - 
2. View a supplier's list of books supplied - 
3. Add supplier record - 
4. Remove supplier record - 
5. Modify supplier record - 

Member DB Options
1. View member records - 
2. View list of books bought by a member - 
3. View list of books returned by a member - 
4. Add member record - 
5. Remove member record - 
6. Modify member record - 

Sales Records Options
1. See total profits - 
2. See total losses - 
