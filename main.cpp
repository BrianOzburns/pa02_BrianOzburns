// cs24, Mirza
// Brian Ozawa Burns, 05/24/2021

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <cstring>
#include <algorithm>
#include "movies.h"
#include "utility.h"

using namespace std;

bool parseLine(string &line, string &movieName, double &movieRating);

int main(int argc, char** argv){
  if(argc < 4){
    cerr << "Usage: " << argv[ 0 ] << "arg1 arg2 arg3" << endl;
    exit(1);
  }

  bool flag = false;
  if(strcmp(argv[1], "true") == 0){
    flag = true;
  } else if(strcmp(argv[1], "false") == 0) {
    flag = false;
  } else {
    cerr << "Argument 1 must be a boolean (true/false)" << endl;
    exit(1);
  }
  
  ifstream movieFile (argv[2]);
  string line, movieName;
  double movieRating;

  if (movieFile.fail()){
    cerr << "Could not open file " << argv[2];
    exit(1);
  }

  // Create an objects of the BST class you defined 
  // to contain the name and rating in the input file
  MoviesBST m;
  vector<string> moviesVector;
  ofstream outStream1;
  outStream1.open("moviesVisited.dat");
  outStream1 << "N\t\tN_visited" << endl;

  // Read each file and store the name and rating
  while (getline (movieFile, line) && parseLine(line, movieName, movieRating)){
    // Use std::string movieName and double movieRating
    // to construct your Movie objects
    m.insert(movieName, movieRating);
    outStream1 << m.countMovies() - 1 << "\t\t" << m.countMVisited() << endl;
    moviesVector.push_back(movieName);
  }
  m.preorderPrintTitleRatingDepth();
  outStream1.close();

  movieFile.close();

  cout << endl;
  int l = strlen(argv[3]);
  m.printBestMovie(argv[3], l);


  // time analysis
  if ( !flag ){
    ofstream outStream2;
    outStream2.open("timeAnalysis.dat");

    cout << endl;

    int W = atoi(argv[3]);
    double ft = 0.0;

    vector<double> times;

    for ( int j = 0; j < 20; j++ ){
      clock_t t = clock();
      for ( int i = 0; i < W; i++ ){
        for ( auto n : moviesVector ){
          m.getMovieTitle(n);
        }
      }
      t = clock() - t;

      outStream2.setf(ios::fixed);
      outStream2.setf(ios::showpoint);
      outStream2.precision(4);
      ft = static_cast<double>(t)*1000/CLOCKS_PER_SEC/W; // milliseconds
      outStream2 << ft << endl;
      times.push_back(ft);
    }

    double max = times[0], min = times[0], mean = 0.0, median = times[0];

    for ( auto t : times ){
      if ( t > max ){
        max = t;
      }
      if ( t < min ){
        min = t;
      }
      mean += t;
    }
    mean = mean / times.size();
    median = getMedian(times);

    outStream2 << endl << endl;
    outStream2 << "min: " << min << endl;
    outStream2 << "max: " << max << endl;
    outStream2 << "mean: " << mean << endl;
    outStream2 << "median: " << median << endl;

    outStream2.close();
  }

  return 0;
}

bool parseLine(string &line, string &movieName, double &movieRating) {
  if(line.length() <= 0) return false;
  string tempRating = "";

  bool flag = false;
  movieName = tempRating = "", movieRating = 0.0, flag = false;

  for (int i = 0; i < line.length(); i++){
    if(flag) tempRating += line[i];
    else if(line[i]==','&& line[0]!='"') flag = true;
    else {
      if(i==0 && line[0]=='"') continue;
      if(line[i]=='"'){ i++; flag=true; continue;}
      movieName += line[i];
    }
  }
  
  movieRating = stod(tempRating);
  return true;
}

