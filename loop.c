#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

typedef uint32_t u32;
int main() {
  // const u32 TOTAL_LAPS = 6; // 总圈数
  // u32 current_lap = 0;      // 当前圈数

  // puts("Starting race...");
  // while (current_lap < TOTAL_LAPS) {
  //   printf("Lap: %" PRIu32 "\n", current_lap);
  //   current_lap++;
  // }

  /*CASE: Vending machine code here...
  1. 自助贩卖机目前提供的商品只有一种 价格为：￥5元
  2. 购买者可以选择购买商品的数量
  3. 贩卖机目前支持的硬币种类有：1元、2元、5元
   */

  const u32 PRICE = 5;
  u32 quantity = 0;
  u32 total = 0;
  u32 balance = 0;
  u32 coin = 0;

  puts("Welcome to the vending machine!");

  puts("Please enter the quantity of the item: ");
  scanf_s("%" PRIu32, &quantity);

  total = quantity * PRICE;

  while (balance < total) {
    puts("Please insert coins (1, 2, or 5): ");
    scanf_s("%" PRIu32, &coin);
    if (coin == 1 || coin == 2 || coin == 5) {
      balance += coin;
      printf("You have inserted %" PRIu32 " coins. Your total is ￥%" PRIu32
             "\n",
             coin, balance);
    } else {
      puts("Invalid coin. Please insert coins (1, 2, or 5): ");
    }
  }
  if (balance == total) {
    printf("You have bought %" PRIu32 " items for ￥%" PRIu32 "\n", quantity,
           PRICE);
  }

  // 找零
  if (balance > total) {
    printf("Here is your change: ￥%" PRIu32 "\n", balance - total);
  }

  return 0;
}