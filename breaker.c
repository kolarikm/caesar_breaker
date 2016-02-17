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

  //printf("%f   %d\n", found[0], count);
  //printf("%f   %d\n", found[25], count);
  
  fclose(in);
}

char rotate(char ch, int num) {
  if (islower(ch))
    return ((((ch - 'a') + num) % 26) + 'a');
  else
    return ((((ch - 'A') + num) % 26) + 'A');
}
/*
void rotate_one(float arr[], int n) {
  int j, i;
  j = arr[0];
  for (i = 0; i < n-1; i++)
    arr[i] = arr[i+1];
  arr[i] = j;
}
*/
float diff_two_squares(float a, float b) {
  float x = a - b;
  return x * x;
}
/*
void rotate_arr(float arr[], int d, int size) {
  for (int i = 0; i < d; i++)
    rotate_one(arr, size);
}
*/

void rotate_one(float a[], int n) {
  int i, temp;
  temp = a[0];
  for (i = 0; i < n-1; i++)
    a[i] = a[i+1];
  a[i] = temp;
}

void rotate_arr(float a[], int n, int d) {
  int i;
  for (i = 0; i < d; i++)
    rotate_one(a, n);
}

int find_least(float arr[], int size) {
  int f;
  float temp;
  for (int i = 0; i < size; i++) {
    if (arr[i] < temp) {
      temp = arr[i];
      f = i;
    }
  }
  return f;
}

int findKey(float given[], float found[]) {
  float f;
  float diffs[26];
  for (int x = 0; x <26; x++) {
    rotate_arr(found, 26, x);
    printf("%f\n", found[0]);
    f = 0;
    for (int y = 0; y <26; y++) {
      f += diff_two_squares(given[y], found[y]);
    }
    diffs[x] = f;
    //printf("%f\n", f);
  }
  return find_least(diffs, 26);
  printf("Key... %d\n", find_least(diffs, 26));
}

void decrypt(int key, char in_name[], char out_name[]) {
  FILE *in, *out;
  char ch;
  in = fopen(in_name, "r");
  out = fopen(out_name, "w");
  if (in == NULL || out == NULL) {
    printf("Error opening file.\n");
    exit(-1);
  }
  while (fscanf(in, "%c", &ch) != EOF) {
    fprintf(out, "%c", rotate(ch, key));
  }

  fclose(in);
  fclose(out);
}

int main(int argc, char * argv[]) {
  // Take command line arguments for input and output files
  /*
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

  int key;

  if (argc != 3) {
    printf("Please specify an input file (encrypted) and desired output file.\n");
    exit(1);
  }

  readFreq(given_freqs, "LetFreq.txt");
  calcFreq(calc_freqs, argv[1]);
  key = findKey(given_freqs, calc_freqs);
  printf("%d\n", key);
  decrypt(key, argv[1], argv[2]);

  return 0;
}
