// 1.4  Write a method to decide if two strings are anagrams or not
// note that the book thinks the spaces should also match
// but according to wiki, anagram can have different spaces!

#include <string.h>

// solution1: sort

// solution2: count the number of each chars
// O(n+m) time, O(k) space
bool is_anagram(char *str1, char *str2) {
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	
	int counter[256];
	memset(counter, 0, sizeof(counter));
	for(int i = 0; i < len1; ++i)
	{
		if(str1[i] != ' ')
		{
			counter[str1[i]]++;
		}
	}
	
	for(int i = 0; i < len2; ++i)
	{
		if( str2[i] != ' ' && --counter[str2[i]] < 0 )
		{
			return false;
		}
	}
	
	for(int i = 0; i < 256; ++i)
	{
		if(counter[i] != 0)
		{
			return false;
		}
	}
	return true;
}

int main (int argc, char const *argv[])
{
	char str1[] = "george bush";
	char str2[] = "he bugs gore";
	printf("%d\n", is_anagram(str1, str2));
	return 0;
}