#pragma once
#include "IShape.h"

class Circle : public IShape {
private:
    double radius;

public:
    // Конструктор
    Circle(double r) : radius(r) {}

    // Переопределяем методы базового класса 
    void draw() const override {
        std::cout << "[Model] Рисуется КРУГ с радиусом: " << radius << std::endl;
    }

    std::string getType() const override {
        return "Circle";
    }

    std::string serialize() const override {
        return "Circle " + std::to_string(radius);
    }
};