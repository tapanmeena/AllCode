package orderMatching;

import java.util.*;
import java.io.*;

/*######### -->Main Class<-- #########

Main class has two methods 1) main 2) printAll
	
	1) printAll :- it takes matching object as input and prints
					all the pending buyers and pending sellers
					as output
	2) main     :- it takes csv filelocation with comma seperated 
					as input and initialize entry object and pass
					it to stockExchange for validation and
					order matching
					

*/
public class Main {
	
	public static void printAll(matching stockExchange) {
		System.out.println("\t----Printing pending Buyers----");
		for(int i=0; i < stockExchange.buyerlist.size();i++) {
			entry buyer = stockExchange.buyerlist.get(i);
			System.out.println("-> Buyer "+buyer.getOwner()+" has pending stocks of "+buyer.getStock()+" in quantity "+buyer.getQuantity());
		}
		System.out.println("");
		System.out.println("\t----Printing pending Sellers----");
		for(int i=0; i < stockExchange.sellerlist.size();i++) {
			entry buyer = stockExchange.sellerlist.get(i);
			System.out.println("-> Seller "+buyer.getOwner()+" has pending stocks of "+buyer.getStock()+" in quantity "+buyer.getQuantity());
		}
	}
	
	public static void readInput(String filelocation) {
		matching stockExchange = new matching();
		try {
			Scanner sc = new Scanner(new File(filelocation));
			String column = "";
			System.out.println("");
			System.out.println("------------------Stocks Exchange Started------------------");
			System.out.println("");

			while (sc.hasNextLine()) {//parse whole CSV file and do order matching
				column = sc.nextLine();
				String[] InputValue = column.split(",");
				if(InputValue.length!=6)
					continue;
				// initialize entry object
				entry newEntry = new entry(Integer.parseInt(InputValue[0]),InputValue[1],InputValue[2],InputValue[3], Integer.parseInt(InputValue[4]), Integer.parseInt(InputValue[5]));
				
				if(!stockExchange.newOrder(newEntry)) {//pass entry object for ordermatching and validation
					System.out.println("Entry<"+newEntry.getTime()+","+newEntry.getType()+","+newEntry.getOwner()+","+newEntry.getStock()+","+newEntry.getQuantity()+","+newEntry.getPrice()+">is not Valid");
				}
			}
			sc.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		System.out.println("");
		System.out.println("------------Printing Pending Trades------------");
		printAll(stockExchange);
		System.out.println("--------Finished Printing Pending Trades--------");
		System.out.println("");
		System.out.println("------------------Stocks Exchange Finished------------------");
		System.out.println("");
		System.out.println("Total number of Trades happened are:- "+stockExchange.tradeslist.noOfTrades());
	}
	
	public static void main(String[] args) {
		String filelocation = "C:\\Users\\input.csv";
		if(args.length != 0)
			filelocation = args[0];
		readInput(filelocation);
	}
}


package orderMatching;

public class entry{
	int time;				//contains time
	String type;			//contains which type(sell/buy) of entry is this
	String owner;			//contains owner name
	String stock;			//contains stock name
	int quantity;			//contains quantity of stock
	int price;				//contains per stock price
	boolean isComplete;	    //whether a transaction is complete or not
	
	
	public entry(int time,String type,String owner,String stock,int quantity, int price){
		this.time = time;
		this.type = type;
		this.owner = owner;
		this.stock = stock;
		this.quantity = quantity;
		this.price = price;
		isComplete = false;
	}
	
	int getTime() {
		return this.time;
	}
	void setTime(int time) {
		this.time = time;
	}
	
	String getType() {
		return this.type;
	}
	void setType(String type) {
		this.type = type;
	}
	
	String getOwner() {
		return this.owner;
	}
	void setOwner(String owner) {
		this.owner = owner;
	}
	
	String getStock() {
		return this.stock;
	}
	void setStock(String stock) {
		this.stock = stock;
	}
	
	int getQuantity() {
		return this.quantity;
	}
	void setQuantity(int quantity) {
		this.quantity = quantity;
	}
	
	int getPrice() {
		return this.price;
	}
	void setPrice(int price) {
		this.price = price;
	}
	
	boolean getisComplete() {
		return this.isComplete;
	}
	void setCompelete(boolean complete) {
		this.isComplete = complete;
	}

}


package orderMatching;
import orderMatching.trade;
import java.util.*;

public class allTrades {

	ArrayList<trade> alltrades = new ArrayList<trade>();

	ArrayList<trade> getAllTrade(){
		return this.alltrades;
	}

	
	void setAllTrade(trade newTrade) {
		this.alltrades.add(newTrade);
	}
	

	int noOfTrades() {
		return alltrades.size();
	}
	
}


package orderMatching;

import java.util.*;

/*############## -> matching <-##############
matching class has 4 methods:-
	->trading
	->orderMatching
	->validate_entry
	->newOrder

1) trading :- takes buyer and seller entry instance and location of
			  them in thier corresponding lists. It checks the
			  available quantity and trade the stocks and 
			  if all stocks are not sold/bought then update the 
			  remaining stocks in corresponding lists.

2) orderMatching :- takes buyerlist and seller Arraylist as input
					iterate over buyer and seller lists if trade
					possible call trading method and remove the
					seller/buyer entry from list if all their
					stocks are traded.

3) validate_entry :- it take newItem entry instance as input
					 and checks if it's type is either B or S
					 and all types are correct.if correct return
					 true else false.

4)newOrder :- 		takes newItem entry instance as input 
					start the stock exchanging process


*/
public class matching {
	ArrayList<entry> buyerlist = new ArrayList<entry>();
	ArrayList<entry> sellerlist = new ArrayList<entry>();
	allTrades tradeslist = new allTrades();
	
	void trading(entry buyer,entry seller,int i, int j) {
		int quanTraded = 0,buyerQleft = 0,sellerQleft = 0;
		if(buyer.getQuantity() > seller.getQuantity()) {
			quanTraded = seller.getQuantity();
		}
		else if(buyer.getQuantity() <= seller.getQuantity()) {
			quanTraded =  buyer.getQuantity();
		}
		trade newTrade = new trade(Math.max(buyer.getTime(),seller.getTime()),buyer.getOwner(),seller.getOwner(),buyer.getStock(),quanTraded,seller.getPrice());
		this.tradeslist.setAllTrade(newTrade);
		System.out.println("-> Trade happened at "+Math.max(buyer.getTime(),seller.getTime())+" of stock "+buyer.getStock()+" sold by "+seller.getOwner()+" bought by "+buyer.getOwner()+" at price "+seller.getPrice()+" of quantity "+quanTraded+"<-");
		
		buyerQleft = buyer.getQuantity() - quanTraded;
		sellerQleft = seller.getQuantity() - quanTraded;
		buyerlist.get(i).setQuantity(buyerQleft);
		sellerlist.get(j).setQuantity(sellerQleft);		
	}
	
	boolean orderMatching(ArrayList<entry> buyerlist,ArrayList<entry> sellerlist) {
		boolean tradeHap = false;
		for(int i = 0; i<buyerlist.size(); i++) {
			entry buyer = buyerlist.get(i);
			for(int j = 0; j<sellerlist.size();j++) {
				entry seller = sellerlist.get(j);
				if(buyer.getStock().equals(seller.getStock())) {
					if(buyer.getPrice() >= seller.getPrice()) {
						trading(buyer,seller,i,j);
						tradeHap = true;
						if(sellerlist.get(j).getQuantity()==0) {
							sellerlist.remove(j);
							j--;
						}
						if(buyerlist.get(i).getQuantity()==0) {
							buyerlist.remove(i);
							i--;
							break;
 						}
					}
				}
			}
		}
		return tradeHap;
	}
	
	boolean validate_entry(entry newItem){
		if(!(newItem.getType().equals("S") || newItem.getType().equals("B")))
			return false;
		if(newItem.getPrice()>0 && newItem.getQuantity()>0 && newItem.getTime()>0)
			return true;
		else
			return false;
	}
	public boolean newOrder(entry newItem) {
		boolean tradeSearch = false,valid=false;
		
		valid = validate_entry(newItem);		//checking for validation
		if(!valid)
			return false;
		if(newItem.getType().equals("B")) {
			buyerlist.add(newItem);
			if(!sellerlist.isEmpty())			//if seller list is not empty
				tradeSearch = true;				//tradeSearching is possible
		}
		if(newItem.getType().equals("S")) {
			sellerlist.add(newItem);			//if buyer list is not empty
			if(!buyerlist.isEmpty())			//tradeSearching is possible
				tradeSearch = true;
		}
		if(tradeSearch) {
			orderMatching(buyerlist,sellerlist);//do ordermatching over
		}										//buyer and seller arraylist
		return true;
	}
}


package orderMatching;

public class trade {
	int time;			//time of trade
	String buyer;		//person who bought the stocks
	String seller;		//person who sold the stocks
	String stock;		//the stock which is traded
	int quantity;		//number of stocks traded
	int price;			//per stock value of stock
	public trade(int time,String buyer,String seller,String stock,int quantity, int price){
		this.time = time;
		this.buyer= buyer;
		this.seller = seller;
		this.stock = stock;
		this.quantity = quantity;
		this.price = price;
	}
	
	int getTime() {
		return this.time;
	}
	void setTime(int time) {
		this.time = time;
	}
	
	String getBuyer() {
		return this.buyer;
	}
	void setBuyer(String buyer) {
		this.buyer = buyer;
	}
	
	String getSeller() {
		return this.seller;
	}
	void setSeller(String seller) {
		this.seller = seller;
	}
	
	String getStock() {
		return this.stock;
	}
	void setStock(String stock) {
		this.stock = stock;
	}
	
	int getQuantity() {
		return this.quantity;
	}
	void setQuantity(int quantity) {
		this.quantity = quantity;
	}
	
	int getPrice() {
		return this.price;
	}
	void setPrice(int price) {
		this.price = price;
	}
}

