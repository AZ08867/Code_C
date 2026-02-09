#include "pointer_safety.h"
#include "error_handling.h"

bool is_nullptr(const void *ptr) {
  if (ptr == NULL) {
    log_error("Detected NULL pointer.");
    return true;
  }
  return false;
}