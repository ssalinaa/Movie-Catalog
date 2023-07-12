#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include "Serializable.h"
#include "Movie.h"
#include "MovieCatalog.h"

int main()
{
    try {

        MovieCatalog catalog("Paradise.bin");

        Movie movie1("Fast & Furious", "Justin Lin", 2019, { 20, 0 }, 110);
        Movie movie2("Need for Speed", "Scott Waugh", 2022, { 13, 15 }, 105);
        Movie movie3("Titanic", "James Cameron", 2017, { 10, 30 }, 90);

        catalog.addMovie(movie1);
        catalog.addMovie(movie2);
        catalog.addMovie(movie3);

        Movie* foundMovie = catalog.findMovie("Need for Speed");
        if (foundMovie) {

            std::cout << "Found movie: " << foundMovie->getTitle() << ", Director: " << foundMovie->getDirector() << std::endl;
        }
        else {

            std::cout << "Movie is not found." << std::endl;
        }

        int countMovies = catalog.moviesInTimeInterval({ 12, 0 }, { 22, 0 });
        std::cout << "Movies in the interval 12:00 - 22:00: " << countMovies << std::endl;

        catalog.removeMovie("Titanic");
    }
    catch (const std::exception& e) {

        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
