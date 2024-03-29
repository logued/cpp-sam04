#include <iostream>

// Pointer Basics	Feb 2023

#include <iostream>
using namespace std;


void demo1();
void demo2();
void swap_by_pointer(int* , int*);

int main()
{
    cout << "Pointer Basics - sample code." << endl;
    demo1();
    demo2();
    return 0;
}

void demo1()		// Pointer basics - declaring a pointer, initialising a pointer and de-referencing a pointer
{
    int x = 25;

    int* p = &x;
    // declares a variable p as type "pointer to int" (or 'p is a pointer to an int').
    // p is a variable that can store the address of an int.
    // '&x' means: get the memory address of the variable x. ('&' is the 'address-of' operator)
    // We can assign the address of x into the pointer variable p, as a pointer variable can store an address.


    cout << "x: (value in x): " << x << endl;		//value of x
    cout << "&x: (address of x): " << &x << endl;	//address of x

    cout << "p: (value in p): " << p << endl;		//value stored in p, which is the address of x

    // Dereferencing a pointer variable by using *p
    // Dereferencing means: getting the value from the location that the pointer points to.

    cout << "*p (de-referencing the pointer)(i.e. get value at location where p points to):\t";
    cout << *p << endl;

    // note that when "*p" is evaluated, its type is the same as the type that
    // the pointer p was declared to point at - here, an int.
    // p was declared to be a pointer to an int, therefore,
    // *p evaluates to an int (*p is the thing that p points to)
    // p is used as an r-value above.


    // Using *p as an l-value  (left-value)
    // Below, we assign the number 99 to the location that p is pointing to.
    // Note the slightly different interpretation of *p (as either r-value or l-value)

    *p = 99;
    // put the value 99 into where p is pointing.
    // p is pointing at x, so *p dereferences p, giving access to the memory space that p points to,
    // 99 will be put into that memory space (which is into variable x)
    // The value in x has now been changed by use of the pointer.

    cout << "... after executing *p = 99;";
    cout << "*p: " << *p << endl;
    cout << "x: (value in x): " << x << endl;	//value of x was changed using pointer p

    //TODO in class -- complete in class and confirm your output
    // Q1.
    // - declare a variable of type double called 'height' and assign it your height in meters (e.g. 1.56)
    //    - declare a variable pHeight of type 'pointer to double';
    //    - get the address of the height variable and assign it to the pointer pHeight;
    //    - print out the height variable
    //    - print out the address of the height variable using '&'
    //    - print out the value of the pointer pHeight
    //    - print out the value of the height variable by de-referencing the pHeight pointer variable
    //    - assign a new value to the height variable e.g. 1.88
    //    - print out the value
    //    - assign a new value the height variable using the pointer pHeight  (dereference as an l-value)
    //    - DRAW a memory diagram on paper to show the state of all variables just before end of main()

    //TODO Q.2 Declare and initialize a double d with the value 3.14.
    //    Declare a pointer pd and set it to point at the variable d.
    //    Using the pointer, set the value of d to 3.14159, and output
    //    the new value of d using the pointer.

    //TODO Q.3 Declare a pointer to a char called pc, but don't assign it a value.
    // Print out the value of pc.  Look at the value. What does the value represent?
    //    Output *pc (that is, the thing that pc is pointing at)
    // -- did it run?, if so, study the output. What has happened?  Explain!
}


void demo2()	// swap values of two variables by passing their addresses
{
    int x = 22;
    int y = 33;

    swap_by_pointer(&x, &y);	// pass the addresses of x and y - (pass addresses by value)

    cout << "After swap_by_pointer(): x=" << x << ",  y=" << y << endl;

    // pointers can be passed as arguments also, which is really means
    // passing the addresses contained in teh pointers.
    // Remember - a pointer stores an address

    int* pX = &x;	// pX is a pointer to an int (pointing at x)
    int* pY = &y;   // pY is a pointer to y

    swap_by_pointer(pX, pY);	// passes the value of pX (the address of x)
    // and pY (the address of y)

    cout << "After swap_by_pointer(): x=" << x << ",  y=" << y << endl;

    //TODO  Code a solution to the question below and test.
    // Q4.
    //    - a. write a function called add() with two pointer parameters to accept the addresses
    //      of two int arguments.  The function should add the values of the objects
    //      pointed to, and return an int.  Test your program.
    //    - b. how would you prevent the pointer parameters in add() from modifying the
    //      objects that they point to?  Try it out.
}

// Declares two 'pointer to int' type parameters that can accept
// the addresses of two int variables.
// We use the pointers to swap the values in x and y
// that were created in, and belong to, demo2()
//
void swap_by_pointer(int* ptr1, int* ptr2)
{
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

