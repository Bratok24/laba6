#pragma once
#include "IShape.h"

class Rectangle : public IShape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    void draw() const override {
        std::cout << "[Model] Рисуется ПРЯМОУГОЛЬНИК размером " << width << "x" << height << std::endl;
    }

    std::string getType() const override {
        return "Rectangle";
    }

    std::string serialize() const override {
        return "Rectangle " + std::to_string(width) + " " + std::to_string(height);
    }
};