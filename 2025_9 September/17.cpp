// https://leetcode.com/problems/design-a-food-rating-system/description/?envType=daily-question&envId=2025-09-17

class Food {
public:
    int foodRating;
    string foodName;
    
    Food(int rating, string food) {
        foodRating = rating;
        foodName = food;
    }

    bool operator<(const Food& obj) const {
        if(foodRating == obj.foodRating) {
            return foodName > obj.foodName;
        }

        return foodRating < obj.foodRating;
    }
};

class FoodRatings {
private:
    unordered_map<string, int>foodRatingMap; // {food: rating}
    unordered_map<string, string>foodCuisineMap; // {food: cuisine}
    unordered_map<string, priority_queue<Food>>cuisineFoodMap; // {cuisine: [food]}

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i = 0; i < foods.size(); i++) {
            string food = foods[i];
            string cuisine = cuisines[i];
            int rating = ratings[i];

            // create mapping
            foodRatingMap[food] = rating; // food: rating
            foodCuisineMap[food] = cuisine; // food: cuisine

            // add food to priority queue of corresponding cuisine
            cuisineFoodMap[cuisine].push(Food(rating, food));
        }
    }
    
    void changeRating(string food, int newRating) {
        // update the rating
        foodRatingMap[food] = newRating;

        // get the cusine of food
        string cuisineName = foodCuisineMap[food];

        // add new rating to priority queue of corresponsing cuisine
        cuisineFoodMap[cuisineName].push(Food(newRating, food));   
    }
    
    string highestRated(string cuisine) {
        auto highestRated = cuisineFoodMap[cuisine].top();

        while(foodRatingMap[highestRated.foodName] != highestRated.foodRating) {
            cuisineFoodMap[cuisine].pop();
            highestRated = cuisineFoodMap[cuisine].top();
        }

        return highestRated.foodName;
    }
};