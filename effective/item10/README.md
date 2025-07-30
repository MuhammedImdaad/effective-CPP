 ### Have assignment operators return a reference to *this

wonder why this works? 
x = y = z = 15;                        // chain of assignments

Here, 15 is assigned to z, then the result of that assignment (the updated z) is assigned to y,
then the result of that assignment (the updated y) is assigned to x.
The way this is implemented is that assignment returns a reference to its left-hand argument.

#### THINGS TO REMEMBER
* Have assignment operators return a reference to *this.