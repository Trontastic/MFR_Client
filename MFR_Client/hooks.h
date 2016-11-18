#pragma once
#include "CSingleton.h"

enum eGameVersion
{
	VERSION_ALL = 0,
	VERSION_EU_10 = 5,
	VERSION_US_10 = 11,
	VERSION_11 = 15,
	VERSION_20 = 20,
	VERSION_UNKNOWN = 0xFF,
};

eGameVersion FindGameVersion(void);

class Hooks : public CSingleton<Hooks>
{
	friend class CSingleton<Hooks>;
public:
	Hooks(void) = default;
	~Hooks(void) = default;

	void Initialize(void);
	void UnInitialize(void);
	void PostInstall(void); // at first frame
private:
	float m_fAircraftMaxHeight;
	float m_fAircraftMaxVelocity;
	float m_fAircraftMaxVelocity_Sq;
};