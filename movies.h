// cs24, Mirza
// Brian Ozawa Burns, 05/24/2021

// implentation of binary search tree to store movies information

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class MoviesBST {

 public:
 
    MoviesBST();                   // constructor
    ~MoviesBST();                  // destructor
    bool insert(string t, double r);     // insert value; return false if duplicate
    void printPreOrder() const; // prints tree data pre-order to cout

    void printInOrder() const;       // print tree data in-order to cout
    void printPostOrder() const;     // print tree data post-order to cout
    double sumRatings() const;                 // sum of all values
    int countMovies() const;               // count of values
    bool contains(string t) const;  // true if value is in tree

    string getPredecessor(string t) const;       // returns the predecessor value of the given value or "" if there is none
    string getSuccessor(string t) const;         // returns the successor value of the given value or "" if there is none
    bool remove(string t);                    // deletes the Movie containing the given value from the tree

    void preorderPrintTitleRatingDepth() const;     // Prints "movie title, rating, depth" in preorder
    void printBestMovie(string prefix, int prefixLength);     // Prints best movie with title starting with prefix

 private:

    struct Movie {
        string title;
        double rating;
        Movie *left, *right, *parent;
        // useful constructor:
        Movie(string t = "", double v = 0) : title(t), rating(v), left(0), right(0), parent(0) { }
    };

    // just one instance variable (pointer to root Movie):
    Movie *root;

    // recursive utility functions for use by public methods above
    void clear(Movie *n); // for destructor
    bool insert(string t, double r, Movie *n); // note overloading names for simplicity
    void printPreOrder(Movie *n) const;
    void printInOrder(Movie *n) const;
    void printPostOrder(Movie *n) const;
    double sumRatings(Movie *n) const;
    int countMovies(Movie *n) const;
    
    stack<Movie*> findInstancesOfPrefix(stack<Movie*>& movies, Movie *m, string prefix, int prefixLength);   // finds instances of movie titles that start with prefix adds them to a stack then returns the stack
    void preorderPrintTitleRatingDepth(Movie *m, int depth) const;     // Prints "movie title, rating, depth" in preorder

    // these should be used by getPredecessor and getSuccessor, and ONE of them should be used by remove
    Movie* getSuccessorMovie(string t) const;   // returns the Movie containing the successor of the given value
    Movie* getPredecessorMovie(string t) const; // returns the Movie containing the predecessor of the given value 
};