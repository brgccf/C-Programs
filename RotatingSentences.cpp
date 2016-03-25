#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>

using namespace std;

string lines[100];

int read_data()
{
	string read;
	int i = 0;
	
	while(getline(cin, read))
	{
		lines[i].append(read);
		i++;
	}
	
	int total_of_lines = i;
	
	int biggest, actual, big_text;
	biggest = lines[0].size();
	big_text = 0;
	for(i = 1; i < 100; i++)
	{
		actual = lines[i].size();
	    if(actual > biggest)
		{
			biggest = lines[i].size();
			big_text = i;
		}
	}
	
	int j, k, print_position;
	for(j = biggest-1; j >= 0; j--)
	{	
		for(k = total_of_lines - 1; k >= 0; k--)
		{
			print_position = biggest -1 - j;
			actual = lines[k].size();
			if(print_position >= actual) printf(" ");
			else cout << lines[k].at(print_position);
			
		}
		
		printf("\n");
	}
}

int main()
{

	read_data();
	
	return 0;	
}
