#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

// size_t lcs(string &str0, string &str1, size_t m, size_t n, size_t **memo);

inline size_t max(size_t a, size_t b)
{
  return (a > b) ? a : b;
}

inline size_t make_key(size_t a, size_t b)
{
  // shitty hash algorithm used to simplify our memoization
  return (a << 32) | b;
}

size_t lcs(string &str0, string &str1,
           const size_t m, const size_t n,
           size_t *memo, size_t line_size)
{
  if ((m == 0) || (n == 0)) {
    memo[m * line_size + n] = 0;
    return 0;
  }
  if (str0[m - 1] == str1[n - 1]) {
    if (memo[(m - 1) * line_size + n - 1] != 0)
      return 1 + memo[(m - 1) * line_size + n - 1];
    else
      return 1 + lcs(str0, str1, m - 1, n - 1, memo, line_size);
  }
  return max(lcs(str0, str1, m, n - 1, memo, line_size),
             lcs(str0, str1, m - 1, n, memo, line_size));
}

int main()
{
  string str0 = "AGGTAB";
  string str1 = "GXTXAYB";
  const size_t m = str0.size();
  const size_t n = str1.size();
  size_t *memo = new size_t[m * n]();  // default init to 0
  cout << lcs(str0, str1, m, n, memo, n) << endl;

  return 0;
}
