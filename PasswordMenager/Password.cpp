//
// Created by smurf on 02.06.2023.
//

#include "Password.h"



#include "Password.h"
#include <iostream>

/**
    * @brief Konstruuje obiekt Password z podanymi parametrami.
    *
    * @param name Nazwa hasła.
    * @param password Wartość hasła.
    * @param category Kategoria hasła.
    * @param website Powiązana strona internetowa hasła.
    * @param login Powiązany login użytkownika hasła.
    */
Password::Password(const std::string& name, const std::string& password, const std::string& category,
                   const std::string& website, const std::string& login)
        : name(name), password(password), category(category), website(website), login(login) {}
/**
     * @brief Pobiera nazwę hasła.
     *
     * @return Nazwa hasła.
     */
std::string Password::getName() const {
    return name;
}
/**
     * @brief Pobiera wartość hasła.
     *
     * @return Wartość hasła.
     */
std::string Password::getPassword() const {
    return password;
}
/**
     * @brief Pobiera kategorię hasła.
     *
     * @return Kategoria hasła.
     */
std::string Password::getCategory() const {
    return category;
}
/**
   * @brief Pobiera powiązaną stronę internetową hasła.
   *
   * @return Powiązana strona internetowa hasła.
   */
std::string Password::getWebsite() const {
    return website;
}
/**
    * @brief Pobiera powiązany login użytkownika hasła.
    *
    * @return Powiązany login użytkownika hasła.
    */
std::string Password::getLogin() const {
    return login;
}
/**
     * @brief Ustawia wartość hasła.
     *
     * @param password Nowa wartość hasła.
     */
void Password::setPassword(const std::string& password) {
    this->password = password;
}
/**
     * @brief Ustawia kategorię hasła.
     *
     * @param category Nowa kategoria hasła.
     */
void Password::setCategory(const std::string& category) {
    this->category = category;
}
/**
     * @brief Ustawia powiązaną stronę internetową hasła.
     *
     * @param website Nowa powiązana strona internetowa hasła.
     */
void Password::setWebsite(const std::string& website) {
    this->website = website;
}
/**
    * @brief Ustawia powiązany login użytkownika hasła.
    *
    * @param login Nowy powiązany login użytkownika hasła.
    */
void Password::setLogin(const std::string& login) {
    this->login = login;
}
/**
     * @brief Wypisuje informacje o haśle na standardowe wyjście.
     */
void Password::print() const {
    std::cout << "Nazwa: " << name << std::endl;
    std::cout << "Haslo: " << password << std::endl;
    std::cout << "Kategoria: " << category << std::endl;
    std::cout << "Strona WWW: " << website << std::endl;
    std::cout << "Login: " << login << std::endl;
}


