#pragma once
#include "IShape.h"

class MyRect : public IShape { 
private:
    double width;
    double height;

public:
    MyRect(double w, double h) : width(w), height(h) {} 

    void draw() const override {
        std::cout << "[Model] Рисуется ПРЯМОУГОЛЬНИК размером " << width << "x" << height << std::endl;
    }

    std::string getType() const override {
        return "MyRect"; // <--- И тут
    }

    std::string serialize() const override {
        return "MyRect " + std::to_string(width) + " " + std::to_string(height);
    }
};