Vending Machine - designing an approval printer
-----------------------------------------------

We'll play around with a central concept of
Approval Testing: the printer.

The printer is responsible for converting the
object/structure/datatype we are interested
in testing into a text string.

This is why it is called a printer: it "prints"
the object onto "paper" (text).


Instructions
------------
1. vending_maching_gtest.cpp: make sure the
   test is running
2. Find the *.approved.txt file, have a look at
   it. What asserts is it covering already?
3. vending_machine_printer.c: Extend the printer
   to include the other asserts. Keep running the
   test, and approve the output (if it looks good).
4. Goal: No asserts, just a verify
