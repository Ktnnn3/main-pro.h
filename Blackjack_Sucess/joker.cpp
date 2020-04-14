//Project Compro
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <vector>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <Windows.h>  //include for music
#include <mmsystem.h> //include for music

using namespace std;
int gameover = 0;
int gamestart = 0, howtoplay = 0, leaderB = 0, order = 0, doyouwant = 1;
int input_menu = 0;
char player_start = '\0';
bool nameagain = true;

struct Card
{
    string type;
    string namecard;
    int score;
};

class unit
{
    string name;
    string typeofp;
    vector<string> item; //items in shop
    vector<string> onhand;
    int leader;
    int money;
    int score;
    int betm;
    bool stand_on;

public:
    void showitemsnleader(); //show rank after lost
    void shop();             //goto shop
    void showStatus();       //Show card on hand
    bool betmoney();
    void Addmoney();
    void removemoney();
    bool checkgameover();
    bool checkgamewin();
    void Hit(vector<Card> &);
    void newTurn();
    void create(string); //create 'hero' or 'bot'
    bool scorecheck();
    void gamelost();
    bool stand();
    int getscore();
    void gamedraw();
    void gamewin();
};

bool stand();

bool betmoney();

void Addmoney();

void removemoney();

bool checkgameover();

void checkgamemode(int);

bool checkgamewin();

void Hit(vector<Card> &);

void newTurn();

void create(string);

bool scorecheck();

int getscore();

void gamelost();

void gamedraw();

void gamewin();

void chooseaction();

void startgameinfomation();

void showgameover();

void howtoplayfunc();

void leaderfunc();

HWND hConsole;
int main()
{
    SetConsoleTitle("PIRATE'S SEA");
    Sleep(10); //Let the window to update the Title!
    hConsole = FindWindow(NULL, "PIRATE'S SEA");
    HMENU hMenu = GetSystemMenu((HWND)hConsole, FALSE);
    ::DeleteMenu(hMenu, 4, MF_BYPOSITION); // disable 'Maximize'
    system("mode 45, 30");                 //size of console app
    system("COLOR E0");                    //color of font and console app
    startgameinfomation();
    PlaySound(TEXT("coin.wav"), NULL, SND_SYNC); //do not unlock if you not install
    //PlaySound("pirate.wav", NULL, SND_FILENAME|SND_LOOP|SND_ASYNC); //background musics

    int menu = 0;
    srand(time(0));

    while (menu == 0)
    {
        unit player, bot;
        char player_action = '\0', bot_action = '\0';
        int player_bit;
        player.create("Player");
        bot.create("bot");
        cout << "\tType [1] to start game" << endl;
        cout << "\tType [2] how to play the game" << endl;
        cout << "\tType [3] check leader board" << endl;
        cout << "\tEnter your input : ";
        cin.clear();
        cin >> input_menu;
        while (input_menu != 1)
        {
            if (input_menu == 2 | input_menu == 3)
                break;
            else
            {
                cout << "\t[!] Error input plese try again\n";
                cin.clear();
                cin.ignore();
                cout << "\tEnter your input : ";
                cin >> input_menu;
            }
        }
        checkgamemode(input_menu);

        while (gamestart == 1)
        {
            PlaySound(TEXT("gameStart.wav"), NULL, SND_SYNC); //do not unlock if you not install

            vector<Card> cc;
            ifstream cards;
            cards.open("cards.txt");
            string ccard;

            while (getline(cards, ccard))
            {
                Card c;
                char desk[100];
                char name[100];
                sscanf(ccard.c_str(), "%[^;];%[^;];%d", desk, name, &c.score);
                c.type = desk;
                c.namecard = name;
                cc.push_back(c);
            }

            while (true)
            {
                player.newTurn();
                bot.newTurn();
                chooseaction();
                if (player_start == 'P')
                {
                    player_start = '\0';
                    while (player.betmoney())
                        ;
                    bot.Hit(cc);
                    bot.Hit(cc);
                    bot.showStatus();
                    while (player.scorecheck() == true)
                    {

                        cout << "\t [H] Hit [S] Stand";
                        cout << "\n \tEnter your action: ";
                        cin >> player_action;
                        player_action = toupper(player_action);
                        if (player_action == 'H')
                        {
                            PlaySound(TEXT("hit.wav"), NULL, SND_SYNC); //do not unlock if you not install
                            player.Hit(cc);
                            bot.showStatus();
                            player.showStatus();
                        }
                        if (player_action == 'S')
                        {
                            PlaySound(TEXT("save.wav"), NULL, SND_SYNC); //do not unlock if you not install
                            player.stand();
                            break;
                        }
                    }
                }
                else if (player_start == 'E')
                {
                    player_start = '\0';
                    player.shop();
                    continue;
                }

                while (player.scorecheck() == false)
                {
                    player.removemoney();
                    player.gamelost();
                    break;
                }

                if (player.scorecheck() != false)
                {
                    while (player.stand() == true)
                    {

                        while (bot.scorecheck() == true)
                        {

                            if (bot.getscore() < player.getscore())
                            {
                                cout << "\tEnemy Hit [Press Double Enter]";
                                cin.ignore();
                                cin.get();
                                cin.ignore();
                                bot.Hit(cc);
                                bot.showStatus();
                                player.showStatus();
                            }
                            else if (bot.getscore() == player.getscore() && bot.getscore() < 22)
                            {
                                cout << "\tEnemy Hit [Press Double Enter]";
                                cin.ignore();
                                cin.get();
                                cin.ignore();
                                bot.Hit(cc);
                                bot.showStatus();
                                player.showStatus();
                            }
                            else if (bot.getscore() == player.getscore() && bot.getscore() >= 21)
                            {
                                player.gamedraw();
                                bot_action = 'E';
                                break;
                            }
                            else if (bot.getscore() > player.getscore() && bot.getscore() < 22)
                            {
                                player.removemoney();
                                player.gamelost();
                                break;
                            }
                        }
                        while (bot.scorecheck() == false)
                        {
                            player.Addmoney();
                            player.gamewin();
                            bot_action = 'E';
                            break;
                        }
                        if (bot_action = 'E')
                            break;
                    }
                }

                player.checkgameover();
                if (player.checkgameover() == 1)
                {

                    cout << "--------------------------------------------\n";
                    cout << setw(35) << "! ! G A M E O V E R ! !\n";
                    cout << "--------------------------------------------";
                    player.showitemsnleader();
                    cout << "        Good bye the 'Pirate's Sea'.\n        and thank you to enjoy us.\n";
                    cout << "               See you soon......\n";
                    cout << "--------------------------------------------\n";
                    gamestart = 0;
                    break;
                }

                player.checkgamewin();
                if (player.checkgamewin() == true)
                {

                    cout << "--------------------------------------------\n";
                    cout << setw(35) << "! ! YOU ARE THE WINNER ! !\n";
                    cout << "--------------------------------------------";
                    player.showitemsnleader();
                    cout << "        Good bye the 'Pirate's Sea'.\n        and thank you to enjoy us.\n";
                    cout << "               See you soon......\n";
                    cout << "--------------------------------------------\n";
                    gamestart = 0;
                    break;
                }
            }
        }
        while (howtoplay == 1)
        {
            howtoplayfunc();
            gamestart = 0;
            break;
        }

        while (leaderB == 1)
        {
            leaderfunc();
            gamestart = 0;
            break;
        }
    }
}

bool unit::betmoney()
{ //x cin from player
    cout << "\tEnter your bet: ";
    int player_bit;
    cin >> player_bit;
    while (player_bit != 1)
    {
        if (player_bit > 0)
            break;
        else
        {
            cout << "\tError input plese try again\n";
            cin.clear();
            cin.ignore();
            cin >> player_bit;
        }
    }
    if (player_bit > money)
    {
        cout << "\t[!] Not enough money\n";
        return true;
    }
    else
    {
        betm = player_bit;
        return false;
    }
}

void unit::Addmoney()
{ //x from function bet.
    money += betm * 2;
}

void unit::removemoney()
{ //x from function bet.
    money -= betm;
}

bool unit::checkgameover()
{
    if (money <= 0)
        return true;
    else
        return false;
}

bool unit::checkgamewin()
{
    if (leader == 10730645)
        return true;
    else
        return false;
}

void checkgamemode(int x)
{
    if (x == 1)
        gamestart = 1;
    else if (x == 2)
        howtoplay = 1;
    else if (x == 3)
        leaderB = 1;
    input_menu = 0;
}

void unit::Hit(vector<Card> &a)
{
    int i = rand() % a.size();
    string x = a[i].type;
    string y = a[i].namecard;
    int z = a[i].score;
    onhand.push_back(x + " " + y);
    a.erase(a.begin() + i);
    score += z;
}

bool unit::stand()
{
    stand_on = true;
    return true;
}

void unit::newTurn()
{
    onhand.clear();
    score = 0;
    stand_on = false;
}

void unit::create(string t)
{

    if (t == "Player")
    {
        cin.clear();
        cin.ignore();
        cout << "\tPlease input your name: ";
        getline(cin, name);
        money = 500;
    }
    else if (t == "bot")
    {
        name = "Enemy";
    }
}

bool unit::scorecheck()
{
    if (score > 21)
    {
        return false;
    }
    else
        return true;
}

/////////////////////////////////////////////////

void unit::gamelost()
{
    cout << "\t" << name << "'s money is: " << money << "\n";
    cout << "\t*************************\n";
    cout << "\t*                       *\n";
    cout << "\t*        You lost       *\n";
    cout << "\t*                       *\n";
    cout << "\t*************************\n";
}

void unit::gamedraw()
{
    cout << "\t" << name << "'s money is: " << money;
    cout << "\n\t*************************\n";
    cout << "\t*                       *\n";
    cout << "\t*         Draw          *\n";
    cout << "\t*                       *\n";
    cout << "\t*************************\n";
}

void unit::gamewin()
{
    cout << "\t" << name << "'s money is: " << money;
    cout << "\n\t*************************\n";
    cout << "\t*                       *\n";
    cout << "\t*        You win!       *\n";
    cout << "\t*                       *\n";
    cout << "\t*************************\n";
}

//////////////////////////////////////////////

int unit::getscore()
{
    int scorenow;
    scorenow = score;
    return scorenow;
}

void unit::showStatus()
{

    cout << "\t -------------------------\n";
    for (int i = 0; i < onhand.size(); i++)
        cout << "\t" << name << "'s card is: " << onhand[i] << "\n";
    cout << "\t" << name << "'s score is: " << score << "\n";
    cout << "\t -------------------------\n";
}

void unit::shop()
{
    int sel, choose;
    int pricelist[11] = {10000, 800, 5000, 2000, 500, 150000, 300, 5500, 555555, 990, 10000000};
    string items[11] = {"GRAPPLING HOOK", "CUTLASS", "STINKPOT", "MUSKET", "CANNON",
                        "BOARDING AXE", "BLUNDERBUS", "AK-47", "POCARI SWEAT", "HOOK",
                        "VERY KAK ITEM"};

    cout << "--------------------------------------------\n";
    cout << "\t  P I R A T E ' S  S T O R E\n";
    cout << "--------------------------------------------\n";
    cout << "\t    Welcome to our shop!!!\n";
    cout << "\twhich one do you want to buy?\n";
    cout << "\t[Your money : " << money << "]\n";
    cout << "--------------------------------------------\n";
    do
    {
        cout << "\t[1] GRAPPLING HOOK 10,000b\n";
        cout << "\t[2] CUTLASS 800b\n";
        cout << "\t[3] STINKPOT 5,000b\n";
        cout << "\t[4] MUSKET 2,000b\n";
        cout << "\t[5] CANNON 500b\n";
        cout << "\t[6] BOARDING AXE 150,000b\n";
        cout << "\t[7] BLUNDERBUS 300b\n";
        cout << "\t[8] AK-47 5,500b\n";
        cout << "\t[9] POCARI SWEAT 555,555b\n";
        cout << "\t[10] HOOK 990b\n";
        cout << "\t[11] VERY KAK ITEM 10,000,000b\n";
        cout << "\t[0] EXIT\n";
        cout << "\tSelect : ";
        cin >> sel;
        if (money <= 0)
        {
            cout << "\t[!] Not enough money\n";
            break;
        }

        switch (sel)
        {
        case 1:
            if (money < 10001)
            {
                cout << "\t[!] Not enough money\n";
                cout << "/////////////////////////////////////////////\n";
                cout << "\t    Your Balance : " << money << endl;
                cout << "/////////////////////////////////////////////\n";
            }
            else
            {

                money -= pricelist[0];
                cout << "/////////////////////////////////////////////\n";
                cout << "\t [+] You've got GRAPPLING HOOK\n";
                cout << "\t    Your Balance : " << money << endl;
                cout << "/////////////////////////////////////////////\n";
                leader += pricelist[0];
                item.push_back(items[0]);
            }
            break;
        case 2:
            if (money < 801)
            {
                cout << "\t[!] Not enough money\n";
                cout << "/////////////////////////////////////////////\n";
                cout << "\t    Your Balance : " << money << endl;
                cout << "/////////////////////////////////////////////\n";
            }
            else
            {
                money -= pricelist[1];
                cout << "/////////////////////////////////////////////\n";
                cout << "\t [+] You've got CUTLASS\n";
                cout << "\t    Your Balance : " << money << endl;
                cout << "/////////////////////////////////////////////\n";
                leader += pricelist[1];
                item.push_back(items[1]);
            }
            break;
        case 3:
            if (money < 5001)
            {
                cout << "\t[!] Not enough money\n";
                cout << "/////////////////////////////////////////////\n";
                cout << "\t    Your Balance : " << money << endl;
                cout << "/////////////////////////////////////////////\n";
            }
            else
            {
                money -= pricelist[2];
                cout << "/////////////////////////////////////////////\n";
                cout << "\t [+] You've got STINKPOT\n";
                cout << "\t    Your Balance : " << money << endl;
                cout << "/////////////////////////////////////////////\n";
                leader += pricelist[2];
                item.push_back(items[2]);
            }
            break;
        case 4:
            if (money < 2001)
            {
                cout << "\t[!] Not enough money\n";
                cout << "/////////////////////////////////////////////\n";
                cout << "\t    Your Balance : " << money << endl;
                cout << "/////////////////////////////////////////////\n";
            }
            else
            {

                money -= pricelist[3];
                cout << "/////////////////////////////////////////////\n";
                cout << "\t [+] You've got MUSKET\n";
                cout << "\t    Your Balance : " << money << endl;
                cout << "/////////////////////////////////////////////\n";
                leader += pricelist[3];
                item.push_back(items[3]);
            }
            break;
        case 5:
            if (money < 501)
            {
                cout << "\t[!] Not enough money\n";
                cout << "/////////////////////////////////////////////\n";
                cout << "\t    Your Balance : " << money << endl;
                cout << "/////////////////////////////////////////////\n";
            }
            else
            {
                money -= pricelist[4];
                cout << "/////////////////////////////////////////////\n";
                cout << "\t [+] You've got CANNON\n";
                cout << "\t    Your Balance : " << money << endl;
                cout << "/////////////////////////////////////////////\n";
                leader += pricelist[4];
                item.push_back(items[4]);
            }
            break;
        case 6:
            if (money < 150001)
            {
                cout << "\t[!] Not enough money\n";
                cout << "/////////////////////////////////////////////\n";
                cout << "\t    Your Balance : " << money << endl;
                cout << "/////////////////////////////////////////////\n";
            }
            else
            {
                money -= pricelist[5];
                cout << "/////////////////////////////////////////////\n";
                cout << "\t [+] You've got BOARDING AXE\n";
                cout << "\t    Your Balance : " << money << endl;
                cout << "/////////////////////////////////////////////\n";
                leader += pricelist[5];
                item.push_back(items[5]);
            }
            break;
        case 7:
            if (money < 301)
            {
                cout << "\t[!] Not enough money\n";
                cout << "/////////////////////////////////////////////\n";
                cout << "\t    Your Balance : " << money << endl;
                cout << "/////////////////////////////////////////////\n";
            }
            else
            {
                money -= pricelist[6];
                cout << "/////////////////////////////////////////////\n";
                cout << "\t [+] You've got BLUNDERBUS\n";
                cout << "\t    Your Balance : " << money << endl;
                cout << "/////////////////////////////////////////////\n";
                leader += pricelist[6];
                item.push_back(items[6]);
            }
            break;
        case 8:
            if (money < 5501)
            {
                cout << "\t[!] Not enough money\n";
                cout << "/////////////////////////////////////////////\n";
                cout << "\t    Your Balance : " << money << endl;
                cout << "/////////////////////////////////////////////\n";
            }
            else
            {
                money -= pricelist[7];
                cout << "/////////////////////////////////////////////\n";
                cout << "\t [+] You've got AK_47\n";
                cout << "\t    Your Balance : " << money << endl;
                cout << "/////////////////////////////////////////////\n";
                leader += pricelist[7];
                item.push_back(items[7]);
            }
            break;
        case 9:
            if (money < 555556)
            {
                cout << "\t[!] Not enough money\n";
                cout << "/////////////////////////////////////////////\n";
                cout << "\t    Your Balance : " << money << endl;
                cout << "/////////////////////////////////////////////\n";
            }
            else
            {
                money -= pricelist[8];
                cout << "/////////////////////////////////////////////\n";
                cout << "\t [+] You've got POCARI SWEAT\n";
                cout << "\t    Your Balance : " << money << endl;
                cout << "/////////////////////////////////////////////\n";
                leader += pricelist[8];
                item.push_back(items[8]);
            }
            break;
        case 10:
            if (money < 991)
            {
                cout << "\t[!] Not enough money\n";
                cout << "/////////////////////////////////////////////\n";
                cout << "\t    Your Balance : " << money << endl;
                cout << "/////////////////////////////////////////////\n";
            }
            else
            {
                money -= pricelist[9];
                cout << "/////////////////////////////////////////////\n";
                cout << "\t [+] You've got HOOK\n";
                cout << "\t    Your Balance : " << money << endl;
                cout << "/////////////////////////////////////////////\n";
                leader += pricelist[9];
                item.push_back(items[9]);
            }
            break;
        case 11:
            if (money < 10000001)
            {
                cout << "\t[!] Not enough money\n";
                cout << "/////////////////////////////////////////////\n";
                cout << "\t    Your Balance : " << money << endl;
                cout << "/////////////////////////////////////////////\n";
            }
            else
            {
                money -= pricelist[10];
                cout << "/////////////////////////////////////////////\n";
                cout << "\t [+] You've got VERY KAK ITEM\n";
                cout << "\t    Your Balance : " << money << endl;
                cout << "/////////////////////////////////////////////\n";
                leader += pricelist[10];
                item.push_back(items[10]);
            }
            break;
        case 0:
            chooseaction();
            doyouwant = 0;
            break;
        }
        if (doyouwant == 1)
        {
            cout << "\tDo you want to buy another one?" << endl;
            cout << "\tYES press [1] or NO press [2] : ";
            cin >> choose;
        }

        if (choose != 1)
            chooseaction();
    } while (choose == 1);
}

void unit::showitemsnleader()
{
    for (int i = 0; i < item.size(); i++)
    {
        cout << "\t  You got items....\n";
        cout << "\t" << item[i] << endl;
    }

    cout << setw(25) << "           [Your rank is ";
    if (leader >= 501 && leader <= 10000)
        cout << "D]";
    else if (leader >= 10001 && leader <= 499999)
        cout << "C]";
    else if (leader >= 500000 && leader <= 999999)
        cout << "B]";
    else if (leader >= 1000000 && leader <= 9999999)
        cout << "A]";
    else if (leader >= 10000000)
        cout << "S]";
    else
        cout << "F]";
    cout << "\n";
}

void chooseaction()
{
    if (player_start != '\0')
        return;
    cout << "\t [P] Play [E] Exit";
    cout << "\n\tEnter your action: ";
    cin >> player_start;
    player_start = toupper(player_start);
    while (player_start != 'P')
    {
        if (player_start == 'E')
            break;
        else
        {
            player_start = '\0';
            cout << "\tError input plese try again\n";
            cout << "\t [P] Play [E] Exit\n";
            cin.clear();
            cin.ignore();
            cout << "\tEnter your input : ";
            cin >> player_start;
            player_start = toupper(player_start);
        }
    }
}

void startgameinfomation()
{
    cout << "              mmmm         mmmm            \n";
    cout << "             E    3mmmmmmmE    3           \n";
    cout << "              E               3            \n";
    cout << "              E   X       X   3            \n";
    cout << "              E       W       3            \n";
    cout << "        mmm   E               3   mmm      \n";
    cout << "       m   m  E               3  m   m     \n";
    cout << "--------------------------------------------\n";
    cout << setw(35) << "I N F O M A T I O N S\n";
    cout << "--------------------------------------------\n";
    cout << "        Welcome to the 'Pirate's Sea'.\n        and you are one of pirates.\n";
    cout << "        Because fighting on the sea \n";
    cout << "         is the most important. \n";
    cout << "          Hence you must protect\n";
    cout << "          your ship from others. \n";
    cout << "--------------------------------------------\n";
    cout << setw(35) << "W A R N I N G ! ! ! \n";
    cout << "--------------------------------------------\n";
    cout << "        Now doubt ship is coming.\n";
    cout << "   Becareful and prepare for fighting \n";
    cout << "--------------------------------------------\n";
    cout << "           [+] You get 500 Baht \n";
    cout << "--------------------------------------------\n";
    cout << "\tEnter to start the game!" << endl;
}

void howtoplayfunc()
{
    howtoplay = 0;
    if (order == 3)
    {
        order = 0;
        return;
    }
    cout << "    **************************************\n";
    cout << "    *                                    *\n";
    cout << "    *          Welcome to our game!      *\n";
    cout << "    *                                    *\n";
    cout << "    **************************************\n";
    cout << " I will tell how to play to you step by step." << endl;
    while (true)
    {
        if (order == 3)
        {
            order = 0;
            break;
        }
        cout << "\tpress[1] to show Rules of play\n\tpress[2] to Card point\n\tpress[3] to Exit\n ";
        cout << "\tEnter your input: ";
        cin >> order;
        if (order == 1)
        {
            int repeat;
            do
            {
                cout << "--------------------------------------------\n";
                cout << "     Firstly, your own money is 500 bahts.\n     you have to bet your own money\n to the game and there is no minimum betting \n   requirements\n";
                cout << "--------------------------------------------\n";
                cout << "\tpress enter to continue..." << endl;
                cin.ignore();
                cin.get();
                cout << "--------------------------------------------\n";
                cout << "  The principle is simple: after everyone \n has received all the cards in their hand\n Everyone can draw unlimited number of cards \n   Draw until your point is 21 or close  \n   to 21 or get a happy at the point\n";
                cout << "--------------------------------------------\n";
                cout << "\tpress enter to continue..." << endl;
                cin.get();
                cout << "--------------------------------------------\n";
                cout << " If your card point is higher than opponent, \n         And be less than 21 \n   you will be the winner of that game \n   and get double money of you bet\n";
                cout << "--------------------------------------------\n";
                cout << "\tpress enter to continue..." << endl;
                cin.get();
                cout << "--------------------------------------------\n";
                cout << "On the other hand,if your card point over 21, \n   you will lose in that game \n   and lose your money as well\n";
                cout << "--------------------------------------------\n";
                cout << "\tpress enter to continue..." << endl;
                cin.get();
                cout << "\tDo you want to repeat again? \n\tYes[1],No[0]: ";
                cin >> repeat;
            } while (repeat == 1);
        }
        else if (order == 2)
        {
            int repeat1;
            do
            {
                cout << "--------------------------------------------\n";
                cout << "  1.Cards from 2 - 10 have points according \n   to the face of the card.\n";
                cout << "--------------------------------------------\n";
                cout << "\tpress enter to continue..." << endl;
                cin.ignore();
                cin.get();
                cout << "--------------------------------------------\n";
                cout << "\t2.J is equal to 11\n\t  Q is equal to 12\n\t  K is equal to 13\n";
                cout << "--------------------------------------------\n";
                cout << "\tpress enter to continue..." << endl;
                cin.get();
                cout << "--------------------------------------------\n";
                cout << "\t3.card A has a score of 1.\n";
                cout << "--------------------------------------------\n";
                cout << "\tpress enter to continue..." << endl;
                cin.get();
                cout << "--------------------------------------------\n";
                cout << "   4.The total value of the cards \n   equals 21 is blackjack.\n";
                cout << "--------------------------------------------\n";
                cout << "\tpress enter to continue..." << endl;
                cin.get();
                cout << "\tDo you want to repeat again? \n\tYes[1],No[0]: ";
                cin >> repeat1;
            } while (repeat1 == 1);
        }
        else if (order == 3)
        {
            startgameinfomation();
            gamestart = 0;
            order = 0;
            break;
        }
        else
        {
            cout << "\tYour input is not correct.";
        }
    }
}

void leaderfunc()
{
    cout << "--------------------------------------------\n";
    cout << setw(30) << "G A M E R A N K \n";
    cout << "      calculateed from your items.\n";
    cout << "--------------------------------------------\n";
    cout << setw(10) << "Rank" << setw(30) << "Payment\n";
    cout << "--------------------------------------------\n";
    cout << " [S] Pirate king" << setw(28) << "10,000,000+\n";
    cout << " [A] First mate" << setw(29) << "1,000,000-9,999,999\n";
    cout << " [B] Advisor" << setw(32) << "500,000-999,999\n";
    cout << " [C] Assassin" << setw(31) << "10,001-499,999\n";
    cout << " [D] Servant" << setw(32) << "501-10,000\n";
    cout << " [F] Cabin Boy" << setw(30) << "0-500\n";
    cout << "--------------------------------------------\n";
    leaderB = 0;
}

void showgameover()
{
    cout << "*******************************************************\n";
    cout << "*                                                     *\n";
    cout << "*                      GAME OVER!!!                   *\n";
    cout << "*                                                     *\n";
    cout << "*******************************************************\n";
}

