```mermaid
classDiagram
    class Shape {
        - string name
        - float r
        + Shape(string n, float rr)
        + setName(string n)
        + getName() string
        + setR(float rr)
        + getR() float
    }

    class TwoDShape {
        - float area
        - float perimeter
        + TwoDShape(string n, float rr)
        + getArea() float
        + getPerimeter() float
        + print()*
    }

    class Circle {
        - float x_center
        - float y_center
        + Circle(float x, float y, float radius, string n)
        + calcArea()
        + calcPerimeter()
        + print()
    }

    class Square {
        - float x
        - float y
        + Square(float x0, float y0, float side, string n)
        + calcArea()
        + calcPerimeter()
        + print()
    }

    class Triangle {
        - float x1
        - float y1
        - float x2
        - float y2
        - float x3
        - float y3
        + Triangle(float x, float y, float side, string n)
        + Vertices()
        + Area()
        + Perimeter()
        + print()
    }

    Shape <|-- TwoDShape
    TwoDShape <|-- Circle
    TwoDShape <|-- Square
    TwoDShape <|-- Triangle
