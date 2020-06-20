#include <iostream>
#include <vector>

using namespace std;


enum class LodgerType
{
    noworker,
    worker,
    student,
    retiree
};


class Lodger
{
public:
    Lodger(int id, string name, string surname, int age, LodgerType type)
    {
        setId(id);
        setName(name);
        setSurname(surname);
        setAge(age);
        setType(type);
    }

    Lodger(string name, string surname, int age, LodgerType type)
    {
        setName(name);
        setSurname(surname);
        setAge(age);
        setType(type);
    }

    int getId()
    {
        return this->id;
    }
    string getName()
    {
        return this->name;
    }
    string getSurname()
    {
        return this->surname;
    }
    int getAge()
    {
        return this->age;
    }
    LodgerType getType()
    {
        return this->type;
    }
    string getTypeSuchString()
    {
        switch (type)
        {
        case LodgerType::noworker:
            return "Безработный";
            break;
        case LodgerType::worker:
            return "Работает";
            break;
        case LodgerType::student:
            return "Студент";
            break;
        case LodgerType::retiree:
            return "Пенсионер";
            break;
        default:
            return "Не известно";
            break;
        }
    }

    void setId(int id)
    {
        if (id >= 0)
        {
            this->id = id;
        }
        else
        {
            this->id = 0;
        }
        
    }
    void setName(string name)
    {
        if (!name.empty())
        {
            this->name = name;
        }
        else
        {
            throw new exception("Неверное имя квартиранта", 1);
        }
    }
    void setSurname(string surname)
    {
        if (!surname.empty())
        {
            this->surname = surname;
        }
        else
        {
            throw new exception("Неверная фамилия квартиранта", 2);
        }
    }
    void setAge(int age)
    {
        if (age >= 0 && age < 130)
        {
            this->age = age;
        }
        else
        {
            throw new exception("Неверный возраст квартиранта", 3);
        }
    }
    void setType(LodgerType type)
    {
        this->type = type;
    }

    void print()
    {
        cout << "ID: " << getId() << endl;
        cout << "Имя: " << getName() << endl;
        cout << "Фамилия: " << getSurname() << endl;
        cout << "Возраст: " << getAge() << endl;
        cout << "Род занятий: " << getTypeSuchString() << endl;
    }



private:
    int id;
    string name;
    string surname;
    int age;
    LodgerType type;
};

class Flat
{
public:
    Flat(int number)
    {
        this->number = number;
    }


    void addLodger(Lodger lodger)
    {
        lodgers.push_back(lodger);
    }


    
private:
    int getMaxId()
    {
        int max = 0;

        for (auto it : lodgers)
        {
            if (it.getId() > 0) max = it.getId();
        }
    }


private:
    vector<Lodger> lodgers;
    int number;
};

class House
{
    vector<Flat> flats;
};


int main()
{
    setlocale(LC_ALL, "");
    auto lodger1 = new Lodger(1, "Антон", "Сыроежкин", 20, LodgerType::student);


    lodger1->print();
    
}