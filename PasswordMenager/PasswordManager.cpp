//
// Created by smurf on 02.06.2023.
//

#include "PasswordManager.h"


#include "PasswordManager.h"
#include <iostream>
#include <fstream>
#include <algorithm>
/**
 * @class PasswordManager
 * @brief Klasa do zarządzania hasłami.
 *
 * Klasa PasswordManager umożliwia wczytywanie, zapisywanie, dodawanie, edycję,
 * usuwanie, sortowanie i wyszukiwanie haseł. Dodatkowo oferuje funkcje do
 * szyfrowania i deszyfrowania haseł oraz obsługę kategorii.
 */





/**
 * @brief Wczytuje hasła z pliku do wektora passwords.
 *
 * @param filename Nazwa pliku, z którego mają zostać wczytane hasła.
 */
void PasswordManager::loadPasswords(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        passwords.clear();
        std::string line;
        while (std::getline(file, line)) {
            // Odczytaj dane z linii i utwórz obiekt Password
            // Dodaj obiekt Password do wektora passwords
            std::string name, password, category, website, login;
            // Przykładowy format danych w pliku: Nazwa:Hasło:Kategoria:Strona WWW:Login
            size_t pos1 = line.find(':');
            if (pos1 != std::string::npos) {
                name = line.substr(0, pos1);
                size_t pos2 = line.find(':', pos1 + 1);
                if (pos2 != std::string::npos) {
                    password = line.substr(pos1 + 1, pos2 - pos1 - 1);
                    size_t pos3 = line.find(':', pos2 + 1);
                    if (pos3 != std::string::npos) {
                        category = line.substr(pos2 + 1, pos3 - pos2 - 1);
                        size_t pos4 = line.find(':', pos3 + 1);
                        if (pos4 != std::string::npos) {
                            website = line.substr(pos3 + 1, pos4 - pos3 - 1);
                            login = line.substr(pos4 + 1);
                            Password newPassword(name, password, category, website, login);
                            passwords.push_back(newPassword);
                        }
                    }
                }
            }
        }
        file.close();
        std::cout << "Pomyslnie zaladowano hasla z pliku: " << filename << std::endl;
    } else {
        std::cout << "Nie mozna otworzyc pliku: " << filename << std::endl;
    }
}

/**
 * @brief Zapisuje hasła z wektora passwords do pliku.
 *
 * @param filename Nazwa pliku, do którego mają zostać zapisane hasła.
 */
void PasswordManager::savePasswords(const std::string& filename) const {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const Password& password : passwords) {
            // Zapisz informacje o haśle do pliku w zaszyfrowanej formie
            file << password.getName() << ':' << password.getPassword() << ':' << password.getCategory() << ':' << password.getWebsite() << ':' << password.getLogin() << std::endl;
        }
        file.close();
        std::cout << "Pomyslnie zapisano hasla do pliku: " << filename << std::endl;
    } else {
        std::cout << "Nie mozna otworzyc pliku: " << filename << std::endl;
    }
}
/**
 * @brief Dodaje nowe hasło do wektora passwords.
 */
void PasswordManager::addPassword() {
    std::string name;
    std::string password;
    std::string category;
    std::string website;
    std::string login;

    std::cout << "Podaj nazwe hasla: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    std::cout << "Podaj haslo: ";
    std::getline(std::cin, password);

    std::cout << "Podaj kategorie: ";
    std::getline(std::cin, category);

    std::cout << "Podaj strone WWW: ";
    std::getline(std::cin, website);

    std::cout << "Podaj login: ";
    std::getline(std::cin, login);

    Password newPassword(name, password, category, website, login);
    passwords.push_back(newPassword);

    std::cout << "Dodano nowe haslo." << std::endl;
}
/**
    * @brief Edytuje istniejące hasło.
    */
void PasswordManager::editPassword() {
    std::string name;
    std::cout << "Podaj nazwe hasla do edycji: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    auto it = std::find_if(passwords.begin(), passwords.end(), [&name](const Password& password) {
        return password.getName() == name;
    });

    if (it != passwords.end()) {
        std::string newPassword;
        std::string newCategory;
        std::string newWebsite;
        std::string newLogin;

        std::cout << "Podaj nowe haslo: ";
        std::getline(std::cin, newPassword);

        std::cout << "Podaj nowa kategorie: ";
        std::getline(std::cin, newCategory);

        std::cout << "Podaj nową strone WWW: ";
        std::getline(std::cin, newWebsite);

        std::cout << "Podaj nowy login: ";
        std::getline(std::cin, newLogin);

        it->setPassword(newPassword);
        it->setCategory(newCategory);
        it->setWebsite(newWebsite);
        it->setLogin(newLogin);

        std::cout << "Haslo zostalo zaktualizowane." << std::endl;
    } else {
        std::cout << "Nie znaleziono hasla o podanej nazwie." << std::endl;
    }
}
/**
     * @brief Usuwa hasło.
     */
void PasswordManager::deletePassword() {
    std::string name;
    std::cout << "Podaj nazwe hasla do usuniecia: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    auto it = std::find_if(passwords.begin(), passwords.end(), [&name](const Password& password) {
        return password.getName() == name;
    });

    if (it != passwords.end()) {
        passwords.erase(it);
        std::cout << "Haslo zostalo usuniete." << std::endl;
    } else {
        std::cout << "Nie znaleziono hasla o podanej nazwie." << std::endl;
    }
}
/**
     * @brief Sortuje hasła.
     */
void PasswordManager::sortPasswords() const {
    int choice;
    std::cout << "Wybierz kryterium sortowania: " << std::endl;
    std::cout << "1. Nazwa" << std::endl;
    std::cout << "2. Kategoria" << std::endl;
    std::cout << "3. Strona WWW" << std::endl;
    std::cout << "4. Login" << std::endl;
    std::cin >> choice;

    std::vector<Password> sortedPasswords = passwords;

    switch (choice) {
        case 1:
            std::sort(sortedPasswords.begin(), sortedPasswords.end(), [](const Password& a, const Password& b) {
                return a.getName() < b.getName();
            });
            break;
        case 2:
            std::sort(sortedPasswords.begin(), sortedPasswords.end(), [](const Password& a, const Password& b) {
                return a.getCategory() < b.getCategory();
            });
            break;
        case 3:
            std::sort(sortedPasswords.begin(), sortedPasswords.end(), [](const Password& a, const Password& b) {
                return a.getWebsite() < b.getWebsite();
            });
            break;
        case 4:
            std::sort(sortedPasswords.begin(), sortedPasswords.end(), [](const Password& a, const Password& b) {
                return a.getLogin() < b.getLogin();
            });
            break;
        default:
            std::cout << "Nieprawidłowy wybór." << std::endl;
            return;
    }

    std::cout << "Posortowane hasla:" << std::endl;
    for (const Password& password : sortedPasswords) {
        std::cout << "Nazwa: " << password.getName() << std::endl;
        std::cout << "Kategoria: " << password.getCategory() << std::endl;
        std::cout << "Strona WWW: " << password.getWebsite() << std::endl;
        std::cout << "Login: " << password.getLogin() << std::endl;
        std::cout << "-----------------------" << std::endl;
    }
}
/**
     * @brief Wyszukuje hasła na podstawie podanego parametru.
     */
void PasswordManager::searchPasswords() const {
    std::string searchParam;
    std::cout << "Podaj parametr wyszukiwania: ";
    std::cin.ignore();
    std::getline(std::cin, searchParam);

    std::vector<Password> matchingPasswords;
    for (const Password& password : passwords) {
        if (password.getName().find(searchParam) != std::string::npos ||
            password.getCategory().find(searchParam) != std::string::npos ||
            password.getWebsite().find(searchParam) != std::string::npos ||
            password.getLogin().find(searchParam) != std::string::npos) {
            matchingPasswords.push_back(password);
        }
    }

    if (matchingPasswords.empty()) {
        std::cout << "Nie znaleziono pasujących hasel." << std::endl;
    } else {
        std::cout << "Pasujace hasla:" << std::endl;
        for (const Password& password : matchingPasswords) {
            std::cout << "Nazwa: " << password.getName() << std::endl;
            std::cout << "Kategoria: " << password.getCategory() << std::endl;
            std::cout << "Strona WWW: " << password.getWebsite() << std::endl;
            std::cout << "Login: " << password.getLogin() << std::endl;
            std::cout << "-----------------------" << std::endl;
        }
    }
}
/**
    * @brief Dodaje nową kategorię.
    */
void PasswordManager::addCategory() {
    std::string category;
    std::cout << "Podaj nazwe nowej kategorii: ";
    std::cin.ignore();
    std::getline(std::cin, category);

    categories.push_back(category);

    std::cout << "Dodano nowa kategorie." << std::endl;
}
/**
     * @brief Usuwa kategorię wraz z powiązanymi hasłami.
     */
void PasswordManager::deleteCategory() {
    std::string category;
    std::cout << "Podaj nazwe kategorii do usuniecia: ";
    std::cin.ignore();
    std::getline(std::cin, category);

    auto it = std::find(categories.begin(), categories.end(), category);

    if (it != categories.end()) {
        categories.erase(it);
        // Usuń hasła związane z tą kategorią
        passwords.erase(std::remove_if(passwords.begin(), passwords.end(), [&category](const Password& password) {
            return password.getCategory() == category;
        }), passwords.end());

        std::cout << "Kategoria zostala usunieta." << std::endl;
    } else {
        std::cout << "Nie znaleziono kategorii o podanej nazwie." << std::endl;
    }
}
/**
     * @brief Szyfruje hasło.
     * @param password Hasło do zaszyfrowania.
     * @return Zaszyfrowane hasło.
     */
std::string PasswordManager::encryptPassword(const std::string& password) const {
    std::string encryptedPassword = password;
    for (char& c : encryptedPassword) {
        if (isalpha(c)) {
            c = static_cast<char>(c + 2);
        } else if (isdigit(c)) {
            int digit = c - '0';
            int encryptedDigit = (digit + 5) % 10;
            c = static_cast<char>(encryptedDigit + '0');
        }
    }
    return encryptedPassword;
}
/**
     * @brief Deszyfruje hasło.
     * @param encryptedPassword Zaszyfrowane hasło.
     * @return Odszyfrowane hasło.
     */
std::string PasswordManager::decryptPassword(const std::string& encryptedPassword) const {
    std::string decryptedPassword = encryptedPassword;
    for (char& c : decryptedPassword) {
        if (isalpha(c)) {
            c = static_cast<char>(c - 2);
        } else if (isdigit(c)) {
            int digit = c - '0';
            int decryptedDigit = (digit + 5) % 10;
            c = static_cast<char>(decryptedDigit + '0');
        }
    }
    return decryptedPassword;
}
/**
   * @brief Szyfruje hasła i zapisuje je do pliku.
   */
void PasswordManager::encryptAndSavePasswords() const {
    std::string encryptedFilename;
    std::cout << "Podaj nazwę pliku, do ktorego chcesz zapisac zaszyfrowane hasla: ";
    std::cin >> encryptedFilename;

    std::ofstream file(encryptedFilename);
    if (file.is_open()) {
        for (const Password& password : passwords) {
            std::string encryptedPassword = encryptPassword(password.getPassword());
            // Zapisz informacje o haśle do pliku w zaszyfrowanej formie
            file << password.getName() << "," << encryptedPassword << "," << password.getCategory() << "," << password.getWebsite() << "," << password.getLogin() << "\n";
        }
        file.close();
        std::cout << "Pomyslnie zapisano zaszyfrowane hasla do pliku: " << encryptedFilename << std::endl;
    } else {
        std::cout << "Nie mozna otworzyć pliku: " << encryptedFilename << std::endl;
    }
}
/**
     * @brief Deszyfruje hasła i zapisuje je do pliku.
     */
void PasswordManager::decryptAndSavePasswords() const {
    std::string decryptedFilename;
    std::cout << "Podaj nazwe pliku, do ktorego chcesz zapisac odszyfrowane hasla: ";
    std::cin >> decryptedFilename;

    std::ofstream file(decryptedFilename);
    if (file.is_open()) {
        for (const Password& password : passwords) {
            std::string decryptedPassword = decryptPassword(password.getPassword());
            // Zapisz informacje o haśle do pliku w odszyfrowanej formie
            file << password.getName() << "," << decryptedPassword << "," << password.getCategory() << "," << password.getWebsite() << "," << password.getLogin() << "\n";
        }
        file.close();
        std::cout << "Pomyslnie zapisano odszyfrowane hasla do pliku: " << decryptedFilename << std::endl;
    } else {
        std::cout << "Nie mozna otworzyc pliku: " << decryptedFilename << std::endl;
    }
}




