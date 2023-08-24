# SmartCalc v1.0

- The program is developed in C language of C11 standard using gcc compiler.
- The program code is located in the src folder.
- The program is built with Makefile which contains standard set of targets for GNU-programs: all, install, uninstall,clean, dvi, dist, tests, gcov_report.
- GUI implementation, based on Qt.
- The calculation is done after you complete entering the calculating expression and press the = symbol.
- Calculating arbitrary bracketed arithmetic expressions in infix notation.
- Calculate arbitrary bracketed arithmetic expressions in infix notation with substitution of the value of the variable x as a number.
- Plotting a graph of a function given by an expression in infix notation with the variable x (with coordinate axes, mark of the used scale and an adaptive grid).
- The scope of definition and the scope of function values are limited to at least numbers from -1000000 to 1000000
- Users is able to enter up to 255 characters.
- Bracketed arithmetic expressions in infix notation supports the following arithmetic operations and mathematical functions: cos(x), sin(x), tan(x), acos(x), asin(x), atan(x), sqrt(x), ln(x), log(x).

A special mode "credit calculator" is provided:

- Input: total credit amount, term, interest rate, type (annuity, differentiated).
- Output: monthly payment, overpayment on credit, total payment.
