```mermaid
classDiagram
    class Shape {
        - string name
        - float r
        + Shape(string n="Shape", float rr=0)
        + void setName(string n)
        + string getName()
        + void setR(float rr)
        + float getR()
    }

    class TwoDShape {
        # float area
        # float perimeter
        + TwoDShape(string n="2D Shape", float rr=0)
        + float getArea()
        + float getPerimeter()
        + void print()*
    }

    class Circle {
        - float x_center
        - float y_center
        + Circle(float x, float y, float radius, string n="Circle")
        + void calcArea()
        + void calcPerimeter()
        + void print()
    }

    class Triangle {
        - float x1, y1
        - float x2, y2
        - float x3, y3
        + Triangle(float x, float y, float side, string n="Triangle")
        + void Vertices()
        + void Area()
        + void Perimeter()
        + void print()
    }

    class Square {
        - float x
        - float y
        + Square(float x0, float y0, float side, string n="Square")
        + void calcArea()
        + void calcPerimeter()
        + void print()
    }

    %% Удамшлын харилцаа
    TwoDShape --|> Shape
    Circle --|> TwoDShape
    Triangle --|> TwoDShape
    Square --|> TwoDShape
