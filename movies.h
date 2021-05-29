// cs24, Mirza
// Brian Ozawa Burns, 05/24/2021

// implentation of binary search tree to store movies information

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class MoviesBST {

 public:
 
    MoviesBST(); // constructor
    ~MoviesBST(); // destructor
    bool insert(string t, double r); // insert value; return false if duplicate
    void printPreOrder() const; // prints tree data pre-order to cout

    void printInOrder() const; // print tree data in-order to cout
    void printPostOrder() const; // print tree data post-order to cout
    double sumRatings() const; // sum of all values
    int countMovies() const; // returns numMovies
    int countMVisited() const; // returns moviesVisited
    bool contains(string t) const; // true if value is in tree

    string getMovieTitle(string t) const; // returns the title of the movie containing the title t
    string getPredecessor(string t) const; // returns the predecessor value of the given value or "" if there is none
    string getSuccessor(string t) const; // returns the successor value of the given value or "" if there is none
    bool remove(string t); // deletes the Movie containing the given value from the tree

    void preorderPrintTitleRatingDepth() const; // Prints "movie title, rating, depth" in preorder
    void printBestMovie(string prefix, int prefixLength); // Prints best movie with title starting with prefix

 private:

    struct Movie {
        string title;
        double rating;
        Movie *left, *right, *parent;
        // useful constructor:
        Movie(string t = "", double v = 0) : title(t), rating(v), left(0), right(0), parent(0) { }
    };

    Movie *root;
    int numMovies = 0; // increments by 1 each time a movie is inserted
    int moviesVisited = 0; // changes every time insert function is called

    void clear(Movie *n); // for destructor
    bool insert(string t, double r, Movie *n); // note overloading names for simplicity
    void printPreOrder(Movie *n) const;
    void printInOrder(Movie *n) const;
    void printPostOrder(Movie *n) const;
    double sumRatings(Movie *n) const; // returns sum of all movie ratings
    
    stack<Movie*> findInstancesOfPrefix(stack<Movie*>& movies, Movie *m, string prefix, int prefixLength); // finds instances of movie titles that start with prefix adds them to a stack then returns the stack
    void preorderPrintTitleRatingDepth(Movie *m, int depth) const; // Prints "movie title, rating, depth" in preorder

    Movie* getMovie(string t) const; // returns the Movie containing the title t
    Movie* getSuccessorMovie(string t) const; // returns the Movie containing the successor of the given title t
    Movie* getPredecessorMovie(string t) const; // returns the Movie containing the predecessor of the given title t 
};