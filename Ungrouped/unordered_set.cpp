#include <bits/stdc++.h>
using namespace std;

int main(){
	unordered_set<string> stringset;

	stringset.insert("my");
	stringset.insert("name");
	stringset.insert("is");
	stringset.insert("Tapan");
	stringset.insert("Meena");

	string key = "Tapan";
	// for Finding key in unordered set
	if(stringset.find(key) == stringset.end())
		cout<<"Key Not Found"<<endl;
	else
		cout<<key<<" found"<<endl;

	key = "nothing";

	if(stringset.find(key) == stringset.end())
		cout<<"Key not found"<<endl;
	else
		cout<<key<<" found"<<endl;
	// for printing all elements in unordered set
	unordered_set<string> :: iterator itr;
	for(itr = stringset.begin(); itr != stringset.end(); itr++)
		cout<<*itr<<endl;
}
/*
operations in unordered_set

    insert()– Insert a new {element} in the unordered_set container.

    begin()– Return an iterator pointing to the first element in the unordered_set container.

    end()– Returns an iterator pointing to the past-the-end-element.

    count()– Count occurrences of a particular element in an unordered_set container.
 
    find()– Search for an element in the container.
 
    clear()– Removes all of the elements from an unordered_set and empties it.
 
    cbegin()– Return a const_iterator pointing to the first element in the unordered_set container.
 
    cend()– Return a const_iterator pointing to past-the-end element in the unordered_set container or in one of it’s bucket.
 
    bucket_size()– Returns the total number of elements present in a specific bucket in an unordered_set container.
 
    erase()– Remove either a single element of a range of elements ranging from start(inclusive) to end(exclusive).
 
    size()– Return the number of elements in the unordered_set container.
 
    swap()– Exchange values of two unordered_set containers.
 
    emplace()– Insert an element in an unordered_set container.
 
    max_size()– Returns maximum number of elements that an unordered_set container can hold.
 
    empty()– Check if an unordered_set container is empty or not.
 
    equal_range– Returns range that includes all elements equal to given value.
 
    operator= – Copies (or moves) an unordered_set to another unordered_set and unordered_set::operator= is the corresponding operator function.
 
    hash_function() – This hash function is a unary function which takes asingle argument only and returns a unique value of type size_t based on it.
 
    reserve()– Used to request capacity change of unordered_set.
 
    bucket()– Returns the bucket number of a specific element.
 
    bucket_count() – Returns the total number of buckets present in an unordered_set container.
 
    load_factor()– Returns the current load factor in the unordered_set container.
 
    rehash()– Set the number of buckets in the container of unordered_set to given size or more.
 
    max_load_factor()– Returns(Or sets) the current maximum load factor of the unordered set container.
 
    emplace_hint()– Inserts a new element in the unordered_set only if the value to be inserted is unique, with a given hint.
 
    == operator – The ‘==’ is an operator in C++ STL performs equality comparison operation between two unordered sets and unordered_set::operator== is the corresponding operator function for the same.
 
    key_eq()– Returns a boolean value according to the comparison. It returns the key equivalence comparison predicate used by the unordered_set.
 
    operator!=– The != is a relational operator in C++ STL which compares the equality and inequality between unordered_set containers.
 
    max_bucket_count() – Find the maximum number of buckets that unordered_set can have.
*/