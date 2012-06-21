
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;

int cmp(const void* a, const void* b) {
	char* c = (char*)a;
	char* d = (char*)b;
	return *c - *d;
}

bool is_anagram(char* str1, char* str2) {
	int n1 = strlen(str1);
	int n2 = strlen(str2);
	qsort(str1, n1, sizeof(char), cmp);
	qsort(str2, n2, sizeof(char), cmp);
	return strcmp(str1,str2) == 0?true:false;
}

int main (int argc, char const *argv[])
{
	// sort the strings and compare.
	// O(nlog(n))
	char str1[] = "abcde";
	char str2[] = "edcba";
	cout << is_anagram(str1, str2) << endl;
	
	char str3[] = "abcd";
	char str4[] = "dcb";
	cout << is_anagram(str3, str4) << endl;
	return 0;
}