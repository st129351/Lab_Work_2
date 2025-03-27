#include "Trader.h"
#include "Amulet.h"
#include "AFearOfDeath.h"
#include "Player.h"
#include "AHeal.h"

Trader::Trader(Player& p) : NPC("Trader", "Trader, who can sell you different interesting things."), player(p) 
{
    std::shared_ptr<AFearOfDeath> f_d = std::make_shared<AFearOfDeath>(player);
    std::shared_ptr<Amulet> fear_death = f_d;
    amulets.push_back(fear_death);

    speak_flag = false;

}

Trader::~Trader() {}

void Trader::speak()
{
    if (!speak_flag)
    {
        std::cout << "Hi, I can show you something interesting..." << std::endl;
        speak_flag = true;
    }
    std::cout << this->showStore() << std::endl;
}

std::string Trader::showStore() 
{
    std::stringstream ss;
    std::string limiter = "--------------------------------";
    ss << "OLD STORE" << std::endl;
    ss << limiter << std::endl;
    int i = 1;
    for (const auto& amulet : amulets)
    {
        ss << "Number: " << i << std::endl;
        ss << "Amulet: " << amulet->getName() << std::endl;
        ss << "Description: ???" << std::endl;
        ss << "Cost: " << player.getGold() << '/' << amulet->getCost() << std::endl;
        ss << limiter << std::endl;
        i++;
    }
    ss << "How you can see, my toys don't have a descriprion." << std::endl;
    ss << "yet... Buy them and find out what they are capable of :)" << std::endl;
    ss << "if you want to buy, just press the number of amulet.";

    return ss.str();
}