#include "MyContactResolver.hpp"

using namespace MyPhysics;

//* ╔═══════════════════════════════╗
//* ║ Constructors & Deconstructors ║
//* ╚═══════════════════════════════╝
MyContactResolver::MyContactResolver(unsigned int maxIterations)
    : maxIterations(maxIterations),
      currentIterations(0) {}

//* ╔═════════╗
//* ║ Methods ║
//* ╚═════════╝
vector<MyParticleContact*> MyContactResolver::resolveContacts(vector<MyParticleContact*> contacts,
                                                              double time) {
    map<MyParticleContact*, double> contactsWithSeparatingSpeed;
    MyParticleContact* contactToBeResolved = contacts.front();

    //? Will try to iterate through all the given contacts and solve them one by one.
    while (!contactsWithSeparatingSpeed.empty() || this->currentIterations < this->maxIterations) {
        //? Though do note as we resolve a contact the other’s Separating Speed might change
        for (MyParticleContact* contact : contacts) {
            contactsWithSeparatingSpeed[contact] = contact->calculateSeparatingSpeed();
        }

        //? We need to prioritize the one with the LEAST separating speed first going up.
        for (map<MyParticleContact*, double>::iterator contact =
                 contactsWithSeparatingSpeed.begin();
             contact != contactsWithSeparatingSpeed.end();
             contact++) {
            if (contact->second < contactsWithSeparatingSpeed[contactToBeResolved])
                contactToBeResolved = contact->first;
        }
        contactToBeResolved->resolve(time);
        contactsWithSeparatingSpeed.erase(contactToBeResolved);

        //? In order to escape the possible loops, we’ll need to set the limit to the following per
        //? frame
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