/** Path.h is the header file for Path.cpp
 */

#ifndef PATH_H_
#define PATH_H_

#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>

using namespace std;

class Path
{
  public:
    Path();
    int find(const string &program) const;
    char *getDirectory(int i) const;

  private:
    vector<string> dirVec;
};

#endif
