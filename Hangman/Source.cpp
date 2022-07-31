#include <iostream>
#include<ctime>
#include <string>
#include<fstream>
using namespace std;
const int turns = 6;
int letterFill(char, string, string&);
int main()
{
	string name;
	char letter;
	int wrong_guesses = 0;
	string word;
	string words[1000];
	ifstream read;
	read.open("file.txt");
	read.getline(words, 1000, '#');
	srand(time(NULL));
	int n = rand() % 10;
	word = words[n];
	string unknown(word.length(), '_ _');
	cout << "\n\nWelcome to hangman...Guess a words";
	cout << "\n\nEach letter is represented by a Dash.";
	cout << "\n\nYou have to type only one letter in one try";
	cout << "\n\nYou have " << turns << " tries to try and guess the word.";
	cout << "\n  \\+---------START----------+/";
	while (wrong_guesses < turns)
	{
		cout << "\n\n" << unknown;
		cout << "\n\nGuess a letter: ";
		cin >> letter;
		if (letterFill(letter, word, unknown) == 0)
		{
			cout << endl << "Whoops! That letter isn't in there!" << endl;
			wrong_guesses++;
		}
		else
		{
			cout << endl << "You found a letter! Isn't that exciting!" << endl;
		}
		cout << "You have " << turns - wrong_guesses;
		cout << " guesses left." << endl;
		if (word == unknown)
		{
			cout << word << endl;
			cout << "Yeah! You got it!";
			break;
		}
	}
	if (wrong_guesses == turns)
	{
		cout << "\nSorry, you lose...you've been hanged." << endl;
		cout << "|========|" << endl;
		cout << "|    }  " << endl;
		cout << "|  ('_')" << endl;
		cout << "| //-|-//" << endl;
		cout << "|    |" << endl;
		cout << "|  // //" << endl;
		cout << "|_____";
		cout << " YOU ARE DEAD" << endl;
		cout << "The word was : " << word << endl;
	}
	cin.ignore();
	cin.get();
	return 0;
}


int letterFill(char guess, string secretword, string &guessword)
{
	int i;
	int matches = 0;
	int len = secretword.length();
	for (i = 0; i< len; i++)
	{
		if (guess == guessword[i])
			return 0;
		if (guess == secretword[i])
		{
			guessword[i] = guess;
			matches++;
		}
	}
	return matches;
}