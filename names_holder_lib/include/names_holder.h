#pragma once

#include <cstdlib>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stdexcept>


class NamesHolder {
private:
    std::unordered_map<std::size_t, std::string> items;
    std::unordered_set<std::string> existing_names;

public:

    NamesHolder() = default;

    std::size_t create();
    bool rename(std::size_t id, const std::string& new_name);
    void erase(std::size_t id);
    std::string get(std::size_t id) const;

    std::unordered_map<std::size_t, std::string>::const_iterator begin()  const;
    std::unordered_map<std::size_t, std::string>::const_iterator end()  const;
};
