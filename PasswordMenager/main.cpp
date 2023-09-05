
/**
 * @file main.cpp
 *
 * @brief Plik zawiera funkcję `main` dla aplikacji Password Manager.
 */

#include <iostream>
#include <string>
#include "PasswordManager.h"

/**
 * @brief Główna funkcja programu.
 *
 * @return Kod zakończenia.
 */
int main() {
    PasswordManager passwordManager;
    std::string filename;

    std::cout << "Podaj nazwe pliku z haslami: ";
    std::cin >> filename;

    passwordManager.loadPasswords(filename);

    int choice;
    do {
        std::cout << "------------------------\n";
        std::cout << "Menu:\n";
        std::cout << "1. Wyszukaj hasla\n";
        std::cout << "2. Posortuj hasla\n";
        std::cout << "3. Dodaj haslo\n";
        std::cout << "4. Edytuj haslo\n";
        std::cout << "5. Usun haslo\n";
        std::cout << "6. Dodaj kategorie\n";
        std::cout << "7. Usun kategorie\n";
        std::cout << "8. Zaszyfruj haslo\n";
        std::cout << "9. Odszyfruj haslo\n";
        std::cout << "0. Wyjdz\n";
        std::cout << "Wybierz opcje: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                passwordManager.searchPasswords();
                break;
            case 2:
                passwordManager.sortPasswords();
                break;
            case 3:
                passwordManager.addPassword();
                break;
            case 4:
                passwordManager.editPassword();
                break;
            case 5:
                passwordManager.deletePassword();
                break;
            case 6:
                passwordManager.addCategory();
                break;
            case 7:
                passwordManager.deleteCategory();
                break;
            case 8:
                passwordManager.encryptAndSavePasswords();
                break;
            case 9:
                passwordManager.decryptAndSavePasswords();
                break;
            case 0:
                std::cout << "Zapisywanie hasel i wyjscie z programu...\n";
                passwordManager.savePasswords(filename);
                break;

            default:
                std::cout << "Nieprawidlowa opcja. Sprobuj ponownie.\n";
        }
    } while (choice != 0);

    return 0;
}
