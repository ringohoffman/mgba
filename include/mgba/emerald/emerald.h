#ifndef EMERALD_H
#define EMERALD_H

#include <mgba-util/common.h>

CXX_GUARD_START

void func1(void);

#define PLAYER_PARTY_BASE 0x020244EC      // https://git.cactys.dev/mirror/pret/pokeemerald/-/blob/96511dc214b9f343864b125816751040edccd010/sym_ewram.txt#L534
#define OPPONENT_PARTY_BASE 0x02024744    // https://git.cactys.dev/mirror/pret/pokeemerald/-/blob/96511dc214b9f343864b125816751040edccd010/sym_ewram.txt#L537
#define SPECIES_NAME_TABLE_BASE 0x83185C8 // https://git.cactys.dev/mirror/pret/pokeemerald/-/blob/96511dc214b9f343864b125816751040edccd010/data/text/species_names.inc#L1
#define TYPE_STRING_TABLE_BASE 0x831AE38  // https://git.cactys.dev/mirror/pret/pokeemerald/-/blob/96511dc214b9f343864b125816751040edccd010/data/text/type_names.inc#L1
#define ITEM_TABLE_BASE 0x85839A0         // https://git.cactys.dev/mirror/pret/pokeemerald/-/blob/96511dc214b9f343864b125816751040edccd010/data/items.inc#L2
#define MOVE_TABLE_BASE 0x831C898         // https://git.cactys.dev/mirror/pret/pokeemerald/-/blob/96511dc214b9f343864b125816751040edccd010/data/battle_moves.inc#L2
#define MOVE_STRING_TABLE_BASE 0x831977C  // https://git.cactys.dev/mirror/pret/pokeemerald/-/blob/96511dc214b9f343864b125816751040edccd010/data/text/move_names.inc
#define BASE_STATS_TABLE_BASE 0x83203CC
#define ABILITY_NAME_TABLE_BASE 0x831B6DB
#define PLAYER_PARTY_COUNT 0x20244E9      // https://git.cactys.dev/mirror/pret/pokeemerald/-/blob/96511dc214b9f343864b125816751040edccd010/sym_ewram.txt#L528
#define OPPONENT_PARTY_COUNT 0x20244EA    // https://git.cactys.dev/mirror/pret/pokeemerald/-/blob/96511dc214b9f343864b125816751040edccd010/sym_ewram.txt#L531
#define BATTLE_WEATHER 0x20243CC          // https://git.cactys.dev/mirror/pret/pokeemerald/-/blob/96511dc214b9f343864b125816751040edccd010/sym_ewram.txt#L447

#define PSN_STRING 0x85EAE31              // https://git.cactys.dev/mirror/pret/pokeemerald/-/blob/96511dc214b9f343864b125816751040edccd010/data/strings.s#L1793
#define PAR_STRING 0x85EAE35
#define SLP_STRING 0x85EAE39
#define BRN_STRING 0x85EAE3D
#define FRZ_STRING 0x85EAE41
#define TOXIC_STRING 0x85EAE45
#define OK_STRING 0x85EAE4B

#define BATTLE_OUTCOME 0x202433A          // https://git.cactys.dev/mirror/pret/pokeemerald/-/blob/96511dc214b9f343864b125816751040edccd010/sym_ewram.txt#L438
#define BATTLE_TURN_NUMBER 0x2024082      // https://git.cactys.dev/mirror/pret/pokeemerald/-/blob/96511dc214b9f343864b125816751040edccd010/sym_ewram.txt#L294
#define BATTLE_TYPE 0x2022FEC             // https://git.cactys.dev/mirror/pret/pokeemerald/-/blob/96511dc214b9f343864b125816751040edccd010/sym_ewram.txt#L246

#define BATTLE_ACTION_SELECTION_CURSOR 0x20244AC // https://git.cactys.dev/mirror/pret/pokeemerald/-/blob/96511dc214b9f343864b125816751040edccd010/sym_ewram.txt#L483
#define BATTLE_MOVE_SELECTION_CURSOR 0x20244B0 // https://git.cactys.dev/mirror/pret/pokeemerald/-/blob/96511dc214b9f343864b125816751040edccd010/sym_ewram.txt#L486

#define BATTLE_MONS_BASE 0x2024084
#define FRAME_COUNTER 0x20249C0
#define IN_ACTION_MENU 0x2024332

#define PERSONALITY_STRING_POINTER_TABLE_BASE 0x861CB50

// gCritMultiplier: @ 2024211
	// .space 0x1

// gCurrentMove: @ 20241EA
// 	.space 0x2

// gChosenMove: @ 20241EC
// 	.space 0x2

enum ActionType {
	fight=0,
	bag=1,
	pokemon=2,
	run=3
};


extern double typeChart[18][18];

struct growth {
	uint16_t species;
	uint16_t item;
	uint32_t xp;
	uint8_t ppBonuses;
	uint8_t friendship;
	uint16_t unknown;
};

struct attacks {
	uint16_t move1;
	uint16_t move2;
	uint16_t move3;
	uint16_t move4;
	uint8_t pp1;
	uint8_t pp2;
	uint8_t pp3;
	uint8_t pp4;
};

struct ev {
	uint8_t hp;
	uint8_t attack;
	uint8_t defense;
	uint8_t speed;
	uint8_t spAttack;
	uint8_t spDefense;
	uint8_t coolness;
	uint8_t beauty;
	uint8_t cuteness;
	uint8_t smartness;
	uint8_t toughness;
	uint8_t feel;
};

struct iv {
	bool hp1:1;
	bool hp2:1;
	bool hp3:1;
	bool hp4:1;
	bool hp5:1;
	bool attack1:1;
	bool attack2:1;
	bool attack3:1;
	bool attack4:1;
	bool attack5:1;
	bool defense1:1;
	bool defense2:1;
	bool defense3:1;
	bool defense4:1;
	bool defense5:1;
	bool speed1:1;
	bool speed2:1;
	bool speed3:1;
	bool speed4:1;
	bool speed5:1;
	bool spAttack1:1;
    bool spAttack2:1;
    bool spAttack3:1;
    bool spAttack4:1;
    bool spAttack5:1;
    bool spDefense1:1;
    bool spDefense2:1;
    bool spDefense3:1;
    bool spDefense4:1;
    bool spDefense5:1;
	bool egg:1;
	bool ability:1;
};

struct misc {
	uint8_t pokerus;
	uint8_t metLocation;
	uint16_t origins;
	struct iv iv;
	uint32_t ribonObedience;
};

struct stats {
	uint32_t statusCondition;
	uint8_t level;
	uint8_t pokerus;
	uint16_t currentHp;
	uint16_t totalHp;
	uint16_t attack;
	uint16_t defense;
	uint16_t speed;
	uint16_t spAttack;
	uint16_t spDefense;
};

struct pokemonDataStructure {
	uint32_t personality;
	uint32_t originalTrainerId;
	char nickname[10];
	uint16_t language;
	char originalTrainerName[7];
	uint8_t markings;
	uint16_t checksum;
	uint16_t unknown;
	struct growth growth;
	struct attacks attacks;
	struct ev ev;
	struct misc misc;
	struct stats stats;
};

//----------------------------------------------------------------------------//
// https://bulbapedia.bulbagarden.net/wiki/Pok%C3%A9mon_species_data_structure_(Generation_III)

struct baseStats {
    uint8_t hp;
    uint8_t attack;
    uint8_t defense;
    uint8_t speed;
    uint8_t spAttack;
    uint8_t spDefense;
    uint8_t type1;
    uint8_t type2;
    uint8_t catchRate;
    uint8_t xpYield;
    uint16_t effortYield;
    uint16_t item1;
    uint16_t item2;
    uint8_t gender;
    uint8_t eggCycle;
    uint8_t friendship;
    uint8_t levelUpType;
    uint8_t eggGroup1;
    uint8_t eggGroup2;
    uint8_t ability1;
    uint8_t ability2;
    uint8_t safariZoneRate;
    uint8_t colorFilp;
    uint16_t padding;
};

//----------------------------------------------------------------------------//

// https://bulbapedia.bulbagarden.net/wiki/Item_data_structure_(Generation_III)
// https://git.cactys.dev/mirror/pret/pokeemerald/-/blob/96511dc214b9f343864b125816751040edccd010/data/items.inc
struct item {
  char name[14];
  uint16_t indexNumber;
  uint16_t price;
  uint8_t holdEffect;
  uint8_t parameter;
  uint32_t descriptionPointer;
  uint16_t mysteryValue;
  uint8_t pocket;
  uint8_t type;
  uint32_t pointerToFieldUsageCode;
  uint32_t battleUsage;
  uint32_t pointerToBattleUsageCode;
  uint32_t extraParameter;
};

//----------------------------------------------------------------------------//

enum pokemonType {
	normal = 0,
	fighting = 1,
	flying = 2,
	poison = 3,
	ground = 4,
	rock = 5,
	bug = 6,
	ghost = 7,
	steel = 8,
	unknown = 9,
	fire = 10,
	water = 11,
	grass = 12,
	electric = 13,
	psychic = 14,
	ice = 15,
	dragon = 16,
	dark = 17,
};

struct PokemonData {
	struct pokemonDataStructure pokemonDataStructure;
	struct baseStats baseStats;
	struct item item;
	char nickname[10];
	char speciesName[11];
	char typeString1[7];
	char typeString2[7];
	char ability[13];
	char statusEffect[6];
	char personalityString[8];
	char hiddenPowerTypeString[7];
	char move1[13];
	char move2[13];
	char move3[13];
	char move4[13];
	uint16_t actualChecksum;
	uint8_t hiddenPowerType;
	uint32_t hiddenPowerPower;
	uint8_t personalityIndex;
	uint16_t hpIv;
	uint16_t attackIv;
	uint16_t defenseIv;
	uint16_t speedIv;
	uint16_t spAttackIv;
	uint16_t spDefenseIv;
};

// // https://bulbapedia.bulbagarden.net/wiki/Save_data_structure_(Generation_III)#Section_1_-_Team_.2F_Items
// struct teamAndItems {
// 	uint32_t teamSize;
// 	uint8_t team[600];
// 	uint32_t money;
// 	uint16_t coins;
// 	uint8_t pcItems[120];
// 	uint8_t itemPocket[168];
// 	uint8_t keyItemPocket[120];
// 	uint8_t ballItemPocket[52];
// 	uint8_t tmCase[232];
// 	uint8_t berryPocket[172];
// };

enum statusCondition {
	ok = 0,
	slp1 = 1,
	slp2 = 2,
	slp3 = 3,
	slp4 = 4,
	slp5 = 5,
	slp6 = 6,
	slp7 = 7,
	psn = 8,
	brn = 16,
	frz = 32,
	par = 64,
	toxic = 128,
	fnt = 256      // this one is not official but is useful
};

//----------------------------------------------------------------------------//

CXX_GUARD_END

#endif
