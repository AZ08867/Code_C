#include <stdarg.h>
#include <stdbool.h>
// 日志级别枚举类型
typedef enum {
  LOG_DEBUG,
  LOG_INFO,
  LOG_WARNING,
  LOG_ERROR,
  LOG_FATAL
} LogLevel;

/*
 * 初始化日志模块
 * @params logFilePath 日志文件路径, 如果为NULL则输出到标准输出
 * @return true 成功，false 失败
 */
bool logger_init(const char *logFilePath);

/* 日志终止模块*/
void logger_close(void);

/*
 * 记录日志信息
 * @params level 日志级别
 * @params format 格式化字符串，类似printf
 */
void log_message(LogLevel level, const char *format, ...);

/* 设置当前日志级别 */
void set_log_level(LogLevel level);