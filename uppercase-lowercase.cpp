#include <iostream>
#include <string>
using namespace std;

string text = "Benim adim ONur YukSel";
char returnText[] = {};

void lowerCase(string procText)
{
	
	
	for (int i = 0; i < text.size(); i++)
	{
		int caseHolder = procText[i];
		if (caseHolder >= 65 && caseHolder <= 90)
		{
			returnText[i] = caseHolder + 32;
		}
		else {
			returnText[i] = caseHolder;
		}
	}
}

void upperCase(string procText)
{	
	for (int i = 0; i < text.size(); i++)
	{
		int caseHolder = procText[i];
		if (caseHolder >= 97 && caseHolder <= 122)
		{
			returnText[i] = caseHolder - 32;
		 }
		 	else {
			returnText[i] = procText[i];
		}
	}
}

void onlyFirstCharUpper(string procText)
{
	int i = 1;
				if (procText[0] >= 97 && procText[0] <= 122 )
				{
				
	returnText[0] = procText[0] - 32;
}

else 
		{
			returnText[0] = procText[0];
		}
	while (i < text.size())
	{
		int caseHolder = procText[i];
		if (procText[i] == 32)
		{
			if (procText[i+1] >= 97 && procText[i+1] <= 122 )
			{
			
			returnText[i+1] = procText[i+1] - 32;
		
	}
	
		
		else {
			returnText[i+1] = procText[i+1];
		}
		i++;
		}
		else if (procText[i] >= 65 && procText[i] <= 90)
		{
			returnText[i] = procText[i] + 32;
		}
		i++;
		}
}

void writeText(string procText)
{
	int i = 0;
	while (procText[i] != NULL)
	{
		cout << procText[i];
		i++;
	}
	cout << endl;
}


int main()
{
	upperCase(text);
	writeText(returnText);
	lowerCase(text);
	writeText(returnText);
	onlyFirstCharUpper(text);
			writeText(returnText);


}
