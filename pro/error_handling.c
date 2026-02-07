#include "error_handling.h"
#include <stdarg.h>
#include <stdlib.h>

void log_error(const char *format, ...) {
  va_list args;
  va_start(args, format);
  log_message(LOG_ERROR, format, args);
  va_end(args);
}

void log_warning(const char *format, ...) {
  va_list args;
  va_start(args, format);
  log_message(LOG_WARNING, format, args);
  va_end(args);
}
void log_fatal(const char *format, ...) {
  va_list args;
  va_start(args, format);
  log_message(LOG_FATAL, format, args);
  va_end(args);
  exit(EXIT_FAILURE);
}