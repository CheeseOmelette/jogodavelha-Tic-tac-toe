#include <iostream>
#include <ctime>
#include <time.h>
#include <cstdlib>
#include <string.h>

void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces,char computer, int diffculty, int plays);
bool checkWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);
void help();



int main () {
	
	char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
	char player;
	char computer;
	bool running = true;
	char choice;
	bool choosen = true;
	int dfc = 1;
	int ply = 1;
	
	while(choosen) {
	std::cout << "Welcome to the Tic Tac Toe Game! Please select your shapes: " << '\n';
	std::cout << "Press X to play with the crosses." << '\n';
	std::cout << "Press O to play with the circles." << '\n';
	std::cin >> choice;
	std::cout << '\n' << "Choose the Difficulty: " << '\n';
	std::cout << "1. Random" << '\n' << "2. Active AI" << '\n' << "3. Smart AI (Not implemented yet)" << '\n';
	std::cin >> dfc;
	switch(choice) {
		case 'X': 
		player = 'X';
		computer = 'O';
		choosen = false;
		break;
		
		case 'x':
		player = 'X';
		computer = 'O';
		choosen = false;
		break;	
		
		case 'O':
		player = 'O';
		computer = 'X';
		choosen = false;
		break;
		
		case 'o':
		player = 'O';
		computer = 'X';
		choosen = false;
		break;
	};
};
	

	
	
	drawBoard(spaces); //Array on function decays into a pointer.

	while (running) {
		playerMove(spaces, player);
	
		
		if (checkWinner(spaces, player, computer)) {
			running = false;
			break;
			
		}
		else if (checkTie(spaces)) {
			running = false;
			break;
		 }
		computerMove(spaces, computer, dfc, ply);
		ply++;
		drawBoard(spaces);

		if (checkWinner(spaces, player, computer)) {
			running = false;
			break;
			
		}
		else if (checkTie(spaces)) {
			running = false;
			break;
		}

	}
	std::cout << "Thanks for playing! \n";
	
	return 0;
}

void drawBoard(char *spaces) {
	std::cout << '\n';
	std::cout << "     |     |     " << "              |   |  " << '\n';
	std::cout << "  " << spaces [0] << "  |  "<< spaces [1] << "  |  " << spaces [2] << "              1 | 2 | 3" << '\n';
    std::cout << "_____|_____|_____ " << "          ___|___|___" << '\n';
    std::cout << "     |     |     " << "              |   |  " << '\n';
	std::cout << "  " << spaces [3] << "  |  "<< spaces [4] << "  |  " << spaces [5] << "              4 | 5 | 6" << "   <Board Numbers>" << '\n';
    std::cout << "_____|_____|_____ " << "	    ___|___|___" << '\n';
    std::cout << "     |     |     " << "              |   |  " << '\n';
    std::cout << "  " << spaces [6] << "  |  "<< spaces [7] << "  |  " << spaces [8] << "              7 | 8 | 9" << '\n';    
	std::cout << "     |     |     " << "  	       |   |  " << '\n';				
	std::cout << '\n';



}

void playerMove(char *spaces, char player) {
	int number;
	do {
		std::cout << "Enter a spot to place a marker (1-9): ";
		std::cin >> number;
		number--;
		if (spaces[number] == ' ') {
			spaces[number] = player;
			break;
		}
	}while (!number > 0 || !number < 8);
}

void computerMove(char *spaces, char computer, int diffculty, int plays) {

	int number;
	int auxnumb;
	srand(time(0));
	
	
	if (diffculty == 2 && plays > 1 ) {
			while (true) {
			
			if (spaces[number + 1] == ' ') {
				spaces[number] = computer;
				std::cout << "The computer choose: " << number << '\n';
				break;
			} 
			else {
			
			
			if (spaces[number - 1] == ' ') {
				spaces[number] = computer;
				std::cout << "The computer choose: " << number << '\n';
				break;
			}
			else {
			
			number = rand() % 9;
			if (spaces[number] == ' ') {
			spaces[number] = computer;
			std::cout << "The computer choose: " << number << '\n';
			break;
		}
	}
}
}
		
		
	} else {
	
	
	while(true) {
		number = rand() % 9;
	 if (spaces[number] == ' ') {
			spaces[number] = computer;
			std::cout << "The computer choose: " << number << '\n';
			break;
		}
	}
	
  }
  
 

}
bool checkWinner(char *spaces, char player, char computer) {
	
	if ((spaces[0] != ' ') && (spaces[0] == spaces[1]) && (spaces[1] == spaces[2])) {
		spaces[0] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOOSE!\n";
	}
	
	else if ((spaces[3] != ' ') && (spaces[3] == spaces[4]) && (spaces[4] == spaces[5])) {
		spaces[3] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOOSE!\n";
	}
	
	else if ((spaces[6] != ' ') && (spaces[6] == spaces[7]) && (spaces[7] == spaces[8])) {
		spaces[6] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOOSE!\n";
	}
	
	else if ((spaces[0] != ' ') && (spaces[0] == spaces[3]) && (spaces[3] == spaces[6])) {
		spaces[0] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOOSE!\n";
	}
	
	else if ((spaces[1] != ' ') && (spaces[1] == spaces[4]) && (spaces[4] == spaces[7])) {
		spaces[1] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOOSE!\n";
	}
	
	else if ((spaces[2] != ' ') && (spaces[2] == spaces[5]) && (spaces[5] == spaces[8])) {
		spaces[2] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOOSE!\n";
	}
	
	else if ((spaces[0] != ' ') && (spaces[0] == spaces[4]) && (spaces[4] == spaces[8])) {
		spaces[0] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOOSE!\n";
	}
	
	else if ((spaces[2] != ' ') && (spaces[2] == spaces[4]) && (spaces[4] == spaces[6])) {
		spaces[2] == player ? std::cout << "YOU WIN!\n" : std::cout << "YOU LOOSE!\n";
	}
	
	 else {
	 	return false;
	 }
	return true;
}
bool checkTie(char *spaces) {
	
	for (int i = 0; i < 9; i++) {
		if(spaces[i] == ' ') {
			return false;
		}
	}
	std::cout << "IT'S A TIE! \n";
	return true;
	return 0;
}
void help() {
	std::cout << "\n";
	std::cout << "   |   |  " << '\n';
	std::cout << " 1 | 2 | 3" << '\n';
	std::cout << "___|___|___" << '\n';
	std::cout << "   |   |  " << '\n';
	std::cout << " 4 | 5 | 6" << '\n';
	std::cout << "___|___|___" << '\n';
	std::cout << "   |   |  " << '\n';
	std::cout << " 7 | 8 | 9" << '\n';
	std::cout << "   |   |  " << '\n';
	std::cout << "\n";


}
