#pragma once
#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include <string>
#include "Serializable.h"
#include "Movie.h"

struct Date {

	int day;
	int month;
	int year;
};

class MovieCatalog : public Serializable {

private:
	std::string cinemaName;
	Date date;
	std::vector<Movie> movies;

public:
	MovieCatalog(const std::string& filename);
	MovieCatalog(const MovieCatalog& other);
	~MovieCatalog();
	MovieCatalog& operator=(const MovieCatalog& other);

	void addMovie(const Movie& movie);
	void removeMovie(const std::string& title);
	Movie* findMovie(const std::string& title);
	int moviesInTimeInterval(const Time& startTime, const Time& endTime);

	void serialize(std::ofstream& stream) const override;
	void deserialize(std::istream& stream) override;

	void copy(const MovieCatalog& other);
};