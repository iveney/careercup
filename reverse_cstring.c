#include <stdio.h>

// O(n) time O(1) space
void reverse_cstring(char *str, int len) {
	int b = 0, e = len - 1;
	while (b < e) {
		char tmp = str[b];
		str[b] = str[e];
		str[e] = tmp;
		b++; e--;
	}
}

int main (int argc, char const *argv[])
{
	char str[] = "string";
	reverse_cstring(str, 6);
	printf("%s\n", str);
	return 0;
}