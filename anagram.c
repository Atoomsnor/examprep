#include <stdio.h>
#include <string.h>

int anagram(char *s1, char *s2)
{
	int c1[256] = {0};
	int c2[256] = {0};

	int i = 0;
	while (s1[i])
	{
		c1[s1[i]]++;
		i++;
	}
	i = 0;
	while (s2[i])
	{
		c2[s2[i]]++;
		i++;
	}
	i = 0;
	while (i < 256)
	{
		if (c1[i] != c2[i])
			return 0;
		i++;
	}
	return 1;
}

int main()
{
	char s1[] = "listeen";
	char s2[] = "silent";

	// Checking if s1 and s2 are anagram
	if (anagram(s1, s2))
		printf("Anagrams");
	else
		printf("Not Anagrams");

	return 0;
}
