#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Serializable.h"

struct Time {

	int hours;
	int minutes;
};

class Movie : public Serializable {

private:
	std::string title;
	std::string director;
	int year;
	Time startTime;
	int duration;

public:
	Movie(const std::string& _title, const std::string& _director,
		int _year, const Time& _startTime, int _duration);
	Movie();

	std::string getTitle() const;
	std::string getDirector() const;
	int getYear() const;
	Time getTime() const;
	int getDuration() const;

	void setTitle(const std::string& _title);
	void setDirector(const std::string& _director);
	void setYear(int _year);
	void setStartTime(const Time& _startTime);
	void setDuration(int _duration);

	void serialize(std::ofstream& stream) const override;
	void deserialize(std::istream& stream) override;
};