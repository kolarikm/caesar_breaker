#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float given_freqs[26];
float calc_freqs[26];

void readFreq(float given[], char fname[]) {
  char str[20];
  int x = 0;
  FILE* in;
  in = fopen(fname, "r");
  if (in == NULL) {
    printf("Error opening file.\n");
    exit(-1);
  }
  while (fgets(str, 20, in) != NULL) {
    given_freqs[x] = atof(str+2);
    x++;
  }
  fclose(in);
}

void calcFreq(float found[], char fname[]) {
  FILE* in;
  char c;
  int count = 0;
  
  in = fopen(fname, "r");
  if (in == NULL) {
    printf("Error opening file.\n");
    exit(-1);
  }
  while ((c = fgetc(in)) != EOF) {
    if (isalpha(c)) {
      if (c >= 'a' && c <= 'z') {
	found[c - 'a']++;
	count++;
      }
      if (c >= 'A' && c <= 'Z') {
	found[c - 'A']++;
	count++;
      }
    }
  }
  for (int i = 0; i < 26; i++) {
    found[i] = (found[i]/count);
  }

  printf("%f   %d\n", found[0], count);
  printf("%f   %d\n", found[25], count);
  
  fclose(in);
}

char rotate(char ch, int num) {
  if (islower(ch))
    return ((((ch - 'a') + num) % 26) + 'a');
  else
    return ((((ch - 'A') + num) % 26) + 'A');
}

void rotate_one(float arr[], int n) {
  int j, i;
  j = arr[0];
  for (i = 0; i < n-1; i++)
    arr[i] = arr[i+1];
  arr[i] = j;
}

void rotate_arr(float arr[], int d, int size) {
  for (int i = 0; i < d; i++)
    rotate_one(arr, size);
}

int findKey(float given[], float found[]) {

  

  return 0;
}

void decrypt(int key, char fname[]) {

}

int main() {
  // Take command line arguments for input and output files
  readFreq(given_freqs, "LetFreq.txt");
  calcFreq(calc_freqs, "lol.txt");
  printf("%f\n", calc_freqs[0]);
  printf("%f\n", calc_freqs[1]);
  rotate_arr(calc_freqs, 1, 26);
  printf("%f\n", calc_freqs[0]);
  printf("%f\n", calc_freqs[1]);
  /*char s = rotate('z', 2);
  printf("%c\n", s);
  s = rotate('A', 2);
  printf("%c\n", s);
  */

  FILE *in, *out;
  /*
  if (argc != 3) {
    printf("Please specify an input file (encrypted) and desired output file.\n");
    exit(1);
  }

  in = fopen(argv[1], "r");
  out = fopen(argv[2], "w");

  if (in == NULL || out == NULL) {
    printf("Error opening file!"\n);
    exit(1);
  }

  */

  // Call find key and decrypt on input here

  return 0;
}
