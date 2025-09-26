#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 1024
errno_t update_log_record_s(const char *file_name, const char *search_str,
                            const char *replace_str);
int main(int argc, char *argv[]) {
  const char *file_name = "./file.log";
  const char *search_str = "[1999-12-31 23:59:59]";
  const char *replace_str = "[2025-09-26 12:12:12]";

  errno_t result = update_log_record_s(file_name, search_str, replace_str);
  if (result != 0) {
    char error_msg[256];
    strerror_s(error_msg, sizeof(error_msg), result);
    fprintf(stderr, "An error occurred: %s\n", error_msg);
  } else {
    puts("Record update successfully.");
  }

  _fcloseall();
  return 0;
}

errno_t update_log_record_s(const char *file_name, const char *search_str,
                            const char *replace_str) {
  if (file_name == NULL || search_str == NULL || replace_str == NULL) {
    return EINVAL;
  }

  FILE *file_ptr = NULL;
  errno_t err = fopen_s(&file_ptr, file_name, "r+");
  if (err != 0 || file_ptr == NULL) {
    char error_msg[256];
    strerror_s(error_msg, sizeof(error_msg), errno);
    fprintf(stderr, "Failed to open config file for reading: %s\n", error_msg);
    exit(EXIT_FAILURE);
  }

  char buffer[BUFFER_SIZE];
  long position = 0;
  int found = 0;

  while (fgets(buffer, BUFFER_SIZE, file_ptr) != NULL) {
    if (strstr(buffer, search_str) != NULL) {
      found = 1;
      position = ftell(file_ptr) - (long)strlen(buffer) - 1;
      break; // 找到第一个匹配项之后，立刻停止
    }
  }
  if (found) {
    fseek(file_ptr, position, SEEK_SET); // 移动回找到记录的位置
    size_t replace_len = strlen(replace_str);
    size_t search_len = strlen(search_str);

    if (replace_len > BUFFER_SIZE - 1 || search_len > BUFFER_SIZE - 1) {
      fclose(file_ptr);
      return ERANGE; // 返回错误码，表示字符串长度超出范围
    }
    // 写入新纪录之前，清楚所在位置的行数据
    memset(buffer, ' ', strlen(buffer) - 1); // 使用空格填充
    buffer[strlen(buffer) - 1] = '\n';

    fseek(file_ptr, position, SEEK_SET); // 重新定位到标记行开始
    fputs(buffer, file_ptr);             // 清除原来行的内容
    fseek(file_ptr, position, SEEK_SET);

    int result = fputs(replace_str, file_ptr);

    if (result == EOF) {
      fclose(file_ptr);
      return errno;
    }
  } else {
    fclose(file_ptr);
    return ENOENT; // 返回未找到的匹配项
  }
  fclose(file_ptr);
  return 0;
}
