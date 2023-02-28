/**
 * @file timer.cpp
 * @brief 処理時間を計測する
 * @author naokichi
 * @date 2023/02/27
 */

#include <timer.h>

/**
 * コンストラクタ
 */
Timer::Timer() {
  BOOL retval = QueryPerformanceFrequency(&freq);
  if (retval == FALSE) {
    std::cout << "パフォーマンスカウンタの周波数を取得できません。"
              << std::endl;
  }
  Restart();
}

/**
 * @brief タイマーをリスタートする
 */
void Timer::Restart() {
  BOOL retval = QueryPerformanceCounter(&start);
  if (retval == FALSE) {
    std::cout << "パフォーマンスカウンタを取得できません。" << std::endl;
  }
}

/**
 * @brief 経過時間を取得する
 * @return 経過時間 [s]
 */
double Timer::GetElapsedTime() {
  BOOL retval = QueryPerformanceCounter(&end);
  if (retval == FALSE) {
    std::cout << "パフォーマンスカウンタを取得できません。" << std::endl;
  }
  return (double)(end.QuadPart - start.QuadPart) / freq.QuadPart;
}