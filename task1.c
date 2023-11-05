#include <stdio.h>

#include <math.h>
 //task1
void bin(int biti, unsigned int nr, int bin[]) {
  int i;
  for (i = biti - 1; nr != 0; i--) {
    if (nr % 2 == 1)
      bin[i] = 1;
    else
      bin[i] = 0;
    nr /= 2;
  }
}

int main() {
  unsigned int inst;
  int inst_bin[32] = {0}, N = 1, dim = 1, i, j = 0;
  scanf("%u", & inst);
  bin(32, inst, inst_bin);
  for (i = 2; i >= 0; i--) // N
    if (inst_bin[i] == 1)
      N = N + pow(2, 2 - i);
  printf("%d ", N);
  char tip_op[N];
  for (i = 3; i <= N * 2 + 2; i = i + 2) //operatii
  {
    if (inst_bin[i] == 0 && inst_bin[i + 1] == 0)
      tip_op[j] = '+';
    if (inst_bin[i] == 0 && inst_bin[i + 1] == 1)
      tip_op[j] = '-';
    if (inst_bin[i] == 1 && inst_bin[i + 1] == 1)
      tip_op[j] = '/';
    if (inst_bin[i] == 1 && inst_bin[i + 1] == 0)
      tip_op[j] = '*';
    j++;
  }
  for (i = 0; i < N; i++)
    printf("%c ", tip_op[i]);
  for (i = N * 2 + 6; i > N * 2 + 2; i--) //dim
    if (inst_bin[i] == 1)
      dim = dim + pow(2, (N * 2 + 6) - i);
  printf("%d\n", dim);

  return 0;
}