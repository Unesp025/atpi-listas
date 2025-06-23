#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;
int main()
{
	char* ptr = (char*) malloc(3*sizeof(char));
	ptr[0] = 'a';
	ptr[1] = 'b';
	ptr[2] = 'c';

	for (int i = 0; i<3; i++)
		printf("%c", ptr[i]);

	char* word = "wolrd";
	for (int j = 0; j < 5; j++)
		printf("%c", word[j]);

	char** words = (char**)malloc(3*sizeof(char*));
	words[0] = "brunosilv";
	words[1] = "brocolliz";
	words[2] = "pineapple";
	for (int w = 0; w<3; w++)
	{
		for (int y = 0; y < 9; y++)
			printf("%c", words[w][y]);
		printf("\n");
	}

	char* palavras[2] = {"bruno", "mamae"};
	for (int p = 0; p < 2; p++)
		for (int l = 0; l<5; l++)
			printf("%c", palavras[p][l]);
	char* name = "bananazz";
	for (int i = 0; i<7; i++)
		printf("\n\n\n%c", name[i]);
/*
	string* palavras2 = (string)malloc(2* sizeof(string));
	for (int s = 0; s<2; s++)
	{
		palavras2[s] = "bruno";
		printf("\n%s\t", palavras2[s]);
	}
*/
	return(0);
}

