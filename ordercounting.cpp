#include <bits/stdc++.h>
using namespace std;

struct entry
{
	int time;
	string type;
	string owner;
	string stock;
	int quantity;
	int price;
	bool isComplete = false;
};

int countTrades(vector<entry> buyer,vector<entry> seller){
	vector<entry> allTrades;
	int no_of_trades = 0;
	if(buyer.size()==0 || seller.size()==0)
		return no_of_trades;
	for(int i=0;i<buyer.size();i++){
		if(buyer[i].isComplete)
			continue;
		int quanTrade = 0;
		int priceTrade = 0;
		bool halfComplete = false;
		for(int j=0;j<seller.size();j++){
			if(buyer[i].stock == seller[j].stock && !seller[j].isComplete){
				if(buyer[i].price >= seller[j].price){
					if ( buyer[i].quantity == seller[j].quantity ){
						allTrades.push_back(seller[j]);
						allTrades.push_back(buyer[i]);
						buyer[i].isComplete = true;
						seller[j].isComplete = true;
						no_of_trades += 2;
						halfComplete = false;
						quanTrade += buyer[i].quantity;
						priceTrade += buyer[i].price;
						cout<<"for "<<seller[j].owner<<" for "<<seller[j].quantity<<": sell at "<<seller[j].price<<endl;
						cout<<"for "<<buyer[i].owner<<" for "<<buyer[i].quantity<<": buy at "<<priceTrade<<endl<<endl;
						break;
					}
					else if ( buyer[i].quantity > seller[j].quantity ){
						allTrades.push_back(seller[j]);
						buyer[i].quantity -= seller[j].quantity;
						halfComplete = true;
						seller[j].isComplete = true;
						quanTrade += seller[j].quantity;
						no_of_trades += 1;
						priceTrade += seller[j].price;
						cout<<"for "<<seller[j].owner<<" for "<<seller[j].quantity<<": sell at "<<seller[j].price<<endl;
					}
					else if ( buyer[i].quantity < seller[j].quantity ){
						halfComplete = false;
						allTrades.push_back(seller[j]);
						allTrades.push_back(buyer[i]);
						buyer[i].isComplete = true;
						seller[j].quantity -= buyer[i].quantity;
						quanTrade += buyer[i].quantity;
						no_of_trades += 2;
						priceTrade += seller[j].price;
						cout<<"for "<<seller[j].owner<<" for "<<buyer[i].quantity<<": sell at "<<seller[j].price<<endl;
						cout<<"for "<<buyer[i].owner<<" for "<<buyer[i].quantity<<": buy at "<<priceTrade<<endl<<endl;
						break;
					}
				}
			}
		}
		if(halfComplete){
			allTrades.push_back(buyer[i]);
			no_of_trades+=1;
			cout<<"for "<<buyer[i].owner<<" for "<<quanTrade<<": buy at "<<priceTrade<<endl<<endl;
		}
	}
	return no_of_trades;
}

int main(){
	int n;
	cin>>n;
	vector <entry> buyer;
	vector <entry> seller;
	for(int i=0;i<n;i++){
		entry temp;
		temp.time = i+1;
		// string type;
		// cin>>type;
		cin>>temp.type;
		cin>>temp.owner;
		cin>>temp.stock;
		cin>>temp.quantity;
		cin>>temp.price;
		if(temp.type == "buy")
			buyer.push_back(temp);
		else if(temp.type == "sell")
			seller.push_back(temp);
		else{
			cout<<"Wrong Type.....exiting"<<endl;
			return 0;
		}
	}
	cout<<endl;
	int tCount = countTrades(buyer,seller);
	cout<<"Number of Trades happened is "<<tCount<<endl;
}
