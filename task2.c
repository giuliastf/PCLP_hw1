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
  int inst_bin[32] = {0}, N = 1, dim = 1, i, j, k, nr_opz, rez, x, y;
  short unsigned int nr, o = 0;
  scanf("%u", & inst);
  bin(32, inst, inst_bin);
  for (i = 2; i >= 0; i--) //N
    if (inst_bin[i] == 1)
      N = N + pow(2, 2 - i);
  char tip_op[N];
  short unsigned int opz[N + 1];
  j = 0;
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
  for (i = N * 2 + 6; i > N * 2 + 2; i--)
    if (inst_bin[i] == 1)
      dim = dim + pow(2, (N * 2 + 6) - i); //dim
  //task2
  if ((N + 1) * dim % 16 == 0) //nr_opz
    nr_opz = (N + 1) * dim / 16;
  else
    nr_opz = 1 + ((N + 1) * dim / 16);
  x = 0;
  for (i = 0; i < nr_opz; i++) //interpretare operanzi
  {
    scanf("%hu", & nr);
    int nr_bin[16] = {0};
    bin(16, nr, nr_bin);
    y = 1;
    for (j = 0; j < 16 && x < N + 1; j = j + dim) {
      for (k = j; k < y * dim; k++)
        if (nr_bin[k] == 1)
          o = o + pow(2, y * dim - k - 1);
      opz[x] = o;
      o = 0;
      x++;
      y++;
    }
  }
  rez = opz[0];
  for (i = 0; i < N; i++) {
    if (tip_op[i] == '+')
      rez = rez + opz[i + 1];
    if (tip_op[i] == '-')
      rez = rez - opz[i + 1];
    if (tip_op[i] == '/')
      rez = rez / opz[i + 1];
    if (tip_op[i] == '*')
      rez = rez * opz[i + 1];
  }
  printf("%d\n", rez);
  return 0;
}