/// 小仓库items管理
#include <corecrt.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

typedef int32_t i32;
typedef struct {
  i32 id;
  char name[MAX_NAME_LENGTH];
  i32 quantity;
  float price;
} Item;

void print_inventory(const Item items[], i32 item_count) {
  printf("ID\tName\t\tQuantity\tPrice\n");
  for (i32 i = 0; i < item_count; i++) {
    printf("%" PRId32 "\t%-15s\t%" PRId32 "\t\t%.2f\n", items[i].id,
           items[i].name, items[i].quantity, items[i].price);
  }
}

i32 add_item(Item items[], i32 *count, i32 id, const char *name, i32 quantity,
             float price) {
  if (*count >= MAX_ITEMS) {
    printf("Inventory is full. Cannot add more items.\n");
    /* return *count; */
    return 0; // Failure
  }
  items[*count].id = id;
  /* snprintf(items[*count].name, MAX_NAME_LENGTH, "%s", name); */
  strncpy_s(items[*count].name, MAX_NAME_LENGTH, name, _TRUNCATE);
  items[*count].quantity = quantity;
  items[*count].price = price;
  /* *count = *count + 1; */
  (*count)++;
  /* return *count; */
  return 1; // Success
}

i32 update_quantity(Item items[], i32 count, i32 id, i32 new_quantity) {
  for (i32 i = 0; i < count; i++) {
    if (items[i].id == id) {
      items[i].quantity = new_quantity;
      return 1; // Success
    }
  }
  printf("Item with ID %d not found.\n", id);
  return 0; // Failure
}

i32 main(void) {
  Item inventory[MAX_ITEMS];
  i32 item_count = 0;
  add_item(inventory, &item_count, 1, "Laptop", 12, 9999.99f);
  add_item(inventory, &item_count, 2, "Mouse", 50, 99.99f);
  add_item(inventory, &item_count, 3, "Keyboard", 25, 199.99f);

  puts("Initial Inventory:");
  print_inventory(inventory, item_count);

  update_quantity(inventory, item_count, 2, 36);
  puts("Updated Inventory:");
  print_inventory(inventory, item_count);
  return 0;
}