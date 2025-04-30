#include <iostream>
#include<cstdlib>

enum choice { rock = 1, paper = 2, scissor = 3 };
enum winner { player = 1, computer = 2, draw = 3 };

struct RoundInfo
{
    int roundNumber = 0;
    choice playerChoice;
    choice computerChoice;
    winner roundWinner;
    std::string roundWinnerName = "";
};

struct GameInfo
{
    int gameRounds = 0;
    int playerWinTimes = 0;
    int computerWinTimes = 0;
    int drawTimes = 0;
    winner gameWinner;
    std::string gameWinnerName = "";
};

int randomNumber(int from, int to)
{
    int randNum = rand() % (to - from + 1) + from;

    return randNum;
}

int chooseNumberOfRounds()
{
    int num = 0;

    do
    {
        std::cout << "How many Rounds 1 to 10:" << std::endl;
        std::cin >> num;
    } while (num < 1 || num >10);

    return num;
}

choice readPlayerChoice()
{
    int playerChoice = 0;
    do
    {
        std::cout << "Your Choice: [1]:Rock, [2]:paper, [3]:Scissors: ";
        std::cin >> playerChoice;
    } while (playerChoice < 1 or playerChoice > 3);

    return choice(playerChoice);
}

choice getComputerChoice()
{
    return (choice)randomNumber(1, 3);
}

std::string choiceName(choice playerComputerChoice)
{
    std::string arrGameChoices[3] = { "Rock","Paper","Sicssor" };

    return arrGameChoices[playerComputerChoice - 1];
}

std::string winnerName(winner playerComputerWinner)
{
    std::string arrWinnerName[3] = { "Player","Computer","Draw" };

    return arrWinnerName[playerComputerWinner - 1];
}

winner decideRoundWinner(RoundInfo round)
{
    if (round.playerChoice == round.computerChoice)
        return winner::draw;

    else if (round.playerChoice == choice::rock && round.computerChoice == choice::scissor)
        return winner::player;

    else if (round.playerChoice == choice::paper && round.computerChoice == choice::rock)
        return winner::player;

    else if (round.playerChoice == choice::scissor && round.computerChoice == choice::paper)
        return winner::player;

    else
        return  winner::computer;
}

winner decideGameWinner(GameInfo& game)
{
    if (game.playerWinTimes == game.computerWinTimes)
        return winner::draw;
    else if (game.playerWinTimes > game.computerWinTimes)
        return winner::player;
    else
        return winner::computer;
}

GameInfo fillGameResults(int gameRounds, int playerWinTimes, int computerWinTimes, int drawTimes)
{
    GameInfo game;

    game.gameRounds = gameRounds;
    game.playerWinTimes = playerWinTimes;
    game.computerWinTimes = computerWinTimes;
    game.drawTimes = drawTimes;
    game.gameWinner = decideGameWinner(game);
    game.gameWinnerName = winnerName(game.gameWinner);

    return game;
}

void consolTheme(winner theWinner)
{
    switch (theWinner)
    {
    case winner::player:
        system("color 2f");
        break;
    case winner::computer:
        system("color 4f");
        std::cout << '\a';
        break;
    case winner::draw:
        system("color 6f");
        break;
    default:
        break;
    }

    return;
}

std::string tabs(int numOfTabs)
{
    std::string tab = "";

    for (int i = 0; i < numOfTabs; i++)
    {
        tab += "\t";
    }

    return tab;
}

void displayHeader()
{
    std::cout << tabs(3) << "________________________________________________________\n" << std::endl;
    std::cout << tabs(5) << "+++ G a m e  O v e r +++" << std::endl;
    std::cout << tabs(3) << "________________________________________________________\n" << std::endl;

    return;
}

void displayRoundResults(RoundInfo roundInfo)
{
    consolTheme(roundInfo.roundWinner);

    std::cout << "\n________________Round[" << roundInfo.roundNumber << "]________________\n" << std::endl;
    std::cout << "Player Choice  : " << choiceName(roundInfo.playerChoice) << std::endl;
    std::cout << "Computer Choice: " << choiceName(roundInfo.computerChoice) << std::endl;
    std::cout << "Round Winner Name   : " << roundInfo.roundWinnerName << std::endl;
    std::cout << "________________________________________\n" << std::endl;

    return;
}

void displayGameResults(GameInfo gameInfo)
{
    std::cout <<tabs(3) << "_____________________[Game Results]_____________________\n" << std::endl;
    std::cout << tabs(3) << "Game Rounds       : " << gameInfo.gameRounds << std::endl;
    std::cout << tabs(3) << "Player win times  : " << gameInfo.playerWinTimes << std::endl;
    std::cout << tabs(3) << "Computer win times: " << gameInfo.computerWinTimes << std::endl;
    std::cout << tabs(3) << "Draw times        : " << gameInfo.drawTimes << std::endl;
    std::cout << tabs(3) << "Final winner      : " << gameInfo.gameWinnerName << std::endl;
    std::cout << tabs(3) << "________________________________________________________" << std::endl;

    consolTheme(gameInfo.gameWinner);

    return;
}

void resetScreen() 
{
    system("cls");
    system("color 0f");
}

GameInfo playGame(int numberOfRounds)
{
    RoundInfo round;
    int playerWinTimes = 0, computerWinTimes = 0, drawTimes = 0;

    for (int gameRound = 1; gameRound <= numberOfRounds; gameRound++)
    {
        std::cout << "\nRound[" << gameRound << "] begins:\n " << std::endl;

        round.roundNumber = gameRound;
        round.playerChoice = readPlayerChoice();
        round.computerChoice = getComputerChoice();
        round.roundWinner = decideRoundWinner(round);
        round.roundWinnerName = winnerName(round.roundWinner);

        if (round.roundWinner == winner::player)
            playerWinTimes++;
        else if (round.roundWinner == winner::computer)
            computerWinTimes++;
        else
            drawTimes++;

        displayRoundResults(round);
    }

    return fillGameResults(numberOfRounds, playerWinTimes, computerWinTimes, drawTimes);
}

void startGame()
{
    char playAgain = 'Y';
    
    do
    {
        resetScreen();

        GameInfo game = playGame(chooseNumberOfRounds());
        displayHeader();
        displayGameResults(game);

        std::cout << "\nDo you wnat to play again? (Y/N): ";
        std::cin >> playAgain;
    } while (playAgain == 'Y' || playAgain == 'y');

    return;
}

int main()
{
    srand((unsigned)time(NULL));

    startGame();

    return 0;
}
