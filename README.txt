Assignment Objective
-------------------------------------------------------------------------

The file table.c is used as the source code for a library libtable.so and
this file contains a vulnerability. Your objective is to

        * Identify and fix the vulnerability
        * Preserve the functionality of the library

The library table.c is extremely simple and provides the functionality
to enter values into an array, retrieve values from an array and finally
to dump contents of an array to stdout. The code should be self-explanatory.

Upload Format
-------------------------------------------------------------------------

You only should upload a single file, the modified 'table.c' since that's
the only piece of code that you are supposed to modify.

Testing table.c
-------------------------------------------------------------------------

You can use ARR30 to test the functionality of table.c. 
Its an interactive program which takes input in the following format
	OP_CODE,arg1,arg2,...argn

where OP_CODE represents the operation that needs to be performed.
For example,

	0,1,19

translates to table[1] = 19

	1,12

translates to print table[12]

	3

translates to dump_table()


Program Structure
-------------------------------------------------------------------------

handout/
        table.c
        table.h
        ARR30-C.c
        compile.sh

table.c
        Source code that's used to generate a library libtable.so.
        There is a vulnerability present within the exposed functions and
        your objective here is to find and fix the same.

table.h
        Functionality exposed by the library to external programs

ARR30-C.c
        Source code of a program that can be used to test the library
        functionality yourself.

compile.sh
        Compiles table.c to generate the library libtable.so
        Compiles ARR30-C.c to generate the library testing program
        ARR30-C
