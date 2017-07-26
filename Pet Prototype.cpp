#include<iostream>

using namespace std;

class Critter
{
public:
	Critter(int, int);
	void Talk();
	void Eat(int);
	void Play(int);
	void GetData();

private:
	int m_Hunger;
	int m_Boredom;

	int GetMood() const;
	void PassTime(int);
};

Critter::Critter(int hunger = 0, int boredom = 0) :
	m_Hunger(hunger), m_Boredom(boredom)
{}

inline int Critter::GetMood()const
{
	return (m_Hunger + m_Boredom);
}

void Critter::PassTime(int time = 1)
{
	m_Hunger += time;
	m_Boredom += time;
}

void Critter::Talk()
{
	if (GetMood() > 15)
	{
		cout << "Critter is mad " << endl;
	}
	else if (GetMood() > 10)
	{
		cout << "Critter is frustrated" << endl;
	}
	else if (GetMood() > 5)
	{
		cout << "Critter is okay " << endl;
	}
	else
	{
		cout << "Critter is happy " << endl;
	}

	PassTime();
}

void Critter::Eat(int food = 4)
{
	cout << "Brruuup. " << endl;
	m_Hunger -= food;
	if (m_Hunger < 0)
	{
		m_Hunger = 0;
	}
	PassTime();
}

void Critter::Play(int fun = 4)
{
	cout << "Wheeeeeeeeeeeee " << endl;
	m_Boredom -= fun;
	if (m_Boredom < 0)
	{
		m_Boredom = 0;
	}
	PassTime();
}

void Critter::GetData()
{
	cout << "Hunger : " << m_Hunger << endl;
	cout << "Boredom : " << m_Boredom << endl;
}

int main()
{
	Critter c1(5, 5);
	c1.Talk();

	int choice;
	do
	{
		cout << "\nCritter Caretaker \n\n";
		cout << "0 - Quit\n";
		cout << "1 - Listen to your critter\n";
		cout << "2 - Feed your critter\n";
		cout << "3 - Play with Your Critter \n";
		cout << "4 - Get Critter Hunger/Boredom lvl\n\n";

		cout << "Enter your choice please :";
		cin >> choice;

		switch (choice)
		{
		case 0:
			cout << "Good-bye.\n";
			break;
		case 1:
			c1.Talk();
			break;
		case 2:
			c1.Eat();
			break;
		case 3:
			c1.Play();
			break;
		case 4:
			c1.GetData();
			break;

		default:
			cout << "\nSorry, but " << choice << " isn't a valid choice.\n";
		}
	} while (choice != 0);

	return 0;
}
