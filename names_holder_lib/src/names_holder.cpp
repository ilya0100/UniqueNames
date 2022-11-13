#include "names_holder.h"


std::size_t NamesHolder::create() {
    std::size_t id = std::rand();
    while (items.contains(id)) {
        id = std::rand();
    }

    std::string name = "Object";
    name.append(std::to_string(id));

    existing_names.insert(name);
    items[id] = name;

    return id;
}

bool NamesHolder::rename(std::size_t id, const std::string& new_name) {
    if (existing_names.find(new_name) != existing_names.end())
        return false;

    auto item_it = items.find(id);
    if (item_it == items.end())
        throw std::out_of_range("id not found");
    
    items[id] = new_name;
    existing_names.insert(new_name);
    return true;
}

void NamesHolder::erase(std::size_t id) {
    auto item_it = items.find(id);
    if (item_it == items.end())
        throw std::out_of_range("id not found");

    existing_names.erase((*item_it).second);
    items.erase(id);
}

std::string NamesHolder::get(std::size_t id) const {
    auto item_it = items.find(id);
    if (item_it == items.end())
        throw std::out_of_range("id not found");
    
    return (*item_it).second;
}

std::unordered_map<std::size_t, std::string>::const_iterator NamesHolder::begin() const {
    return items.begin();
}

std::unordered_map<std::size_t, std::string>::const_iterator NamesHolder::end() const {
    return items.end();
}
