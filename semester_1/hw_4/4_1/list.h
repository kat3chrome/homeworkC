#ifndef LIST_H
#define LIST_H

struct Troop;
struct Soldier;

struct Troop* createTroop();
void addSoldier(int number ,struct Troop* troop);
void nextSoldier(struct Troop* troop);
void killCurrentSoldier(struct Troop* troop);
int getNumberOfLastSoldier(struct Troop* troop);

#endif
