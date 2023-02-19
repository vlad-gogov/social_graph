#pragma once
#include "social_graph.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <unordered_map>
#include <unordered_set>

struct FastSocialGraphUser {
    std::string name;
    size_t age;
    Gender gender;
    std::string city;
    std::unordered_set<size_t> friends;
};

constexpr size_t MAX_AGE = 80;
// constexpr size_t STEP_AGE = 10;

class FastSocialGraph : public SocialGraph {
  public:
    FastSocialGraph() {
        hashed_age.resize(MAX_AGE);
        // hashed_age.resize(MAX_AGE / STEP_AGE);
    }

    FastSocialGraph(const FastSocialGraph &) = default;
    FastSocialGraph(FastSocialGraph &&) = default;

    ~FastSocialGraph() = default;

    size_t addUser(const std::string &name, size_t age, Gender gender, const std::string &city) override {
        FastSocialGraphUser user{name, age, gender, city, {}};
        users.push_back(user);
        size_t inserted_id = users.size() - 1u;
        hashed_name[name.front()].push_back(inserted_id);
        hashed_gender[gender].push_back(inserted_id);
        hashed_city[city].push_back(inserted_id);
        hashed_age[age].push_back(inserted_id);
        return inserted_id;
    }

    void addFriend(size_t userId, size_t friendId) override {
        if (userId == friendId) {
            return;
        }
        auto &current_user = users[userId];
        if (!current_user.friends.contains(friendId)) {
            return;
        }
        current_user.friends.insert(friendId);
        users[friendId].friends.insert(userId);
    }

    GetUserResponse getUser(size_t id) override {
        FastSocialGraphUser user = users[id];
        GetUserResponse response{user.name, user.age, user.gender, user.city, user.friends};
        return response;
    }

    FindUsersResponse findUsers(size_t userId, // current user id
                                const NameFilter &nameFilter, const AgeFilter &ageFilter,
                                const GenderFilter &genderFilter, const CityFilter &cityFilter, SortBy sortBy,
                                size_t limit) override {
        std::vector<size_t> filteredUsers;
        bool filter_use = false;

        if (nameFilter.active) {
            filter_use = true;
            const auto &temp = hashed_name[nameFilter.name.front()];
            const auto &name = nameFilter.name;
            for (size_t id : temp) {
                if (users[id].name == name)
                    filteredUsers.push_back(id);
            }
        }

        if (ageFilter.active) {
            filter_use = true;
            const auto begin = ageFilter.start + 1;
            const auto last = ageFilter.end;
            std::vector<size_t> result;
            for (auto i = begin; i < last; ++i) {
                result.insert(result.end(), hashed_age[i].begin(), hashed_age[i].end());
            }
            std::sort(result.begin(), result.end());
            if (filteredUsers.empty()) {
                filteredUsers = result;
            } else {
                std::vector<size_t> temp;
                std::set_intersection(filteredUsers.begin(), filteredUsers.end(), result.begin(), result.end(),
                                      std::back_inserter(temp));
                filteredUsers.swap(temp);
            }
        }

        if (genderFilter.active) {
            filter_use = true;
            const auto &temp = hashed_gender[genderFilter.gender];
            if (filteredUsers.empty()) {
                filteredUsers = temp;
            } else {
                std::vector<size_t> result;
                std::set_intersection(filteredUsers.begin(), filteredUsers.end(), temp.begin(), temp.end(),
                                      std::back_inserter(result));
                filteredUsers.swap(result);
            }
        }

        if (cityFilter.active) {
            filter_use = true;
            const auto &cities = cityFilter.cities;
            std::vector<size_t> result;
            for (const auto &city : cities) {
                result.insert(result.end(), hashed_city[city].begin(), hashed_city[city].end());
            }
            std::sort(result.begin(), result.end());
            if (filteredUsers.empty()) {
                filteredUsers = result;
            } else {
                std::vector<size_t> temp;
                std::set_intersection(filteredUsers.begin(), filteredUsers.end(), result.begin(), result.end(),
                                      std::back_inserter(temp));
                filteredUsers.swap(temp);
            }
        }
        if (!filter_use) {
            size_t size = users.size();
            filteredUsers.reserve(size);
            for (size_t i = 0; i < size; ++i)
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

    size_t countRelevance(size_t userId, const FastSocialGraphUser &user) {
        size_t relevance = 0;
        auto &friends = users[userId].friends;
        for (size_t f : user.friends) {
            if (friends.contains(f)) {
                ++relevance;
            }
        }
        return relevance;
    }

  private:
    std::vector<FastSocialGraphUser> users;
    std::unordered_map<std::string::value_type, std::vector<size_t>> hashed_name;
    std::unordered_map<Gender, std::vector<size_t>> hashed_gender;
    std::unordered_map<std::string, std::vector<size_t>> hashed_city;
    std::vector<std::vector<size_t>> hashed_age;
};
