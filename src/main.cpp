#include <iostream>
#include <memory>
#include <string>

#ifdef _WIN32
#include <windows.h>
#endif

#include "Document.h"
#include "View.h"
#include "Controller.h"

void onNewDocumentClicked(Controller& controller) {
    std::cout << "\n>>> [GUI] Нажата кнопка 'Новый документ'" << std::endl;
    controller.createNewDocument();
}

void onImportClicked(Controller& controller, const std::string& filename) {
    std::cout << "\n>>> [GUI] Нажата кнопка 'Импорт'" << std::endl;
    controller.importDocument(filename);
}

void onExportClicked(Controller& controller, const std::string& filename) {
    std::cout << "\n>>> [GUI] Нажата кнопка 'Экспорт'" << std::endl;
    controller.exportDocument(filename);
}

void onAddCircleClicked(Controller& controller, double radius) {
    std::cout << "\n>>> [GUI] Нажата кнопка 'Добавить круг'" << std::endl;
    controller.addCircle(radius);
}

void onAddRectangleClicked(Controller& controller, double w, double h) {
    std::cout << "\n>>> [GUI] Нажата кнопка 'Добавить прямоугольник'" << std::endl;
    controller.addRectangle(w, h);
}

void onRemoveShapeClicked(Controller& controller, size_t index) {
    std::cout << "\n>>> [GUI] Нажата кнопка 'Удалить фигуру'" << std::endl;
    controller.removePrimitive(index);
}

void onRenderClicked(Controller& controller) {
    std::cout << "\n>>> [GUI] Нажата кнопка 'Отрисовать'" << std::endl;
    controller.render();
}

int main() {
    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
        SetConsoleCP(CP_UTF8);
    #endif

    std::cout << "=== Запуск векторного редактора (MVC) ===" << std::endl;

    // 1. Создаю Модель 
    Document document;
    
    // 2. Создаю Представление 
    View view;
    
    // 3. Создаю Контроллер, связывая Модель и Представление
    Controller controller(document, view);

    //Демонстрация работы 

    // Создаю новый документ
    onNewDocumentClicked(controller);

    // Добавляю фигуры
    onAddCircleClicked(controller, 5.0);
    onAddRectangleClicked(controller, 10.0, 20.0);
    onAddCircleClicked(controller, 2.5);

    // Смотрю, что получилось
    onRenderClicked(controller);

    // Удаляю вторую фигуру (прямоугольник)
    onRemoveShapeClicked(controller, 1);

    // Смотрю результат после удаления
    onRenderClicked(controller);

    // Экспортирую в файл
    onExportClicked(controller, "my_drawing.txt");

    // Импортирую 
    onImportClicked(controller, "saved_drawing.txt");

    std::cout << "\n=== Работа программы завершена ===" << std::endl;
    return 0;
}