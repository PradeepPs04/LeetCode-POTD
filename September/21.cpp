// https://leetcode.com/problems/design-movie-rental-system/description/?envType=daily-question&envId=2025-09-21

class MovieRentingSystem {
private:
    map<int, set<pair<int, int>>>available_movies; // {movie: {price, shop}}
    map<pair<int, int>, int>movie_price; // {{movie, shop}: price}
    set<tuple<int, int, int>>rented_set; // {price, shop, movie}
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto &it: entries) {
            int shop = it[0];
            int movie = it[1];
            int price = it[2];

            available_movies[movie].insert({price, shop});
            movie_price[{movie, shop}] = price;
        }
    }
    
    vector<int> search(int movie) { 
        // Return up to 5 cheapest shops that have the movie available

        // if movie not availalbe
        if(available_movies.find(movie) == available_movies.end())  return {};

        vector<int>best_shops;
        for(auto &[price, shop]: available_movies[movie]) {
            best_shops.push_back(shop);
            if(best_shops.size() == 5)   break;
        }

        return best_shops;
    }
    
    void rent(int shop, int movie) {
        // Move movie from available -> rented
        int price = movie_price[{movie, shop}];
        rented_set.insert({price, shop, movie});
        available_movies[movie].erase({price, shop});
    }
    
    void drop(int shop, int movie) {
        // Move movie from rented -> available
        int price = movie_price[{movie, shop}];
        rented_set.erase({price, shop, movie});
        available_movies[movie].insert({price, shop});
    }
    
    vector<vector<int>> report() {
        // Return up to 5 cheapest rented movies
        vector<vector<int>>top_rented;
        for(auto &[price, shop, movie]: rented_set) {
            top_rented.push_back({shop, movie});
            if(top_rented.size() == 5)  break;
        }

        return top_rented;
    }
};