int shop(){
	int sel;
	int pricelist[11] = {100,80,50,200,500,150,300,550,5,99,1};
	cout<<"\tWelcome To our shop!!!\n";
	cout<<"\twhich one do you want to buy?\n";
	cout<<"[1]GRAPPLING HOOK 100b\n";
	cout<<"[2]CUTLASS 80b\n";
	cout<<"[3]STINKPOT 50b\n";
	cout<<"[4]MUSKET 200b\n";
	cout<<"[5]CANNON 500b\n";
	cout<<"[6]BOARDING AXE 150b\n";
	cout<<"[7]BLUNDERBUS 300b\n";
	cout<<"[8]AK-47 550b\n";
	cout<<"[9]POCARI SWEAT 5b\n";
	cout<<"[10]HOOK 99b\n";
	cout<<"[11]VERY KAK ITEM 1b\n";
	cout<<"Select : ";
	cin>>sel;
	switch(sel){
		case 1:
		mymoney -= pricelist[0];
		cout<<"You've got GRAPPLING HOOK";
		cout<<"Your Balance : "<<mymoney;
		break;
		case 2:
		mymoney -= pricelist[1];
		cout<<"You've got CUTLASS";
		cout<<"Your Balance : "<<mymoney;
		break;
		case 3:
		mymoney -= pricelist[2];
		cout<<"You've got STINKPOT";
		cout<<"Your Balance : "<<mymoney;
		break;
		case 4:
		mymoney -= pricelist[3];
		cout<<"You've got MUSKET";
		cout<<"Your Balance : "<<mymoney;
		break;
		case 5:
		mymoney -= pricelist[4];
		cout<<"You've got CANNON";
		cout<<"Your Balance : "<<mymoney;
		break;
		case 6:
		mymoney -= pricelist[5];
		cout<<"You've got BOARDING AXE";
		cout<<"Your Balance : "<<mymoney;
		break;
		case 7:
		mymoney -= pricelist[6];
		cout<<"You've got BLUNDERBUS";
		cout<<"Your Balance : "<<mymoney;
		break;
		case 8:
		mymoney -= pricelist[7];
		cout<<"You've got AK_47";
		cout<<"Your Balance : "<<mymoney;
		break;
		case 9:
		mymoney -= pricelist[8];
		cout<<"You've got POCARI SWEAT";
		cout<<"Your Balance : "<<mymoney;
		break;
		case 10:
		mymoney -= pricelist[9];
		cout<<"You've got HOOK";
		cout<<"Your Balance : "<<mymoney;
		break;
		case 11:
		mymoney -= pricelist[10];
		cout<<"You've got VERY KAK ITEM";
		cout<<"Your Balance : "<<mymoney;
		break;
	}

}
