#include "Car.h"

// Empty constructor.
Car::Car()
{ }

// Full constructor.
Car::Car(std::string incomingMake, std::string incomingModel, std::string incomingColor,
	int incomingYear, int incomingMileage, int incomingVin)
{
	setMake(incomingMake);
	setModel(incomingModel);
	setColor(incomingColor);
	setYear(incomingYear);
	setMileage(incomingMileage);
	setVin(incomingVin);
}

// Setter methods.
void Car::setMake(std::string incomingMake)
{
	if (incomingMake.length() < 4)
		throw InvalidMakeException("Make must be at least three characters long!");
	else
		make = incomingMake;
}

void Car::setModel(std::string incomingModel)
{
	model = incomingModel;
}

void Car::setColor(std::string incomingColor)
{
	color = incomingColor;
}

void Car::setYear(int incomingYear)
{
	if (incomingYear < FIRST_YEAR)
		throw YearBefore1970Exception("Year must be greater than or equal to 1970!");
	else if (incomingYear > CURRENT_YEAR)
		throw YearAfter2019Exception("Year must be less than or equal to 2019!");
	else
		year = incomingYear;
}

void Car::setMileage(int incomingMileage)
{
	if (incomingMileage < 0)
		throw NegativeMileageException("Mileage must be a non-negative integer!");
	else
		mileage = incomingMileage;
}

void Car::setVin(int incomingVin)
{
	if (incomingVin < 1000000 || incomingVin > 9999999)
		throw InvalidVINException("VIN must be exactly seven digits!");
	else
		vin = incomingVin;
}

// Getter methods.
std::string Car::getMake() const
{
	return make;
}

std::string Car::getModel() const
{
	return model;
}

std::string Car::getColor() const
{
	return color;
}

int Car::getYear() const
{
	return year;
}

int Car::getMileage() const
{
	return mileage;
}

int Car::getVin() const
{
	return vin;
}

// Operator overloads.
std::ostream & operator << (std::ostream &output, const Car theCar)
{
	output << SET_WIDTH theCar.getMake() << SET_WIDTH theCar.getModel() 
		<< SET_WIDTH theCar.getColor() << SET_WIDTH theCar.getYear() 
		<< SET_WIDTH theCar.getMileage() << SET_WIDTH theCar.getVin() << std::endl;
	return output;
}

bool Car::operator== (const Car& other)
{
	return equals(other);
}

// Class functions.
bool Car::equals(const Car& other)
{
	return getMake() == other.getMake() && getModel() == other.getModel() && getColor() == other.getColor()
		&& getYear() == other.getYear() && getMileage() == other.getMileage() && getVin() == other.getVin();
}