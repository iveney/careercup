#include <iostream>
#include <stdio.h>
#include <string.h>
#include <memory.h>
using namespace std;

// O(n) time and O(n) space
bool is_unique(char *s, int len) {
	char hash[256];
	memset(hash, 0, sizeof(hash));
	for(int i = 0; i < len; ++i)
	{
		if( hash[s[i]] == 1 )
		{
			return false;
		}
		hash[s[i]] = 1;
	}
	return true;
}

// use bit technique to O(k), k is the vocabulary size
bool is_unique_bit(char *s, int len)
{
	
}

int main (int argc, char const *argv[])
{
	char str[] = "abcd";
	cout << is_unique(str, 5) << endl;
	return 0;
}