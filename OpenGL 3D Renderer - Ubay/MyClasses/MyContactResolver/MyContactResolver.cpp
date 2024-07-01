#include "MyContactResolver.hpp"

using namespace MyPhysics;

//* ╔═══════════════════════════════╗
//* ║ Constructors & Deconstructors ║
//* ╚═══════════════════════════════╝
MyContactResolver::MyContactResolver(unsigned int maxIterations) : maxIterations(maxIterations) {}

//* ╔═════════╗
//* ║ Methods ║
//* ╚═════════╝
vector<MyParticleContact*> MyContactResolver::resolveContacts(vector<MyParticleContact*> contacts,
                                                              double time) {
    map<MyParticleContact*, double> contactsWithSeparatingSpeed;
    MyParticleContact* contactToBeResolved = contacts.front();
    for (MyParticleContact* contact : contacts) {
        contactsWithSeparatingSpeed[contact] = contact->calculateSeparatingSpeed();
    }
    while (!contactsWithSeparatingSpeed.empty() || this->currentIterations < this->maxIterations) {
        for (map<MyParticleContact*, double>::iterator contact =
                 contactsWithSeparatingSpeed.begin();
             contact != contactsWithSeparatingSpeed.end();
             contact++) {
            if (contact->second < contactsWithSeparatingSpeed[contactToBeResolved])
                contactToBeResolved = contact->first;
        }
        contactToBeResolved->resolve(time);
        contactsWithSeparatingSpeed.erase(contactToBeResolved);
        this->currentIterations++;
    }
    if (!contactsWithSeparatingSpeed.empty()) {
        vector<MyParticleContact*> leftoverContacts;
        for (map<MyParticleContact*, double>::iterator contact =
                 contactsWithSeparatingSpeed.begin();
             contact != contactsWithSeparatingSpeed.end();
             contact++) {
            leftoverContacts.push_back(contact->first);
        }
        return leftoverContacts;
    }

    return {};
}

//* ╔═══════════════════╗
//* ║ Getters & Setters ║
//* ╚═══════════════════╝