// cs24, Mirza
// Brian Ozawa Burns, 05/24/2021

// contains test code for all classes and methods

#include "tests.h"
#include "movies.h"

int main(){

    cout << endl << endl;

    TEST_INSERT();
    TEST_COUNTMOVIES_AND_SUMRATING();
    TEST_CONTAINS();
    TEST_GET_SUCCESSOR();
    TEST_GET_PREDECESSOR();
    // TEST_FIND_INSTANCES_OF_PREFIX(); // Tests private class function which cannot be accessed anymore
    TEST_PRINT_BEST_MOVIE();

    return 0;
}


void START_TEST(string t){
    cout << "TESTING " << t << "FUNCTION" << endl;
    cout << "----------------------------------" << endl;
}
void END_TEST(){
    cout << "----------------------------------" << endl;
}


void TEST_INSERT(){
    START_TEST("INSERT");
    test_insert_empty();
    test_insert_min();
    test_insert_max();
    test_insert_already_existing();
    END_TEST();
}
void test_insert_empty(){
    MoviesBST m;
    m.insert("Toy Story 3", 8.1);

    cout << "expected:" << endl << "Toy Story 3, 8.1" << endl;
    cout << "actual:" << endl;
    m.printInOrder();
    cout << endl;
}
void test_insert_min(){
    MoviesBST m;
    m.insert("Toy Story 3", 8.1);
    m.insert("Toy Story 4", 7.9);
    m.insert("Monster House", 6.8);

    m.insert("Alvin and the Chipmunks", 10.0);

    cout << "expected:" << endl;
    cout << "Alvin and the Chipmunks, 10" << endl;
    cout << "Monster House, 6.8" << endl;
    cout << "Toy Story 3, 8.1" << endl;
    cout << "Toy Story 4, 7.9" << endl;
    cout << "actual:" << endl;
    m.printInOrder();
    cout << endl;
}
void test_insert_max(){
    MoviesBST m;
    m.insert("Toy Story 3", 8.1);
    m.insert("Toy Story 4", 7.9);
    m.insert("Monster House", 6.8);

    m.insert("Wakefield", 1.0);

    cout << "expected:" << endl;
    cout << "Alvin and the Chipmunks, 10" << endl;
    cout << "Toy Story 3, 8.1" << endl;
    cout << "Toy Story 4, 7.9" << endl;
    cout << "Wakefield, 1" << endl;
    cout << "actual:" << endl;
    m.printInOrder();
    cout << endl;
}
void test_insert_already_existing(){
    MoviesBST m;
    m.insert("Toy Story 3", 8.1);
    m.insert("Toy Story 4", 7.9);
    m.insert("Monster House", 6.8);

    m.insert("Toy Story 4", 1.0);

    cout << "expected:" << endl;
    cout << "Monster House, 6.8" << endl;
    cout << "Toy Story 3, 8.1" << endl;
    cout << "Toy Story 4, 7.9" << endl;
    cout << "actual:" << endl;
    m.printInOrder();
    cout << endl;
}


void TEST_COUNTMOVIES_AND_SUMRATING(){
    START_TEST("COUNT AND SUM");
    test_sum_empty();
    test_sum();
    test_count_empty();
    test_count();
    END_TEST();
}
void test_sum_empty(){
    MoviesBST m;

    cout << "expected:" << endl << "0" << endl;
    cout << "actual:" << endl << m.sumRatings() << endl;
    cout << endl;
}
void test_sum(){
    MoviesBST m;
    m.insert("Toy Story 3", 8.1);
    m.insert("Toy Story 4", 7.9);
    m.insert("Monster House", 6.8);
    m.insert("Alvin and the Chipmunks", 10.0);

    cout << "expected:" << endl;
    cout << "32.8" << endl;
    cout << "actual:" << endl;
    cout << m.sumRatings() << endl;
    cout << endl;
}
void test_count_empty(){
    MoviesBST m;

    cout << "expected:" << endl << "0" << endl;
    cout << "actual:" << endl << m.countMovies() << endl;
    cout << endl;
}
void test_count(){
    MoviesBST m;
    m.insert("Toy Story 3", 8.1);
    m.insert("Toy Story 4", 7.9);
    m.insert("Monster House", 6.8);
    m.insert("Alvin and the Chipmunks", 10.0);

    cout << "expected:" << endl << "4" << endl;
    cout << "actual:" << endl << m.countMovies() << endl;
    cout << endl;
}


void TEST_CONTAINS(){
    START_TEST("CONTAINS");
    test_does_not_contain();
    test_does_contain();
    END_TEST();
}
void test_does_not_contain(){
    MoviesBST m;
    m.insert("Toy Story 3", 8.1);
    m.insert("Toy Story 4", 7.9);
    m.insert("Monster House", 6.8);
    m.insert("Alvin and the Chipmunks", 10.0);

    cout << "expected:" << endl << "does not contain Forest Gump" << endl;
    cout << "actual:" << endl;
    if ( m.contains("Forest Gump") ){
        cout << "contains Forest Gump" << endl;
    }
    else {
        cout << "does not contain Forest Gump" << endl;
    }

    cout << endl;
}
void test_does_contain(){
    MoviesBST m;
    m.insert("Toy Story 3", 8.1);
    m.insert("Toy Story 4", 7.9);
    m.insert("Monster House", 6.8);
    m.insert("Alvin and the Chipmunks", 10.0);

    cout << "expected:" << endl << "contains Monster House" << endl;
    cout << "actual:" << endl;
    if ( m.contains("Monster House") ){
        cout << "contains Monster House" << endl;
    }
    else {
        cout << "does not contain Forest Gump" << endl;
    }

    cout << endl;
}


void TEST_GET_SUCCESSOR(){
    START_TEST("SUCCESSOR");
    test_no_successor();
    test_successor();
    test_successor_with_large_tree();
    test_last_is_successor();
    END_TEST();
}
void test_no_successor(){
    MoviesBST m;
    m.insert("Toy Story 3", 8.1);
    m.insert("Toy Story 4", 7.9);
    m.insert("Monster House", 6.8);
    m.insert("Alvin and the Chipmunks", 10.0);

    cout << "expected:" << endl << "successor of Toy Story 4: " << endl;
    cout << "actual:" << endl;
    cout << "successor of Toy Story 4: " << m.getSuccessor("Toy Story 4") << endl;

    cout << endl;
}
void test_successor(){
    MoviesBST m;
    m.insert("Toy Story 3", 8.1);
    m.insert("Toy Story 4", 7.9);
    m.insert("Monster House", 6.8);
    m.insert("Alvin and the Chipmunks", 10.0);

    cout << "expected:" << endl << "successor of Alvin and the Chipmunks: Monster House" << endl;
    cout << "actual:" << endl;
    cout << "successor of Alvin and the Chipmunks: " << m.getSuccessor("Alvin and the Chipmunks") << endl;

    cout << endl;
}
void test_successor_with_large_tree(){
    MoviesBST m;
    m.insert("Toy Story 3", 8.1);
    m.insert("Toy Story 4", 7.9);
    m.insert("Monster House", 6.8);
    m.insert("Alvin and the Chipmunks", 10.0);
    m.insert("The Dark Knight Rises", 8.9);
    m.insert("Interstellar", 10.0);
    m.insert("Inception", 9.0);
    m.insert("Jojo Rabbit", 8.9);
    m.insert("Fantastic Mr. Fox", 8.5);
    m.insert("Sharknado 1", 1.0);
    m.insert("Sharknado 2", 2.0);
    m.insert("Big Daddy", 4.8);
    m.insert("Happy Gilmore", 7.9);
    m.insert("Merry Christmas Mr. Lawrence", 9.9);
    m.insert("Zebras", 6.8);
    m.insert("Xylophones", 10.0);
    m.insert("Zebras 2", 8.9);

    cout << "expected:" << endl << "successor of Monster House: Sharknado 1" << endl;
    cout << "actual:" << endl;
    cout << "successor of Monster House: " << m.getSuccessor("Monster House") << endl;

    cout << "expected:" << endl << "successor of Toy Story 4: Xylophones" << endl;
    cout << "actual:" << endl;
    cout << "successor of Toy Story 4: " << m.getSuccessor("Toy Story 4") << endl;

    cout << "expected:" << endl << "successor of Interstellar: Jojo Rabbit" << endl;
    cout << "actual:" << endl;
    cout << "successor of Interstellar: " << m.getSuccessor("Interstellar") << endl;

    cout << "expected:" << endl << "successor of Xylophones: Zebras" << endl;
    cout << "actual:" << endl;
    cout << "successor of Xylophones: " << m.getSuccessor("Xylophones") << endl;

    cout << "expected:" << endl << "successor of Alvin and the Chipmunks: Big Daddy" << endl;
    cout << "actual:" << endl;
    cout << "successor of Alvin and the Chipmunks: " << m.getSuccessor("Alvin and the Chipmunks") << endl;

    cout << endl;
}
void test_last_is_successor(){
    MoviesBST m;
    m.insert("Toy Story 3", 8.1);
    m.insert("Toy Story 4", 7.9);
    m.insert("Monster House", 6.8);
    m.insert("Alvin and the Chipmunks", 10.0);
    m.insert("The Dark Knight Rises", 8.9);
    m.insert("Interstellar", 10.0);
    m.insert("Inception", 9.0);
    m.insert("Jojo Rabbit", 8.9);
    m.insert("Fantastic Mr. Fox", 8.5);
    m.insert("Sharknado 1", 1.0);
    m.insert("Sharknado 2", 2.0);
    m.insert("Big Daddy", 4.8);
    m.insert("Happy Gilmore", 7.9);
    m.insert("Merry Christmas Mr. Lawrence", 9.9);
    m.insert("Zebras", 6.8);
    m.insert("Xylophones", 10.0);
    m.insert("Zebras 2", 8.9);

    cout << "expected:" << endl << "successor of last Movie: " << endl;
    cout << "actual:" << endl;
    cout << "successor of last Movie: " << m.getSuccessor("Zebras 2") << endl;

    cout << endl;
}

void TEST_GET_PREDECESSOR(){
    START_TEST("PREDECESSOR");
    test_no_predecessor();
    test_predecessor();
    test_predecessor_with_large_tree();
    test_first_is_predecessor();
    END_TEST();
}
void test_no_predecessor(){
    MoviesBST m;
    m.insert("Toy Story 3", 8.1);
    m.insert("Toy Story 4", 7.9);
    m.insert("Monster House", 6.8);
    m.insert("Alvin and the Chipmunks", 10.0);

    cout << "expected:" << endl << "predecessor of Alvin and the Chipmunks: " << endl;
    cout << "actual:" << endl;
    cout << "predecessor of Alvin and the Chipmunks: " << m.getPredecessor("Alvin and the Chipmunks") << endl;

    cout << endl;
}
void test_predecessor(){
    MoviesBST m;
    m.insert("Toy Story 3", 8.1);
    m.insert("Toy Story 4", 7.9);
    m.insert("Monster House", 6.8);
    m.insert("Alvin and the Chipmunks", 10.0);

    cout << "expected:" << endl << "predecessor of Monster House: Alvin and the Chipmunks" << endl;
    cout << "actual:" << endl;
    cout << "predecessor of Monster House: " << m.getPredecessor("Monster House") << endl;

    cout << endl;
}
void test_predecessor_with_large_tree(){
    MoviesBST m;
    m.insert("Toy Story 3", 8.1);
    m.insert("Toy Story 4", 7.9);
    m.insert("Monster House", 6.8);
    m.insert("Alvin and the Chipmunks", 10.0);
    m.insert("The Dark Knight Rises", 8.9);
    m.insert("Interstellar", 10.0);
    m.insert("Inception", 9.0);
    m.insert("Jojo Rabbit", 8.9);
    m.insert("Fantastic Mr. Fox", 8.5);
    m.insert("Sharknado 1", 1.0);
    m.insert("Sharknado 2", 2.0);
    m.insert("Big Daddy", 4.8);
    m.insert("Happy Gilmore", 7.9);
    m.insert("Merry Christmas Mr. Lawrence", 9.9);
    m.insert("Zebras", 6.8);
    m.insert("Xylophones", 10.0);
    m.insert("Zebras 2", 8.9);

    cout << "expected:" << endl << "predecessor of Toy Story 3: The Dark Knight Rises" << endl;
    cout << "actual:" << endl;
    cout << "predecessor of Toy Story 3: " << m.getPredecessor("Toy Story 3") << endl;

    cout << "expected:" << endl << "predecessor of Sharknado 1: Monster House" << endl;
    cout << "actual:" << endl;
    cout << "predecessor of Sharknado 1: " << m.getPredecessor("Sharknado 1") << endl;

    cout << "expected:" << endl << "predecessor of Fantastic Mr. Fox: Big Daddy" << endl;
    cout << "actual:" << endl;
    cout << "predecessor of Fantastic Mr. Fox: " << m.getPredecessor("Fantastic Mr. Fox") << endl;

    cout << "expected:" << endl << "predecessor of Jojo Rabbit: Interstellar" << endl;
    cout << "actual:" << endl;
    cout << "predecessor of Jojo Rabbit: " << m.getPredecessor("Jojo Rabbit") << endl;

    cout << "expected:" << endl << "predecessor of Xylophones: Toy Story 4" << endl;
    cout << "actual:" << endl;
    cout << "predecessor of Xylophones: " << m.getPredecessor("Xylophones") << endl;

    cout << endl;
}
void test_first_is_predecessor(){
    MoviesBST m;
    m.insert("Toy Story 3", 8.1);
    m.insert("Toy Story 4", 7.9);
    m.insert("Monster House", 6.8);
    m.insert("Alvin and the Chipmunks", 10.0);
    m.insert("The Dark Knight Rises", 8.9);
    m.insert("Interstellar", 10.0);
    m.insert("Inception", 9.0);
    m.insert("Jojo Rabbit", 8.9);
    m.insert("Fantastic Mr. Fox", 8.5);
    m.insert("Sharknado 1", 1.0);
    m.insert("Sharknado 2", 2.0);
    m.insert("Big Daddy", 4.8);
    m.insert("Happy Gilmore", 7.9);
    m.insert("Merry Christmas Mr. Lawrence", 9.9);
    m.insert("Zebras", 6.8);
    m.insert("Xylophones", 10.0);
    m.insert("Zebras 2", 8.9);

    cout << "expected:" << endl << "predecessor of first movie: " << endl;
    cout << "actual:" << endl;
    cout << "predecessor of first movie: " << m.getPredecessor("Alvin and the Chipmunks") << endl;

    cout << endl;
}

/*
void TEST_FIND_INSTANCES_OF_PREFIX(){
    START_TEST("FIND PREFIX");
    test_no_instance_of_prefix();
    test_one_instance_of_prefix();
    test_multiple_instances();
    END_TEST();
}
void test_no_instance_of_prefix(){
    MoviesBST m;
    m.insert("Toy Story 3", 8.1);
    m.insert("Toy Story 4", 7.9);
    m.insert("Monster House", 6.8);
    m.insert("The Dark Knight Rises", 8.9);
    m.insert("Interstellar", 10.0);
    m.insert("Inception", 9.0);
    m.insert("Jojo Rabbit", 8.9);
    m.insert("Fantastic Mr. Fox", 8.5);
    m.insert("Happy Gilmore", 7.9);
    m.insert("Merry Christmas Mr. Lawrence", 9.9);

    stack<MoviesBST::Movie*> movies;
    string prefix = "z";
    int prefixLength = 1;
    movies = m.findInstancesOfPrefix(movies, m.getPredecessorMovie(m.getSuccessor("Toy Story 3")), prefix, prefixLength);

    cout << "expected:" << endl << "movies with prefix z: " << endl;
    cout << "actual:" << endl << "movies with prefix z: ";
    int stackLength = movies.size();
    for ( int i = 0; i < stackLength; i++ ){
        cout << movies.top() << " ";
        movies.pop();
    }
    cout << endl;

    cout << endl;
}
void test_one_instance_of_prefix(){
    MoviesBST m;
    m.insert("Toy Story 3", 8.1);
    m.insert("Toy Story 4", 7.9);
    m.insert("Monster House", 6.8);
    m.insert("The Dark Knight Rises", 8.9);
    m.insert("Interstellar", 10.0);
    m.insert("Inception", 9.0);
    m.insert("Jojo Rabbit", 8.9);
    m.insert("Fantastic Mr. Fox", 8.5);
    m.insert("Happy Gilmore", 7.9);
    m.insert("Merry Christmas Mr. Lawrence", 9.9);

    stack<MoviesBST::Movie*> movies;
    string prefix = "The";
    int prefixLength = 3;
    movies = m.findInstancesOfPrefix(movies, m.getPredecessorMovie(m.getSuccessor("Toy Story 3")), prefix, prefixLength);

    cout << "expected:" << endl << "movies with prefix The: The Dark Knight Rises" << endl;
    cout << "actual:" << endl << "movies with prefix The: ";
    int stackLength = movies.size();
    for ( int i = 0; i < stackLength; i++ ){
        cout << movies.top() << " ";
        movies.pop();
    }
    cout << endl;

    cout << endl;
}
void test_multiple_instances(){
    MoviesBST m;
    m.insert("Toy Story 3", 8.1);
    m.insert("Toy Story 4", 7.9);
    m.insert("Monster House", 6.8);
    m.insert("The Dark Knight Rises", 8.9);
    m.insert("Interstellar", 10.0);
    m.insert("Inception", 9.0);
    m.insert("Jojo Rabbit", 8.9);
    m.insert("Fantastic Mr. Fox", 8.5);
    m.insert("Happy Gilmore", 7.9);
    m.insert("Merry Christmas Mr. Lawrence", 9.9);

    stack<MoviesBST::Movie*> movies;
    string prefix = "Toy";
    int prefixLength = 3;
    movies = m.findInstancesOfPrefix(movies, m.getPredecessorMovie(m.getSuccessor("Toy Story 3")), prefix, prefixLength);

    cout << "expected:" << endl << "movies with prefix Toy: Toy Story 4 Toy Story 3" << endl;
    cout << "actual:" << endl << "movies with prefix Toy: ";
    int stackLength = movies.size();
    for ( int i = 0; i < stackLength; i++ ){
        cout << movies.top() << " ";
        movies.pop();
    }
    cout << endl;

    cout << endl;
}
*/

void TEST_PRINT_BEST_MOVIE(){
    START_TEST("PRINT BEST MOVIE");
    test_no_instance_of_movie();
    test_one_instance_of_movie();
    test_multiple_movies_with_prefix();
    END_TEST();
}
void test_no_instance_of_movie(){
    MoviesBST m;
    m.insert("Toy Story 3", 8.1);
    m.insert("Toy Story 4", 7.9);
    m.insert("Monster House", 6.8);
    m.insert("The Dark Knight Rises", 8.9);
    m.insert("Interstellar", 10.0);
    m.insert("Inception", 9.0);
    m.insert("Jojo Rabbit", 8.9);
    m.insert("Fantastic Mr. Fox", 8.5);
    m.insert("Happy Gilmore", 7.9);
    m.insert("Merry Christmas Mr. Lawrence", 9.9);

    cout << "expected:" << endl << "prefix z: " << endl;
    cout << "actual:" << endl << "prefix z: ";
    m.printBestMovie("z", 1);

    cout << endl;
}
void test_one_instance_of_movie(){
    MoviesBST m;
    m.insert("Toy Story 3", 8.1);
    m.insert("Toy Story 4", 7.9);
    m.insert("Monster House", 6.8);
    m.insert("The Dark Knight Rises", 8.9);
    m.insert("Interstellar", 10.0);
    m.insert("Inception", 9.0);
    m.insert("Jojo Rabbit", 8.9);
    m.insert("Fantastic Mr. Fox", 8.5);
    m.insert("Happy Gilmore", 7.9);
    m.insert("Merry Christmas Mr. Lawrence", 9.9);

    cout << "expected:" << endl << "prefix The: Best movie is The Dark Knight Rises with rating 8.9" << endl;
    cout << "actual:" << endl << "prefix The: ";
    m.printBestMovie("The", 3);

    cout << endl;
}
void test_multiple_movies_with_prefix(){
    MoviesBST m;
    m.insert("Toy Story 3", 8.1);
    m.insert("Toy Story 4", 7.9);
    m.insert("Monster House", 6.8);
    m.insert("The Dark Knight Rises", 8.9);
    m.insert("Interstellar", 10.0);
    m.insert("Inception", 9.0);
    m.insert("Jojo Rabbit", 8.9);
    m.insert("Fantastic Mr. Fox", 8.5);
    m.insert("Happy Gilmore", 7.9);
    m.insert("Merry Christmas Mr. Lawrence", 9.9);

    cout << "expected:" << endl << "prefix Toy: Best movie is Toy Story 3 with rating 8.1" << endl;
    cout << "actual:" << endl << "prefix Toy: ";
    m.printBestMovie("Toy", 3);

    cout << endl;
}