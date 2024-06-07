#include "creature_tracker.h"

CreatureTracker::CreatureTracker() {
    // Constructor implementation
}

CreatureTracker::~CreatureTracker() {
    clear();
}

void CreatureTracker::add_creature(const std::string& name, const std::string& type, int power) {
    // Create a new Creature object
    Creature new_creature(name, type, power);

    // Insert the new creature into the binary search tree
    tree_creatures.insert(new_creature);

    // Update or add the creature's type statistics in the hash table
    if (ht_stats.contains(type)) {
        CreatureTypeStats* stats = ht_stats.get(type);
        stats->increment_count();
        stats->add_power(power);
    } else {
        CreatureTypeStats new_stats(type);
        new_stats.increment_count();
        new_stats.add_power(power);
        ht_stats.insert(new_stats);
    }
}

void CreatureTracker::remove_creature(const std::string& name) {
    // Find the creature in the tree
    // tree_creatures.find
    Creature* creature_ptr = tree_creatures.find(name);
    if (creature_ptr != nullptr) {
        // Remove the creature from the tree
        tree_creatures.remove(creature_ptr->get_key());
        // Update the creature type statistics
        CreatureTypeStats* stats = ht_stats.get(creature_ptr->get_type());
        if (stats != nullptr) {
            stats->decrement_count();
            stats->subtract_power(creature_ptr->get_power());
            if (stats->get_count() == 0) {
                // If no creatures of this type remain, remove the stats from the hash table
                ht_stats.remove(creature_ptr->get_type());
            }
        }
    }
}

bool CreatureTracker::creature_exists(const std::string& name) {
    return tree_creatures.contains(name);
}

Creature* CreatureTracker::get_creature(const std::string& name) {
    return tree_creatures.find(name);
}

int CreatureTracker::type_count(const std::string& type) {
    if (ht_stats.contains(type)) {
        return ht_stats.get(type)->get_count();
    } else {
        return 0;
    }
}

int CreatureTracker::type_power(const std::string& type) {
    if (ht_stats.contains(type)) {
        return ht_stats.get(type)->get_total_power();
    } else {
        return 0;
    }
}

CreatureTypeStats* CreatureTracker::get_stats(const std::string& type) {
    return ht_stats.get(type);
}

void CreatureTracker::clear() {
    tree_creatures.clear();
    ht_stats.clear();
}

void CreatureTracker::print(std::ostream& os) const {
    os << "Creatures: " << tree_creatures << "\n";
    os << "Type stats:\n" << ht_stats << "\n";
}

std::ostream& operator<<(std::ostream& out, const CreatureTracker& tracker) {
    tracker.print(out);
    return out;
}
