#include "person.h"


quint8 Person::getAge() const
{
    return age;
}

void Person::setAge(const quint8 &value)
{
    age = value;
}

Person::Person()
{

}

Person::Person(QString name, quint8 age):name(name), age(age)
{

}

QString Person::getName() const
{
    return name;
}

void Person::setName(const QString &value)
{
    name = value;
}


