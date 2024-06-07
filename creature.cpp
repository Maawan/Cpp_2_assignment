#include "creature.h"
using namespace std;
// Default constructor
Creature::Creature() {
    this->name = "";
    this->type = "";
    this->power = 0;
}

// Parameterized constructor
Creature::Creature(const string& name, const string& type, int power){
    this->name = name;
    this->type = type;
    this->power = power;
}

// Destructor
Creature::~Creature() {}

// Get the name of the creature
const string& Creature::get_key() const {
    return name;
}

// Get the type of the creature
const string& Creature::get_type() const {
    return type;
}

// Get the power rating of the creature
int Creature::get_power() const {
    return power;
}

// Stream insertion operator
ostream& operator << (ostream& os, const Creature& c) {
    os << "("<<c.get_key()<<", " << c.get_type()<<", " << c.get_power()<<")";
    return os;
}

// Equality operator
bool operator == (const Creature& c1, const Creature& c2) {
    return c1.get_key() == c2.get_key();
}

// Less-than operator
bool operator < (const Creature& c1, const Creature& c2) {
    return c1.get_key() < c2.get_key();
}

// Greater-than operator
bool operator > (const Creature& c1, const Creature& c2) {
    return c1.get_key() > c2.get_key();
}
