# ProjectNexus
University exercise with C++ | UniNa
Here the project from my professor as exam trial (Firt year Mechanical Engeneering)
Below you ll find the description about what I needed to code

**Description**
Using the principles of structured programming, design and implement a program that manages the automatic checkout of a supermarket.
All products purchased are stored in a receipt consisting of a maximum of N products.

The program provides a selection menu that cyclically asks the user what operation to be performed.
The programme must enable the following operations to be carried out:
- Print on screen all the operations that can be performed.
- Insert a new product in the receipt.
- Print the receipt without the total.
- Exit the program and, at the exit of the program, print the receipt with the total.

To this end:

1. Define a "product" record consisting of 4 fields:
- product code (integer)
- productname (50 character string)
- unit price (single precision real number)
- quantitative (positive integer)

2. Define an array "receipt" of maximum size N equal to 20 elements (static allocation) initialized with 3 products of your choice (so the initial filling is equal to 3).

3. Provide a "insertProduct" function that receives the receipt and an integer (the value of the first empty position) as input.
The function asks the user to enter the product code, the name of the product, the unit price and the quantity of products.
Subsequently, the function checks that the unit price and the quantity of products entered are both greater than 0:
- if after 3 attempts the user enters a price or quantity less than or equal to 0, the function prints an error message on the screen;
- otherwise, print a confirmation message, insert the product into the receipt and increase the filling.

4. Provide a "calculateTotal" function that receives the receipt and an integer (the value of the first empty position) and returns the total of the receipt.
The function calculates the total receipt taking into account the unit price and the quantity of each product.

5. Provide a "printReceipt" function that receives the receipt as input, an integer (the value of the first empty position) and a Boolean value.
The function prints on screen all the non-empty locations of the receipt according to the format:
productname [product code] -> quantity: totalPartial
(e.g.: Bread [001] -> 4: 6.0) where "totalPartial" is the total price for that product.

Also, if the Boolean value is true, the function prints a last line with the result of the "calculateTotal" function.

6. Provide a "printMenu" function that prints the menu with items related to all the operations that can be performed.

BONUS PART

Add the following features to the menu:
- Look for a product on the receipt and print the total price for that product on the screen.

To this end:

7. Provide a "searchProduct" function that receives the receipt and an integer (the value of the first empty position) and returns a Boolean value with the result of the search (via return) and, if successful, the total price for the product being searched (as an output parameter).
The function asks the user to enter the name of the product to be searched for in the receipt.

For simplicity, assume that strings do not contain spaces by replacing the space character with the "_" character (underscore) when entering information.

You can use library functions<cstring>.
  
******** End Description*****************************************************************
  
 

