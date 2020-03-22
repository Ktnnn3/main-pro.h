//public void showitemsnleader();
void unit::showitemsnleader(){
	for(int i=0;i<item.size();i++){
		cout<<"You got items....\n";
		cout<<item[i]<<"\n";
	}
	cout<<"--------------------------------------------\n";
	cout<<setw(30)<<"Your rank is ";
	if(leader >= 200 && leader <= 299) cout<<'D';
	else if(leader >= 300 && leader <= 399) cout<<'C';
	else if(leader >= 400 && leader <= 449) cout<<'B';
	else if(leader >= 450 && leader <= 499) cout<<'A';
	else if(leader >= 500) cout<<'S';
	else cout<<'F';
	cout<<"\n";
}
