#pragma once
#include "headers.h"

class Rectangle {
private:
    float width;
    float height;
public:
    Rectangle(
    ); // bredd och höjd blir 0
    Rectangle(float width, float height);
    void setWidth(float width);
    void setHeight(float height);
    float circumference();
    bool operator==(Rectangle& other);
    bool operator!=(Rectangle& other);
    bool operator<=(Rectangle& other);
};

class Dog {
private:
    string breed;
    string name;
    float height;
    bool vaccinated;
public:
    Dog(string breed, string name, float height = 0.0f, bool vaccinated = false);
    ~Dog();
    void registerVaccination();
    void setHeight(float height);
    string getBreed() const;
    string getName() const;
    bool operator==(const Dog& other) const;
};
