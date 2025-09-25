# C Programming Language — Learning Notes

## Chapter 1: Fundamental data types

本章概述标准 C（C99/C11）中的基本内建类型。类型的字节大小与表示形式可能依赖于编译器与目标架构；下列值为常见平台（例如 x86-64 上的 gcc/clang）上的典型约定。请使用 sizeof 与 stdint.h 在可移植性要求较高的场景中获取确定性行为。

- `int` — signed integer type; typically 4 bytes on modern desktop/server ABIs. Range is implementation-defined.
- `float` — single-precision IEEE-754 floating-point; typically 4 bytes.
- `double` — double-precision IEEE-754 floating-point; typically 8 bytes.
- `char` — character type; at least 1 byte. May be signed or unsigned depending on implementation.
- `_Bool` — boolean type introduced in C99 (include `<stdbool.h>` to use the token `bool`); typically 1 byte.
- `#define` — preprocessor macro for textual substitution and constants (compile-time).

Notes:

- Always prefer `stdint.h` types (e.g. `int32_t`, `uint32_t`) when fixed widths are required.
- Use `sizeof(T)` to obtain actual byte size on the target platform.

Attachments:

  1. [main.c](main.c)
  2. [hello.c](hello.c)

## Chapter 2: Operators and Expressions

- Arithmetic: `+`, `-`, `*`, `/`, `%`
- Relational: `==`, `!=`, `>`, `<`, `>=`, `<=`
- Logical: `&&`, `||`, `!`
- Bitwise: `&`, `|`, `^`, `~`, `<<`, `>>`
- Assignment: `=`, `+=`, `-=`, `*=`, `/=`, `%=`
- Increment/Decrement: `++`, `--`

Remarks on bitwise operators (按位运算):

按位运算用于在位级别上处理整数表示。请注意有符号整数的右移行为在移位负值时可能由实现定义；位运算常用于掩码、标志位与性能敏感的低级操作。

Attachment:

  1. [operator.c](operator.c)

## Chapter 3: Control Structures

- `if`
  - Syntax: `if (expression) statement;`
  - Example: `if (age >= 18) printf("You are an adult.\n");`
- `if-else`
  - Syntax: `if (expr) stmt1; else stmt2;`
- `if - else if - else`
  - Use when testing multiple mutually exclusive conditions.
- `switch`
  - Syntax: `switch (expression) { case constant: statements; break; ... default: statements; }`
  - Note: switch uses integral constant expressions for cases; remember to add break to avoid fall-through (or use fall-through intentionally with comments).

控制结构用于决定程序的执行流向：条件分支（if/switch）用于选择性执行，循环结构用于重复执行。编写分支时注意可读性与边界条件处理。

## Chapter 4: Loop Structures

- `while`
  - Syntax: `while (expression) statement;`
  - Use for condition-driven repetition.
- `do-while`
  - Syntax: `do { statements } while (expression);`
  - Guarantees body executes at least once.
- `for`
  - Syntax: `for (init; condition; update) statement;`
  - Idiomatic for counter-based loops.

- `while`
  - 用于条件驱动的重复执行，适合循环次数不确定且由运行时条件终止的场景。
- `do-while`
  - 适用于至少需要执行一次循环体的场景；注意循环不变式与终止条件。

Attachments:

- [loop.c](loop.c)
- [loop_case.c](loop_case.c)
- [loop_do.c](loop_do.c)
- [loop_continue.c](loop_continue.c)
- [loop_for.c](loop_for.c)

Training exercises (trains):

- [trains/quadratic_sum.c](./trains/quadratic_sum.c)
- [trains/countdown.c](./trains/countdown.c)
- [trains/factorial.c](./trains/factorial.c)
- [trains/prime_number.c](./trains/prime_number.c)
- [trains/multiplication_table.c](./trains/multiplication_table.c)
- [trains/digital_pyramid.c](./trains/digital_pyramid.c)
- [trains/progress_bar.c](./trains/progress_bar.c)

## Chapter 5: Arrays and Pointers

- Array declaration: `type name[size];`
- Arrays are contiguous sequences of elements; decay to pointers in many expressions.
- Prefer explicit size types and bounds checking when possible.

数组在内存中是连续存储的元素序列，在多数表达式中会衰减为指针。编写与数组相关的代码时，应显式关注边界检查与元素类型的对齐与大小。

Attachments:

- [initial_use_array.c](initial_use_array.c)
- [trains/array_case.c](./trains/array_case.c)

## Chapter 6: Functions

Prototype example:

```c
void greet(int age);
```

- Formal parameter: `int age`
- Actual argument: `greet(18);`

Topics:

- Recursion — functions that call themselves; ensure a base case to avoid unbounded recursion.
- Static local variables — preserve value across function calls (use static keyword).

函数参数采用值传递语义（按值复制）。若需在函数内部修改调用者的数据，应传入指针或结构的地址以实现间接修改。递归函数必须保证基准情况以避免栈耗尽。

Attachments:

- [func.c](func.c)
- [trains/func_case.c](./trains/func_case.c)
- [trains/factorial_recursion.c](./trains/factorial_recursion.c)
- [static.c](static.c)

## Chapter 7: Memory, Pointers and Addressing

- Pointer variables — hold memory addresses; declared as `T *p;`
- Pointer arithmetic — moves in units of the pointed type `sizeof(T)`.
- Pointer arrays — arrays whose elements are pointers.
- Pointer-to-pointer — `T **pp;`
- Function pointers — allow storing and passing functions.
- Null pointer — represents "no object" (use `NULL` or nullptr-like semantics).
- Dangling/wild pointers — pointers that reference freed or invalid memory; avoid by initializing and nulling after free.

Style conventions:

```c
int* p; // emphasizes that p is a pointer to int (stylistic)
int *p; // emphasizes that *p has type int (classic)
```

`size_t` — unsigned integer type used for object sizes and array indexing (defined in `<stddef.h>` / `<stdint.h>`).

Parameter passing:

- C uses pass-by-value semantics: function parameters receive copies of the argument values.
- To allow a function to modify a caller's object, pass a pointer to that object (i.e., simulate pass-by-reference).

指针用于保存内存地址，指针算术按所指类型的对象大小递增或递减。使用指针时应明确所有权与生命周期，避免野指针与重复释放。空指针（`NULL`）用于表示“不指向任何对象”的语义。

`size_t` 为无符号整型，专用于表示对象大小与数组索引，使用时应注意与有符号类型的比较与转换。

Attachments:

- [pointer.c](pointer.c)
- [trains/pointer_case.c](./trains/pointer_case.c)
- [trains/pointer_case_pro.c](./trains/pointer_case_pro.c)
- [trains/ptr_matrix.c](./trains/ptr_matrix.c)
- [trains/pointer_array.c](./trains/pointer_array.c)
- [trains/pointer_func.c](./trains/pointer_func.c)
- [trains/pointer_func_case.c](./trains/pointer_func_case.c)

## Chapter 8: Struct, Enum and Union

Struct:

- Use typedef to create convenient aliases:

```c
typedef struct Date {
    int day;
    int month;
    int year;
} Date;
```

- Use structs to aggregate related data; consider padding/alignment effects on `sizeof`.

结构体用于将多个相关数据项组合为一个复合类型；应考虑内存对齐与填充对 sizeof 的影响。使用 typedef 可以使类型名更简洁、更易读。

Enum:

- Enumerations define related named integer constants.
- By default values start at 0 and increment by 1; explicit values can be assigned.

枚举用于定义一组具名的整型常量，便于表达状态与选项集合；在需要与外部接口交换固定值时推荐使用显式枚举值。

Union:

- A union stores different types in the same memory region; its size equals its largest member.
- Use unions when it is necessary to reinterpret storage or conserve memory — be cautious about active member semantics.

联合体在同一内存区域按不同类型重用存储，非常适合节省内存或实现低级数据重解释；访问时必须明确当前“活动成员”的语义以避免未定义行为。

Attachments:

- [struct.c](struct.c)
- [trains/struct_case.c](./trains/struct_case.c)
- [trains/struct_case_ptr.c](./trains/struct_case_ptr.c)
- [enum.c](enum.c)
- [union.c](union.c)

## Chapter 9: String Handling

- In C, strings are NUL-terminated char arrays.
- Prefer safe functions (`strncpy`/`strncat`/`strlcpy` where available) and always ensure termination.
- Use `string.h` for standard routines (`strlen`, `memcpy`, `strcmp`, etc.).

在 C 中，字符串由以 NUL (`'\0'`) 结尾的 char 数组表示。处理字符串时应始终保证终止符存在，避免缓冲区溢出。优先使用带边界限制的字符串函数或手动检查长度。

Attachments:

- [string.c](string.c)
- [string_func.c](string_func.c)
- [trains/string_case.c](./trains/string_case.c)

## Chapter 10: Streams (stdin, stdout, files)

Stream categories:

流（stream）是抽象的 I/O 源/目标，如文件、标准输入输出、管道或网络套接字。使用文件 I/O 时应检查返回值并及时释放资源以防资源泄露。

1. File streams — reading/writing disk files (`FILE*`, `fopen`, `fread`, `fwrite`, `fclose`).
2. Standard streams — `stdin`, `stdout`, `stderr`.
3. Pipes — inter-process communication where one process's output can be another's input.
4. Memory streams — in-memory buffering APIs.
5. Network streams — socket-based I/O.
6. Device streams — platform/device-specific interfaces.

Attachments:

- [read_file.c](read_file.c)
- [write_file.c](write_file.c)
- [file_func.c](file_func.c)
- [file_err.c](file_err.c)
- [file_append.c](file_append.c)

General recommendations

通用建议：在有可移植性要求时使用明确宽度类型（`stdint.h`）；对 I/O、内存分配等函数的返回值进行检查；明确资源的所有权并及时释放；启用编译器警告以尽早发现潜在缺陷。
