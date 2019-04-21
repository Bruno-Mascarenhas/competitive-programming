#include <bits/stdc++.h>

#define st first
#define nd second
#define pb push_back
#define pf push_front
typedef std::pair<int, int> pii;
typedef std::pair<int, pii> piii;
int dirI[]  = {0, 1, 0, -1};
int dirJ[]  = {1, 0, -1, 0};

const int N = 110, INF = 0x3f3f3f3f;
int n, m, d[N][N][4];
char grid[N][N];
pii src, snk;

bool valid(pii pos) {
  if (pos.st >= n || pos.st < 0) return false;
  if (pos.nd >= m || pos.nd < 0) return false;
  return grid[pos.st][pos.nd] != '*';
}

void bfs01() {
  std::deque<piii> q;
  memset(d, INF, sizeof d);
  for (int i = 0; i < 4; i++) {
    d[src.st][src.nd][i] = 0;
    q.pf({i, src});
  }

  while (!q.empty()) {
    piii top = q.front(); q.pop_front();
    int sense = top.st;
    pii v = top.nd;

    for (int i = 0; i < 4; i++) {
      pii u = {v.st + dirI[i], v.nd + dirJ[i]};
      int w = (sense != i);
      if (valid(u) && d[v.st][v.nd][sense] + w < d[u.st][u.nd][i]) {
        d[u.st][u.nd][i] = d[v.st][v.nd][sense] + w;
        w ? q.pb({i, u}) : q.pf({i, u});
      }
    }
  }
}

int main() {
  scanf("%d%d", &m, &n);

  bool flag = false;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf(" %c", &grid[i][j]);
      if (grid[i][j] == 'C') {
        if (flag) snk = {i, j};
        else src = {i, j};
        flag = true;
      }
    }
  }

  bfs01();
  int ans = INF;
  for (int i = 0; i < 4; i++)
    ans = std::min(ans, d[snk.st][snk.nd][i]);

  printf("%d\n", ans);
  return 0;
}