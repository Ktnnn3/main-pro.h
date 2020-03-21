//Project Compro
#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
#include<vector>
#include<cctype>
#include<ctime>
#include<cstdlib>
#include<iomanip>
#include<Windows.h> //include for music
#include<mmsystem.h> //include for music

using namespace std;
int gameover=0;
int gamestart=0,howtoplay=0,leaderB=0;


struct Card{
	string type;
	string namecard;
	int score;
};

class unit{
		string name;
		string typeofp;
		vector<string> onhand;  //?????????????????????
		int money;		//?????????
		int score;		//??????????????????????????
		int betm;		//????????????????
		bool stand_on;		
	public:	
		void shop(); //goto shop
        void showStatus(); //????		
		bool betmoney(); //???????????? bet
		void Addmoney(); //?????????????????
		void removemoney();//??????????????
		bool checkgameover();
		void Hit(vector<Card> &);//??????????????????????????
		void newTurn();
		void create(string);//??? hero ???? bot
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

void Hit(vector<Card> &);

void newTurn();

void create(string);

bool scorecheck();  //??????????? 21 ????

int getscore(); //???score ?????? private

void gamelost();

void gamedraw();

void gamewin();

int main(){
	system("mode 45, 30"); //size of console app
	system("COLOR B0"); //color of font and console app
	cout << "              mmmm         mmmm            \n";
	cout << "             E    3mmmmmmmE    3           \n";
	cout << "              E               3            \n";
	cout << "              E   X       X   3            \n";
	cout << "              E       W       3            \n";
	cout << "        mmm   E               3   mmm      \n";
	cout << "       m   m  E               3  m   m     \n";
    cout<<"--------------------------------------------\n";
    cout<<setw(35)<<"I N F O M A T I O N S\n";
    cout<<"--------------------------------------------\n";
    cout<<"        Welcome to the 'Pirate's Sea'.\n        and you are one of pirates.\n";
    cout<<"        Because fighting on the sea \n";
    cout<<"         is the most important. \n";
    cout<<"          Hence you must protect\n";
    cout<<"          your ship from others. \n";
    cout<<"--------------------------------------------\n";
    cout<<setw(35)<<"W A R N I N G ! ! ! \n";
    cout<<"--------------------------------------------\n";
	cout<<"        Now doubt ship is coming.\n";
    cout<<"   Becareful and prepare for fighting \n";
	cout<<"--------------------------------------------\n";
	cout<<"           [+] You get 500 Baht \n";
	cout<<"--------------------------------------------\n";
	//PlaySound(TEXT("coin.wav"), NULL, SND_SYNC); //do not unlock if you not install
	
	int menu=0;	
	srand(time(0));
	while (menu==0){
		unit player,bot;
		char player_action = '\0',bot_action = '\0';
		int player_bit;
		player.create("Player");
		bot.create("bot");
		cout<<"Type [1] to start game"<<endl;
		cout<<"Type [2] how to play the game"<<endl;
		cout<<"Type [3] check leader board"<<endl;
		int input_menu;
		cin>>input_menu;
		checkgamemode(input_menu);
		

		while(gamestart==1){
			//PlaySound(TEXT("gameStart.wav"), NULL, SND_SYNC); //do not unlock if you not install
		
			vector<Card> cc;
			ifstream cards;
			cards.open("cards.txt");
			string ccard;
	
	
			while(getline(cards,ccard)){
				Card c;
				char desk[100];
				char name[100];
				sscanf(ccard.c_str(),"%[^;];%[^;];%d",desk,name,&c.score);
				c.type = desk;
				c.namecard = name;
				cc.push_back(c);
			}
			


			while(true){
				player.newTurn();
				while(player.betmoney());
				bot.newTurn();
				bot.Hit(cc);
				bot.Hit(cc);
				while(player.scorecheck() == true){
					cout << "[H] Hit [S] Stand [E] Exit";
					cout << "\nEnter your action: ";
					cin >> player_action;
					player_action = toupper(player_action); 
					if(player_action == 'E'){
						player.shop();
						//?????????
						//??story
					} 
					if(player_action == 'H') {
						//PlaySound(TEXT("hit.wav"), NULL, SND_SYNC); //do not unlock if you not install
                        player.Hit(cc);
                        player.showStatus();
                    }
					if(player_action == 'S'){
						//PlaySound(TEXT("save.wav"), NULL, SND_SYNC); //do not unlock if you not install
						player.stand();
						break;
					}



				}
				while(player.scorecheck() == false){
					player.removemoney();
					player.gamelost();
					break;
				}
				
				if(player.scorecheck() != false){
						while(player.stand() == true){ //??????????? bot ????? player ????? stand


							while(bot.scorecheck() == true){
						
								if(bot.getscore()<player.getscore()){
									bot.Hit(cc);
									cout << "Enter ";
                           		 	cin.get();
								}else if(bot.getscore()==player.getscore() && bot.getscore()==21){
									player.gamedraw();
									bot_action = 'E';
									break;
								}



							}
							while(bot.scorecheck()==false){
								player.Addmoney();
								player.gamewin();
								bot_action = 'E';
								break;
							}
							if(bot_action = 'E')break;

						}	


				}
				
				

				player.checkgameover();


				//??????? gameover ??????????????????????????? 0 ?????????????


				//??????????????

				






			}
		





			
			
			
			
			
			
		}
		while(howtoplay==1){
			cout<<"ihi";
			
			
			
			
		}
		
		while(leaderB==1){
		cout<<"iejiwofjp";	
			
			
			
		}
		
		
		
		
		
		
		
		
		
		
		
	}
	
	
	
	

}



bool unit::betmoney(){ //x cin from player
	cout << "Enter your bet: ";
	int player_bit;
	cin >> player_bit;
	if(player_bit>money){
		cout << "[!] Not enough money\n";
		return true;
	}
	else{
		betm = player_bit;
		return false;
	} 
	
}



void unit::Addmoney(){ //x from function bet.
	money += betm*2;
}




void unit::removemoney(){ //x from function bet.
	money -= betm;
}




bool unit::checkgameover (){
	if(money<=0) return gameover = true;
	else return gameover = false;
}




void checkgamemode(int x){
	if(x==1) gamestart=1;
	else if(x==2) howtoplay=1;
	else if(x==3) leaderB=1;
	
}




void unit::Hit(vector<Card> &a){
	int i = rand()%a.size();
	string x = a[i].type ;
	string y = a[i].namecard;
	int z = a[i].score;
	onhand.push_back(x+" "+y);
	a.erase(a.begin() + i);
	score += z;	
}


bool unit::stand(){
	stand_on = true;
	return true;
}

void unit::newTurn(){
	onhand.clear();
	score = 0;
	stand_on = false;
}





void unit::create(string t){
		if(t == "Player"){
			cout << "Please input your name: ";
			getline(cin,name);
			money = 500;
		}else if(t == "bot"){
			name = "more money\n";

		}
}

bool unit::scorecheck(){
	if(score > 21){
		return false;
	}else return true;
}


/////////////////////////////////////////////////

void unit::gamelost(){
    cout<<""<<name<<"'s money is: "<<money<<"\n";
	cout<<"*************************\n";
	cout<<"*                       *\n";
	cout<<"*        You lost       *\n";
	cout<<"*                       *\n";
	cout<<"*************************\n";

}

void unit::gamedraw(){
    cout<<""<<name<<"'s money is: "<<money;
	cout<<"\n*************************\n";
	cout<<"*                       *\n";
	cout<<"*         Draw          *\n";
	cout<<"*                       *\n";
	cout<<"*************************\n";

}

void unit::gamewin(){
    cout<<""<<name<<"'s money is: "<<money; 
	cout<<"\n*************************\n";
	cout<<"*                       *\n";
	cout<<"*        You win!       *\n";
	cout<<"*                       *\n";
	cout<<"*************************\n";

}

//////////////////////////////////////////////



int unit::getscore(){
	int scorenow ;
	scorenow = score;
	return scorenow;
}

void unit::showStatus(){

	cout<<"*************************\n";
    for(int i=0;i<onhand.size();i++)
	cout<<""<<name<<"'s card is: "<<onhand[i]<<"\n";
	cout<<""<<name<<"'s score is: "<<score<<"\n";
	cout<<"*************************\n";
}

void unit::shop(){
	int sel;
	int pricelist[11] = {100,80,50,200,500,150,300,550,5,99,1};
	
	cout<<"--------------------------------------------\n";
	cout<<"\t  P I R A T E ' S  S T O R E\n";
	cout<<"--------------------------------------------\n";
	cout<<"\t    Welcome to our shop!!!\n";
	cout<<"\twhich one do you want to buy?\n";
	cout<<"--------------------------------------------\n";
	cout<<"[1] GRAPPLING HOOK 100b\n";
	cout<<"[2] CUTLASS 80b\n";
	cout<<"[3] STINKPOT 50b\n";
	cout<<"[4] MUSKET 200b\n";
	cout<<"[5] CANNON 500b\n";
	cout<<"[6] BOARDING AXE 150b\n";
	cout<<"[7] BLUNDERBUS 300b\n";
	cout<<"[8] AK-47 550b\n";
	cout<<"[9] POCARI SWEAT 5b\n";
	cout<<"[10] HOOK 99b\n";
	cout<<"[11] VERY KAK ITEM 1b\n";
	cout<<"Select : ";
	cin>>sel;
	if(money<=0) {
		cout<<"[!] Not enough money";
	}
	switch(sel){
		case 1:
		money -= pricelist[0];
		cout<<"/////////////////////////////////////////////\n";
		cout<<"\t [+] You've got GRAPPLING HOOK\n";
		cout<<"\t    Your Balance : "<<money<<endl;
		cout<<"/////////////////////////////////////////////\n";
		break;
		case 2:
		money -= pricelist[1];
		cout<<"/////////////////////////////////////////////\n";
		cout<<"\t [+] You've got CUTLASS\n";
		cout<<"\t    Your Balance : "<<money<<endl;
		cout<<"/////////////////////////////////////////////\n";
		break;
		case 3:
		money -= pricelist[2];
		cout<<"/////////////////////////////////////////////\n";
		cout<<"\t [+] You've got STINKPOT\n";
		cout<<"\t    Your Balance : "<<money<<endl;
		cout<<"/////////////////////////////////////////////\n";
		break;
		case 4:
		money -= pricelist[3];
		cout<<"/////////////////////////////////////////////\n";
		cout<<"\t [+] You've got MUSKET\n";
		cout<<"\t    Your Balance : "<<money<<endl;
		cout<<"/////////////////////////////////////////////\n";
		break;
		case 5:
		money -= pricelist[4];
		cout<<"/////////////////////////////////////////////\n";
		cout<<"\t [+] You've got CANNON\n";
		cout<<"\t    Your Balance : "<<money<<endl;
		cout<<"/////////////////////////////////////////////\n";
		break;
		case 6:
		money -= pricelist[5];
		cout<<"/////////////////////////////////////////////\n";
		cout<<"\t [+] You've got BOARDING AXE\n";
		cout<<"\t    Your Balance : "<<money<<endl;
		cout<<"/////////////////////////////////////////////\n";
		break;
		case 7:
		money -= pricelist[6];
		cout<<"/////////////////////////////////////////////\n";
		cout<<"\t [+] You've got BLUNDERBUS\n";
		cout<<"\t    Your Balance : "<<money<<endl;
		cout<<"/////////////////////////////////////////////\n";
		break;
		case 8:
		money -= pricelist[7];
		cout<<"/////////////////////////////////////////////\n";
		cout<<"\t [+] You've got AK_47\n";
		cout<<"\t    Your Balance : "<<money<<endl;
		cout<<"/////////////////////////////////////////////\n";
		break;
		case 9:
		money -= pricelist[8];
		cout<<"/////////////////////////////////////////////\n";
		cout<<"\t [+] You've got POCARI SWEAT\n";
		cout<<"\t    Your Balance : "<<money<<endl;
		cout<<"/////////////////////////////////////////////\n";
		break;
		case 10:
		money -= pricelist[9];
		cout<<"/////////////////////////////////////////////\n";
		cout<<"\t [+] You've got HOOK\n";
		cout<<"\t    Your Balance : "<<money<<endl;
		cout<<"/////////////////////////////////////////////\n";
		break;
		case 11:
		money -= pricelist[10];
		cout<<"/////////////////////////////////////////////\n";
		cout<<"\t [+] You've got VERY KAK ITEM\n";
		cout<<"\t    Your Balance : "<<money<<endl;
		cout<<"/////////////////////////////////////////////\n";
		break;
	}

}
