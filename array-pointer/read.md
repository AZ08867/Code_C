# array-pointer — 数组指针与矩阵操作示例

本目录展示如何在 C 中使用指向数组的指针（pointer to array）来操作二维数组，以及相关的矩阵运算实践。

## 快速开始

```sh
clang *.c -o array-pointer.exe
.\array-pointer.exe
```

程序会输出数组指针操作、矩阵显示以及矩阵翻转的示例结果。

## 主要文件

- `main.c`：核心示例，包含：
  - 数组指针（`int (*ptr)[cols]`）的声明与使用。
  - `printMatrix()` 函数，使用 VLA 参数打印矩阵。
  - `flip_image()` 函数，演示对矩阵行进行水平翻转。

## 关键概念

- **数组指针 vs 指针数组**：
  - `int (*ptr)[3]` 是指向包含 3 个整数的数组的指针。
  - `int *ptr[3]` 是包含 3 个指针的数组。
  
- **VLA（可变长数组）**：函数参数 `int (*matrix)[cols]` 允许运行时指定列数。
  
- **指针算术**：`ptr++` 会跳过整行（按数组大小，而非单字节）。
