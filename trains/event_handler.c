#include <stdio.h>
#include <stdlib.h>
typedef enum {
  PLAYER_ATTACK,
  PLAYER_MOVE,
  EVENT_COUNT // 记录事件的总数
} GameEventType;

typedef void (*EventHandler)(const char *playerName);

EventHandler eventHandlers[EVENT_COUNT]; // 事件处理函数的数组

// 注册事件处理函数
void registerEventHandler(GameEventType eventType, EventHandler handler);

// 分发事件
void dispatchEvent(GameEventType eventType, const char *playName);

void handlePlayerAttack(const char *playName);
void handlePlayerMove(const char *playName);

int main(void) {
  puts("event handler case");

  registerEventHandler(PLAYER_ATTACK, handlePlayerAttack);
  registerEventHandler(PLAYER_MOVE, handlePlayerMove);

  dispatchEvent(PLAYER_ATTACK, "Hero");
  dispatchEvent(PLAYER_MOVE, "Hero");

  return EXIT_SUCCESS;
}
void registerEventHandler(GameEventType eventType, EventHandler handler) {
  if (eventType < EVENT_COUNT) {
    eventHandlers[eventType] = handler;
  }
}
void dispatchEvent(GameEventType eventType, const char *playName) {
  if (eventHandlers[eventType] != NULL) {
    eventHandlers[eventType](playName);
  }
}

void handlePlayerAttack(const char *playName) {
  printf("%s attacks\n", playName);
}
void handlePlayerMove(const char *playName) { printf("%s moves\n", playName); }