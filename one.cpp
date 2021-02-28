#include<bits/stdc++.h>
using namespace std;

string smallestWindow (string input, string pattern)
{
	int len1 = input.length();
	int len2 = pattern.length();

	if (len1 < len2) 
	{
		return "-1";
	}

	int hash_pattern[256] = { 0 };
	int hash_string[256] = { 0 };

	for (int i = 0; i < len2; i++)
		hash_pattern[pattern[i]]++;

	int i = 0, start = -1, min_len = INT_MAX;
	int count = 0; 
	
	for (int j = 0; j < len1; j++) 
	{
		hash_string[input[j]]++;
		if (hash_string[input[j]] <= hash_pattern[input[j]])
			count++;

		if (count == len2) 
		{
			while (hash_string[input[i]]> hash_pattern[input[i]]) 
				{
				if (hash_string[input[i]]> hash_pattern[input[i]])
					hash_string[input[i]]--;
				i++;
				}

			int end_index = j - i + 1;
			if (min_len > end_index) 
			{
				min_len = end_index;
				start = i;
			}
		}
	}

	// If no window found
	if (start == -1) 
	{
		return "-1";
	}

	return input.substr(start, min_len);
}

int main()
{
    string input,pattern;
    cin>>input>>pattern;

    cout<<smallestWindow(input,pattern);
}
