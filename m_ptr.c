#include <corecrt_search.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int id;
  float price;
  const char *manufacture;
} Product;

Product *create_product(int id, float price, const char *manufacture);
void update_by_wholesaler(Product *product, int new_id, float new_price);
void update_by_retailer(Product *product, int new_id, float new_price);
const char *get_manufacture_info(Product **product_ptr);

int main(int argc, char *argv[]) {
  /// ### Multilevel Pointers
  puts("Multilevel Pointers");

  /*

  int a = 42;        // 一个普通的int变量
  int *ptr = &a;     // 一个指向int变量的指针  ptr -> a
  int **pptr = &ptr; // 一个指向ptr指针的指针

  */

  /* Product *product1 = create_product(1, 10.5); */
  /* Product *product2 = create_product(2, 12.5); */

  /* printf("Product1 ID: %d, Price: %.2f\n", product1->id, product1->price); */
  /* printf("Product2 ID: %d, Price: %.2f\n", product2->id, product2->price); */
  /* printf("Product1 ID: %d, Price: %.2f\n", product1->id, product1->price); */

  Product *product = create_product(1, 15.5, "Az's Company");
  printf("Product ID: %d, Price: %.2f, Manufacture: %s\n", product->id,
         product->price, product->manufacture);

  update_by_wholesaler(product, 12, 20.0);
  printf("Wholesaler New Product ID: %d, Price: %.2f\n", product->id,
         product->price);
  update_by_retailer(product, 112, 22.5);
  printf("Retailer Product ID: %d, Price: %.2f\n", product->id, product->price);

  Product *wholesaler_product = product;
  Product **retailer_product = &wholesaler_product;
  printf("Multilevel Pointers -> Retailer Product ID: %d, Price: %.2f, "
         "Manufacture: %s\n",
         (*retailer_product)->id, (*retailer_product)->price,
         (*retailer_product)->manufacture);

  const char *manufacture_info = get_manufacture_info(retailer_product);
  printf("Retailer contacted factory through wholesaler: Manufacture: %s\n",
         manufacture_info);

  free(product);

  return EXIT_SUCCESS;
}

Product *create_product(int id, float price, const char *manufacture) {
  Product *product = (Product *)malloc(sizeof(Product));

  if (product == NULL) {
    perror("Failed to allocate memory");
    exit(EXIT_FAILURE);
  }

  product->id = id;
  product->price = price;
  product->manufacture = manufacture;
  return product;
}

void update_by_wholesaler(Product *product, int new_id, float new_price) {
  product->id = new_id;
  product->price = new_price;
}
void update_by_retailer(Product *product, int new_id, float new_price) {
  product->id = new_id;
  product->price = new_price;
}
const char *get_manufacture_info(Product **product_ptr) {
  return (*product_ptr)->manufacture;
  /* return (**product_ptr).manufacture; */
}
