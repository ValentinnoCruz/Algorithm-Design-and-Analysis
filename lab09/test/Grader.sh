#!/usr/bin/env bash
#
# Copyright (c) 2018 by
# Arman Zharmagambetov, Yerlan Idelbayev and Miguel A. Carreira-Perpinan

# This "Grader.sh" script is for testing the correctness of your code with a
# collection of test files.
#
# Usage (assume your UC Merced id is jsmith5):
# 1. Create a working directory and put in it this script (Grader.sh), your
#    code in a single file jsmith5.cpp, and all the test files (inputs and
#    outputs) inside a subdirectory called testfiles/. Ensure Grader.sh has
#    execute permissions:
#    $ chmod +x ./Grader.sh
# 2. Compile your code with the GNU C++ compiler using the 2011 C++ standard
#    and put the resulting executable in a file a.exe:
#    $ g++ -std=c++11 -o a.exe jsmith5.cpp
# 3. Run the Grader.sh script:
#    $ ./Grader.sh
#    This will test all examples and print whether they work or not, like this:
#       Test 1: correct.
#       Test 2: correct.
#       Test 3: INCORRECT.
#       Test 4: correct.
#       Test 5: correct.
#       Total correct: 4/5
# 4. To see the output of your code with a given test file:
#    $ ./a.exe < testfiles/t3
#    This should be identical to testfiles/o3 for the code to pass that test.
# 5. When you are ready to submit your code, submit only the single file
#    jsmith5.cpp.
#
# We have tested this script in a few different systems, but we can only
# guarantee that it works in the CSE100 lab computers, so ensure you test
# your code there before you submit it.
# See the course web page for lab policies and guidelines.


# Find test files that exist in testfiles/ and put their numbers in an array.
# Ex: o1 o10 o3 -> tests=(1 10 3)
tests=(); for v in `find testfiles/o*`; do tests+=(${v:11}); done
# Sort them. Ex: tests=(1 3 10)
tests=($(printf '%d\n' ${tests[@]} | sort -n))

# Apply a.exe to each test file and count how many are correct.
correct=0;
for i in ${tests[@]}; do
  ./a.exe < ./testfiles/t$i | diff -q ./testfiles/o$i - > /dev/null
  if [ "$?" -eq 0 ] ; then # if exit code is 0 then correct
    echo "Test $i: correct."
    ((correct=correct+1))
  else
    echo "Test $i: INCORRECT."
  fi
done
echo "Total correct: "$correct"/"${#tests[@]};

