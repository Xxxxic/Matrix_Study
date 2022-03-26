#include <iostream>
#include <string>
using namespace std;
class Cat {
public:
    int cat_age;
    string cat_name;
};

class CatFamily {
public:
    Cat cat_family[101];
    int cat_num = 0;
    int has_cat(string cat_name) {
        for (int i = 0; i < cat_num; i++) {
            if (cat_name == cat_family[i].cat_name)
                return i;
        }
        return 0;
    }
    bool add_a_cat(string cat_name, int cat_age) {
        for (int i = 0; i < cat_num; i++) {
            if (cat_name == cat_family[i].cat_name)
                return 0;
        }
        cat_family[cat_num].cat_age = cat_age;
        cat_family[cat_num].cat_name = cat_name;
        cat_num++;
        return 1;
    }
    bool remove_a_cat(string cat_name) {
        if (has_cat(cat_name)) {
            cat_num--;
            for (int i = has_cat(cat_name); i < cat_num; i++) {
                cat_family[i] = cat_family[i + 1];
            }
            return 1;
        }
        else return 0;
    }
    int number_of_cats() {
        return cat_num;
    }
    Cat get_cat(string cat_name) {
        return cat_family[has_cat(cat_name)];
    }
    string operator[] (int num) const {
        return cat_family[num].cat_name;
    }
};