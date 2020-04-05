#include <bits/stdc++.h>

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

int32_t main() {
  auto start = std::chrono::steady_clock::now();

  long long time_elapsed;
  do {
    //int random = rng() % n;
    //if (good) return puts("YES"), 0;

    auto cur = std::chrono::steady_clock::now();
    time_elapsed =
      std::chrono::duration_cast<std::chrono::milliseconds>(cur-start).count();
  } while (time_elapsed < 1900);
  
  puts("NO");
  return 0;
}
