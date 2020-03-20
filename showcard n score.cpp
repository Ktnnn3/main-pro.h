void Show(unit x){
	cout<<"*************************";
	for(int i=0;i<x.onhand.size();i++)
		cout<<""<<x.name<<"'s card is: "<<x.onhand[i]<<"\n";
	cout<<""<<x.name<<"'s score is: "<<x.score<<"\n";
	cout<<"*************************";
}
