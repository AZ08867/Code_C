# C 语言学习笔记

## 基础知识

### 基本数据类型

- `int` - 整数，4字节
- `float` - 单精度浮点，4字节
- `double` - 双精度浮点，8字节
- `char` - 字符，1字节
- `_Bool` - 布尔值（C99+）

代码: [main.c](knowledge_points/main.c) | [hello.c](knowledge_points/hello.c)

### 运算符

- 算术运算：`+` `-` `*` `/` `%`
- 比较运算：`==` `!=` `>` `<` `>=` `<=`
- 逻辑运算：`&&` `||` `!`
- 位运算：`&` `|` `^` `~` `<<` `>>`
- 赋值运算：`=` `+=` `-=` `*=` `/=` `%=`
- 自增自减：`++` `--`

代码: [operator.c](knowledge_points/operator.c)

### 条件语句

- `if` / `if-else` / `if-else if-else`
- `switch-case` - 记得加 `break` 避免穿透

代码: [control.c](knowledge_points/control.c)

### 循环语句

- `while` - 条件循环
- `do-while` - 至少执行一次
- `for` - 计数循环
- `break` / `continue` - 循环控制

代码: [loop.c](knowledge_points/loop.c) | [loop_for.c](knowledge_points/loop_for.c) | [loop_do.c](knowledge_points/loop_do.c) | [loop_continue.c](knowledge_points/loop_continue.c)

练习: [quadratic_sum](trains/quadratic_sum.c) | [countdown](trains/countdown.c) | [factorial](trains/factorial.c) | [prime](trains/prime_number.c) | [multiplication_table](trains/multiplication_table.c) | [pyramid](trains/digital_pyramid.c) | [progress_bar](trains/progress_bar.c)

## 数组

- 声明：`type arr[size];`
- 连续的内存块
- 代码: [initial_use_array.c](knowledge_points/initial_use_array.c)
- 练习: [array_case.c](trains/array_case.c)

## 函数

### 基础

- 函数声明/定义
- 参数传递（值传递）
- 返回值

### 特殊用法

- 递归函数（需要有基准情况）
- 静态局部变量（保持值跨函数调用）

代码: [func.c](knowledge_points/func.c) | [static.c](knowledge_points/static.c)

练习: [func_case.c](trains/func_case.c) | [factorial_recursion.c](trains/factorial_recursion.c)

## 指针

### 基础概念

- 存储地址：`type *p;`
- 指针运算按类型大小移动
- 空指针：`NULL`
- 避免野指针和重复释放

### 指针的使用

- 指针数组
- 多级指针：`int **pp;`
- 指向数组的指针
- 函数指针

代码: [pointer.c](knowledge_points/pointer.c) | [m_ptr.c](knowledge_points/m_ptr.c)

练习: [pointer_case.c](trains/pointer_case.c) | [pointer_case_pro.c](trains/pointer_case_pro.c) | [ptr_matrix.c](trains/ptr_matrix.c) | [pointer_array.c](trains/pointer_array.c) | [pointer_func.c](trains/pointer_func.c) | [pointer_func_case.c](trains/pointer_func_case.c)

## 复合数据类型

### 结构体 (struct)

- 组合相关的多个成员
- 用 `typedef` 简化类型定义
- 注意内存对齐

代码: [struct.c](knowledge_points/struct.c)

练习: [struct_case.c](trains/struct_case.c) | [struct_case_ptr.c](trains/struct_case_ptr.c)

### 枚举 (enum)

- 定义一组具名常量
- 默认从 0 开始，逐个递增
- 可指定具体值

代码: [enum.c](knowledge_points/enum.c)

### 联合体 (union)

- 多个成员共享同一块内存
- 大小等于最大成员
- 用于节省内存或数据重解释

代码: [union.c](knowledge_points/union.c)

## 字符串

- 以 `\0` 结尾的字符数组
- 使用 `string.h` 的标准函数
- 注意缓冲区溢出

代码: [string.c](knowledge_points/string.c) | [string_func.c](knowledge_points/string_func.c)

练习: [string_case.c](trains/string_case.c)

## 文件 I/O

### 基础操作

- `fopen()` - 打开文件
- `fread()` / `fwrite()` - 读写数据
- `fclose()` - 关闭文件
- 检查返回值，及时释放资源

代码: [read_file.c](knowledge_points/read_file.c) | [write_file.c](knowledge_points/write_file.c) | [file_func.c](knowledge_points/file_func.c) | [file_err.c](knowledge_points/file_err.c) | [file_append.c](knowledge_points/file_append.c)

练习: [bin_r_w.c](trains/bin_r_w.c) | [copy_file.c](trains/copy_file.c)

## 标准库

### Math.h - 数学函数

代码: [math_exp.c](knowledge_points/math_exp.c)

### Time.h - 时间函数

代码: [time_exp.c](knowledge_points/time_exp.c)

## 动态内存

### 栈 vs 堆

#### 栈内存

- 局部变量自动分配和释放
- 快速，但大小受限
- 函数返回时自动销毁

#### 堆内存

- 手动管理：`malloc()` / `calloc()` / `realloc()` / `free()`
- 大小灵活
- 需要手动释放，避免内存泄漏

代码: [dynamic.c](knowledge_points/dynamic.c)

练习: [malloc_case.c](trains/malloc_case.c) | [calloc_case.c](trains/calloc_case.c) | [realloc_case.c](trains/realloc_case.c)

### 多级指针和动态数据结构

代码: [m_ptr.c](knowledge_points/m_ptr.c) | [manage_dds.c](knowledge_points/manage_dds.c)

练习: [m_ptr_case.c](trains/m_ptr_case.c)

## 函数指针

存储函数的地址，用于回调、多态等场景。

代码: [func_ptr.c](knowledge_points/func_ptr.c) | [function_pointer.md](knowledge_points/function_pointer.md)

练习: [func_ptr_case.c](trains/func_ptr_case.c) | [callback.c](trains/callback.c)

## 进阶项目

- [pro/](pro/read.md) - 专业应用
- [queue/](queue/read.md) - 队列实现
- [array2function/](array2function/read.md) - 数组与函数
- [items-train/](items-train/read.md) - 综合训练
- [array-pointer/](array-pointer/read.md) - 数组指针专项
