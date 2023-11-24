#include "headers.h"


Rectangle::Rectangle() {
	this->height = 0;
	this->width = 0;
}; // bredd och höjd blir 0
Rectangle::Rectangle(float width, float height) {
	this->height = height;
	this->width = width;
};
void Rectangle::setWidth(float width) {
	this->width = width;
};
void Rectangle::setHeight(float height) {
	this->height = height;
};
float Rectangle::circumference() {
	return 2*(height + width);
};

bool Rectangle::operator==(Rectangle& other)  {
	return circumference() == other.circumference();
}

bool Rectangle::operator!=(Rectangle& second) {
	return circumference() != second.circumference();
}

bool Rectangle::operator<=(Rectangle& second) {
	return circumference() <= second.circumference();
}



Dog::Dog(string breed, string name, float height, bool vaccinated) {
	this->breed = breed;
	this->name = name;
	this->height = height;
	this->vaccinated = vaccinated;
};
Dog::~Dog() {};
void Dog::registerVaccination() {};
void Dog::setHeight(float height) {
	this->height = height;
};
string Dog::getBreed() const {
	return breed;
};
string Dog::getName() const {
	return name;
};

bool Dog::operator==(const Dog& other) const {
	return breed == other.breed && name == other.name && other.height == height;
}