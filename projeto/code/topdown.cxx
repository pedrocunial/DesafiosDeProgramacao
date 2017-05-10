#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;


inline size_t max(size_t a, size_t b)
{
  return (a > b) ? a : b;
}

inline size_t make_key(size_t a, size_t b)
{
  // Não utilizado, mas por afeto emocional, resolvi deixá-lo aqui
  return (a << 32) | b;
}


/*
  Longest Common Subsequence:
  str0 e str1: Sequência de caracteres de entrada
  m e n: Tamanho da sequência a ser analizada, sendo m o tamanho de str0 e n de
         str1
  memo: Matriz de memoização
  line_size: Tamanho da linha da matriz, utilizado para o cálculo da posição de
             um membro da matriz pelos indices i e j, uma vez que a
             representação da matriz é feita por um array simples (otimização de
             cache)

   A cada iteração do problema, os valores de m ou n diminuem, até chegarem em 0
   (caso base)
 */
size_t lcs(string &str0, string &str1,
           const size_t m, const size_t n,
           size_t *memo, size_t line_size)
{
  if ((m == 0) || (n == 0)) {
    // Caso base da recursao
    memo[m * line_size + n] = 0;
    return 0;
  }
  // Se os caracteres forem iguais: Membro da subsequencia encontrado
  if (str0[m - 1] == str1[n - 1]) {
    size_t i = m - 1, j = n - 1;
    // Solucionando o problema pelo seu subproblema
    if (memo[m * line_size + n] != 0) {
      // Caso já tenha sido calculada a respota, utilizamos o valor salvo
      return 1 + memo[i * line_size + j];
    } else {
      // Caso contrário, realizamos a chamada recursiva para a solução
      memo[m * line_size + n] = 1 + lcs(str0, str1, i, j, memo, line_size);
      return memo[m * line_size + n];
      // return 1 + lcs(str0, str1, i, j, memo, line_size);
    }
  }
  // Por fim, tomamos o valor da máximo atual como o valor máximo entre
  // o caso em que reduziriamos o tamanho da str0 com o caso de que reduziriamos
  // o tamanho da str1 (combinação dos subproblemas)
  memo[m * line_size + n] = max(lcs(str0, str1, m, n - 1, memo, line_size),
                                lcs(str0, str1, m - 1, n, memo, line_size));
  return memo[m * line_size + n];
}

void print_subsequence(string &str0, string &str1, size_t memo[])
{
  const size_t m = str0.size();
  const size_t n = str1.size();
  size_t i = m, j = n;
  // ultimo valor coletado, maior subsequencia (repare que o valor de line_size
  // foi simplificado para n aqui)
  size_t lcslen = memo[m * n + n];
  // buffer para criar a string (subsequencia)
  char lcsstr[lcslen + 1];
  lcsstr[lcslen] = '\0';
  while ((i > 0) && (j > 0)) {
    if (str0[i - 1] == str1[j - 1]) {
      // Se o caracter atual for igual em ambas as sequências
      lcsstr[lcslen - 1] = str0[i - 1];  // Poderiamos utilizar str1 e j também
      i--, j--, lcslen--;
    } else if (memo[(i - 1) * n + j] > memo[i * n + j - 1]) {
      // Se não for o mesmo, encontre o maior entre as duas próximas opções,
      // caso o maior seja o anterior em i, sabemos que a mudança foi feita na
      // str0, caso sejam iguais, nenhum dos dois mudou, caso o maior seja o
      // anterior em j, sabemos que a mudança foi feita em str1
      i--;
    } else {
      // Caso o maior não esteja em i, decrementamos o valor de j, pois ou o
      // maior está em j ou eles são iguais e, em ambos os casos, reduzir o
      // valor de j é uma opção válida para continuar o loop.
      j--;
    }
  }
  cout << "A maior subsequência encontrada foi: "<< lcsstr << "." << endl;
}

int main()
{
  // Entradas de exemplo (duas strings)
  string str0 = "AGGTAB";
  string str1 = "GXTXAYB";
  const size_t m = str0.size();
  const size_t n = str1.size();
  // Memo é a matriz de memoização, onde os valores já calculados são armazenados
  size_t *memo = new size_t[(m + 1) * (n + 1)];  // default init to 0
  cout << "A maior subsequência encontrada possui " << lcs(str0, str1, m, n, memo, n)
       << " caracteres." << endl;
  print_subsequence(str0, str1, memo);

  return 0;
}
