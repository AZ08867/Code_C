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
  - Grammar: `for (initialization; condition; increment/decrement) statement`
  - Example: `for (int i = 0; i < 10; i++) { printf("%d ", i); }`

- attachment:
  - [loop.c](loop.c)
  - [loop_case.c](loop_case.c)
  - [loop_do.c](loop_do.c)
  - [loop_continue.c](loop_continue.c)
  - [loop_for.c](loop_for.c)

### Trains

- [quadratic_sum.c](./trains/quadratic_sum.c)
- [countdown.c](./trains/countdown.c)
- [factorial.c](./trains/factorial.c)
- [prime_number.c](./trains/prime_number.c)
- [multiplication_table.c](./trains/multiplication_table.c)
- [digital_pyramid.c](./trains/digital_pyramid.c)
- [progress_bar.c](./trains/progress_bar.c)

## Chapter 5: Arrays and Pointers

- `array`
  - Grammar: `type array_name[size];`

- attachment:
  - [initial_use_array.c](initial_use_array.c)
  - [array_case.c](./trains/array_case.c)

## Chapter 6: Functions

```c
void greet(int age) {}
```

形式参数： `int age`
实参： `greet(18);`

- 递归 -- Recursion
- 静态变量 -- Static Variables
- attachment:
  - [func.c](func.c)
  - [func_case.c](./trains/func_case.c)
  - [factorial_recursion.c](./trains/factorial_recursion.c)
  - [static.c](static.c)

## Chapter 7: Address and Pointer

- 指针变量 -- Pointer Variables
- 指针运算 -- Pointer Arithmetic
- 指针数组 -- Array of Pointers
- 指向指针的指针 -- Pointer to Pointer
- 函数指针 -- Function Pointers
- 空指针 -- Null Pointer --> 指向了一个不指向任何有效内存地址的指针
- 野指针 -- Wild Pointer --> 指向了一个无效的内存地址或已经释放的内存地址的指针

```c
int* p; // 微软的规范，表明强调 p 是一个指向 int 类型的指针
int *p; // K&R 的规范，表明强调 *p 是一个 int 类型
```

`size_t` - 无符号整数类型，通常用于表示对象的大小。

### 函数的值传递与地址引用传递

- 函数的值传递 -- Passing by Value
  - 调用函数时，将实参的值复制到函数的局部变量中，因此函数内对实参的修改不会影响到调用函数的地方。
  - 表示形参与实参是不同的地址，因为是复制值。
- 函数的地址引用传递 -- Passing by Reference to Pointer

- attachment:
  - [pointer.c](pointer.c)
  - [pointer_case.c](./trains/pointer_case.c)
  - [pointer_case_pro.c](./trains/pointer_case_pro.c)
  - [ptr_matrix.c](./trains/ptr_matrix.c)
  - [pointer_array.c](./trains/pointer_array.c)
  - [pointer_func.c](./trains/pointer_func.c)
  - [pointer_func_case.c](./trains/pointer_func_case.c)

## Chapter 8: Structures and Enumeration and Union

### Struct

关于给结构体起别名：可以使用 `typedef` 关键字为结构体创建别名 下面是使用别名的两种方式：

```c
struct Date {
    int day;
    int month;
    int year;
};
typedef struct Date Date;  // 创建别名

Date today = {17, 9, 2025};  // 使用时可以直接用 Date
```

```c
// 推荐使用
typedef struct Date {
    int day;
    int month;
    int year;
} Date;  // 直接在结构体定义时创建别名

Date today = {17, 9, 2025};  // 使用时可以直接用 Date
```

### Enum

定义：枚举是一种用户定义的数据类型，它允许你定义一组命名的常量。默认情况下，第一个枚举成员的值为 0，后续成员的值依次加 1。

- 使用场景:
  - 用于定义一组相关的常量
  - 提高代码的可读性和可维护性
  - 常用于表示状态、选项或固定的值集合
  - 每个枚举成员占用独立的存储空间

### Union

定义：联合是一种特殊的数据类型，允许在相同的内存位置存储不同的数据类型。联合的大小由最大的成员决定，所有成员共享同一块内存空间。主要用于在同一内存位置存储不同类型的数据。

- 使用场景:
  - 节省内存空间
  - 只能同时使用一个成员
  - 所有成员共享同一块内存空间
  - 常用于需要在不同类型间复用内存的场景

- attachment:
  - [struct.c](struct.c)
  - [struct_case.c](./trains/struct_case.c)
  - [struct_case_ptr.c](./trains/struct_case_ptr.c)
  - [enum.c](enum.c)
  - [union.c](union.c)
