#pragma once

#include <algorithm>
#include <string>
#include <unordered_set>
#include <variant>
#include <vector>

// Задача:
// Необходимо написать структуру данных для социального графа, чтобы эффективно
// выполнять следущие запросы:
// - addUser: добавление пользователя
// - addFriend: добавление друга пользователю
// - getUser: получение пользователя по id
// - findUsers: поиск среди всех пользователей
// с заданными фильтрами (каждый фильтр может быть включен или выключен в
// зависимости от поля <active>)

// Поддерживаемые фильтры
// - NameFilter: оставляет только пользователей с именем <name>
// - AgeFilter: оставляет только пользователей с возрастом в диапазоне от
// <start> до <end>
// - GenderFilter: оставляет только пользователей с заданным полом
// - CityFilter: оставляет только пользователей живущих в одном из городов,
// указанных в <cities>

// Так же поддерживается несколько видов сортировок пользователей
// - SortBy_DontSort - сортировка не используется
// - SortBy_Name: - сортировка по имени в лексикографическом порядке
// - SortBy_Age: - сортировка по возрасту
// - SortBy_Relevance: - сортировка по количеству общих друзей

// Поле limit ограничивает количество записей в результате заданным числом.
// Например при limit = 10, в результате должно оказаться 10 верхних записей в
// порядке сортировки, подходящих под заданные фильтры. Если записей меньше, чем
// limit, то необходимо вывести все подходящие записи.

enum Gender {
    Male,
    Female,
};

struct GetUserResponse {
    std::string name;
    size_t age;
    Gender gender;
    std::string city;
    std::variant<std::unordered_set<size_t>, std::vector<size_t>> friends;
};

struct FindUsersResponse {
    std::vector<size_t> userIds;
};

struct NameFilter {
    bool active;
    std::string name;
};

struct AgeFilter {
    bool active;
    size_t start;
    size_t end;
};

struct GenderFilter {
    bool active;
    Gender gender;
};

struct CityFilter {
    bool active;
    std::vector<std::string> cities;
};

enum class SortBy {
    DontSort,
    Name,
    Age,
    Relevance,
};

class SocialGraph {
  public:
    virtual size_t addUser(const std::string &name, size_t age, Gender gender, const std::string &city) = 0;

    virtual void addFriend(size_t userId, size_t friendId) = 0;

    virtual GetUserResponse getUser(size_t id) = 0;

    virtual FindUsersResponse findUsers(size_t userId, // current user id
                                        const NameFilter &nameFilter, const AgeFilter &ageFilter,
                                        const GenderFilter &genderFilter, const CityFilter &cityFilter, SortBy sortBy,
                                        size_t limit) = 0;

    virtual size_t usersCount() const = 0;
};