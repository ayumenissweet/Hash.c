# Main Problem
Hashmaps are a very modern data structure, it uses a very strong system to store key value pairs cleanly, the data structure is defined like this :

![[image1.png]]

## How it works
- A hashmap is simply a large array
- each key is **hashed** using a hashing function and then done an operation to turn into a usable index

this idea provides a O(1) performance which is very convenient

---
## How hashmaps handle collisions :

![[image2.png]]
a "collision"  is when two names return the same "index" after hashing them and assigning an index, this hash map solves this by making each bucket a linked list element

---
## Resizing : 
This hashmaps works like dynamic arrays, the map resizes automatically once the load factor reaches 75%, once that happens, we double the size of the array

--- 
## Utilities :
those are the functions this program currently supports
```c
// 1. Initialization
// Initialize an empty map with default capacity (16)
Hashmap map = initMap(); 

//initialize when creating the map
Hashmap grades = initMapOf({"Aymen", 15}, {"Karim", 18}, {"Melissa", 12});


// 2. Core Operations
set(&grades, "Khennak", 20);      // Add a new key-value pair
set(&grades, "Melissa", 14);      // Update an existing key's value (overwrites)

int* aymenScore = get(grades, "Aymen"); // Retrieve value pointer -> returns &15
if (aymenScore) {
    printf("Aymen's grade: %d\n", *aymenScore);
}

removeMap(&grades, "Karim");      // Remove an entry by its key


// 3. Utility & Checks
size(grades);                     // Returns the total number of active entries
containsKey(grades, "Khennak");   // Returns true
containsValue(grades, 11);        // Returns false


// 4. Debugging
displayMap(grades);               // Prints the entire map structure
```

--- 
## What else i want to add : 
those are some of the convenient methods i'd like to add to this program in the future :

- [ ] add an `iterate` method (basically a method that cleanly returns only the valid keys)
- [ ] enhance the `get` method to be prettier to use
- [ ] add a `freeMap` and `clearMap` methods to delete/empty out the hashmap
- [ ] add `putIfAbsent` like in python : if key does not exist, insert

---
## How to use : 
in your main program : 

```c
#include "include/map.h"

int main(){
	Hashmap map = initMap();
	//now you can call map methods
	set(&map,"aymen",5);
}
```
