// similar to replace ' ' with '%20'
// This time also delets 'A'

#include <stdio.h>
#include <string.h>

// assume that buf has enough space
int replace_space_deleta_A(char *str, int size, char *buf) {
	int n = 0;
	// first pass: calculate number of final characters
	for (int i=0;i<size;i++) {
		if (str[i]==' ') {
			n += 3;
		}
		else if (str[i] != 'A') {
			n += 1;
		}
	}
	
	buf[n] = '\0';
	int len = n;
	// second pass: fill buf from the end
	for (int i=size-1;i>=0;i--) {
		if (str[i]==' ') {
			buf[--n] = '0';
			buf[--n] = '2';
			buf[--n] = '%';
		}
		else if (str[i]!='A'){
			buf[--n] = str[i];
		}
	}
	return len;
}

#define MAXSIZE 1000

int main(int argc, char *argv[]) {
	char str[] = " A 1AA  2";
	char buf[MAXSIZE];
	replace_space_deleta_A(str, strlen(str), buf);
	printf("%s\n", buf);
}