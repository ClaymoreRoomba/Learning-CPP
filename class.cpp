#include <iostream>

// Define a base class named "Shape" with the following member variables:
class Shape
{
    public:
        std::string name;  // Public member variable
        int sides;         // Public member variable

        // Constructor with default values
        Shape(std::string _name = "", int _sides = 0)
        {
            name = _name;
            sides = _sides;
        }

        // Public member function to print the shape's name and number of sides
        void printInfo()
        {
            std::cout << "Name: " << name << ", Sides: " << sides << std::endl;
        }
};

// Define a derived class named "Rectangle" that inherits from the "Shape" class
// Only inherits its public members, if anything was in private, it would not be accessible, even within the class
class Rectangle: public Shape
{
    private:
        int width;  // Private member variable
        int height; // Private member variable

    public:
        // Constructor with default values
        Rectangle(std::string _name = "Rectangle", int _sides = 4, int _width = 0, int _height = 0)
            : Shape(_name, _sides), width(_width), height(_height)  // Initialize the base class with default values
        {
            std::cout << "A rectangle has been created\n"; // Additional code goes here
        }

        // Getters and setters for the private member variables
        void setWidth(int _width) { width = _width; }
        int getWidth() { return width; }

        void setHeight(int _height) { height = _height; }
        int getHeight() { return height; }

        // Public member function to calculate and return the area of the rectangle
        int getArea() { return width * height; }
};

int main()
{
    // Create an object of the Rectangle class
    Rectangle r1;

    // Access the member variables and member functions inherited from the base class
    r1.name = "Square";
    r1.printInfo();  // Output: "Name: Square, Sides: 4"

    // Set the width and height of the rectangle using the setters
    r1.setWidth(10);
    r1.setHeight(20);

    // Get the width and height of the rectangle using the getters
    int width = r1.getWidth();
    int height = r1.getHeight();
    std::cout << "Width: " << width << ", Height: " << height << std::endl;  // Output: "Width: 10, Height: 20"

    // Call the member function of the derived class to calculate the area
    int area = r1.getArea();
    std::cout << "Area: " << area << std::endl;  // Output: "Area: 200"

}
