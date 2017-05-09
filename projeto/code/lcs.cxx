#include <iostream>
#include <string>

using namespace std;

size_t max(int a, int b);
size_t lcs(string &str0, string &str1, const size_t len0, const size_t len1);

/* Returns length of LCS for X[0..len0-1], Y[0..len1-1] */
// LCS: Longest Common Subsequence
size_t lcs(string &str0, string &str1, const size_t len0, const size_t len1)
{
  size_t L[len0 + 1][len1 + 1];
  size_t i, j;

  /* Following steps build L[len0+1][len1+1] in bottom up fashion. Note
     that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
  for (i = 0; i <= len0; i++) {
    for (j = 0; j <= len1; j++) {
      if ((i == 0) || (j == 0))
        L[i][j] = 0;
      else if (str0[i - 1] == str1[j - 1])
        L[i][j] = L[i - 1][j - 1] + 1;
      else
        L[i][j] = max(L[i - 1][j], L[i][j - 1]);
    }
  }

  size_t lcslen = L[len0][len1];
  char lcsstr[lcslen + 1];
  i = len0;
  j = len1;
  lcsstr[lcslen] = 0;
  while ((i > 0) && (j > 0)) {
    if (str0[i - 1] == str1[j - 1]) {
      // if the current char is the same in both strs
      lcsstr[lcslen - 1] = str0[i - 1];  // we could have str1 here also
      i--, j--, lcslen--;
    } else if (L[i - 1][j] > L[i][j - 1]) {
      // if not the same, then find the larger of the two next options
      // (bellow or right) and go to there for our next iteration
      i--;
    } else {
      j--;
    }
  }
  cout << "The Subsequence is: " << lcsstr << endl;

  /* L[len0][len1] contains length of LCS for X[0..len1-1] and Y[0..len0-1] */
  return L[len0][len1];
}

/* Utility function to get max of 2 integers */
size_t max(int a, int b)
{
  return (a > b) ? a : b;
}

/* Driver program to test above function */
int main()
{
  string str0 = "AGGTAB";
  string str1 = "GXTXAYB";
  string lcsstr;

  cout << "Length of LCS is " << lcs(str0, str1, str0.size(), str1.size()) << endl;
  return 0;
}
