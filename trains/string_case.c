#include <stddef.h>
#include <stdio.h>
#include <string.h>
#define TEXT_SIZE 100
#define WORD_SIZE 100
#define DELIMS " ,.!?\n"

void replaceWord(const char *text, const char *oldWord, const char *newWord,
                 char *result);
int countChar(const char *text, char ch);
int countWord(const char *text);
void extractUniqueWords(const char *text, char uniqueWords[][WORD_SIZE],
                        int *uniqueCount);

int main(void) {
  puts("String Case!");
  char text[TEXT_SIZE] = "This is a simple test. This text is for testing.";
  char replacedText[TEXT_SIZE] = {0};
  char oldWord[] = "test";
  char newWord[] = "example";
  char countCharTarget = 's';

  char uniqueWords[TEXT_SIZE][WORD_SIZE] = {0};
  int uniqueCount = 0;

  replaceWord(text, oldWord, newWord, replacedText);
  printf("%s\n", replacedText);

  int charCount = countChar(replacedText, countCharTarget);
  printf("Character '%c' appears %d times.\n", countCharTarget, charCount);

  int wordCount = countWord(replacedText);
  printf("Total number of words is: %d\n", wordCount);

  extractUniqueWords(replacedText, uniqueWords, &uniqueCount);
  puts("Unique words:");
  for (int i = 0; i < uniqueCount; ++i) {
    printf("%s\n", uniqueWords[i]);
  }

  return 0;
}
void replaceWord(const char *text,    // 源字符串
                 const char *oldWord, // 要被替换的单词
                 const char *newWord, // 新的单词
                 char *result) {      // 存储结果的缓冲区
  // 创建临时缓冲区并初始化为0
  char buffer[TEXT_SIZE] = {0};

  // pos 指向当前处理位置
  const char *pos = text;
  // temp 用于存储查找结果
  const char *temp = text;
  // 获取要替换的单词长度
  size_t oldLen = strlen(oldWord);

  // 循环查找并替换所有匹配的单词
  while ((temp = strstr(pos, oldWord)) != NULL) {
    // 1. 复制从pos到找到的单词之前的所有字符
    strncat_s(buffer, sizeof(buffer), pos, temp - pos);

    // 2. 添加新单词
    strcat_s(buffer, sizeof(buffer), newWord);

    // 3. 移动pos指针到旧单词后面
    pos = temp + oldLen;
  }

  // 4. 复制剩余的字符
  strcat_s(buffer, sizeof(buffer), pos);

  // 5. 将结果复制到结果缓冲区
  strcpy_s(result, TEXT_SIZE, buffer);
}

int countChar(const char *text, char ch) {
  int count = 0;
  while (*text) {
    if (*text == ch) {
      count++;
    }
    text++;
  }
  return count;
}

int countWord(const char *text) {
  int count = 0;
  char buffer[TEXT_SIZE] = {0};
  strcpy_s(buffer, TEXT_SIZE, text);

  char *context = NULL;
  char *token = strtok_s(buffer, DELIMS, &context);
  while (token != NULL) {
    count++;
    token = strtok_s(NULL, DELIMS, &context);
  }
  return count;
}

void extractUniqueWords(const char *text, char uniqueWords[][WORD_SIZE],
                        int *uniqueCount) {
  char tempText[TEXT_SIZE] = {0};
  strcpy_s(tempText, TEXT_SIZE, text);

  char *context = NULL;
  char *token = strtok_s(tempText, DELIMS, &context);
  while (token != NULL) {
    int found = 0;
    for (int j = 0; j < *uniqueCount; ++j) {
      if (strcmp(token, uniqueWords[j]) == 0) {
        found = 1;
        break;
      }
    }
    if (!found) {
      strcpy_s(uniqueWords[*uniqueCount], WORD_SIZE, token);
      (*uniqueCount)++;
    }
    token = strtok_s(NULL, DELIMS, &context);
  }
}