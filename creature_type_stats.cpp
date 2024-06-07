#include "creature_type_stats.h"
using namespace std;

// Default constructor
CreatureTypeStats::CreatureTypeStats() {
    this->type = "";
    this->count = 0;
    this->total_power = 0;
    // Initializes type to an empty string, count to 0, and total power to 0
}

// Parameterized constructor
CreatureTypeStats::CreatureTypeStats(const std::string& type){
    this->type = type;
    this->count = 0;
    this->total_power = 0;
    // Initializes the type with the supplied type, count to 0, and total power to 0
}

// Destructor
CreatureTypeStats::~CreatureTypeStats() {
    // No dynamic memory allocation, so nothing specific to do here
}

// Get the type of the creature
const std::string& CreatureTypeStats::get_key() const {
    return type;
}

// Get the count of creatures of this type
int CreatureTypeStats::get_count() const {
    return count;
}

// Get the total power of creatures of this type
int CreatureTypeStats::get_total_power() const {
    return total_power;
}

// Increment the count by 1
void CreatureTypeStats::increment_count() {
    count++;
}

// Decrement the count by 1
void CreatureTypeStats::decrement_count() {
    if (count > 0) {
        count--;
    }
}

// Add power to the total power
void CreatureTypeStats::add_power(int amount) {
    total_power += amount;
}

// Subtract power from the total power
void CreatureTypeStats::subtract_power(int amount) {
    total_power -= amount;
}

// Stream insertion operator
std::ostream& operator<<(std::ostream& os, const CreatureTypeStats& c) {
    os << "(" << c.get_key() << ", " << c.get_count() << ", " << c.get_total_power() << ")";
    return os;
}

// Equality operator
bool operator==(const CreatureTypeStats& c1, const CreatureTypeStats& c2) {
    return c1.get_key() == c2.get_key();
}

// Less-than operator
bool operator<(const CreatureTypeStats& c1, const CreatureTypeStats& c2) {
    return c1.get_key() < c2.get_key();
}

// Greater-than operator
bool operator>(const CreatureTypeStats& c1, const CreatureTypeStats& c2) {
    return c1.get_key() > c2.get_key();
}
