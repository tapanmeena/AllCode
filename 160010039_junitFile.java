package orderMatching;

import static org.junit.Assert.*;
import org.junit.Test;

public class TestCase {
	
//	method for comparing two entry instances	
	boolean compare(entry entry1, entry entry2){
		if(entry1.getTime() == entry2.getTime() && entry1.getType().equals(entry2.getType()) && entry1.getOwner().equals(entry2.getOwner()) && entry1.getStock().equals(entry2.getStock()) && entry1.getQuantity() == entry2.getQuantity() && entry1.getPrice() == entry2.getPrice())
			return true;
		else 
			return false;
	}
	
	// method for comparing trades instances
	boolean compareTrade(trade trade1, trade trade2){
		if(trade1.getTime() == trade2.getTime() && trade1.getBuyer().equals(trade2.getBuyer()) && trade1.getSeller().equals(trade2.getSeller()) && trade1.getStock().equals(trade2.getStock()) && trade1.getQuantity() == trade2.getQuantity() && trade1.getPrice() == trade2.getPrice())
			return true;
		else 
			return false;
	}
	
	// testcase for Type Buy is adding in buyer list
	@Test
	public void buyer_test() {
		matching unitTest = new matching();
		boolean found = false,actual=true;

		entry newItem = new entry(1,"B","Tapan","Sony",10,100);
		unitTest.newOrder(newItem);

		found = compare(newItem,unitTest.buyerlist.get(0));
		
		assertEquals(found,actual);
	}
	
	//testcase for type Sell is adding in Seller list
	@Test
	public void seller_test() {
		matching unitTest = new matching();
		boolean found = false,actual=true;

		entry newItem = new entry(2,"S","John","Sony",84,50);
		unitTest.newOrder(newItem);
		// entry newItem = new entry(1,"S","Johnny","Sony",84,200);
		// unitTest.newOrder(newItem);

		found = compare(newItem,unitTest.sellerlist.get(0));
		
		assertEquals(found,actual);
	}

	//testcase for validating entry instances
	//i.e given input is valid or not
	@Test
	public void validate_Test(){
		matching unitTest = new matching();
		boolean found = false,actual=true;

		/*
		 * basic correct format for input
		 */
		entry newItem = new entry(1,"B","Tapan","Sony",11,1);
		found = unitTest.validate_entry(newItem);
		assertEquals(found,actual);

		
		/*
		 * when wrong type is inputeed
		 * B or S is expected other than 
		 * them all are invalid
		 */
		newItem = new entry(1,"b","Tapan","Sony",11,1);
		actual = false;
		found = unitTest.validate_entry(newItem);
		assertEquals(found,actual);

		/*
		 * when wrong time is inputted
		 * time > 0 is expected
		 */

		newItem = new entry(-1,"B","Tapan","Sony",11,1);
		actual = false;
		found = unitTest.validate_entry(newItem);
		assertEquals(found,actual);

		/*
		 * valid sell entry
		 */
		
		newItem = new entry(1,"S","Tapan","Sony",11,1);
		actual = true;
		found = unitTest.validate_entry(newItem);
		assertEquals(found,actual);

		/*
		 * invalid sell entry Type
		 */
		
		newItem = new entry(1,"s","Tapan","Sony",11,1);
		actual = false;
		found = unitTest.validate_entry(newItem);
		assertEquals(found,actual);

		/*
		 * when wrong or invalid quantity is inputed
		 * expected quantity > 0
		 */
		
		newItem = new entry(1,"B","Tapan","Sony",-11,1);
		actual = false;
		found = unitTest.validate_entry(newItem);
		assertEquals(found,actual);

		/*
		 * expected price is greater than 0
		 */
		
		newItem = new entry(1,"B","Tapan","Sony",11,-1);
		actual = false;
		found = unitTest.validate_entry(newItem);
		assertEquals(found,actual);		
	}

	
	// testcase for when trading happen in Main class
	@Test
	public void trading(){

		matching unitTest = new matching();
		boolean found = false,actual = false;		

		entry newItem = new entry(1,"B","Tapan","Sony",10,100);
		unitTest.newOrder(newItem);
		newItem = new entry(2,"S","Cruz","Sony",100,50);
		unitTest.newOrder(newItem);
		newItem = new entry(3,"B","Diaz","Microsoft",10,100);
		unitTest.newOrder(newItem);
		newItem = new entry(4,"B","Jason","Sony",100,49);
		unitTest.newOrder(newItem);
		newItem = new entry(5,"S","Ninja","Microsoft",50,90);
		unitTest.newOrder(newItem);

		/*
		 * checking trades
		 */
		actual = true;
		trade newTrade = new trade(2,"Tapan","Cruz","Sony",10,50);
		found = compareTrade(newTrade,unitTest.tradeslist.getAllTrade().get(0));
		assertEquals(actual,found);

		actual = true;
		newTrade = new trade(5,"Diaz","Ninja","Microsoft",10,90);
		found = compareTrade(newTrade,unitTest.tradeslist.getAllTrade().get(1));
		assertEquals(actual,found);
		
		actual = false;
		found = false;
		newTrade = new trade(6,"Ninja","Tifu","Apple",10,500);
		for(int i=0;i<unitTest.tradeslist.noOfTrades(); i++) {
			found = compareTrade(newTrade,unitTest.tradeslist.getAllTrade().get(i));
			if(found)
				break;
		}
		assertEquals(actual,found);
	}
}

