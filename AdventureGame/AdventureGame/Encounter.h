#pragma once
#include <string>
using std::string;
class Encounter
{
public:
	virtual std::string to_string() const;
	virtual void OnEncounterStarted() const;
	virtual void OnEncounterCompleted() const;
};

