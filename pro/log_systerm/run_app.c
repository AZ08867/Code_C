#include "application_logic.h"
#include "types.h"
#include <stdlib.h>

/*
 * 日志错误系统
 * 模块
 * 1. 跨平台的基础数据类型
 * 2. 日志模块
 * 3. 日志级别模块
 * 4. 封装内存分配和释放安全操作
 * 5. 统一错误处理策略，记录错误，警告，致命错误
 * 6. 检查指针是否为空指针
 * 7. 包含完整的运行逻辑
 */

int main(void) {
  // 日志系统初始化
  if (!app_init()) {
    return -1;
  }

  if (!app_execute()) {
    app_cleanup();
  }

  app_cleanup();

  return EXIT_SUCCESS;
}