// Necessary includes.
#include <vector>
#include "Car.h"
#include "LinkedList.cpp"

// Defining prototypes.
void setUpAllCars(LinkedList<Car>& allCars);
void printAllCars(LinkedList<Car>& allCars);
Car getCar();
template <typename T>
T getValidatedInput(const char * prompt);

//*************************************************************************************************
// Defining main():																				  *
//																								  *
// Okay... I learned a lot on this one. I wanted to keep this as 'generic' as possible, so I made *
// a generic template for the linked list class. In an effort to do that I had to adjust the way  *
// this program works. The printAllCars function uses the display function in the LinkedList, so  *
// worry not. The remove function in the LinkedList only uses indexes (to keep in the generic     *
// feel of the program) so I made a function here to identify the correct VIN to remove and then  *
// removes that object from the list.															  *
//																								  *
// I did some extra stuff in the LinkedList as well for future implementation. I just wanted to   *
// see if I could do it or not.																	  *
//*************************************************************************************************
int main()
{
	// Initializing the linked list.
	LinkedList<Car> allCars;

	// Set up all the car structures and print it.
	setUpAllCars(allCars);
	printAllCars(allCars);

	// Get car information from user.
	Car userCar = getCar();

	// Insert the new car into the list and display it.
	allCars.insert(userCar);
	printAllCars(allCars);

	// Prompt the user to press enter to exit and keeping the console open.
	std::cout << "\nPress Enter to Exit...";
	std::cin.get();
	return 0;
}

//*************************************************************************************************
// Defining setUpAllCars(LinkedList<Car>& allCars):												  *
//																								  *
// SetUpAllCars simply sets the values for all Car objects in the linked list to the predefined   *
// values.																						  *
//*************************************************************************************************
void setUpAllCars(LinkedList<Car>& allCars)
{
	std::string makes[] = { "Porsche", "Ford", "Chevrolet" };
	std::string models[] = { "911", "Mustang", "Beretta" };
	std::string colors[] = { "Silver", "Red", "Black" };
	int years[] = { 2005, 2007, 1989 };
	int mileages[] = { 18990, 49842, 90332 };
	int vins[] = { 1237362, 7337372, 2873644 };

	for (unsigned int i = 0; i < 3; i++)
	{
		Car newCar(makes[i], models[i], colors[i], years[i], mileages[i], vins[i]);
		allCars.append(newCar);
	}
}

//*************************************************************************************************
// Defining printAllCars(LinkedList<Car>& allCars):												  *
//																								  *
// PrintAllCars simply loops through the linked list storing all the Car objects and prints out   *
// the values associated with each Car.															  *
//*************************************************************************************************
void printAllCars(LinkedList<Car>& allCars)
{
	std::cout << std::left << SET_WIDTH "Make" << SET_WIDTH "Model"
		<< SET_WIDTH "Color" << SET_WIDTH "Year" << SET_WIDTH "Mileage" << SET_WIDTH "VIN"
		<< "\n" << std::endl;

	allCars.display();
}

Car getCar()
{
	std::string make, model, color;
	int year, mileage, vin;

	std::cout << "Let's make a car to insert into the list!\n" << std::endl;
	make = getValidatedInput<std::string>("Please input the car's make: ");
	model = getValidatedInput<std::string>("Please input the car's model: ");
	color = getValidatedInput<std::string>("Please input the car's color: ");
	year = getValidatedInput<int>("Please input the car's year: ");
	mileage = getValidatedInput<int>("Please input the car's mileage: ");
	vin = getValidatedInput<int>("Please input the car's VIN: ");

	Car newCar = Car(make, model, color, year, mileage, vin);

	return newCar;
}

//*************************************************************************************************
// Defining getValidatedInput(const char * prompt):												  *
//																								  * 
// Ever since I learned about templates, I've been going insane implementing them. I love these	  *
// things. So this literally takes a prompt and displays it to the user and returns a type		  *
// specified by its call. Pretty nifty, I think.												  *
//*************************************************************************************************
template <typename T>
T getValidatedInput(const char * prompt)
{
	T returnValue;
	bool validInput = false;
	char nextLetter;

	while (!validInput)
	{
		std::cout << prompt;
		std::cin >> returnValue;
		if (std::cin.fail() || std::cin.get() != '\n')
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Expected type (" << typeid(T).name() 
				<< "). Try again? (y/n): ";
			std::cin.get(nextLetter);
			if (!(nextLetter == 'y' || nextLetter == 'Y'))
			{
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "\nExiting program. Press enter to close...";
				std::cin.get();
				exit(EXIT_FAILURE);
			}
		}
		else
			validInput = true;
	}

	return returnValue;
}