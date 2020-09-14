#include <QCoreApplication>
#include <QDebug>
#include <QList>

#include <person.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    quint8 age = 44;  // declaration avec initialisation
    age = 45; // affectation (assign)

    // declaration d'une variable objet avec initialisation par constructeur
    Person p1("Matthias", age);  // p1 = 1 objet/1 instance de la classe Person

    Person p2("Xavier", 20); // p2 = 1 autre objet/1 instance de la classe Person
    QList<Person> persons;
    persons << p1 << p2;
    // persons << "John Doe";  // only Person accepted

    qDebug() << "Hello World: " << p1.getName() << " and " << p2.getName()
             << ", it's monday at " << 11;

    //for (Person &p: persons) {  // iteration par reference avec type déclaré
    for (auto &p: persons) {  // iteration par reference avec type auto
        if (p.getAge() >= 21) {
            qDebug() << p.getName() << " can drink a beer";
        } else {
            qDebug() << p.getName() << " can drink a coke";
        }
    }

    for (auto it = persons.begin(); it != persons.end(); ++it) {
        qDebug() << it->getName() << " (by iterator)";
    }

//    for (quint8 cpt=0; cpt<10; cpt++) {
//        qDebug() << cpt << " ";
//    }
    return a.exec();
}
