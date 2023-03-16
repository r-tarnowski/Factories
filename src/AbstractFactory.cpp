#include <iostream>
#include <memory>
#include <string>
#include <map>
#include <functional>

using std::cout;
using std::endl;

struct HotDrink {
   virtual ~HotDrink() = default;
   virtual void prepare(int volume) = 0;
};

struct Tea : HotDrink {

   void prepare(int volume) override {
      cout << "Weź torebkę harbaty, zagotuj wodę, zalej " << volume << " ml, dodaj platerek cytryny." << endl;
   }
};

struct Coffee : HotDrink {
   void prepare(int volume) override {
      cout << "Zmiel ziarna, zagotuj wodę, zalej " << volume << " ml, dodaj śmietankę, smacznego!" << endl;
   }
};

struct HotDrinkFactory {
   virtual std::unique_ptr<HotDrink> make() const = 0;
};

struct TeaFactory : HotDrinkFactory {

   std::unique_ptr<HotDrink> make() const override {
      return std::make_unique<Tea>();
   }
};

struct CoffeeFactory : HotDrinkFactory {
   std::unique_ptr<HotDrink> make() const override {
      return std::make_unique<Coffee>();
   }
};

class DrinkFactory {
   std::map<std::string, std::unique_ptr<HotDrinkFactory>> hot_factories;
public:
   DrinkFactory() {
      hot_factories["coffee"] = std::make_unique<CoffeeFactory>();
      hot_factories["tea"] = std::make_unique<TeaFactory>();
   }

   std::unique_ptr<HotDrink> make_drink( const std::string & name) {
      auto drink = hot_factories[name]->make();
      drink->prepare(200); // ups!
      return drink;
   }
};

class DrinkWithVolumeFactory {
   std::map<std::string, std::function<std::unique_ptr<HotDrink>()>> factories;

public:

   DrinkWithVolumeFactory() {
      factories["tea"] = [] {
         auto tea = std::make_unique<Tea>();
         tea->prepare(200);
         return tea;
      };
   }

   std::unique_ptr<HotDrink> make_drink(const std::string & name);
};

inline std::unique_ptr<HotDrink> DrinkWithVolumeFactory::make_drink(const std::string & name) {
   return factories[name]();
}

std::unique_ptr<HotDrink> make_drink(std::string type) {
   std::unique_ptr<HotDrink> drink;
   if (type == "tea") {
      drink = std::make_unique<Tea>();
      drink->prepare(200);
   }
   else {
      drink = std::make_unique<Coffee>();
      drink->prepare(50);
   }
   return drink;
}

void printHeader() {
   cout << endl;
   cout << "================================================" << endl;
   cout << "Design Patterns in Modern C++ by Dmitri Nesteruk" << endl;
   cout << "Factories, Abstract Factory                      "<< endl;
   cout << "================================================" << endl;
   cout << endl;
}

int main(int argc, char * argv[] ) {
   printHeader();

   //Coffee coffee;
   //Tea tea;

   auto d = make_drink("tea");

   DrinkFactory df;
   df.make_drink("coffee");

   return 0;
}