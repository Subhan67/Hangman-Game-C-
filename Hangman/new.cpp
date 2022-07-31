	#include<iostream>
	#include<fstream>
	#include<ctime>
#include<string>
	using namespace std;
	int main()
	{
		const int turns = 6;
		int wrong_guesses = 0;
		int len = 0;
		char letter;
		string word;
		string words[100] = { "bulb", "whatsapp", "school", "apple", "mango", "glass", "phone", "cup", "teacher", "laptop" };
		//ifstream read;
		//read.open("file.txt");
		//read.getline(words, 1000, '#');
		//choose and copy a word from array of words randomly
		srand(time(NULL));
		int n = rand() % 10;
		word = words[n];
		
		// welcome the user
		cout << "\n\nWelcome to hangman...Guess a words";
		cout << "\n\nEach letter is represented by a Dash.";
		cout << "\n\nYou have to type only one letter in one try";
		cout << "\n\nYou have " << turns << " tries to try and guess the word.";
		cout << "\n  \\+---------START----------+/";
		for (; word[len] != '\0'; len++);

		// Loop until the guesses are used up
		while (wrong_guesses < turns)
		{
			cout << "\n\n";
			for (int i = 0; i < len; i++)
			{
				cout << "_";
			}
			cout << "\n\nGuess a letter: ";
			cin >> letter;
			for (int i = 0; i < len; i++)
			{

				if (letter != word[i])
				{
					cout << endl << "Whoops! That letter isn't in there!" << endl;
					wrong_guesses++;
					break;
				}
				else if (letter == word[i])
				{
					cout << word;
				}
			}
			// Tell user how many guesses has left.
			cout << "You have " << turns - wrong_guesses;
			cout << " guesses left." << endl;
			

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

	return 0;
}