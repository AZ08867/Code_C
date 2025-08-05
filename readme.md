# C Programming Language Learn

## Chapter 1: Basic data types

- `int` - Integer type, typically 4 bytes.
- `float` - Single precision floating point type, typically 4 bytes.
- `double` - Double precision floating point type, typically 8 bytes.
- `char` - Character type, typically 1 byte.
- `bool` - Boolean type, typically 1 byte (requires `<stdbool.h>`).
- `define` - Preprocessor macro definition.

相关文件:

1. main.c
2. hello.c

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
