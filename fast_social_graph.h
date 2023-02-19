#pragma once
#include "social_graph.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
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
        hashed_name[name.front()].insert(inserted_id);
        hashed_gender[gender].insert(inserted_id);
        hashed_city[city].insert(inserted_id);
        hashed_age[age].insert(inserted_id);
        return inserted_id;
    }

    void addFriend(size_t userId, size_t friendId) override {
        if (userId == friendId) {
            return;
        }
        // auto &current_user = users[userId];
        // if (current_user.friends.contains(friendId)) {
        //     return;
        // }
        users[userId].friends.insert(friendId);
        users[friendId].friends.insert(userId);
    }

    GetUserResponse getUser(size_t id) override {
        FastSocialGraphUser &user = users[id];
        GetUserResponse response{user.name, user.age, user.gender, user.city, user.friends};
        return response;
    }

    FindUsersResponse findUsers(size_t userId, // current user id
                                const NameFilter &nameFilter, const AgeFilter &ageFilter,
                                const GenderFilter &genderFilter, const CityFilter &cityFilter, SortBy sortBy,
                                size_t limit) override {
        std::unordered_set<size_t> filteredId;
        bool filter_used = false;

        if (nameFilter.active) {
            filter_used = true;
            const auto &temp = hashed_name[nameFilter.name.front()];
            const auto &name = nameFilter.name;
            for (const auto &id : temp) {
                if (users[id].name == name)
                    filteredId.insert(id);
            }
        }

        if (ageFilter.active) {
            filter_used = true;
            const auto begin = ageFilter.start + 1;
            const auto last = ageFilter.end;
            std::unordered_set<size_t> result;
            for (auto i = begin; i < last; ++i) {
                const auto &temp = hashed_age[i];
                for (const auto &id : temp) {
                    result.insert(id);
                }
            }
            if (filteredId.empty()) {
                filteredId.swap(result);
            } else {
                filteredId = intersection(filteredId, result);
            }
        }

        if (genderFilter.active) {
            filter_used = true;
            const auto &temp = hashed_gender[genderFilter.gender];
            if (filteredId.empty()) {
                filteredId = temp;
            } else {
                filteredId = intersection(filteredId, temp);
            }
        }

        if (cityFilter.active) {
            filter_used = true;
            const auto &cities = cityFilter.cities;
            std::unordered_set<size_t> result;
            for (const auto &city : cities) {
                for (const auto &id : city) {
                    result.insert(id);
                }
            }
            if (filteredId.empty()) {
                filteredId.swap(result);
            } else {
                filteredId = intersection(filteredId, result);
            }
        }

        std::vector<size_t> filteredUsers;
        if (!filter_used) {
            size_t size = sortBy == SortBy::DontSort ? std::min(limit, users.size()) : users.size();
            filteredUsers.resize(sortBy == SortBy::DontSort ? std::min(limit, users.size()) : users.size());
            std::iota(std::begin(filteredUsers), std::end(filteredUsers), 0);
        } else {
            filteredUsers.reserve(filteredId.size());
            for (const auto &id : filteredId) {
                filteredUsers.push_back(id);
            }
        }

        if (sortBy != SortBy::DontSort) {
            if (sortBy == SortBy::Age) {
                std::sort(filteredUsers.begin(), filteredUsers.end(),
                          [this](auto u1, auto u2) { return users[u1].age < users[u2].age; });
            } else if (sortBy == SortBy::Name) {
                std::sort(filteredUsers.begin(), filteredUsers.end(),
                          [this](auto u1, auto u2) { return users[u1].name < users[u2].name; });
            } else if (sortBy == SortBy::Relevance) {
                std::sort(filteredUsers.begin(), filteredUsers.end(), [this, userId](auto u1, auto u2) {
                    return countRelevance(userId, users[u1]) > countRelevance(userId, users[u2]);
                });
            }
            filteredUsers.resize(limit);
        }

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
    std::unordered_map<std::string::value_type, std::unordered_set<size_t>> hashed_name;
    std::unordered_map<Gender, std::unordered_set<size_t>> hashed_gender;
    std::unordered_map<std::string, std::unordered_set<size_t>> hashed_city;
    std::vector<std::unordered_set<size_t>> hashed_age;

    std::unordered_set<size_t> intersection(const std::unordered_set<size_t> &first,
                                            const std::unordered_set<size_t> &second) {
        std::unordered_set<size_t> result;
        for (const auto &id : first) {
            if (second.contains(id)) {
                result.insert(id);
            }
        }
        return result;
    }
};
