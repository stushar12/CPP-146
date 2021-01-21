
#include <bits/stdc++.h>
using namespace std;

string smallestWindow (string str, string pat)
{
	int len1 = str.length();
	int len2 = pat.length();

	if (len1 < len2) 
	{
		return "-1";
	}

	int hash_pat[256] = { 0 };
	int hash_str[256] = { 0 };

	// Store occurrence ofs characters 
	// of pattern
	for (int i = 0; i < len2; i++)
		hash_pat[pat[i]]++;

	int start = 0, start_index = -1, min_len = INT_MAX;

	// Start traversing the string
	// Count of characters
	int count = 0; 
	for (int j = 0; j < len1; j++) 
	{
	
		// Count occurrence of characters 
		// of string
		hash_str[str[j]]++;

		// If string's char matches with 
		// pattern's char
		// then increment count
		if (hash_str[str[j]] <= hash_pat[str[j]])
			count++;

		// if all the characters are matched
		if (count == len2) 
		{
		
			// Try to minimize the window 
			while (hash_str[str[start]]> hash_pat[str[start]]|| hash_pat[str[start]] == 0) 
				{
				if (hash_str[str[start]]> hash_pat[str[start]])
					hash_str[str[start]]--;
				start++;
				}

			// update window size
			int end_index = j - start + 1;
			if (min_len > end_index) 
			{
				min_len = end_index;
				start_index = start;
			}
		}
	}

	// If no window found
	if (start_index == -1) 
	{
		return "-1";
	}

	return str.substr(start_index, min_len);
}

// Driver code
int main()
{
	string str = "this is a test string";
	string pat = "tist";

	cout << "Smallest window is : \n"
		<< smallestWindow(str, pat);
	return 0;
}
