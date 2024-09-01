#include <bits/stdc++.h>
using namespace std;

class Order
{   
    private:
    int orderID;
    int orderTotalAmount;
    map<string, int> orderItems;
    int orderStatus;   //  (1 - in cart ,2 - out for delivery , 3 - delivered) 
    string DeliveryAddress;

    public:
    Order(int orderID , int orderTotalAmount, map<string, int> orderItems, int orderStatus , string DeliveryAddress)
    {
        this->orderID = orderID;
        this->orderTotalAmount = orderTotalAmount;
        this->orderStatus = orderStatus;
        this->DeliveryAddress = DeliveryAddress;
    }

    void orderInCart(int status)
    {
        this->orderStatus = status;
    }

    void orderOutForDelivery(int status)
    {
        this->orderStatus = status;
    }

    void orderDelivered(int status)
    {
        this->orderStatus = status;
    }
};

class Item
{

public:
    string itemName;
    int price;

    Item(string itemName, int price)
    {
        this->itemName = itemName;
        this->price = price;
    }
};

class Restaurant
{

public:
    int restaurantID;
    string restaurantName;
    string ownerName;
    double rating;
    double distance;
    map<string, int> menu; // menu will be a map of type (itemName , price)

    Restaurant(int id, string restaurantName, string ownerName, double rating, double distance, map<string, int> menu)
    {
        this->restaurantID = id;
        this->restaurantName = restaurantName;
        this->ownerName = ownerName;
        this->rating = rating;
        this->distance = distance;
        this->menu = menu;
    }

    void addItemToMenu(Item item)
    {
        if (this->menu.find(item.itemName) != this->menu.end())
        {
            cout << "Item already exist\n";
        }
        else
        {
            this->menu[item.itemName] = item.price;
        }
    }

    void deleteItemFromMenu(Item item)
    {
        if (this->menu.find(item.itemName) != this->menu.end())
        {
            this->menu.erase(item.itemName);
        }
        else
        {
            cout << "Item not found\n";
        }
    }

    void updateItemPrice(Item item)
    {
        if (this->menu.find(item.itemName) != this->menu.end())
        {
            this->menu[item.itemName] = item.price;
        }
        else
        {
            cout << "Item not found\n";
        }
    }

    void showMenu()
    {
        for (auto &val : this->menu)
        {
            cout << "Item:" << val.first << " Price:" << val.second << endl;
        }
    }
    
    void updateStatusToOutForDelivery(Order order)
    {
        int outForDeliveryStatus = 2;
        order.orderOutForDelivery(outForDeliveryStatus);
    }
};

class DeliveryGuy
{
    int ID;
    string name;
    int age;

public:
    DeliveryGuy(int id , string name , int age)
    {
        this->ID = id;
        this->name = name;
        this->age = age;
    }

    void updateStatusToOutForDelivery(Order order)
    {
        int outForDeliveryStatus = 2;
        order.orderOutForDelivery(outForDeliveryStatus);
    }

    void updateStatusToDelivered(Order order)
    {
        int deliveredStatus = 3;
        order.orderDelivered(deliveredStatus);
    }
};

class Customer
{
    int customerID;
    int customerAge;
    string customerName;
    string customerAddress;
    
public:
    Customer(int id , int age, string name , string address)
    {
        this->customerID = id;
        this->customerAge = age;
        this->customerName = name;
        this->customerAddress = address;
    }

    void addItemsToCart(Order order)
    {
        int InCartStatus = 1;
        order.orderInCart(InCartStatus);
    }  
};

class Query
{
private:
    vector<Restaurant> restaurants;

    static bool sortByRating(pair<int, double> restaurantOne , pair<int, double> restaurantTwo)
    {
        return restaurantOne.second > restaurantTwo.second;     // highest rating restaurant will be at start of list
    }

    static bool sortByDistance(pair<int, double> restaurantOne , pair<int, double> restaurantTwo)
    {
        return restaurantOne.second < restaurantTwo.second;     // lowest distance restaurant will be at start of list
    }   

public:
    Restaurant getRestaurantById(int restaurantID)
    {
        for (int i = 0; i < restaurants.size(); i++)
        {
            if (restaurants[i].restaurantID == restaurantID)
            {
                return restaurants[i];
            }
        }

        cout << "Restaurant not found with this ID\n";
    }

    vector<int> getRestaurantListByDish(string Dish)
    {
        vector<int> result;

        for (int i = 0; i < restaurants.size(); i++)
        {
            if (restaurants[i].menu.find(Dish) != restaurants[i].menu.end())
            {
                result.push_back(restaurants[i].restaurantID);
            }
        }

        return result;
    }

    vector<pair<int, double>> getRestaurantListByRating()
    {
        vector<pair<int, double>> result; // restaurant Id , rating

        for (int i = 0; i < restaurants.size(); i++)
        {
            result.push_back({restaurants[i].restaurantID , restaurants[i].rating});
        }

        sort(result.begin(), result.end() , sortByRating);
        return result;
    }

    vector<pair<int, double>> getRestaurantListByDistance()
    {
        vector<pair<int, double>> result; // restaurant Id , distance
        for (int i = 0; i < restaurants.size(); i++)
        {
            result.push_back({restaurants[i].restaurantID , restaurants[i].distance});
        }

        sort(result.begin(), result.end() , sortByDistance);
        return result;
    }

    map<string, int> getMenuOfRestaurant(int restaurantID)
    {
        for (int i = 0; i < restaurants.size(); i++)
        {
            if (restaurants[i].restaurantID == restaurantID)
            {
                return restaurants[i].menu;
            }
        }

        cout << "Restaurant Not Found\n";
    }

    void addRestaurantToList(Restaurant restaurant)
    {
        restaurants.push_back(restaurant);
    }

    void addItemToRestaurantMenu(int restaurantID , Item item)
    {
        for(int i=0; i < restaurants.size(); i++)
        {
            if(restaurants[i].restaurantID == restaurantID)
            {
                restaurants[i].addItemToMenu(item);
            }
        }
    }

    void deleteItemFromRestaurantMenu(int restaurantID , Item item)
    {
        for(int i=0; i < restaurants.size(); i++)
        {
            if(restaurants[i].restaurantID == restaurantID)
            {
                restaurants[i].deleteItemFromMenu(item);
            }
        }
    }

    void updateItemPriceInRestaurantMenu(int restaurantID , Item item)
    {
        for(int i=0; i < restaurants.size(); i++)
        {
            if(restaurants[i].restaurantID == restaurantID)
            {
                restaurants[i].updateItemPrice(item);
            }
        }
    }

    void showRestaurantMenu(int restaurantID)
    {
        for(int i=0; i < restaurants.size(); i++)
        {
            if(restaurants[i].restaurantID == restaurantID)
            {
                restaurants[i].showMenu();
            }
        }
    }
};

int main()
{
    Restaurant restaurantOne(1, "BK Plaza", "Harish", 4, 10, {});
    Query queries;
    queries.addRestaurantToList(restaurantOne);

    queries.addItemToRestaurantMenu(restaurantOne.restaurantID , Item("Paneer" , 300));
    
    queries.showRestaurantMenu(restaurantOne.restaurantID);

    return 0;
}