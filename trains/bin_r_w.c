#include <stdio.h>
#include <stdlib.h>
typedef struct {
  float volume;
  int resolution_x;
  int resolution_y;
  int difficulty;
} GameSettings;

int save_game_settings(const GameSettings *settings, const char *filename);
int load_game_settings(GameSettings *settings, const char *filename);
int main(void) {
  puts("----------case: 读写二进制文件----------");
  // fread
  // fwrite
  // GameSettings settings = {0.75, 1920, 1080, 3};
  // save_game_settings(&settings, "./game_settings.bin");

  GameSettings load_settings;
  load_game_settings(&load_settings, "./game_settings.bin");
  puts("游戏设置已加载！");
  printf("音量: %.2f\n分辨率: %d*%d\n难度: %d\n", load_settings.volume,
         load_settings.resolution_x, load_settings.resolution_y,
         load_settings.difficulty);
  return 0;
}

int save_game_settings(const GameSettings *settings, const char *filename) {
  FILE *file;
  errno_t err = fopen_s(&file, filename, "wb");

  if (err != 0 || file == NULL) {
    perror("无法打开文件进行写入操作");
    return EXIT_FAILURE;
  }

  fwrite(settings, sizeof(GameSettings), 1, file);
  fclose(file);
  return 0;
}
int load_game_settings(GameSettings *settings, const char *filename) {
  FILE *file;
  errno_t err = fopen_s(&file, filename, "rb");

  if (err != 0 || file == NULL) {
    perror("无法打开文件进行读取操作");
    return EXIT_FAILURE;
  }

  fread(settings, sizeof(GameSettings), 1, file);
  fclose(file);
  return 0;
}