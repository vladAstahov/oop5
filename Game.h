// Game.h
#pragma once

#include <iostream>
#include <fstream>
#include <string>

class Game {
private:
    std::string title;
    std::string genre;
    std::string platform;
    int year;
    std::string developer;
    int players;
    int min_cpu;
    int min_ram;
    int min_hdd;

public:
    Game();
    ~Game();

    std::string getTitle() const;
    std::string getGenre() const;
    std::string getPlatform() const;
    int getYear() const;
    std::string getDeveloper() const;
    int getPlayers() const;
    int getMinCPU() const;
    int getMinRAM() const;
    int getMinHDD() const;

    void inputData();
    void readFromFile(std::ifstream& inputFile);
    void display() const;
    void writeToFile(std::ofstream& outputFile) const;
    bool operator==(const Game& other) const;
    // объявления перегрузки дружественной функции вывода в консоль
    friend std::ostream& operator<<(std::ostream& os, const Game& game);
    // объявления перегрузки дружественной функции считывания из консоли
    friend std::istream& operator>>(std::istream& is, Game& game);
    // объявления перегрузки дружественной функции записи в файл
    friend std::ofstream& operator<<(std::ofstream& ofs, const Game& game);
    // объявления перегрузки дружественной функции считываения из файла
    friend std::ifstream& operator>>(std::ifstream& ifs, Game& game);
};