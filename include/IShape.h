#pragma once
#include <string>
#include <iostream>

// Абстрактный базовый класс для всех фигур.
// Благодаря ему мы сможем хранить в одном векторе и круги, и квадраты.
class IShape {
public:
    virtual ~IShape() = default; // Виртуальный деструктор обязателен для полиморфизма

    virtual void draw() const = 0;   
    virtual std::string getType() const = 0; 
    
    // Виртуальный метод для сохранения в файл 
    virtual std::string serialize() const = 0; 
};