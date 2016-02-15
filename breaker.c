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

//Read the encoded text from an input file and accumulate the letter frequency store in found
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
    //DO IT
    //First check if C is a char
    //Next check if it is uppercase or lowercase and react accordingly
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
  //Need another loop to go through and determine freqs
  for (int i = 0; i < 26; i++) {
    found[i] = (found[i]/count);
  }
  
  printf("%f   %d\n", found[0], count);
  printf("%f   %d\n", found[25], count);
  
  fclose(in);
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
  //  readFreq(given_freqs, "LetFreq.txt");
  calcFreq(calc_freqs, "lol.txt");
  return 0;
}
