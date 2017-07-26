#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{
	int score = 0;
	int x = 0;
	string guess;
	
	enum fields {word, hint ,fieldsNum};
	const int wordsNum = 5;
	string words[wordsNum][fieldsNum] =
	{
		{ "wall", "Do you feel you’re banging your head against something?" },
		{ "glasses", "These might help you see the answer." },
		{ "labored", "Going slowly, is it?" },
		{ "persistent", "Keep at it." },
		{ "jumble", "It’s what the game is all about." }
	};

	cout << "\t\t Welcome to Word Jumble!\n\n";
	cout << "Unscramble the letters to make a word. \n";
	cout << "Enter 'hint' for a hint . \n";
	cout << "Using hint will deduct points of your score" << endl;
	cout << "Enter 'quit' to quit the game. \n\n";

	do
	{
		srand(static_cast<unsigned int>(time(0)));
		int choice = rand() % wordsNum;
		string theWord = words[choice][word];
		string theHint = words[choice][hint];

		string jumble = theWord;		
		int length = jumble.size();
		for (int i = 0; i < length; i++)
		{
			int index1 = rand() % length;
			int index2 = rand() % length;
			
			char temp = jumble[index1];
			jumble[index1] = jumble[index2];
			jumble[index2] = temp;
		}


		cout << "The jumbled word : " << jumble << endl;
		cout << "Your guess is: ";
		cin >> guess;
		x = length;
		while (guess != theWord)
		{
			if (guess == "hint")
			{
				score -= (length / 2);
				cout << "Your hint is: " << theHint << endl;
				cout << "Your guess is: ";
				cin >> guess;
			}
			else if (guess == "quit")
			{
				break;
			}
			else
			{
				cout << "Wrong guess try again" << endl;
				cout << "Your guess is:";
				cin >> guess;				
			}	
		} 
		cout << "Your guess is right \n" << endl;
		score += length;
		
	} while (guess != "quit");
	score -= x;
	cout << "Your Score is: " << score << endl;
	cout << "Thanks for playing our game\n" << endl;
	return 0;
}
