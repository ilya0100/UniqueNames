#include "names_holder.h"

#include <vector>
#include <gtest/gtest.h>


TEST(NamesHolderTest, Create) {
    NamesHolder names;

    std::size_t first_id = names.create();
    ASSERT_TRUE(first_id != 0);

    std::size_t second_id = names.create();
    ASSERT_NE(first_id, second_id);
}

TEST(NamesHolderTest, Get) {
    NamesHolder names;
    std::size_t id = names.create();
    
    std::string name = "Object" + std::to_string(id);

    ASSERT_EQ(name, names.get(id));
}

TEST(NamesHolderTest, Rename) {
    NamesHolder names;
    std::size_t id = names.create();
    
    std::string new_name = "new_name";
    names.rename(id, new_name);

    ASSERT_EQ(new_name, names.get(id));
}

TEST(NamesHolderTest, RenameExisting) {
    NamesHolder names;
    std::size_t id = names.create();
    std::string name = names.get(id);
    
    ASSERT_FALSE(names.rename(id, name));
}

TEST(NamesHolderTest, Erase) {
    NamesHolder names;
    int size = 5;
    std::vector<std::size_t> id_list;
    for (int i = 0; i < size; ++i) {
        id_list.push_back(names.create());
    }

    names.erase(id_list[0]);
    names.erase(id_list[size - 1]);

    EXPECT_THROW(names.get(id_list[0]), std::out_of_range);
    EXPECT_THROW(names.get(id_list[size - 1]), std::out_of_range);
}

TEST(NamesHolderTest, IdNotValid) {
    NamesHolder names;
    std::size_t id = 55;

    EXPECT_THROW(names.rename(id, "abc"), std::out_of_range);
    EXPECT_THROW(names.erase(id), std::out_of_range);
    EXPECT_THROW(names.get(id), std::out_of_range);
}
