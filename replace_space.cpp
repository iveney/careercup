// 1.5 Write a method to replace all spaces in a string with ‘%20’

#include <stdio.h>
#include <string.h>

char *replace_space(char *str) {
	int len = 0;
	int count = 0;
	while(str[len]) {
		if(str[len] == ' ')
		{
			count++;
		}
		len++;
	}
	int new_len = len + count * 2;
	char *new_str = new char[new_len];
	for(int i = 0, j = 0; i < len; ++i)
	{
		if(str[i] == ' ')
		{
			new_str[j++] = '%';
			new_str[j++] = '2';
			new_str[j++] = '0';
		}
		else
			new_str[j++] = str[i];
	}
	return new_str;
}

int main (int argc, char const *argv[])
{
	char str[256] = "ab kla fasd  asdf";
	char *new_str = replace_space(str);
	printf("%s\n%s\n", str, new_str);
	return 0;
}