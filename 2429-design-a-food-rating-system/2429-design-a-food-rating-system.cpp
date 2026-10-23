// #include <vector>
// #include <string>
// #include <unordered_map>
// #include <set>
// #include <utility>
// #include <string_view>

// using namespace std;

// class FoodRatings {
// private:
//     // Store the actual strings so string_view has a valid, persistent lifetime owned by the class
//     vector<string> stored_foods;
//     vector<string> stored_cuisines;

// public:
//     struct Cuisine {
//         set<pair<int, string_view>> ranked;
//     };

//     unordered_map<string_view, Cuisine> cuisine_idx;
//     unordered_map<string_view, int> rating;
//     unordered_map<string_view, string_view> food_cuisine;

//     FoodRatings(vector<string>& foods, vector<string>& cuisines,
//                 vector<int>& ratings) {
//         int n = foods.size();

//         // Copy strings into class storage
//         stored_foods = foods;
//         stored_cuisines = cuisines;

//         cuisine_idx.reserve(n);
//         rating.reserve(n);
//         food_cuisine.reserve(n);

//         for (int i = 0; i < n; i++) {
//             // string_view now points to our class-owned storage
//             string_view f = stored_foods[i];
//             string_view c = stored_cuisines[i];

//             cuisine_idx[c].ranked.insert({-ratings[i], f});
//             rating[f] = ratings[i];
//             food_cuisine[f] = c;
//         }
//     }

//     void changeRating(const string& food, int newRating) {
//         // Find the canonical string_view from food_cuisine
//         auto it_fc = food_cuisine.find(food);
//         string_view f = it_fc->first;
//         string_view c = it_fc->second;

//         int oldRating = rating.at(f);
//         auto& ranked = cuisine_idx.at(c).ranked;

//         ranked.erase({-oldRating, f});
//         ranked.insert({-newRating, f});

//         rating[f] = newRating;
//     }

//     string highestRated(const string& cuisine) {
//         auto it = cuisine_idx.find(cuisine);
//         return string(it->second.ranked.begin()->second);
//     }
// };


class FoodRatings {
private:
    vector<string>& foods, & cuisines;
    vector<int>& ratings;
    unordered_map<string_view, int> lkp{};
    unordered_map<string_view, priority_queue<pair<int, string_view>, vector<pair<int, string_view>>, greater<pair<int, string_view>>>> mp{};
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) : foods{foods}, cuisines{cuisines}, ratings{ratings} {
        const int n{static_cast<int>(foods.size())};
        for (const int i : views::iota(0, n)) {
            const string_view food{foods[i]}, cuisine{cuisines[i]};
            const int rating{ratings[i]};
            lkp[food] = i;
            mp[cuisine].emplace(-rating, food);
        }
    }
    
    void changeRating(string food, int newRating) {
        const int i{lkp[food]};
        const string_view sv{foods[i]}, cuisine{cuisines[i]};
        mp[cuisine].emplace(-newRating, sv);
        ratings[i] = newRating;
    }
    
    string highestRated(string cuisine) {
        while (-mp[cuisine].top().first != ratings[lkp[mp[cuisine].top().second]]) mp[cuisine].pop();
        return string{mp[cuisine].top().second};
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */