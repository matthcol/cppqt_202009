#ifndef PERSON_H
#define PERSON_H

#include <QString>

class Person
{
private:
    QString name;
    quint8 age;
public:
    Person();
    Person(QString name, quint8 age);


    QString getName() const;
    void setName(const QString &value);
    quint8 getAge() const;
    void setAge(const quint8 &value);
};

#endif // PERSON_H
