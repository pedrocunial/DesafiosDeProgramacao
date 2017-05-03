#include <iostream>
#include <queue>
#include <stack>

#define A 'A'
#define C 'C'
#define G 'G'
#define T 'T'
#define DNA_LEN 4

using namespace std;

const char DNA_ARR[] = { A, C, G, T };

void gen_dna(size_t n)
{
  queue<string> base_q;
  stack<string> curr_q;
  size_t max = 4 * 5 * (n - 1);
  base_q.push({A, 0});
  base_q.push({C, 0});
  base_q.push({G, 0});
  base_q.push({T, 0});
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < DNA_LEN; j++) {
      curr_q.push(base_q.front());
      base_q.pop();
      cout << curr_q.top() << endl;
    }
    base_q = curr_q;
  }
}

void print_permutation(size_t n)
{
  size_t max = n == 1 ? 4 : 4 * 5 * (n - 1);
  char str[n + 1] = { A };
  str[1] = '\0';
  for (size_t i = 0; i < max; i++) {
    size_t tmp = i / 4;
    if (str[tmp] == '\0') {
      for (size_t j = 0; j < i; j++) {
        str[j] = A;
      }
      str[tmp + 1] = '\0';
    }
    str[tmp] = DNA_ARR[i % 4];
    cout << str << endl;
  }
}


void blabal(size_t n)
{
  for (size_t i = 0; i < n; i++) {
    char *str = new char[i];
    char[i] = 0;
    for (char c : str) {

    }
  }
}

void foo_bar(size_t n, size_t o, char *str_buff)
{
  if (n == 0) return;
  str += A;
  foo_bar(n - 1, str);
  for (size_t i = 1; i < n; i++) {
    str[n - 1] = DNA_ARR[i];
    foo_bar(n - 1, str);
  }
}

void gen_dna_r(size_t n) {
  // if (n <= 1) return;
  // // gen_dna_r(n - 1);
  // for (size_t i = 0; i < n; i++) {
  print_permutation(n);
  // }
}

int main()
{
  size_t n;
  cin >> n;
  if (n == 0)
    return 0;
  // gen_dna(n);
  char *str_buff = new char[n]

  return 0;
}
