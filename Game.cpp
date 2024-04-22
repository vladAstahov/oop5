// Game.cpp
#include "Game.h"

// инициализируем пустой конструктор класса 
Game::Game() {}

// инициализируем пустой деструктор класса 
Game::~Game() {}

// инициализируем метод для получения названия игры
std::string Game::getTitle() const {
    return title;
}

// инициализируем метод для получения жанра игры
std::string Game::getGenre() const {
    return genre;
}

// инициализируем метод для получения платформы игры
std::string Game::getPlatform() const {
    return platform;
}

// инициализируем метод для получения года выпуска игры
int Game::getYear() const {
    return year;
}

// инициализируем метод для получения разработчика игры
std::string Game::getDeveloper() const {
    return developer;
}

// инициализируем метод для получения допустимого количесва игроков игры
int Game::getPlayers() const {
    return players;
}

// инициализируем метод для получения минимальной CPU игры
int Game::getMinCPU() const {
    return min_cpu;
}

// инициализируем метод для получения минимальной RAM игры
int Game::getMinRAM() const {
    return min_ram;
}

// инициализируем метод для получения минимальной HDD игры
int Game::getMinHDD() const {
    return min_hdd;
}

// инициализируем метод для считывания данных об игре из консоли
void Game::inputData() {
    std::cout << "введите название игры: ";
    std::cin.ignore();
    // считваем введенное значение из консоли
    std::getline(std::cin, title);

    std::cout << "введите жанр игры: ";
    // считваем введенное значение из консоли
    std::getline(std::cin, genre);

    std::cout << "введите платформу игры: ";
    // считваем введенное значение из консоли
    std::getline(std::cin, platform);

    std::cout << "введите год выпуска игры: ";
    // считваем введенное значение из консоли
    std::cin >> year;

    std::cout << "введите разработчика игры: ";
    std::cin.ignore();
    // считваем введенное значение из консоли
    std::getline(std::cin, developer);

    do {
        std::cout << "введите количество игроков (больше 0): ";
        std::cin >> players;
    } while (players <= 0);  // проверка на положительное количество игроков


    std::cout << "введите минимальную частоту CPU: ";
    // считваем введенное значение из консоли
    std::cin >> min_cpu;

    std::cout << "введите минимальный объем RAM: ";
    // считваем введенное значение из консоли
    std::cin >> min_ram;

    std::cout << "введите минимальный объем HDD: ";
    // считваем введенное значение из консоли
    std::cin >> min_hdd;
}

// инициализируем метод для считывания данных об игре из файла
void Game::readFromFile(std::ifstream& inputFile) {
    // считываем построчно значения из файла
    inputFile >> title >> genre >> platform >> year >> developer >> players >> min_cpu >> min_ram >> min_hdd;
}

// инициализируем метод для вывода данных об игре
void Game::display() const {
    std::cout << "Название: " << title << std::endl;
    std::cout << "Жанр: " << genre << std::endl;
    std::cout << "Платформа: " << platform << std::endl;
    std::cout << "Год выпуска: " << year << std::endl;
    std::cout << "Разработчик: " << developer << std::endl;
    std::cout << "Игроки: " << players << std::endl;
    std::cout << "Минимальный CPU: " << min_cpu << std::endl;
    std::cout << "Минимальный RAM: " << min_ram << std::endl;
    std::cout << "Минимальный HDD: " << min_hdd << std::endl;
    std::cout << "----------------------------------------" << std::endl;
}

// инициализируем методя для записи данных в файл
void Game::writeToFile(std::ofstream& outputFile) const {
    // записываем построчно значения в файл
    outputFile << title << "\n" << genre << "\n" << platform << "\n" << year << "\n" << developer
        << "\n" << players << "\n" << min_cpu << "\n" << min_ram << "\n" << min_hdd << "\n";
}

// инициализируем перезагрузку оператора вывода в консоль
std::ostream& operator<<(std::ostream& os, const Game& game) {
    // выводим данные в консоль
    os << "Название: " << game.title << "\n"
        << "Жанр: " << game.genre << "\n"
        << "Платформа: " << game.platform << "\n"
        << "Год выпуска: " << game.year << "\n"
        << "Разработчик: " << game.developer << "\n"
        << "Игроки: " << game.players << "\n"
        << "Минимальный CPU: " << game.min_cpu << "\n"
        << "Минимальный RAM: " << game.min_ram << "\n"
        << "Минимальный HDD: " << game.min_hdd << "\n"
        << "----------------------------------------\n";
    return os;
}

// инициализируем перезагрузку оператора считывания из консоли
std::istream& operator>>(std::istream& is, Game& game) {
    std::cout << "Введите название игры: ";
    is.ignore();
    // считваем введенное значение из консоли
    std::getline(is, game.title);

    std::cout << "Введите жанр игры: ";
    // считваем введенное значение из консоли
    std::getline(is, game.genre);

    std::cout << "Введите платформу игры: ";
    // считваем введенное значение из консоли
    std::getline(is, game.platform);

    std::cout << "Введите год выпуска игры: ";
    // считваем введенное значение из консоли
    is >> game.year;

    std::cout << "Введите разработчика игры: ";
    is.ignore();
    // считваем введенное значение из консоли
    std::getline(is, game.developer);

    do {
        std::cout << "Введите количество игроков (больше 0): ";
        is >> game.players;
    } while (game.players <= 0);  // проверка на положительное количество игроков

    std::cout << "Введите минимальную частоту CPU: ";
    // считваем введенное значение из консоли
    is >> game.min_cpu;

    std::cout << "Введите минимальный объем RAM: ";
    // считваем введенное значение из консоли
    is >> game.min_ram;

    std::cout << "Введите минимальный объем HDD: ";
    // считваем введенное значение из консоли
    is >> game.min_hdd;

    return is;
}

// инициализируем перезагрузку оператора записи в файл
std::ofstream& operator<<(std::ofstream& ofs, const Game& game) {
    ofs << game.title << "\n"
        << game.genre << "\n"
        << game.platform << "\n"
        << game.year << "\n"
        << game.developer << "\n"
        << game.players << "\n"
        << game.min_cpu << "\n"
        << game.min_ram << "\n"
        << game.min_hdd << "\n";
    return ofs;
}

// инициализируем перезагрузку оператора получения записи из файла
std::ifstream& operator>>(std::ifstream& ifs, Game& game) {
    ifs >> game.title >> game.genre >> game.platform >> game.year >>
        game.developer >> game.players >> game.min_cpu >> game.min_ram >> game.min_hdd;
    return ifs;
}

// инициализируем перезагрузку оператора сравнения двух игр
bool Game::operator==(const Game& other) const {
    return title == other.title &&
        genre == other.genre &&
        platform == other.platform &&
        year == other.year &&
        developer == other.developer &&
        players == other.players &&
        min_cpu == other.min_cpu &&
        min_ram == other.min_ram &&
        min_hdd == other.min_hdd;
}


