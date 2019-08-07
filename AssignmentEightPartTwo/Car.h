// #pragma statement that helps prevent multiple includes of the same file.
#pragma once

// Necessary includes. Because they are here I don't do these includes in any other file.
#include "Exceptions.h"
#include <string>
#include <iomanip>

// Preprocessor define statements.
// Visual Studio is still yelling at me to change this to constexpr instead of #defines, but
// I doubt it matters much at all.
#define CURRENT_YEAR 2019
#define FIRST_YEAR 1970
#define SET_WIDTH std::setw(13) << 

// Here is the actual Car class.
class Car
{
private:
	// Class variables.
	std::string make;
	std::string model;
	std::string color;
	int year;
	int mileage;
	int vin;
public:
	// Constructors.
	Car();
	Car(std::string, std::string, std::string, int, int, int);

	// Setter functions.
	void setMake(std::string);
	void setModel(std::string);
	void setColor(std::string);
	void setYear(int);
	void setMileage(int);
	void setVin(int);

	// Getter functions.
	std::string getMake() const;
	std::string getModel() const;
	std::string getColor() const;
	int getYear() const;
	int getMileage() const;
	int getVin() const;

	// Operator overloads.
	friend std::ostream & operator << (std::ostream &output, const Car theCar);
	bool operator== (const Car& other);

	// Class functions.
	bool equals(const Car& other);
};
