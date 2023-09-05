//
// Created by smurf on 02.06.2023.
//

#ifndef PR_PASSWORD_H
#define PR_PASSWORD_H


#include <string>

class Password {
private:
    std::string name;
    std::string password;
    std::string category;
    std::string website;
    std::string login;

public:
    /**
     * @brief Konstruuje obiekt Password z podanymi parametrami.
     *
     * @param name Nazwa hasła.
     * @param password Wartość hasła.
     * @param category Kategoria hasła.
     * @param website Powiązana strona internetowa hasła.
     * @param login Powiązany login użytkownika hasła.
     */
    Password(const std::string& name, const std::string& password, const std::string& category,
             const std::string& website = "", const std::string& login = "");

    std::string getName() const;
    std::string getPassword() const;
    std::string getCategory() const;
    std::string getWebsite() const;
    std::string getLogin() const;

    void setPassword(const std::string& password);
    void setCategory(const std::string& category);
    void setWebsite(const std::string& website);
    void setLogin(const std::string& login);

    void print() const;

    void setName(std::string basicString);

    void setName(std::string &name);
};

#endif //PR_PASSWORD_H
