#pragma once
#include "Document.h"
#include "View.h"
#include "Circle.h"
#include "Rectangle.h"
#include <memory>
#include <string>

class Controller {
private:
    Document& doc; // Ссылка на Модель 
    View& view;    // Ссылка на Представление

public:
    // Конструктор принимает ссылки на Модель и Представление
    Controller(Document& d, View& v) : doc(d), view(v) {}

    // Обработчики команд

    // 1. Создание нового документа
    void createNewDocument() {
        doc.clear(); // Очищаем старый
        view.showMessage("Создан новый документ.");
    }

    // 2. Импорт документа из файла (имитация)
    void importDocument(const std::string& filename) {
        // В реальности тут был бы парсинг файла и вызов doc.addShape()
        view.showMessage("Документ успешно импортирован из файла: " + filename);
    }

    // 3. Экспорт документа в файл (имитация)
    void exportDocument(const std::string& filename) {
        view.showMessage("Документ успешно экспортирован в файл: " + filename);
        // В реальности тут мы бы прошлись по всем фигурам и вызвали shape->serialize()
    }

    // 4. Создание графического примитива (Круг)
    void addCircle(double radius) {
        // Создаем умный указатель и передаем владение в Модель
        auto circle = std::make_unique<Circle>(radius);
        doc.addShape(std::move(circle));
        view.showMessage("Добавлен круг радиуса " + std::to_string(radius));
    }

    // 4. Создание графического примитива (Прямоугольник)
        void addRectangle(double w, double h) {
        auto rect = std::make_unique<MyRect>(w, h); // <--- Поменяли тут
        doc.addShape(std::move(rect));
        view.showMessage("Добавлен прямоугольник размером " + std::to_string(w) + "x" + std::to_string(h));
    }

    // 5. Удаление графического примитива по индексу
    void removePrimitive(size_t index) {
        doc.removeShape(index);
        view.showMessage("Фигура с индексом " + std::to_string(index) + " удалена.");
    }

    // Вспомогательный метод для отрисовки
    void render() {
        view.renderDocument(doc);
    }
};