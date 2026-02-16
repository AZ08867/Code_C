#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
typedef uint8_t u8;
int main() {
  // case
  /*
   * 公司内部权限访问案例 -- 使用swith_case
   * 员工可以访问公司资源，规则如下：
   * 1.经理可以访问所有资源
   * 2.普通员工完成5个以上的任务可以访问公司资源
   * 3.实习生完成10个以上的任务,并且经过经理的批准才可以访问公司资源
   */
  u8 role = 2;                     // 1:经理 2:普通员工 3:实习生
  u8 completed_task = 10;          // 完成的任务数
  bool approved_by_manager = true; // 是否经过经理批准
  bool can_access = false;         // 是否可以访问公司资源

  switch (role) {
  case 1: // 经理
    can_access = true;
    break;
  case 2: // 普通员工
    if (completed_task > 5) {
      can_access = true;
    }
    break;
  case 3: // 实习生
    if (completed_task > 10 && approved_by_manager) {
      can_access = true;
    }
    break;
  default:
    can_access = false;
    break;
  }

  if (can_access) {
    puts("可以访问公司资源\n");
  } else {
    puts("无法访问公司资源\n");
  }

  return 0;
}