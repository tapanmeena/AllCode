#include <bits/stdc++.h>
using namespace std;

void insert_tickets(map<string,string> &dataSet){
	dataSet["Chennai"] = "Banglore"; 
	dataSet["Bombay"] = "Delhi"; 
	dataSet["Goa"] = "Chennai"; 
	dataSet["Delhi"] = "Goa"; 
}

void print_path(map<string,string> tickets){
	map<string, string> reverse_map;
	map<string, string> ::iterator itr;

	for(itr = tickets.begin(); itr != tickets.end(); itr++)
		reverse_map[itr->second] = itr->first;
	string start;
	for(itr = tickets.begin(); itr != tickets.end(); itr++){
		if(reverse_map.find(itr->first) == reverse_map.end()){
			start = itr->first;
			break;
		}
	}
	itr = tickets.find(start);
	for(itr; itr != tickets.end();){
		cout<<itr->first<<" -> "<<itr->second<<endl;
		itr = tickets.find(itr->second);
	}
}

int main(){
	map<string,string> tickets;
	insert_tickets(tickets);
	print_path(tickets);
}