#pragma once
#include "social_graph.h"

struct DummySocialGraphUser {
    std::string name;
    size_t age;
    Gender gender;
    std::string city;
    std::vector<size_t> friends;
};

struct DummySocialGraph : public SocialGraph {
    size_t addUser(const std::string &name, size_t age, Gender gender, const std::string &city) override {
        DummySocialGraphUser user{name, age, gender, city, {}};
        users.push_back(user);
        return static_cast<size_t>(users.size()) - 1;
    }

    void addFriend(size_t userId, size_t friendId) override {
        if (std::find(users[userId].friends.begin(), users[userId].friends.end(), friendId) !=
            users[userId].friends.end()) {
            return;
        }

        if (userId == friendId) {
            return;
        }

        users[userId].friends.push_back(friendId);
        users[friendId].friends.push_back(userId);
    }

    GetUserResponse getUser(size_t id) override {
        DummySocialGraphUser user = users[id];
        GetUserResponse response{user.name, user.age, user.gender, user.city, user.friends};
        return response;
    }

    FindUsersResponse findUsers(size_t userId, // current user id
                                const NameFilter &nameFilter, const AgeFilter &ageFilter,
                                const GenderFilter &genderFilter, const CityFilter &cityFilter, SortBy sortBy,
                                size_t limit) override {

        std::vector<size_t> filteredUsers;

        for (size_t i = 0; i < users.size(); i++) {
            DummySocialGraphUser user = users[i];

            if (nameFilter.active && user.name != nameFilter.name) {
                continue;
            }

            if (ageFilter.active && (user.age < ageFilter.start || user.age > ageFilter.end)) {
                continue;
            }

            if (genderFilter.active && (user.gender != genderFilter.gender)) {
                continue;
            }

            if (cityFilter.active) {
                if (std::find(cityFilter.cities.begin(), cityFilter.cities.end(), user.city) ==
                    cityFilter.cities.end()) {
                    continue;
                }
            }

            filteredUsers.push_back(i);
        }

        if (sortBy != SortBy_DontSort) {
            std::sort(filteredUsers.begin(), filteredUsers.end(), [this, userId, sortBy](auto u1, auto u2) {
                auto user1 = users[u1];
                auto user2 = users[u2];

                if (sortBy == SortBy_Age) {
                    return user1.age < user2.age;
                }

                if (sortBy == SortBy_Name) {
                    return user1.name < user2.name;
                }

                if (sortBy == SortBy_Relevance) {
                    return countRelevance(userId, user1) > countRelevance(userId, user2);
                }

                return false;
            });
        }

        filteredUsers.resize(limit);

        FindUsersResponse response;
        response.userIds = filteredUsers;

        return response;
    }

    size_t usersCount() const override {
        return static_cast<size_t>(users.size());
    }

    size_t countRelevance(size_t userId, const DummySocialGraphUser &user) {
        size_t relevance = 0;
        for (size_t f : user.friends) {
            for (size_t uf : users[userId].friends) {
                if (f == uf) {
                    relevance++;
                }
            }
        }
        return relevance / 2;
    }

    std::vector<DummySocialGraphUser> users;
};