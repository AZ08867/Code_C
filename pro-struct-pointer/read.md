
# pro-struct-pointer — 结构体与指针成员（图书馆示例）

在 C 中使用结构体与指针成员的简单项目。该示例实现了一个小型图书馆（`Library`）用于动态管理 `Book` 记录：添加书籍、查找书籍、打印列表以及释放资源。

## 快速开始

```sh
clang main.c -o pro_struct_pointer.exe
.\pro_struct_pointer.exe
```

程序会创建一个 `Library`，添加几本示例书籍，打印出库中内容并在结束时释放内存。

## 主要文件

- [main.c](main.c): 包含 `Book` 和 `Library` 的定义与示例操作（构造、添加、查找、打印、析构）。
- [read.md](read.md): 本文件，介绍如何构建与运行，以及实现要点。

## 功能要点

- 使用了动态数组来存储 `Book`：`Library` 持有 `Book *books`、`size` 和 `capacity`。
- `create_library()`：构造函数，分配初始容量并返回 `Library` 实例。
- `add_book()`：处理重复 ID 检查、扩容（`realloc`）并为书名分配内存。
- `find_book()`：按 ID 查找并返回指向 `Book` 的指针（若找到）。
- `free_library()`：释放每本书名的内存并释放书籍数组，重置 `Library` 字段。

## 编码与移植性注意

- 源码中使用了 `strcpy_s`（Windows 安全函数），在跨平台或使用 `gcc/clang` 时可替换为 `strcpy` 或 `strncpy` 并做好长度检查。
- 添加书名时为每本书分配了独立内存，确保 `free_library()` 逐一释放以避免内存泄漏。
- `realloc` 扩容时未检查 `new_capacity` 溢出；在生产代码中可加入更严格的容量上限检查。
