#include <iostream>
#include <timer.h>

int main() {
  Timer timer;
  timer.Restart();
  Sleep(1000);
  std::cout << timer.GetElapsedTime() << " sec";
}
