//
// Created by smurf on 02.06.2023.
//

#ifndef PR_PASSWORDMANAGER_H
#define PR_PASSWORDMANAGER_H


#include <vector>
#include "Password.h"
/**
 * @class PasswordManager
 * @brief Klasa do zarządzania hasłami.
 *
 * Klasa PasswordManager umożliwia wczytywanie, zapisywanie, dodawanie, edycję,
 * usuwanie, sortowanie i wyszukiwanie haseł. Dodatkowo oferuje funkcje do
 * szyfrowania i deszyfrowania haseł oraz obsługę kategorii.
 */
class PasswordManager {
private:
    std::vector<Password> passwords;
    std::vector<std::string> categories;

public:
    void loadPasswords(const std::string& filename);
    void savePasswords(const std::string& filename) const;

    void searchPasswords() const;
    void sortPasswords() const;
    void addPassword();
    void editPassword();
    void deletePassword();

    void addCategory();
    void deleteCategory();


//    std::string encryptPassword(const std::string &password) const;
//
//    std::string decryptPassword(const std::string &encryptedPassword) const;
//
//    void encryptAndSavePasswords(const std::string &filename) const;
//
//    void decryptAndSavePasswords(const std::string &filename) const;
//
//    void decryptPasswords();

    void decryptAndSavePasswords() const;

    void encryptAndSavePasswords() const;

    std::string encryptPassword(const std::string &password) const;

    std::string decryptPassword(const std::string &encryptedPassword) const;
};


#endif //PR_PASSWORDMANAGER_H
