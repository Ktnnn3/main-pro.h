void unit::shop(){
	int sel,choose;
	int pricelist[11] = {100,80,50,200,500,150,300,550,5,99,1};
	string items[11] = {"GRAPPLING HOOK","CUTLASS","STINKPOT","MUSKET","CANNON",
						"BOARDING AXE","BLUNDERBUS","AK-47","POCARI SWEAT","HOOK",
						"VERY KAK ITEM"};


	cout<<"--------------------------------------------\n";
	cout<<"\t  P I R A T E ' S  S T O R E\n";
	cout<<"--------------------------------------------\n";
	cout<<"\t    Welcome to our shop!!!\n";
	cout<<"\twhich one do you want to buy?\n";
	cout<<"\t[Your money : "<<money<<"]";
	cout<<"--------------------------------------------\n";
do{
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
	item.push_back(items[sel]);
	switch(sel){
		case 1:
			if(money<100){
				cout<<"[!] Not enough money";
				cout<<"/////////////////////////////////////////////\n";
				cout<<"\t    Your Balance : "<<money<<endl;
				cout<<"/////////////////////////////////////////////\n";
			}else{
			
		money -= pricelist[0];
		cout<<"/////////////////////////////////////////////\n";
		cout<<"\t [+] You've got GRAPPLING HOOK\n";
		cout<<"\t    Your Balance : "<<money<<endl;
		cout<<"/////////////////////////////////////////////\n";
		leader += pricelist[0];
		item.push_back(items[sel]);
			}
		cout<<"Do you want to buy another one?"<<endl;
		cout<<"YES press [1] or NO press [2]"
		cin>>choose;
		if(choose==2) break;
		case 2:
			if(money<80){
				cout<<"[!] Not enough money";
				cout<<"/////////////////////////////////////////////\n";
				cout<<"\t    Your Balance : "<<money<<endl;
				cout<<"/////////////////////////////////////////////\n";
			}else{
		money -= pricelist[1];
		cout<<"/////////////////////////////////////////////\n";
		cout<<"\t [+] You've got CUTLASS\n";
		cout<<"\t    Your Balance : "<<money<<endl;
		cout<<"/////////////////////////////////////////////\n";
		leader += pricelist[1];
				}
		break;
		case 3:
			if(money<50){
				cout<<"[!] Not enough money";
				cout<<"/////////////////////////////////////////////\n";
				cout<<"\t    Your Balance : "<<money<<endl;
				cout<<"/////////////////////////////////////////////\n";
			}else{
		money -= pricelist[2];
		cout<<"/////////////////////////////////////////////\n";
		cout<<"\t [+] You've got STINKPOT\n";
		cout<<"\t    Your Balance : "<<money<<endl;
		cout<<"/////////////////////////////////////////////\n";
		leader += pricelist[2];
		}
		break;
		case 4:
			if(money<200){
				cout<<"[!] Not enough money";
				cout<<"/////////////////////////////////////////////\n";
				cout<<"\t    Your Balance : "<<money<<endl;
				cout<<"/////////////////////////////////////////////\n";
			}else{
			
		money -= pricelist[3];
		cout<<"/////////////////////////////////////////////\n";
		cout<<"\t [+] You've got MUSKET\n";
		cout<<"\t    Your Balance : "<<money<<endl;
		cout<<"/////////////////////////////////////////////\n";
		leader += pricelist[3];
		}
		break;
		case 5:
			if(money<500){
				cout<<"[!] Not enough money";
				cout<<"/////////////////////////////////////////////\n";
				cout<<"\t    Your Balance : "<<money<<endl;
				cout<<"/////////////////////////////////////////////\n";
			}else{
		money -= pricelist[4];
		cout<<"/////////////////////////////////////////////\n";
		cout<<"\t [+] You've got CANNON\n";
		cout<<"\t    Your Balance : "<<money<<endl;
		cout<<"/////////////////////////////////////////////\n";
		leader += pricelist[4];
		}
		break;
		case 6:
			if(money<150){
				cout<<"[!] Not enough money";
				cout<<"/////////////////////////////////////////////\n";
				cout<<"\t    Your Balance : "<<money<<endl;
				cout<<"/////////////////////////////////////////////\n";
			}else{
		money -= pricelist[5];
		cout<<"/////////////////////////////////////////////\n";
		cout<<"\t [+] You've got BOARDING AXE\n";
		cout<<"\t    Your Balance : "<<money<<endl;
		cout<<"/////////////////////////////////////////////\n";
		leader += pricelist[5];
		}
		break;
		case 7:
			if(money<300){
				cout<<"[!] Not enough money";
				cout<<"/////////////////////////////////////////////\n";
				cout<<"\t    Your Balance : "<<money<<endl;
				cout<<"/////////////////////////////////////////////\n";
			}else{
		money -= pricelist[6];
		cout<<"/////////////////////////////////////////////\n";
		cout<<"\t [+] You've got BLUNDERBUS\n";
		cout<<"\t    Your Balance : "<<money<<endl;
		cout<<"/////////////////////////////////////////////\n";
		leader += pricelist[6];
		}
		break;
		case 8:
			if(money<550){
				cout<<"[!] Not enough money";
				cout<<"/////////////////////////////////////////////\n";
				cout<<"\t    Your Balance : "<<money<<endl;
				cout<<"/////////////////////////////////////////////\n";
			}else{
		money -= pricelist[7];
		cout<<"/////////////////////////////////////////////\n";
		cout<<"\t [+] You've got AK_47\n";
		cout<<"\t    Your Balance : "<<money<<endl;
		cout<<"/////////////////////////////////////////////\n";
		leader += pricelist[7];
		}
		break;
		case 9:
			if(money<5){
				cout<<"[!] Not enough money";
				cout<<"/////////////////////////////////////////////\n";
				cout<<"\t    Your Balance : "<<money<<endl;
				cout<<"/////////////////////////////////////////////\n";
			}else{
		money -= pricelist[8];
		cout<<"/////////////////////////////////////////////\n";
		cout<<"\t [+] You've got POCARI SWEAT\n";
		cout<<"\t    Your Balance : "<<money<<endl;
		cout<<"/////////////////////////////////////////////\n";
		leader += pricelist[8];
		}
		break;
		case 10:
			if(money<99){
				cout<<"[!] Not enough money";
				cout<<"/////////////////////////////////////////////\n";
				cout<<"\t    Your Balance : "<<money<<endl;
				cout<<"/////////////////////////////////////////////\n";
			}else{
		money -= pricelist[9];
		cout<<"/////////////////////////////////////////////\n";
		cout<<"\t [+] You've got HOOK\n";
		cout<<"\t    Your Balance : "<<money<<endl;
		cout<<"/////////////////////////////////////////////\n";
		leader += pricelist[9];
		}
		break;
		case 11:
			if(money<1){
				cout<<"[!] Not enough money";
				cout<<"/////////////////////////////////////////////\n";
				cout<<"\t    Your Balance : "<<money<<endl;
				cout<<"/////////////////////////////////////////////\n";
			}else{
		money -= pricelist[10];
		cout<<"/////////////////////////////////////////////\n";
		cout<<"\t [+] You've got VERY KAK ITEM\n";
		cout<<"\t    Your Balance : "<<money<<endl;
		cout<<"/////////////////////////////////////////////\n";
		leader += pricelist[10];
		}
	}
		
}while(choose==1);
	break;
}
