#include <iostream>
#include <fstream>
#include <string>
#include "Serializable.h"
#include "Movie.h"

	Movie::Movie(const std::string& _title, const std::string& _director,
		int _year, const Time& _startTime, int _duration): 
		title(_title), director(_director), year(_year),
		startTime(_startTime), duration(_duration){}

	Movie::Movie() {

		title = "";
		director = "";
		year = 0;
		duration = 0;
	}

	std::string Movie::getTitle() const {
	
		return title;
	}

	std::string Movie::getDirector() const {

		return director;
	}

	int Movie::getYear() const {

		return year;
	}

	Time Movie::getTime() const {

		return startTime;
	}

	int Movie::getDuration() const {

		return duration;
	}

	void Movie::setTitle(const std::string& _title) {

		title = _title;
	}

	void Movie::setDirector(const std::string& _director) {

		director = _director;
	}

	void Movie::setYear(int _year) {

		year = _year;
	}

	void Movie::setStartTime(const Time& _startTime) {

		startTime = _startTime;
	}

	void Movie::setDuration(int _duration) {
		
		duration = _duration;
	}

	void Movie::serialize(std::ofstream& stream) const {

		stream << "Title: " << title << std::endl;
		stream << "Director: " << director << std::endl;
		stream << "Year: " << year << std::endl;
		stream << "Hours: " << startTime.hours << std::endl;
		stream << "Minutes: " << startTime.minutes << std::endl;
		stream << "Duration: " << duration << std::endl << std::endl;
	}

	void Movie::deserialize(std::istream& stream) {

		std::getline(stream, title);
		std::getline(stream, director);
		stream >> year;
		stream >> startTime.hours;
		stream >> startTime.minutes;
		stream >> duration;
	}