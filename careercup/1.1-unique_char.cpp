/* Implement an algorithm to determine if a string has all unique characters What if you
can not use additional data structures? */

#include <cstring>
#include <map>
using namespace std;

typedef map<char, int> CharMap;

bool is_unique(char *buf, int n) {
	CharMap cm;
	for(int i = 0; i < n; ++i)
	{
		if(cm[buf[i]] > 0) {
			return false;
		}
		cm[buf[i]]++;
	}
	return true;
}

bool is_unique_sorting(char *buf, int n) {
	char *copy = new char[n+1];
	strncpy(copy, buf, n);
	copy[n] = '\0';
	sort(copy, copy+n);
	for(int i = 1; i < n; ++i)
	{
		if(buf[i-1] == buf[i])
		{
			return false;
		}
	}
	delete [] copy;
	return true;
}

int main (int argc, char const *argv[])
{
	char duplicate[] = "the characters is not unique";
	char unique[] = "abcdefghij";
	
	// use hash, O(n)
	cout << "The string '" << duplicate << "' :"
		<< is_unique(duplicate, strlen(duplicate)) << endl;
		
	cout << "The string '" << unique << "' :"
		<< is_unique(unique, strlen(unique)) << endl;
		
	// use sorting, O(nlog(n))
	cout << "The string '" << duplicate << "' :"
		<< is_unique_sorting(duplicate, strlen(duplicate)) << endl;
		
	cout << "The string '" << unique << "' :"
		<< is_unique_sorting(unique, strlen(unique)) << endl;
	
	return 0;
}