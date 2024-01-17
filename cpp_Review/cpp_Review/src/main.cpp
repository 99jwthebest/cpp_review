#include <iostream> // use angle brakcet when using another library, when it is your library, use quotation marks
// include is different from using in c#, it copies everything from the include file and pastes it when the code runs
#include <vector> // List<> equivalent of c#
#include <memory>

// pass const by reference - const correctness: use const whenever you can
void PrintInt(const int& numToPrint) // if it's a texture or a vector, use & so that it doesn't make a new copy of that texture or vector
{
	std::cout << numToPrint << std::endl;
}

// other people will think that you are going to change num with writing the function this way
void PrintInt2(int& num) 
{

}

int numWaterBottles(int numBottlesCanDrink, int numExchange) {
	int initialBottles = numBottlesCanDrink;
	numExchange = initialBottles / 3;
	numBottlesCanDrink = initialBottles + numExchange;
	numExchange /= 3;
	numBottlesCanDrink += numExchange;

	std::cout << numBottlesCanDrink << std::endl;
	return numBottlesCanDrink;
}


int main() 
{
	int initialBottles = 100;
	int numExchange = 0;

	numWaterBottles(initialBottles, numExchange);
	
}

void Notes() {
	int a = 4;
	int* aPtr = &a;
	a = 5;
	std::cout << aPtr << std::endl; // prints memory address, put *aPtr so that it prints what is in that ptr
	std::cout << *aPtr << std::endl; // prints value

	// non-defined behavior, when you do something like the line below, it's basically garbage data. Very dangerous behavior
	//std::cout << *(aPtr+1) << std::endl; // prints value

	//only use pointers when you have to, otherwise use a reference
	/// use a pointer when you want to store something big

	// the const keyword means the variable is immutable
	int id = 12345;
	PrintInt(id);

	// how to create a length or count for a list in c++
	std::vector<int> intVec{ 1,2,3,4,5 };

	intVec.push_back(6);
	intVec.insert(intVec.begin(), 55);
	std::cout << *intVec.begin() << std::endl;
	std::cout << *(intVec.begin() + 1) << std::endl;

	int* heapInt = new int(5); // have to use a pointer, making an integer on heap with "new int"
	//int* anotherRef = heapInt;
	// heap memory is not automatically deleted for you.
	// stack does delete automatically when out of scope.
	// manually delete heap memory
	delete heapInt; // doesn't delete the pointer, just the value
	heapInt = nullptr; // this does delete the pointer
	//delete anotherRef;
	//anotherRef = nullptr;
	// using nullptr only without delete will cause the memory to be constantly occupied and create a memory leak

	if (heapInt)
	{
		std::cout << "lehkldfk" << std::endl;

		std::cout << *heapInt << std::endl;
	}


	// smart pointers
	// this will delete the pointers for you
	// so use unique pointers all the time

	while (true)
	{
		int* heapInt = new int{ 5 }; // use curly brackets for writing an integer instead of parathesis

		std::unique_ptr<int> uniqueInt{ new int{5} };

		std::unique_ptr<int> another = std::move(uniqueInt); // game itself

		// allow to share pointers, deletes the pointer when the last pointer is delete from shared pointer
		std::shared_ptr<int> sharedInt{ new int{5} }; // texture

		std::shared_ptr<int> another2 = sharedInt;

		std::shared_ptr<int> another3 = sharedInt; // weak pointer is for gun references

		std::weak_ptr<int> weakRef = another3;
		std::cout << *weakRef.lock() << std::endl;

		if (weakRef.expired()) {
			std::cout << "pointer is not alive" << std::endl;
		}
		else {
			std::cout << *weakRef.lock() << std::endl;
		}

		// if you want to do the delete and nullptr manually
		another.reset();
	}


	for (int element : intVec)
	{
		std::cout << element << std::endl;
	}

	for (int i = 0; i < intVec.size(); i++)
	{
		std::cout << intVec[i] << std::endl;
	}

	// how to create a length or count for an array in c++
	int nums[] = { 1, 2, 3, 4, 5 };
	for (int i = 0; i < sizeof(nums) / sizeof(int); i++)
	{
		std::cout << nums[i] << std::endl;
	}
}