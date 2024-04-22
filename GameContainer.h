// GameContainer.h
#pragma once

#include "Game.h"
#include <vector>

class GameContainer {
public:
    // конструктор
    GameContainer();
    // диструктор
    ~GameContainer();

    // метод для добавления игры
    void addGame(const Game& game);
    // метод для удаления игры
    void removeGame(const std::string& title);
    // метод для загрузки игр с файла
    void loadFromFile(const std::string& filename);
    // метод для сохранения игр в файл
    void saveToFile(const std::string& filename);
    // метод для отображения игр
    void displayGames() const;
    // метод для поиска игр по жанру
    void searchGameByGenreAndRAM(const std::string& genre) const;
    // метод для поиска игры подходящих под ваш пк
    void displayCompatibleGames(int cpu, int ram, int hdd) const;
    // метод для добавления нового элемента в файл
    void appendToFile(const std::string& filename, const Game& newGame);
    // объявления перегрузки дружественной функции вывода в консоль
    friend std::ostream& operator<<(std::ostream& os, const GameContainer& container);
    // инициализируем метод для получения списка всех игр
    const std::vector<Game>& getGames() const {
        return games;
    }

private:
    std::vector<Game> games;
};