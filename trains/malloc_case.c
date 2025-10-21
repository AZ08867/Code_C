#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *name;
  int level;
  int hp;
} Character;

Character *create_character(const char *name, int level, int hp);
void free_character(Character *character);

int main(int argc, char *argv[]) {
  puts("Malloc 函数与结构体的使用案例");
  Character *hero = create_character("Hero", 1, 100);
  if (hero == NULL) {
    return EXIT_FAILURE;
  }
  free(hero);
  return EXIT_SUCCESS;
}
Character *create_character(const char *name, int level, int hp) {
  Character *new_character = (Character *)malloc(sizeof(Character));
  if (new_character == NULL) {
    perror("Failed to allocate memory for new character");
    return NULL;
  }

  new_character->name = (char *)malloc(strlen(name) + 1);
  if (new_character->name == NULL) {
    perror("Failed to allocate memory for new character name");
    free(new_character); // 防止内存泄露
    return NULL;
  }

  strcpy_s(new_character->name, strlen(name) + 1, name);
  new_character->level = level;
  new_character->hp = hp;

  return new_character;
}
void free_character(Character *character) {
  if (character != NULL) {
    free(character->name);
    free(character);
  }
}