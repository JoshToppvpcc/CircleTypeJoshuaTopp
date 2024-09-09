#include <iostream>
#include <cmath> // For sqrt and M_PI

// Define Pointype class to find distance between points. This will allow me to find the radius which will be used for the other calculations of the circle. 
template <typename T>
class PointType {
private:
    T x, y;

public:
    // Default constructor
    PointType() : x(0), y(0) {}

    // Parameterized constructor
    PointType(T x, T y) : x(x), y(y) {}

    // Set x-coordinate
    void setX(T x) { this->x = x; }

    // Get x-coordinate
    T getX() const { return x; }

    // Set y-coordinate
    void setY(T y) { this->y = y; }

    // Get y-coordinate
    T getY() const { return y; }

    // Calculate the distance between this point and another point
    T distanceTo(const PointType<T>& other) const {
        T dx = x - other.x;
        T dy = y - other.y;
        return std::sqrt(dx * dx + dy * dy);
    }

    // Overload the subtraction operator
    T operator-(const PointType<T>& other) const {
        return distanceTo(other);
    }
};

// Define Circletype class to use pointtype class for points of a circle.
template <typename T>
class CircleType {
private:
    PointType<T> center;
    PointType<T> circumferencePoint;

public:
    // Default constructor
    CircleType() : center(PointType<T>()), circumferencePoint(PointType<T>()) {}

    // Parameterized constructor
    CircleType(PointType<T> center, PointType<T> circumferencePoint)
        : center(center), circumferencePoint(circumferencePoint) {}

    // Set center point
    void setCenter(PointType<T> center) { this->center = center; }

    // Get center point
    PointType<T> getCenter() const { return center; }

    // Set circumference point
    void setCircumferencePoint(PointType<T> circumferencePoint) {
        this->circumferencePoint = circumferencePoint;
    }

    // Get circumference point
    PointType<T> getCircumferencePoint() const { return circumferencePoint; }

    // Calculate the radius of the circle
    T radius() const {
        return center.distanceTo(circumferencePoint);
    }

    // Calculate the circumference of the circle
    T circumference() const {
        T r = radius();
        return 2 * M_PI * r;
    }

    // Calculate the area of the circle
    T area() const {
        T r = radius();
        return M_PI * r * r;
    }

    // Print the radius, area, and circumference of the circle
    void print() const {
        std::cout << "The radius of this circle is: " << radius() << std::endl;
        std::cout << "The circumference of this circle is: " << circumference() << std::endl;
        std::cout << "The area of this circle is: " << area() << std::endl;
    }
};

// Example usage
int main() {
    PointType<double> center(0.0, 0.0);
    PointType<double> circumferencePoint(2.5, 6.0);

    CircleType<double> circle(center, circumferencePoint);

    circle.print();

    return 0;
}
