#include<iostream>

char user_choice() {
	char choice;
	std::cout << "Welcome to the game\n\n" << "Choose one of the suggested options ";
	std::cout << std::endl;
	std::cout << "For rock enter 'r'\t\t" << "For Paper enter 'p'\t\n\n" << "For scissors enter 's'\t       "
		<< "For lizard enter 'l'\n\n\t        " << "For spock enter 'k'\n";
	std::cin >> choice;
	std::cout << std::endl;
	while (choice != 'r' && choice != 'p' && choice != 's' && choice != 'l' && choice != 'k') {
		std::cout << "You must choose one of the suggested options\n";
		std::cin >> choice;
		std::cout << std::endl;
	}
	return choice;
}

char computer_choice() {
	srand(time(0));
	int val = rand() % 5 + 1;
	if (val == 1) { return 'r'; }
	if (val == 2) { return 'p'; }
	if (val == 3) { return 's'; }
	if (val == 4) { return 'l'; }
	if (val == 5) { return 'k'; }
}

void chooseWinner(char Player, char Computer) {
	if ((Player == 'r' && Computer == 's')
		|| (Player == 'r' && Computer == 'l')
		|| (Player == 'p' && Computer == 'r')
		|| (Player == 'p' && Computer == 'k')
		|| (Player == 's' && Computer == 'p')
		|| (Player == 's' && Computer == 'l')
		|| (Player == 'l' && Computer == 'p')
		|| (Player == 'l' && Computer == 'k')
		|| (Player == 'k' && Computer == 'r')
		|| (Player == 'k' && Computer == 's'))

	{
		std::cout << " Congratulations, You have WON! " << std::endl;

	}
	else if ((Player == 's' && Computer == 'r')
		|| (Player == 'l' && Computer == 'r')
		|| (Player == 'r' && Computer == 'p')
		|| (Player == 'k' && Computer == 'p')
		|| (Player == 'p' && Computer == 's')
		|| (Player == 'l' && Computer == 's')
		|| (Player == 'p' && Computer == 'l')
		|| (Player == 'k' && Computer == 'l')
		|| (Player == 'r' && Computer == 'k')
		|| (Player == 's' && Computer == 'k'))
	{
		std::cout << " oh, You have lost! " << std::endl;
	}
	else if ((Player == 'r' && Computer == 'r')
		|| (Player == 'p' && Computer == 'p')
		|| (Player == 's' && Computer == 's')
		|| (Player == 'k' && Computer == 'k')
		|| (Player == 'l' && Computer == 'l')
		)
	{
		std::cout << "try again";
	}
}

void show_choice(char choice) {
	if (choice == 'r') std::cout << "Rock" << std::endl;
	if (choice == 'p') std::cout << "Paper" << std::endl;
	if (choice == 's') std::cout << "Scissors" << std::endl;
	if (choice == 'l')std::cout << "Lizard" << std::endl;
	if (choice == 'k') std::cout << "Spock" << std::endl;

}

int main() {
	char user = user_choice();
	std::cout << "your choice is  ";
	show_choice(user);
	std::cout << std::endl;
	char comp = computer_choice();
	std::cout << "computer choice is  ";
	show_choice(comp);
	std::cout << std::endl;
	chooseWinner(user, comp);
}
