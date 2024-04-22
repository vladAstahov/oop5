#include "GameContainer.h"

int main() {
    // устанавливаем язык консоли на русский
    setlocale(LC_ALL, "Russian");

    // инициализируем экземпляр класса контейнера игр
    GameContainer gameContainer;

    // запускаем меню
    while (true) {
        std::cout << "меню:" << std::endl;
        std::cout << "1. вывести список игр" << std::endl;
        std::cout << "2. поиск игры с минимальными требованиями по RAM в указанном жанре" << std::endl;
        std::cout << "3. вывести игры, установимые на вашем компьютере" << std::endl;
        std::cout << "4. выйти" << std::endl;
        std::cout << "5. добавить новую игру" << std::endl;
        std::cout << "6. удалить игру" << std::endl;
        std::cout << "7. загрузить данные из файла" << std::endl;


        int choice;
        std::cout << "выберите действие (1/2/3/4/5/6/7): ";
        std::cin >> choice;

        if (choice == 1) {
            // вызываем метод класса GameContainer для загрузки данных из файла
            gameContainer.loadFromFile("games.txt");
            // используем перезагрузку оператора вывода в консоль класса GameContainer для вывода игр в консоль
            std::cout << "список игр:\n" << gameContainer;
        }
        else if (choice == 2) {
            // считываем из консоли искомый жанр
            std::string genre;
            std::cout << "введите жанр для поиска игры: ";
            std::cin >> genre;
            
            // вызываем метод класса GameContainer для поиска игр по жанру с минимальными RAM требования
            gameContainer.searchGameByGenreAndRAM(genre);
        }

        else if (choice == 3) {
            // считываем минимальные характеристики ПК
            int cpu, ram, hdd;
            std::cout << "введите характеристики вашего компьютера:" << std::endl;
            std::cout << "частота процессора: ";
            std::cin >> cpu;
            std::cout << "объем оперативной памяти: ";
            std::cin >> ram;
            std::cout << "объем места на диске: ";
            std::cin >> hdd;

            // вызываем метод класса GameContainer для поиска игр доступных при минимальных требованиях
            gameContainer.displayCompatibleGames(cpu, ram, hdd);
        }
        else if (choice == 4) {
            // прерываем меню => заканчиваем программу
            break;
        }

        else if (choice == 5) {
            // инициализируем экземпляр класса Game
            Game newGame;
            // используем перегрузку оперератора считываения из консоли класса Game для получения данных новой игры
            std::cin >> newGame;
            // вызываем метод класса GameContainer для добавления игры в список
            gameContainer.addGame(newGame);
            // вызываем метод класса GameContainer для добавления игры в файл
            gameContainer.appendToFile("games.txt", newGame);
            // вызываем метод класса GameContainer для сохранения текущего состояния в файл
            gameContainer.saveToFile("games.txt");
            std::cout << "игра добавлена." << std::endl;
        }

        else if (choice == 6) {
            // считываем названия удаляемой игры
            std::string titleToRemove;
            std::cout << "введите название игры для удаления: ";
            std::cin >> titleToRemove;
            // вызываем метод класса GameContainer для удаления игры
            gameContainer.removeGame(titleToRemove);
            std::cout << "игра удалена." << std::endl;
        }

        else if (choice == 7) {
            // вызываем метод класса GameContainer для загрузки данных из файла
            gameContainer.loadFromFile("games.txt");
            std::cout << "данные загружены из файла." << std::endl;
        }

        else {
            // обрабатываем некорректный ввод команды 
            std::cout << "Неверный выбор. ѕожалуйста, выберите (1/2/3/4/5/6/7)" << std::endl;
        }
    }


    gameContainer.saveToFile("games.txt");

    return 0;
}
