#include <iostream>
#include <memory>
#include <vector>
#include <list>

class Kid
{
private:
    std::string name;
    int age;

public:
    Kid(std::string name, int age) : name(name), age(age) {}
    friend std::ostream &operator<<(std::ostream &os, const Kid &p)
    {
        os << p.name << " " << p.age;
        return os;
    }

    int getAge()
    {
        return age;
    }
    std::string getName()
    {
        return name;
    }
    void setAge(int age)
    {
        this->age = age;
    }
    void setName(std::string name)
    {
        this->name = name;
    }

    std::string toString()
    {
        return name + " ";
    }
};

class Trampoline
{
private:
    std::list<Kid> esperando;
    std::list<Kid> brincando;

public:
    Trampoline() {}

    Kid *removeKid(std::string name)
    {
        for (auto it = brincando.begin(); it != brincando.end(); it++)
        {
            if (it->getName() == name)
            {
                Kid *kid = new Kid(it->getName(), it->getAge());
                brincando.erase(it);
                return kid;
            }
        }
        return nullptr;
    }

    void arrieves(Kid kid)
    {
        esperando.push_back(kid);
    }

    Kid *start(std::string name)
    {
        for (auto it = esperando.begin(); it != esperando.end(); it++)
        {
            if (it->getName() == name)
            {
                Kid *kid = new Kid(it->getName(), it->getAge());
                esperando.erase(it);
                brincando.push_back(*kid);
                return kid;
            }
        }
        return nullptr;
    }

    void stop(std::string name)
    {
        for (auto it = brincando.begin(); it != brincando.end(); it++)
        {
            if (it->getName() == name)
            {
                Kid *kid = new Kid(it->getName(), it->getAge());
                brincando.erase(it);
                esperando.push_back(*kid);
                return;
            }
        }
    }

    void leave(std::string name)
    {
        for (auto it = brincando.begin(); it != brincando.end(); it++)
        {
            if (it->getName() == name)
            {
                brincando.erase(it);
                return;
            }
        }
        for (auto it = esperando.begin(); it != esperando.end(); it++)
        {
            if (it->getName() == name)
            {
                esperando.erase(it);
                return;
            }
        }
    }

    //saldo acumulado de uma criança
    int getBalance(std::string name)
    {
        int balance = 0;
        for (auto it = brincando.begin(); it != brincando.end(); it++)
        {
            if (it->getName() == name)
            {
                balance += it->getAge();
            }
        }
        for (auto it = esperando.begin(); it != esperando.end(); it++)
        {
            if (it->getName() == name)
            {
                balance -= it->getAge();
            }
        }
        return balance;
    }

    std::string toString()
    {
        std::string str = "";
        for (auto it = brincando.begin(); it != brincando.end(); it++)
        {
            str += it->toString() + " ";
        }
        for (auto it = esperando.begin(); it != esperando.end(); it++)
        {
            str += it->toString() + " ";
        }
        return str;
    }
};

int main()
{
    Trampoline t;

    t.arrieves(Kid("Joao", 10));
    t.arrieves(Kid("Maria", 12));
    t.arrieves(Kid("Pedro", 15));
    std::cout << t.toString() << std::endl;
    Kid *kid = t.start("Joao");
    std::cout << "Kid: " << kid->getName() << " " << kid->getAge() << " entrou" << std::endl;
    std::cout << t.toString() << std::endl;
    kid = t.start("Maria");
    std::cout << "Kid: " << kid->getName() << " " << kid->getAge() << " entrou" << std::endl;
    std::cout << t.toString() << std::endl;
    kid = t.start("Pedro");
    std::cout << "Kid: " << kid->getName() << " " << kid->getAge() << " entrou" << std::endl;
    std::cout << t.toString() << std::endl;
    kid = t.removeKid("Joao");
    std::cout << "Kid: " << kid->getName() << " " << kid->getAge() << " saiu" << std::endl;
    std::cout << t.toString() << std::endl;
    kid = t.removeKid("Maria");
    std::cout << "Kid: " << kid->getName() << " " << kid->getAge() << " saiu" << std::endl;
    std::cout << t.toString() << std::endl;

    return 0;
}