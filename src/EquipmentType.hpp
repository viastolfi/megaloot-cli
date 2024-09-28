#ifndef EQUIPMENTTYPE_HPP
#define EQUIPMENTTYPE_HPP

enum EquipmentType {
	sword,
	shield,
};

inline std::ostream& operator<<(std::ostream& s, EquipmentType et){
	switch(et) {
	case sword:
		s << "🗡️  SWORD";
		break;
	case shield:
		s << "🛡️  SHIELD";
		break;
	}
	return s;
}

#endif //EQUIPMENTTYPE_HPP
