// cs24, Mirza
// Brian Ozawa Burns, 05/24/2021

// implentation of binary search tree to store movies information

#include "movies.h"

// constructor sets up empty tree
MoviesBST::MoviesBST() : root(0) { }

// destructor deletes all Movies
MoviesBST::~MoviesBST() {
    clear(root);
}

// recursive helper for destructor
void MoviesBST::clear(Movie *n) {
    if (n) {
        clear(n->left);
        clear(n->right);
        delete n;
    }
}

// insert title t and rating r in tree; return false if duplicate
bool MoviesBST::insert(string t, double r) {
    // handle special case of empty tree first
    if (!root) {
        root = new Movie(t, r);
        return true;
    }
    // otherwise use recursive helper
    return insert(t, r, root);
}

// recursive helper for insert (assumes n is never 0)
bool MoviesBST::insert(string t, double r, Movie *n) {
    if (t == n->title)
	    return false;
    if (t < n->title) {
        if (n->left)
            return insert(t, r, n->left);
        else {
            n->left = new Movie(t, r);
            n->left->parent = n;
            return true;
        }
    }
    else {
        if (n->right)
            return insert(t, r, n->right);
        else {
            n->right = new Movie(t, r);
            n->right->parent = n;
            return true;
        }
    }
}

// print tree data pre-order
void MoviesBST::printPreOrder() const {
    printPreOrder(root);
}

// recursive helper for printPreOrder()
void MoviesBST::printPreOrder(Movie *n) const {
    if (n) {
        cout << n->title << ", " << n->rating << endl;
        printPreOrder(n->left);
        printPreOrder(n->right);
    }
}

// print tree data in-order, with helper
void MoviesBST::printInOrder() const {
    printInOrder(root);
}
void MoviesBST::printInOrder(Movie *n) const {
    if ( !n ){ // root doesn't exist, tree/subtree empty
        return;
    }
    else { // tree not empty, order: left Movie, root Movie, right Movie
        if ( n->left ){
            printInOrder(n->left);
        }
        cout << n->title << ", " << n->rating << endl;
        if ( n->right ){
            printInOrder(n->right);
        }
    }
}

// prints tree data post-order, with helper
void MoviesBST::printPostOrder() const {
    printPostOrder(root);
}

void MoviesBST::printPostOrder(Movie *n) const {
    if ( !n ){ // root doesn't exist, tree/subtree empty
        return;
    }
    else { // tree not empty, order: left Movie, right Movie, root Movie
        if ( n->left ){
            printPostOrder(n->left);
        }
        if ( n->right ){
            printPostOrder(n->right);
        }
        cout << n->title << ", " << n->rating << endl;
    }
}

// return sum of ratings in tree
double MoviesBST::sumRatings() const {
    return sumRatings(root);
}

// recursive helper for sum
double MoviesBST::sumRatings(Movie *n) const {
    double total = 0.0;
    if ( !n ){ // root doesn't exist, tree/subtree empty
        return 0;
    }
    else { // tree not empty, return sum of left and right subtree Movies with current Movie's title
        if ( n->left ){
            total += sumRatings(n->left);
        }
        if ( n->right ){
            total += sumRatings(n->right);
        }
        return total + n->rating;
    }
}

// return number of movies in tree
int MoviesBST::countMovies() const {
    return countMovies(root);
}

// recursive helper for count
int MoviesBST::countMovies(Movie *n) const {
    int numMovies = 0;
    if ( !n ){ // root doesn't exist, tree/subtree empty
        return 0;
    }
    else { // tree not empty, return sum of numMovies in left and right subtrees +1 with current Movie included
        if ( n->left ){
            numMovies += countMovies(n->left);
        }
        if ( n->right ){
            numMovies += countMovies(n->right);
        }
        return numMovies + 1;
    }

    return 0;
}

// returns true if title t is in the tree; false if not
bool MoviesBST::contains(string t) const {
    Movie *n;
    n = this->root;
    if ( !n ){ // root doesn't exist, tree/subtree empty
        return false;
    }
    while ( n ){
        if ( t < n->title ){ // search left subtree
            n = n->left;
        }
        else if ( t > n->title ){ // search right subtree
            n = n->right;
        }
        else { // n->title is t, return true
            return true;
        }
    }

    return false; 
}

// returns the Movie containing the title t
MoviesBST::Movie* MoviesBST::getMovie(string t) const{
    Movie *n;
    n = root;
    if ( !n ){ // root doesn't exist, tree/subtree empty
        return nullptr;
    }
    if ( contains(t) ){ // check to make sure title t is in fact contained within the BST
        while ( n ){
            if ( t < n->title ){ // search left subtree for title t
                n = n->left;
            }
            else if ( t > n->title ){ // search right subtree for title t
                n = n->right;
            }
            else{ // title t found
                return n;
            }
        }
    }
    return nullptr;
}

// returns the Movie containing the predecessor of the given title t
MoviesBST::Movie* MoviesBST::getPredecessorMovie(string t) const{
    Movie *n;
    n = root;
    if ( !n ){ // root doesn't exist, tree/subtree empty
        return nullptr;
    }
    if ( contains(t) ){ // checks to make sure title t is in fact contained within the BST
        while ( n ){
            if ( t < n->title ){ // search left subtree for title t
                n = n->left;
            }
            else if ( t > n->title ){ // search right subtree for title t
                n = n->right;
            }
            else{ // title t found, now find predecessor
                if ( !n->parent && !n->left ){ // if Movie has no parent and no left subtree, then there is no predecessor
                    return nullptr;
                }
                else if ( n->parent && !n->left ){ // else if Movie has no left subtree, but has a parent
                    if ( n->parent->title < n->title ){ // check if parent is predecessor
                        return n->parent;
                    }
                    else if ( n->parent->title > n->title ){ // check if parent's parent is predecessor and so on until null
                        n = n->parent;
                        while ( n->parent->parent ){
                            n = n->parent;
                            if ( n->title < t ){ // return first parent whose rating is less than title t
                                return n;
                            }
                        }
                        if ( n->parent->title < t ){ // n->parent->parent is null so checking root if predecessor
                            return n->parent;
                        }
                        else { // no parent is predecessor, return nullptr
                            return nullptr;
                        }
                    }
                    else {
                        return nullptr;
                    }
                }
                else if ( n->left ){ // else left subtree exists, predecessor is the rightmost element of left subtree
                    n = n->left;
                    while ( n && n->right ){
                        n = n->right;
                    }
                    return n;
                }
            }
        }
    }
    return nullptr;
}

// returns the predecessor title of the given title t or "" if there is none
string MoviesBST::getPredecessor(string t) const{
    Movie *n;
    n = root;
    if ( !n ){ // root doesn't exist, tree/subtree empty
        return "";
    }
    if ( contains(t) ){ // checks to make sure title t is in fact contained within the BST
        while ( n ){
            if ( t < n->title ){ // search left subtree for title t
                n = n->left;
            }
            else if ( t > n->title ){ // search right subtree for title t
                n = n->right;
            }
            else{ // title t found, now find predecessor
                if ( !n->parent && !n->left ){ // if Movie has no parent and no left subtree, then there is no predecessor
                    return "";
                }
                else if ( n->parent && !n->left ){ // else if Movie has no left subtree, but has a parent
                    if ( n->parent->title < n->title ){ // check if parent is predecessor
                        return n->parent->title;
                    }
                    else if ( n->parent->title > n->title ){ // check if parent's parent is predecessor and so on until null
                        n = n->parent;
                        while ( n->parent->parent ){
                            n = n->parent;
                            if ( n->title < t ){ // return first parent whose rating is less than title t
                                return n->title;
                            }
                        }
                        if ( n->parent->title < t ){ // n->parent->parent is null so checking root if predecessor
                            return n->parent->title;
                        }
                        else { // no parent is predecessor, return 0
                            return "";
                        }
                    }
                    else {
                        return "";
                    }
                }
                else if ( n->left ){ // else left subtree exists, predecessor is the rightmost element of left subtree
                    n = n->left;
                    while ( n && n->right ){
                        n = n->right;
                    }
                    return n->title;
                }
            }
        }
    }
    return "";
}

// returns the Movie containing the successor of the given title t
MoviesBST::Movie* MoviesBST::getSuccessorMovie(string t) const{
    Movie *n;
    n = root;
    if ( !n ){ // root doesn't exist, tree/subtree empty
        return nullptr;
    }
    if ( contains(t) ){ // checks to make sure title t is in fact contained within the BST
        while ( n ){
            if ( t < n->title ){ // search left subtree for title t
                n = n->left;
            }
            else if ( t > n->title ){ // search right subtree for title t
                n = n->right;
            }
            else{ // title t found, now find successor
                if ( !n->parent && !n->right ){ // if Movie has no parent and no right subtree, then there is no successor
                    return nullptr;
                }
                else if ( n->parent && !n->right ){ // else if Movie has no right subtree, but has a parent, then check if parent is successor
                    if ( n->parent->title > n->title ){
                        return n->parent;
                    }
                    else {
                        if ( n->parent->parent ){
                            n = n->parent;
                            while ( n->parent ){
                                if ( n->title > t ){
                                    return n;
                                }
                                n = n->parent;
                            }
                            if ( n->parent ){
                                if (n->parent->title > t){
                                    return n->parent;
                                }
                                else {
                                    return nullptr;
                                }
                            }
                            else {
                                return nullptr;
                            }
                        }
                        else {
                            return nullptr;
                        }
                    }
                }
                else if ( n->right ){ // else right subtree exists, successor is the leftmost element of right subtree
                    n = n->right;
                    while ( n && n->left ){
                        n = n->left;
                    }
                    return n;
                }
            }
        }
    }
    return nullptr; 
}

// returns the successor title of the given title t or "" if there is none
string MoviesBST::getSuccessor(string t) const{
    Movie *n;
    n = root;
    if ( !n ){ // root doesn't exist, tree/subtree empty
        return "";
    }
    if ( contains(t) ){ // checks to make sure title t is in fact contained within the BST
        while ( n ){
            if ( t < n->title ){ // search left subtree for title t
                n = n->left;
            }
            else if ( t > n->title ){ // search right subtree for title t
                n = n->right;
            }
            else { // title t found, now find successor
                if ( !n->parent && !n->right ){ // if Movie has no parent and no right subtree, then there is no successor
                    return "";
                }
                else if ( n->parent && !n->right ){ // else if Movie has no right subtree, but has a parent, then check if parent is successor
                    if ( n->parent->title > n->title ){
                        return n->parent->title;
                    }
                    else {
                        if ( n->parent->parent ){
                            n = n->parent;
                            while ( n->parent ){
                                if ( n->title > t ){
                                    return n->title;
                                }
                                n = n->parent;
                            }
                            if ( n->parent ){
                                if (n->parent->title > t){
                                    return n->parent->title;
                                }
                                else {
                                    return "";
                                }
                            }
                            else {
                                return "";
                            }
                        }
                        else {
                            return "";
                        }
                    }
                }
                else if ( n->right ){ // else right subtree exists, successor is the leftmost element of right subtree
                    n = n->right;
                    while ( n && n->left ){
                        n = n->left;
                    }
                    return n->title;
                }
            }
        }
    }
    return "";
}

// deletes the Movie containing the given title t from the tree
// returns true if the Movie exist and was deleted or false if the Movie does not exist
bool MoviesBST::remove(string t){
    if ( !root ){ // root doesn't exist, tree/subtree empty
        return false;
    }
    if ( contains(t) ){ // if title t is in tree, find it, remove it
        Movie *n;
        n = root;
        while ( n ){
            if ( t < n->title ){ // search left subtree for title t
                n = n->left;
            }
            else if ( t > n->title ){ // search right subtree for title t
                n = n->right;
            }
            else { // title t found, remove it and update BST
                if ( !n->left && !n->right ){ // no left or right subtrees
                    if ( !n->parent ){ // Movie to delete is the root
                        root = nullptr;
                    }
                    else if ( n->parent->left == n ){
                        n->parent->left = nullptr;
                    }
                    else {
                        n->parent->right = nullptr;
                    }
                    delete n;
                    return true;
                }   
                else if ( n->left && !n->right ){ // no right subtree
                    if ( !n->parent ){ // Movie to delete is the root
                        root = n->left;
                    }
                    else if ( n->parent->left == n ){
                        n->parent->left = n->left;
                    }
                    else {
                        n->parent->right = n->left;
                    }
                    delete n;
                    return true;
                }
                else if ( !n->left && n->right ){ // no left subtree
                    if ( !n->parent ){ // Movie to delete is the root
                        root = n->right;
                    }
                    else if ( n->parent->left == n ){
                        n->parent->left = n->right;
                    }
                    else {
                        n->parent->right = n->right;
                    }
                    delete n;
                    return true;
                }
                else { // left and right subtrees both exist
                    Movie *succ = getSuccessorMovie(t);
                    n->title = succ->title;
                    n = n->right;
                    t = succ->title;
                }
            }
        }
    }
    // else title t is not in tree, return false
    return false;
}

void MoviesBST::preorderPrintTitleRatingDepth() const{
    preorderPrintTitleRatingDepth(root, 0);
}

void MoviesBST::preorderPrintTitleRatingDepth(MoviesBST::Movie *m, int depth) const{
    // traverse the tree to find title t then print title, rating, depth
    if ( m ){
        cout << m->title << ", " << m->rating << ", " << depth << endl;
    }
    if ( m->left ){
        preorderPrintTitleRatingDepth(m->left, depth+1);
    }
    if ( m->right ){
        preorderPrintTitleRatingDepth(m->right, depth+1);
    }
}

void MoviesBST::printBestMovie(string prefix, int prefixLength){
    // traverse the tree for all instances of movies whose title begins with prefix
    Movie *m = this->root;
    stack<Movie*> movies;
    movies = findInstancesOfPrefix(movies, m, prefix, prefixLength);

    string bestMovieTitle = "";
    double bestMovieRating = 0;

    int stackLength = movies.size();
    for ( int i = 0; i < stackLength; i++ ){
        Movie *current = movies.top();
        movies.pop();
        if ( current->rating > bestMovieRating ){
            bestMovieTitle = current->title;
            bestMovieRating = current->rating;
        }
    }
    if ( bestMovieTitle != "" ){
        cout << "Best movie is " << bestMovieTitle << " with rating " << bestMovieRating << endl;
    }
}

stack<MoviesBST::Movie*> MoviesBST::findInstancesOfPrefix(stack<MoviesBST::Movie*>& movies, MoviesBST::Movie *m, string prefix, int prefixLength){

    if ( !m ){
        return movies;
    }
    findInstancesOfPrefix(movies, m->left, prefix, prefixLength);
    if ( (m->title).substr(0, prefixLength) == prefix ){
        movies.push(m);
    }
    findInstancesOfPrefix(movies, m->right, prefix, prefixLength);

    return movies;
}