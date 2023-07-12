#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include "Serializable.h"
#include "Movie.h"
#include "MovieCatalog.h"

MovieCatalog::MovieCatalog(const std::string& filename) {

	std::ifstream file(filename, std::ios::binary);
	if (file.is_open()) {

		deserialize(file);
		file.close();

	}
	else {

		cinemaName = filename.substr(0, filename.find(".bin"));
		std::time_t currentDate = std::time(nullptr);
		std::tm now;
		localtime_s(&now, &currentDate);

		date.year = now.tm_year + 1900;
		date.month = now.tm_mon + 1;
		date.day = now.tm_mday;

	}
}

MovieCatalog::MovieCatalog(const MovieCatalog& other) {

	copy(other);
}

MovieCatalog::~MovieCatalog() {

	std::ofstream file(cinemaName + ".bin", std::ios::binary);
	if (file.is_open()) {
		serialize(file);
		file.close();
	}
}

MovieCatalog& MovieCatalog::operator=(const MovieCatalog& other) {

	if (this != &other) {

		MovieCatalog::~MovieCatalog();
		copy(other);
	}
	return *this;
}

void MovieCatalog::addMovie(const Movie& movie) {

	movies.push_back(movie);
}

void MovieCatalog::removeMovie(const std::string& title) {

	for (auto it = movies.begin(); it != movies.end(); ++it) {

		if (it->getTitle() == title) {

			movies.erase(it);
			return;
		}
	}
}

Movie* MovieCatalog::findMovie(const std::string& title) {

	for (auto& movie : movies) {

		if (movie.getTitle() == title) {

			return &movie;
		}
	}

	throw std::runtime_error("The movie was not found.");
}

int MovieCatalog::moviesInTimeInterval(const Time& startTime, const Time& endTime) {

	int count = 0;
	for(const auto& movie : movies) {

		if (movie.getTime().hours > startTime.hours
			|| (movie.getTime().hours == startTime.hours && movie.getTime().minutes >= startTime.minutes)) {

			if (movie.getTime().hours < endTime.hours
				|| (movie.getTime().hours == endTime.hours && movie.getTime().minutes < endTime.minutes)) {

				count++;
			}
		}
	}

	return count;
}

void MovieCatalog::serialize(std::ofstream& stream) const {

	stream << "Cinema name: " << cinemaName << std::endl << std::endl;
	stream << "Day: " << date.day << std::endl;
	stream << "Month: " << date.month << std::endl;
	stream << "Year: " << date.year << std::endl;
	stream << "Movies count: " << movies.size() << std::endl << std::endl;

	for (const auto& movie : movies) {

		movie.serialize(stream);
	}
}

void MovieCatalog::deserialize(std::istream& stream) {

	std::getline(stream, cinemaName);
	stream >> date.day;
	stream >> date.year;

	int moviesCount;
	stream >> moviesCount;

	movies.clear();

	for (size_t i = 0; i < moviesCount; ++i) {

		Movie movie("", "", 0, { 0, 0 }, 0);
		movie.deserialize(stream);
		movies.push_back(movie);
	}
}

void MovieCatalog::copy(const MovieCatalog& other) {

	cinemaName = other.cinemaName;
	date = other.date;
}