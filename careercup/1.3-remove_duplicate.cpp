/*
Design an algorithm and write code to remove the duplicate characters in a string
without using any additional buffer NOTE: One or two additional variables are fine An
extra copy of the array is not
*/
#include <cstring>

int remove_duplicate(char *str, int n) {
	if(str == NULL) return 0;
	if(n == 1) return 1;
	int i,j;
	for(i=1, j=1; j < n; ++j)
	{
		char c = str[j];
		int k;
		for(k = 0; k < i; ++k) {
			if(c == str[k]) {
				break;
			}
		}
		if (k==i) { // no duplicate, copy this to the end
			str[i++] = c;
		}
	}
	str[i] = '\0';
	return i;
}

void test_case(char *str) {
	int n = strlen(str);
	n = remove_duplicate(str, n);
	printf("%s: %d\n", str, n);
}

int main (int argc, char const *argv[])
{
	// for each char, check whether it appears before or not
	// maintain two pointers: one points to the non-duplicated characters so far
	// one points to the current visiting characters
	// O(n^2)
	char str[] = "ababbdfacd";
	char str2[] = "aaaa";
	char str3[] = "abcd";
	char str4[] = "aaabbbccc";
	test_case(str);
	test_case(str2);
	test_case(str3);
	test_case(str4);
	return 0;
}