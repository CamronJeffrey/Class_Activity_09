#include <iostream>
#include <string>
#include <limits>

using namespace std;


struct Movie {
    string title, genre;
    int releaseYear;
    double rating;
};

ostream& operator<<(ostream& os, const Movie& m) {
    return os << "Title: " << m.title << "\nGenre: " << m.genre
        << "\nYear: " << m.releaseYear << "\nRating: " << m.rating << "/10\n";
}

Movie createMovie() {
    Movie m;
    cout << "Enter title: "; getline(cin, m.title);
    cout << "Enter genre: "; getline(cin, m.genre);

    cout << "Enter year: ";
    while (!(cin >> m.releaseYear) || m.releaseYear < 1888 || m.releaseYear > 2100) {
        cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid year. Try again: ";
    }

    cout << "Enter rating (0-10): ";
    while (!(cin >> m.rating) || m.rating < 0.0 || m.rating > 10.0) {
        cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid rating. Try again: ";
    }
    cin.ignore();
    return m;
}

int main() {
    Movie myMovie = createMovie();
    cout << "\nMovie Details:\n" << myMovie;
    return 0;
}
