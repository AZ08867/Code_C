# C Programming Language Learn

## Chapter 1: Basic data types

- `int` - Integer type, typically 4 bytes.
- `float` - Single precision floating point type, typically 4 bytes.
- `double` - Double precision floating point type, typically 8 bytes.
- `char` - Character type, typically 1 byte.
- `bool` - Boolean type, typically 1 byte (requires `<stdbool.h>`).
- `define` - Preprocessor macro definition.

- attachment:
    1. [main.c](main.c)
    2. [hello.c](hello.c)

## Chapter 2: Operators and Expressions

- Arithmetic Operators: `+`, `-`, `*`, `/`, `%`
- Relational Operators: `==`, `!=`, `>`, `<`, `>=`, `<=`
- Logical Operators: `&&`, `||`, `!`
- Bit
- wise Operators: `&`, `|`, `^`, `~`, `<<`, `>>`
- Assignment Operators: `=`, `+=`, `-=`, `*=`, `/=`, `%=`
- Increment/Decrement Operators: `++`, `--`

> 按位与操作符是 &，按位或操作符是 |，按位异或操作符是 ^, 取反操作符是 ~，左移操作符是 <<，右移操作符是 >>。

- 按位与：两个位都为1时，结果位为1，否则为0。
- 按位或：两个位中有一个为1时，结果位为1，否则为0。
- 按位异或：两个位不同时为1时，结果位为1，否则为0。
- 取反：对每个位取反，即0变1，1变0。

- attachment:
    1. [operator.c](operator.c)

## Chapter 3: Control Structures

- `if` statement
  - Grammar: `if (expression) statement`
  - Example: `if (age >= 18) printf("You are an adult.");`
- `if-else` statement
  - Grammar: `if (expression) statement1 else statement2`
  - Example: `if (age >= 18) printf("You are an adult."); else printf("You are a minor.");`
- `if- else if - else` statement
  - Grammar: `if (expression1) statement1 else if (expression2) statement2 else statement3`
  - Example: `if (age >= 18) printf("You are an adult."); else if (age >= 6) printf("You are a teenager."); else printf("You are a child.");`
- `switch` statement
  - Grammar: `switch (expression) { case constant1: statement1; case constant2: statement2; ...; default: statementN; }`
  - Example: `switch (day) { case 1: printf("Monday"); break; case 2: printf("Tuesday"); break; ...; default: printf("Invalid day"); }`

## Chapter 4: Loop Structures

- `while` loop
  - Grammar: `while (expression) statement`
  - Example: `int i = 0; while (i < 10) { printf("%d ", i); i++; }`
- `do-while` loop
  - Grammar: `do { statement } while (expression);`
  - Example: `int i = 0; do { printf("%d ", i); i++; } while (i < 10);`
- `for` loop

- attachment:
  - [loop.c](loop.c)
