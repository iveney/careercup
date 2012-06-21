// Write code to reverse a C-Style String (C-String means that “abcd” is represented as
// five characters, including the null character )
#include <cstring>

void reverse_string(char* str, int n) {
	// swap the characters
	for(int i = 0; i < n/2; ++i)
	{
		char c = str[i];
		str[i] = str[n-i-1];
		str[n-i-1] = c;
	}
}

int main (int argc, char const *argv[])
{
	char str[] = "This is the string to reverse";
	int n = strlen(str);
	printf("Original string: %s\n", str);
	reverse_string(str, n);
	printf("Reversed string: %s\n", str);
	
	char str2[] = "first";
	n = strlen(str2);
	printf("Original string: %s\n", str2);
	reverse_string(str2, n);
	printf("Reversed string: %s\n", str2);
	
	char str3[] = "second";
	n = strlen(str3);
	printf("Original string: %s\n", str3);
	reverse_string(str3, n);
	printf("Reversed string: %s\n", str3);
	return 0;
}