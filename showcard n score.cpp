//เพิ่มเติมใน class unit
void unit::Show(){
	cout<<"*************************\n";
	for(int i=0;i<onhand.size();i++)
		cout<<""<<name<<"'s card is: "<<onhand[i]<<"\n";
	cout<<""<<name<<"'s score is: "<<score<<"\n";
	cout<<"*************************\n";
}
