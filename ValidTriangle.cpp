// ValidTriangle.cpp : This file contains the code for the valid triangle program

#include <iostream>
#include <iomanip>
#include <cmath>

// Function Prototypes
double GetOneSideLength();
bool IsTriangle(double, double, double);
double GetArea(double, double, double);
void DisplayMessages(double, double, double, double);

int main() {
	// Create variables for triangle sides and area 
	double area;
	double a, b, c;

	// Get side length inputs until a valid triangle is made
	do {
		a = GetOneSideLength();
		b = GetOneSideLength();
		c = GetOneSideLength();
		if (IsTriangle(a, b, c) == false)
			std::cout << "Invalid! Try again.\n";
	} while (IsTriangle(a, b, c) == false);
	
	// Find the area of the triangle and call output function
	area = GetArea(a, b, c);
	DisplayMessages(a, b, c, area);
}

double GetOneSideLength() {
	// Create variable for side length to get
	double x;

	// Get input for side length until valid input is given
	do {
		std::cout << "Enter a triangle side length ";
		std::cout << "thats positive and does not exceed 500.0:\n";
		std::cin >> x;

		if (x > 500.0 || x <= 0)
			std::cout << "Invalid input! Enter another length:\n";
	} while (x > 500.0 || x <= 0);
	return x;
}

bool IsTriangle(double num1, double num2, double num3) {
	// Check if the side lengths create a valid triangle 
	if ((num1 + num2 > num3) && (num2 + num3 > num1) && (num3 + num1 > num2))
		return true;
	return false;
}

double GetArea(double num1, double num2, double num3) {
	// Calculate the area by taking sum of lengths divided by 2 ("s"), and 
	// plugging s into the area calculation for a triangle
	double s = (num1 + num2 + num3) / 2;
	double area = sqrt(s * (s - num1) * (s - num2) * (s - num3));
	return area;
}

void DisplayMessages(double num1, double num2, double num3, double area){
	// Display message for the final triangle and its results
	std::cout << "The three sides of the triangle are: ";
	std::cout << std::setprecision(2) << std::fixed;
	std::cout << num1 << ", " << num2 << ", and " << num3 << ".\n";
	std::cout << "The area is: " << area << std::endl;
	return;
}