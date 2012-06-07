// http://goo.gl/Eaisd
// Knuth's mutiplcative 
// pick a multiplier that is in the order of your hash 
// and has no common factors with it.

// hash(i)=i*2654435761 mod 2^32

// General purpose hash function
// http://goo.gl/Ziw31

#include <memory.h>

// simple hash table for integer
const int MULTIPLIER = 997;
const int MAX_SIZE = 1000; // first prime less than 1000
class HashTable {
public:
	HashTable();
	void hash(int key);
	bool has(int key);
	void remove(int key);
private:
	int find_key(int key);
	int table[MAX_SIZE];
};

HashTable::HashTable() {
	memset(table, -1, sizeof(table));
}

// use linear probe technique
void HashTable::hash(int key) {
	int p = key * MULTIPLIER % MAX_SIZE;
	while (table[p] != -1)
		p = (p + 1) % MAX_SIZE;
	table[p] = key;
}

int HashTable::find_key(int key) {
	int p = key * MULTIPLIER % MAX_SIZE;
	do {
		if ( table[p] == -1 )
			return -1;
		else if ( table[p] == key )
			return key;
		p = (p + 1) % MAX_SIZE;
	} while(1);
}

bool HashTable::has(int key) {
	return find_key(key) != -1;
}

void HashTable::remove(int key) {
	int p = find_key(key);
	if(p != -1)	{
		int q = p;
		do {
			q = (q + 1) % MAX_SIZE;
			if(table[q] == -1) return;
			int r = table[q] * MULTIPLIER % MAX_SIZE;
			if( q >= r && )
			{
				/* code */
			}
		} while(1);
		table[p] = -1;
	}
}