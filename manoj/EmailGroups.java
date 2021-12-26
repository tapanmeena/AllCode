package manoj.EmailGroups;

import java.io.IOException;
import java.time.*;
import java.util.*;
import java.text.ParseException;

public class EmailGroups
{

	private List<String[]> peoples;
	private List<String> words;
	private List<EmailData> emails;
	private List<TransactionData> emailTransac;

	private List<List<String>> emailGroups;

	EmailGroups(final String email, final String keywords,
		final String person) throws IOException, ParseException
	{
		readCSV readcsv = new readCSV();
		this.peoples = readcsv.readPersons(person);
		this.words = readcsv.readKeywords(keywords);
		this.emails = readcsv.readEmail(email);
		this.emailTransac = emailTransactions();
		// this.emailGroups = ();
	}


	private List<TransactionData> emailTransactions()
	{
		// List<TransactionData> result = 
	}
}