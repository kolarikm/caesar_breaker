#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float given_freqs[26];

void readFreq(float given[], char fname[]) {
  char str[20];
  int x = 0;
  FILE* in;
  in = fopen(fname, "r");
  if (in == NULL) {
    printf("Error opening file.\n");
    return -1;
  }
  while (fgets(str, 20, in) != NULL) {
    given_freqs[x] = atof(str+2);
    x++;
  }
}

void calcFreq(float found[], char fname[]) {

}

char rotate(char ch, int num) {

  return 'a';
}

int findKey(float given[], float found[]) {

  return 0;
}

void decrypt(int key, char fname[]) {

}

int main() {
  /*
  FILE *in_freq;
  char str[20];
  char val[7];
  
  in_freq = fopen("LetFreq.txt", "r");
  if(in_freq == NULL) {
    printf("Error\n");
    return -1;
  }
  while (fgets(str, 20, in_freq) != NULL) {
    // strcpy(val, str+2);
    printf("%s\n", str+2);
  }
  fclose(in_freq);

  //readFreq(given_freqs, "LetFreq.txt");
  */
  readFreq(given_freqs, "LetFreq.txt");
  return 0;
}
