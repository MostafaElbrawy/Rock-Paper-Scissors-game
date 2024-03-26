#include <iostream>
#include <cstdlib>
#include <ctime>
#include<limits>
#include <string>
using namespace std;

enum enChoice{ Rock=1, Paper=2, Scissors=3 };


enChoice ReadUserChoice() {
    
    int choice;
    cout << "(1) Rock\n";
    cout << "(2) Paper\n";
    cout << "(3) Scissors\n";
    cout << "Try to beat me: ";
    cin >> choice;
    return enChoice (choice);


}


string ReadComputerChoice() {

    srand(time(0));

    string choices[] = { "Rock", "Paper", "Scissors" };
    string ComputerChoice = choices[rand() % 3];

    return ComputerChoice;

}


bool AnotherRound() {


    char again;

    cout << "\nDo you want to play again? (Y/N) : ";
    cin >> again;

    do {


        if (again == 'y' || again == 'Y')
        {
            system("cls");
            return true;
        }

        else if (again == 'n' || again == 'N')
        {
            cout << "\nSee you in the next game :) " << endl;
            exit(0);
        }

        else
        {
            do {
                cout << "\nWrong choice, please choose (Y/N) : ";
                cin >> again;

            } while (again != 'y' && again != 'Y' && again != 'n' && again != 'N');

        }

    } while (true);


}


void PrintChoices(string UserChoice, string ComputerChoice) {

    cout << "You choosed: " << UserChoice<<'\n';
    cout << "I choosed: " << ComputerChoice<<'\n';


}


void PrintRoundWinner(string UserChoice, string ComputerChoice, int& UserWon, int& ComputerWon, int& NoWinner){

    if(UserChoice == ComputerChoice)
    {
        cout << "\nNO winner !\n";
        PrintChoices(UserChoice, ComputerChoice);

        NoWinner++;
        system("color 6F");
    
    }

    else if (UserChoice == "Rock" && ComputerChoice == "Paper")
    {
        cout << "\nI beat you !\n";
        PrintChoices(UserChoice, ComputerChoice);

        ComputerWon++;
        system("color 4F");
    }

    else if (UserChoice == "Rock" && ComputerChoice == "Scissors")
    {
        cout << "\nGreat! you beat me\n";
        PrintChoices(UserChoice, ComputerChoice);

        UserWon++;
        system("color 2F");
    }

    else if (UserChoice == "Paper" && ComputerChoice == "Rock")
    {
        cout << "\nGreat! you beat me\n";
        PrintChoices(UserChoice, ComputerChoice);

        UserWon++;
        system("color 2F");
    }

    else if(UserChoice== "Paper" && ComputerChoice=="Scissors")
    {
        cout << "\nI beat you !\n";
        PrintChoices(UserChoice, ComputerChoice);

        ComputerWon++;
        system("color 4F");
    }

    else if (UserChoice == "Scissors" && ComputerChoice == "Paper")
    {
        cout << "\nGreat! you beat me\n";
        PrintChoices(UserChoice, ComputerChoice);

        UserWon++;
        system("color 2F");
    }

    else if (UserChoice == "Scissors" && ComputerChoice == "Rock")
    {
        cout << "\nI beat you !\n";
        PrintChoices(UserChoice, ComputerChoice);

        ComputerWon++;
        system("color 4F");
    }

}


void PrintResults(int UserWon, int ComputerWon,int NoWinner) {

    cout << "GAME RESULTS: \n";
    cout << "************************************************\n";
    cout << "User won: "<< UserWon <<"\n";
    cout << "Computer won: "<< ComputerWon <<"\n";
    cout << "No winner: " << NoWinner << "\n";
    cout << "************************************************\n";

}


void Game(int rounds, int &UserWon, int &ComputerWon, int &NoWinner){

    cout << "Round " << rounds << ".....Go! \n";
    cout << "************************************************\n";
    

    switch (ReadUserChoice()) {

    case Rock:

        PrintRoundWinner("Rock", ReadComputerChoice(), UserWon, ComputerWon,  NoWinner);

        break;

    case Paper:

        PrintRoundWinner("Paper", ReadComputerChoice(), UserWon, ComputerWon, NoWinner);

        break;

    case Scissors:

        PrintRoundWinner("Scissors", ReadComputerChoice(), UserWon, ComputerWon, NoWinner);

        break;

    default:
        
        cout << "\nWrong choice, Please Choose(Paper or Rock or Scissors)\n\n";
        Game(rounds, UserWon, ComputerWon, NoWinner);
    }

    cout << "************************************************\n\n";


}


void PlayRounds(int &UserWon,int &ComputerWon,int &NoWinner) {

    int rounds;

    cout << "How many rounds do you want to play? \n";
    cin >> rounds;

    for (int round = 1; round <= rounds; round++)
    {
    
     Game(round, UserWon, ComputerWon, NoWinner);
    
    }

  
}


void StartGame() {

    int UserWon, ComputerWon, NoWinner;

    cout << "WELCOME TO ROCK, PAPER, SCISSORS GAME\n";
    cout << "************************************************\n";

    do {

        UserWon = 0, ComputerWon = 0, NoWinner = 0;

        system("color 07");

        PlayRounds(UserWon, ComputerWon, NoWinner);
        PrintResults(UserWon, ComputerWon, NoWinner);

    } while (AnotherRound());

  
}


int main()
{
   
    StartGame();
    return 0;

}

