#include "Trader.h"
#include "Amulet.h"
#include "AFearOfDeath.h"
#include "AKillerLook.h"
#include "Player.h"
#include "AHeal.h"
#include "GameField.h"
#include "AMadness.h"
#include "APerseverance.h"
#include "BestExp.h"
#include "AHeal.h"
#include "ADash.h"

Trader::Trader(Player& p, GameField& f) : NPC("Trader", "Trader, who can sell you different interesting things."), player(p), field(f)
{
    enemies = field.getEnemies();
    std::shared_ptr<AFearOfDeath> f_d = std::make_shared<AFearOfDeath>(player);
    std::shared_ptr<Amulet> fear_death = f_d;
    std::shared_ptr<AKillerLook> k_d = std::make_shared<AKillerLook>(enemies);
    std::shared_ptr<Amulet> killer_look = k_d;
    std::shared_ptr<AMadness> md = std::make_shared<AMadness>(player);
    std::shared_ptr<Amulet> madness = md;
    std::shared_ptr<APerseverance> pr = std::make_shared<APerseverance>();
    std::shared_ptr<Amulet> persev = pr;
    std::shared_ptr<BestExp> be = std::make_shared<BestExp>(player);
    std::shared_ptr<Amulet> best_exp = be;
    std::shared_ptr<AHeal> h = std::make_shared<AHeal>();
    std::shared_ptr<Amulet> heal = h;
    std::shared_ptr<ADash> d = std::make_shared<ADash>(field);
    std::shared_ptr<Amulet> dash = d;

    amulets.push_back(fear_death);
    amulets.push_back(killer_look);
    amulets.push_back(madness);
    amulets.push_back(persev);
    amulets.push_back(best_exp);
    amulets.push_back(heal);
    amulets.push_back(dash);

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
        ss << "Cells: " << amulet->getSlots() << std::endl;
        ss << limiter << std::endl;
        i++;
    }
    ss << "How you can see, my toys don't have a descriprion." << std::endl;
    ss << "yet... Buy them and find out what they are capable of :)" << std::endl;
    ss << "if you want to buy, just press the number of amulet.";
    setDialogueComplete(true);
    return ss.str();
}