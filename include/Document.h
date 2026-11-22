#pragma once
#include <vector>
#include <memory>
#include <iostream>
#include "IShape.h"

class Document {
private:
    std::vector<std::unique_ptr<IShape>> shapes;

public:
    // Добавление фигуры 
    void addShape(std::unique_ptr<IShape> shape) {
        std::cout << "[Model] В документ добавлена фигура: " << shape->getType() << std::endl;
        shapes.push_back(std::move(shape)); // std::move передает владение
    }

    // Удаление фигуры по индексу
    void removeShape(size_t index) {
        if (index < shapes.size()) {
            std::cout << "[Model] Из документа удалена фигура: " << shapes[index]->getType() << std::endl;
            shapes.erase(shapes.begin() + index);
        } else {
            std::cerr << "[Model] Ошибка: неверный индекс фигуры!" << std::endl;
        }
    }

    // Отрисовка всех фигур (полиморфизм)
    void drawAll() const {
        if (shapes.empty()) {
            std::cout << "[Model] Документ пуст." << std::endl;
            return;
        }
        for (const auto& shape : shapes) {
            shape->draw(); // Вызывается метод конкретного класса (Circle или Rectangle)
        }
    }

    // Получить количество фигур
    size_t getShapeCount() const {
        return shapes.size();
    }
    
    // Очистить документ
    void clear() {
        shapes.clear();
    }
};