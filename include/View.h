#pragma once
#include <iostream>
#include <string>
#include "Document.h"

class View {
public:
    // Вывод простого сообщения 
    void showMessage(const std::string& message) const {
        std::cout << "[View] " << message << std::endl;
    }

    // Вывод ошибки
    void showError(const std::string& error) const {
        std::cerr << "[View ERROR] " << error << std::endl;
    }

    // Отрисовка всего документа
    void renderDocument(const Document& doc) const {
        std::cout << "\n--- [View] Отрисовка документа ---" << std::endl;
        std::cout << "Количество фигур: " << doc.getShapeCount() << std::endl;
        doc.drawAll(); // Полиморфный вызов
        std::cout << "----------------------------------\n" << std::endl;
    }
};