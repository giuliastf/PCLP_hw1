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
      dim = dim + pow(2, (N * 2 + 6) - i);
  if ((N + 1) * dim % 16 == 0)
    nr_opz = (N + 1) * dim / 16;
  else
    nr_opz = 1 + ((N + 1) * dim / 16);
  y = 1;
  //task4
  int tot[nr_opz * 16];
  for (i = 0; i < nr_opz; i++) {
    scanf("%hu", & nr);
    int nr_bin[16] = {};
    bin(16, nr, nr_bin);
    for (j = (y - 1) * 16; j < y * 16; j++)
      tot[j] = nr_bin[j % 16];
    y++;
  }
  x = 1;
  while (x <= N + 1)
    for (i = 0; i < nr_opz * 16; i = i + dim) {
      for (j = i; j < x * dim; j++) // interpretez operanzii din nr din dim in dim (cu y) in ze
        if (tot[j] == 1)
          o = o + pow(2, x * dim - j - 1);
      opz[x - 1] = o; // vector cu op primeste prima val zecimala
      o = 0; //reinitializez
      x++;
    }
  //task4
  for (i = 0; i < N; i++)
    if (tip_op[i] == '*' || tip_op[i] == '/') {
      if (tip_op[i] == '*')
        opz[i] = opz[i] * opz[i + 1];
      else
        opz[i] = opz[i] / opz[i + 1];
      for (j = i + 1; j < (N + 1); j++)
        opz[j] = opz[j + 1];
      for (j = i; j < N; j++)
        tip_op[j] = tip_op[j + 1];

      N--;
      i--;
    }
  rez = opz[0];
  for (i = 0; i < N; i++) {
    if (tip_op[i] == '+')
      rez = rez + opz[i + 1];
    if (tip_op[i] == '-')
      rez = rez - opz[i + 1];
  }
  printf("%d\n", rez);

  return 0;
}