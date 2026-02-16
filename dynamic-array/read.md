# dynamic-array — 动态数组示例

在 C 中使用动态内存管理实现一个可增长的整型数组（Dynamic Array）。示例包含创建、追加、自动扩容、打印和释放内存等操作。

## 快速开始

```sh
clang main.c -o dynamic_array.exe
.\dynamic_array.exe
```

## 主要文件

- `main.c`：实现 `DynamicArray` 结构体和操作函数，包括 `create_dynamic_array`、`append`、`print_array` 与 `free_dynamic_array`。

## 说明

- 初始化：通过 `create_dynamic_array(size_t initial_capacity)` 创建动态数组。
- 追加：`append(DynamicArray *arr, int value)` 会在必要时将容量翻倍（使用 `realloc`）以容纳更多元素。
- 打印：`print_array` 显示数组元素、当前元素数量和容量，便于观察扩容行为。
- 释放：使用 `free_dynamic_array` 释放内部缓冲区并释放结构体本身。

## 注意与建议

- 初始容量可调，小容量可以更频繁地触发扩容以便观察扩容过程。
- 所有 `malloc`/`realloc` 调用都有失败检查，实际工程中应根据返回值做更细致的错误处理。
- 使用完成后务必调用 `free_dynamic_array` 以避免内存泄漏。
