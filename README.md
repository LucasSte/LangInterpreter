# LangInterpreter
This is an interpreter for a programming language in Portuguese, conceived by the University Professor. The interpreter was built upon Flex and Yacc. It analyses the code lexically, syntatically and semantically to generate an indetermediate code, which is executed.

Files `teste1.dat`, `teste2.dat` and so on contains examples of the programming language usage. The interpreter reads the code from the terminal and reads inputs from the file `entrada.txt`. For instance, if a code has the command to read a variable, the interpreter will reads its value on the file `entrada.txt`.

The interpreter's output is the code pretty-printed and the result of the code's write commands.

To run the application with a code, type the following commands on a linux terminal:

```
flex Lab6.l
yacc Lab6.y
gcc y.tab.c main.c yyerror.c -o Lab6 -lfl
./Lab6 < yourCode.dat
```
