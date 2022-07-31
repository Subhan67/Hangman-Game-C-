	#include<iostream>
	#include<time.h>
	#include<string>
	using namespace std;
	int main()
	{

		system("cls");
		const int turns = 6;
		int wrong_guesses;
		int len = 0, status, win = 0, lose = 0;
		char letter, guessed[30], choice;
		string word;
		string words[500] = { "bulb", "whatsapp", "school", "apple", "mango", "glass", "phone", "cup", "teacher", "laptop","groomed", "sugar", "vest","beg", "book", "foot", "nondescript", "ordinary", "quill", "committee", "abashed", "eggs", "woozy", "stroke", "hospitale", "spectacular", "subsequent", "battle", "strange", "degree", "drum", "poised", "part", "rush", "confess", "grape", "spark" };

	start:
		status = 0;
		wrong_guesses = 0;
		srand(time(NULL));
		int n = rand() % 35;
		word = words[n];
		len = word.length();
		for (int i = 0; i < len; i++)
		{
			guessed[i] = '-';
		}

		// welcome the user
		cout << "Ali Subhan & Hassan Arif \n\n\n\n" << endl;
		cout << "\n\nWelcome to hangman...Guess a words";
		cout << "\n\nEach letter is represented by a Dash.";
		cout << "\n\nYou have to type only one letter in one try";
		cout << "\n\nYou have " << turns << " tries to try and guess the word.";
		cout << "\n  \\+---------START----------+/";
		for (; word[len] != '\0'; len++);

		// Loop until the guesses are used up
		while (wrong_guesses < turns && status != 1)
		{

			char letter;
			int flag = 0;
			cout << "\n\n";
			for (int i = 0; i < len; i++)
			{
				cout << guessed[i];
			}

			cout << "\n\nGuess a letter: ";
			cin >> letter;
			system("cls");
			for (int i = 0; i < len; i++)
			{

				if (letter == word[i] && guessed[i] != letter)
				{
					guessed[i] = letter;
					flag = 1;
				}

			}
			if (flag == 0)
			{
				wrong_guesses++;
			}
			for (int i = 0; i < len; i++)
			{
				status = 1;
				if (guessed[i] == '-')
				{
					status = 0;
					break;
				}
			}
			// Tell user how many guesses has left.
			cout << "You have " << turns - wrong_guesses;
			cout << " guesses left." << endl;


		}
		if (status == 1)
		{
			cout << "you guessed the word correctly" << endl;
			win++;
			cout << "do you want to play again (press Y for yes and N for no): ";
			cin >> choice;
			if (choice == 'Y' || choice == 'y')
			{
				goto start;
			}
			else if (choice == 'N' || choice == 'n')
			{
				goto result;
			}

		}
		else if (wrong_guesses == turns)
		{
			lose++;
			cout << "\nSorry, you lose...you've been hanged." << endl;
			cout << "|========|" << endl;
			cout << "|    }  " << endl;
			cout << "|  ('_')" << endl;
			cout << "| //-|-//" << endl;
			cout << "|    |" << endl;
			cout << "|  // //" << endl;
			cout << "|_";
			cout << " YOU ARE DEAD" << "\n The word was : " <<word<< endl;
			//cout << "The word was : "<< word << endl;
		
			cout << "Do you want to play again (press Y for yes and N for no): ";
			cin >> choice;
			if (choice == 'Y' || choice == 'y')
			{
				goto start;
			}
			else if (choice == 'N' || choice == 'n')
			{
				goto result;
			}
		}
	result:
		cout << "Total words guessed correct: " << win << endl;
		cout << "Total words guessed wrong: " << lose << endl;
		cout << "\n\n\n\n THANKS FOR PLAYING HANGMAN " << endl;
		cout << "\n\n";
		return 0;
	}