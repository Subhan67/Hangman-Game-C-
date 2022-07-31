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
	string words[1000] = { "bulb", "whatsapp", "school", "apple", "mango", "glass", "phone", "cup", "teacher", "laptop" };
	//ifstream read;
	//read.open("file.txt");
	//read.getline(words, 1000, '#');

	//choose and copy a word from array of words randomly
	srand(time(NULL));
	int n = rand() % 10;
	word = words[n];

	// Initialize the secret word with the (-) character.
	string unknown(word.length(), '_ _');
	// welcome the user
	cout << "\n\nWelcome to hangman...Guess a words";
	cout << "\n\nEach letter is represented by a Dash.";
	cout << "\n\nYou have to type only one letter in one try";
	cout << "\n\nYou have " << turns << " tries to try and guess the word.";
	cout << "\n  \\+---------START----------+/";
	// Loop until the guesses are used up
	while (wrong_guesses < turns)
	{
		cout << "\n\n" << unknown;
		cout << "\n\nGuess a letter: ";
		cin >> letter;
		// Fill secret word with letter if the guess is correct,
		// otherwise increment the number of wrong guesses.
		if (letterFill(letter, word, unknown) == 0)
		{
			cout << endl << "Whoops! That letter isn't in there!" << endl;
			wrong_guesses++;
		}
		else
		{
			cout << endl << "You found a letter! Isn't that exciting!" << endl;
		}
		// Tell user how many guesses has left.
		cout << "You have " << turns - wrong_guesses;
		cout << " guesses left." << endl;
		// Check if user guessed the word.
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

/* Take a one character guess and the secret word, and fill in the
unfinished guessword. Returns number of characters matched.
Also, returns zero if the character is already guessed. */

int letterFill(char guess, string secretword, string &guessword)
{
	int i;
	int matches = 0;
	int len = secretword.length();
	for (i = 0; i< len; i++)
	{
		// Is the guess in the secret word?
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