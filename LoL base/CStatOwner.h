#pragma once

enum class EStatType
{
	AbilityPower,
	PhysicalResist,
	AttackDamage,
	AttackSpeed,
	MagicalResist,
	MoveSpeed,
	Crit,
	CritDamageMultiplier,
	PercentCooldownMod,
	Health,
	Unknown3,
	Unknown4,
	SpellVamp,
	LifeSteal,
	MagicPercentPenetration,
	MagicFlatPenetration,
	MagicBonusPercentPenetration,
	MagicLethality,
	ArmorFlatPenetration,
	ArmorPercentPenetration,
	ArmorBonusPercentPenetration,
	Unknown1,
	PhysicalLethality,
	Tenacity,
	AttackRange,
	HealthRegen,
	PARRegen,
	Unknown2,
};

enum class EStatOutputType
{
	TOTAL,
	BASE,
	BONUS,
};

class CStatOwner
{
public:
	float GetStatTotal(EStatType type, EStatOutputType outputType = EStatOutputType::TOTAL)
	{
		typedef float(__thiscall* GetFn)(void*, uint8_t, uint8_t);
		static GetFn Get = (GetFn)(g_BaseAddr + offsets::stat::STATOWNER__GETSTATTOTAL);
		return Get(this, (uint8_t)type, (uint8_t)outputType);
	}
};
