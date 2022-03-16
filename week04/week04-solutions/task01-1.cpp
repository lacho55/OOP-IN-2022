#include <iostream>
#include <cstring>
 
const size_t MAX_SIZE = 1024;
 
class Movie {
public:
    Movie();
 
    Movie(const Movie &movie);
 
    Movie(const char *name, const char *director, size_t length);
 
    ~Movie();
 
    Movie &operator=(const Movie &movie) {
        if (this != &movie) {
            this->destroy();
            this->copy(movie);
        }
        return (*this);
    }
 
    friend std::istream &operator>>(std::istream &input, Movie &movie) {
        movie.destroy();
        char movieName[MAX_SIZE];
        char directorName[MAX_SIZE];
        size_t movieLength = 0;
 
        std::cin.getline(movieName, MAX_SIZE);
        std::cin.getline(directorName, MAX_SIZE);
        std::cin >> movieLength;
 
        Movie temp(movieName, directorName, movieLength);
        movie.copy(temp);
        temp.destroy();
        return input;
    }
 
    friend std::ostream &operator<<(std::ostream &output, const Movie &movie) {
        output << "The name of the movie:" << movie.name << '\n';
        output << "The name of the movie:" << movie.director << '\n';
        output << "The name of the movie:" << movie.length << '\n';
        return output;
    }
 
    void print();
 
private:
    char *name;
    char *director;
    size_t length;
 
    void copy(const Movie &movie);
 
    void destroy();
};
 
Movie::Movie() {
    this->name = nullptr;
    this->director = nullptr;
    this->length = 0;
}
 
Movie::Movie(const Movie &movie) {
    this->copy(movie);
}
 
Movie::Movie(const char *name, const char *director, size_t length) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
 
    this->director = new char[strlen(director) + 1];
    strcpy(this->director, director);
 
    this->length = length;
}
 
Movie::~Movie() {
    this->destroy();
}
 
void Movie::copy(const Movie &movie) {
    this->name = new char[strlen(movie.name) + 1];
    strcpy(this->name, movie.name);
 
    this->director = new char[strlen(movie.director) + 1];
    strcpy(this->director, movie.director);
 
    this->length = movie.length;
}
 
void Movie::destroy() {
    delete[] this->name;
    delete[] this->director;
}
 
//{
// Movie firstMovie();
// Movie secondMove("Random","John Doe",3);
// Movie thirdMovie(secondMovie);
//
// int x = y;
// firstMovie=secondMovie;
//firstMovie=firstMovie;
// }
 
int main() {
    Movie test1;
    std::cin >> test1;
    std::cout<<test1;
 
 
}