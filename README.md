# Validating password strength
A small c program to check the strength of passwords

# Project description
The goal of the project is to create a program that receives a set of passwords as input and verifies for each of them whether the password satisfies all (fixed) required rules. The passwords that pass the check will be output, the others will be discarded.

# Detailed specifications
Implement the program in the source file "pwcheck.c". Input data (password list) will be read from standard input (stdin), output (filtered password list) will be printed to standard output (stdout)

### Committing the source file

```
$ gcc -std=c99 -Wall -Wextra -Werror pwcheck.c -o pwcheck 
```

### Execution syntax

```
./pwcheck LEVEL PARAM [--stats] 
```
The program is executed with two fixed arguments LEVEL and PARAM and with one optional argument --stats, possibly specified in the third position:
* **LEVEL:** an integer in the interval [1, 4] that specifies the required security level (see below)
* **PARAM:** a positive integer that specifies an additional rule parameter
* **--stats:** if specified, specifies whether to print summary statistics of analyzed passwords at the end of the program

### Levels of security
Some rules are parameterizable by an integer specified by the PARAM argument. In the following list, this parameter is denoted as **X**.

**List of rules:**
1. The password contains at least 1 uppercase and 1 lowercase letter.
2. The password contains different characters 
3. The password does not contain a sequence of identical characters of length at least X.
4. The password does not contain two identical substrings of length at least X.
