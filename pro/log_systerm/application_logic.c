#include "application_logic.h"
#include "error_handling.h"
#include "memory_manager.h"

#include <stdbool.h>
#include <stdio.h>

bool app_init(void) {
  // 实例，初始化日志系统
  if (!logger_init(NULL)) {
    fprintf(stderr, "Failed to initialize logger.");
    return false;
  }

  set_log_level(LOG_DEBUG);
  log_message(LOG_INFO, "Application initializing ...");
  return true;
}

bool app_execute(void) {
  log_message(LOG_DEBUG, "Starting app_execute.");
  int *data = safe_malloc(sizeof(int));
  if (data == NULL) {
    log_error("Failed to allocate memory for data.");
    return false;
  }
  log_message(LOG_DEBUG, "Memory allocated successfully, now setting value.");

  *data = 42;
  log_message(LOG_INFO, "Data value set to %d.", *data);
  safe_free((void **)&data);
  log_message(LOG_DEBUG, "Finishing app_execute.");
  return true;
}

void app_cleanup(void) {
  log_message(LOG_INFO, "Cleaning up application ...");
  logger_close();
}