# Homework Assignment 1 (due Sep 19th 11:59pm)

In this assignment, we will explore C++ dynamic memory allocation, classes 
and objects, and problem solving in general.  The assignment is worth a total 
of 100 points.  If you have any questions or need assistance, please don't 
hesitate to reach out to us during office hours or post your questions 
on the `Ed Discussion` forum.

## Preliminaries

You can choose any operating system and development environment you 
prefer, such as `Linux`, `MacOS`, or `Windows`.  However, it is 
strongly recommended that you have access to a `bash` terminal 
to interact with the compiler and other tools.  If you are 
using `Windows`, you can run `Linux` via `WSL` 
(Windows Subsystem for Linux).

The use of an integrated development environment (IDE),
especially one that offers a good debugger, is highly recommended.
Some popular IDEs include `Visual Studio Code` and `CLion`, please
contact a TA if you have any questions about setting up your environment.
Regardless of your choice of IDE, your code must compile and run
correctly using the `g++` compiler from the command line.

## Context

This assignment will use a tiny `Social Network` application to 
illustrate key concepts in C++ programming, including dynamic memory
allocation, classes and objects, and problem solving strategies.

A social network can be defined as a network of individuals or 
organizations connected by various social relationships, such as
friendship, common interests, or professional connections.

The dataset used in this assignment is a small subset of the 
Facebook social network.  The dataset was collected from survey 
participants using a Facebook app.  All data has been anonymized
to protect user privacy.  There are 4,039 users in
the dataset, and each user is represented by a unique integer ID.
Users are connected by friendship links.  There are a total of 
88,234 friendship links in the dataset.

The file containing the dataset is `facebook-combined.txt`, and uses
the following format:

```text
4039 88234
0 1
0 2
0 4
...
```

The first line contains two integers separated by a space.  The first
integer represents the number of users in the social network, and the
second integer represents the number of friendship connections in the
social network. Each of the following lines contains two
integers separated by a space, representing a friendship connection
between the two users.

You are also provided with a smaller dataset `facebook-small.txt` that
you can use for testing and debugging your code.  The smaller dataset
contains only 10 users.

## Sparse Matrices

The simplest way to represent the friendship connections is to use an
**adjacency matrix**, which is a 2D array where the rows and columns
represent the users, and the entries (0 or 1) in the matrix represent 
whether there is a friendship connection between the two users. 
For example, consider the 5x5 matrix below:

```python
0  1  0  1  1     # 0 connected to 1, 3, 4
1  0  1  1  0     # 1 connected to 0, 2, 3  
0  1  0  0  1     # 2 connected to 1, 4
1  1  0  0  0     # 3 connected to 0, 1
1  0  1  0  0     # 4 connected to 0, 2
```

In this example, there are 5 users (0, 1, 2, 3, 4).  Note that 
the matrix is symmetric, meaning that if user A is friends with user B,
then user B is also friends with user A.

The problem with using an adjacency matrix is that it can be very
large and sparse, especially for large social networks.  In our case,
the adjacency matrix would be a 4039 x 4039 matrix, which would
require over 16 million entries.  However, there are only 88,234
friendship connections, meaning that the matrix would be mostly
filled with zeros, leading to a waste of memory.

Possibilities to represent sparse matrix include:
- COO (Coordinate format): uses three arrays to store row indices,
  column indices, and values of the non-zero entries in the matrix.

```python
rows = [0, 0, 0, 1, 1, 1, 2, 2, 3, 3, 4, 4] # row indices
cols = [1, 3, 4, 0, 2, 3, 1, 4, 0, 1, 0, 2] # column indices
data = [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1] # non-zero values
```

- CSR (Compressed sparse row format): uses three arrays to store
  non-zero values, column indices of the non-zero values, and
  a row pointer array that indicates the start of each row in the
  other two arrays.

```python
data = [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1] # non-zero values
col_ind = [1, 3, 4, 0, 2, 3, 1, 4, 0, 1, 0, 2] # column indices
row_ptr = [0, 3, 6, 8, 10, 12] # row pointer
```

- CSC (Compressed sparse column format): uses three arrays to store 
  non-zero values, row indices of the non-zero values, and
  a column pointer array that indicates the start of each column
  in the other two arrays.

```python
data = [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1] # non-zero values
row_ind = [1, 3, 4, 0, 2, 3, 1, 4, 0, 1, 0, 2] # row indices
col_ptr = [0, 3, 6, 8, 10, 12] # column pointer
```

## Task 1 (40 points)

In this task, the goal is to develop a class `Network` that represents
the social network.  The class should be able to read the dataset from
a file and store the friendship connections in an appropriate data 
structure.

You are free to pick any of the three sparse matrix representations
mentioned above (COO, CSR, CSC) to store the friendship connections.
In fact, you can also choose to implement more than one representation
and compare their performance.  The choice is yours.

As the `data` array is always filled with 1s (indicating a friendship 
connection), you can choose to omit it from your implementation.

The class **must** declare all data elements as `private` and provide
`public` methods to access and manipulate the data.  

To implement your class, you will need to use dynamic memory allocation
to allocate memory for the arrays that store the friendship connections.
Their lengths will depend on the exact number of users and friendship
connections in the dataset.

Your class should use the following definition and saved as `network.h`:

```cpp
class Network {
    private:
        int num_users;
        int num_connections;
        // TODO: declare pointers to the arrays needed for your chosen
        // sparse matrix representation (COO, CSR, CSC)

        // ADD any necessary private methods

    public:
        // Constructor: (you can't change the signature)
        //   - filename: the name of the file containing the dataset
        // TODO: implement the constructor to read the dataset from 
        // the file, update the number of users and connections,
        // allocate memory for the arrays, and populate the arrays
        // with the friendship connections
        Network(const std::string &filename);

        // Destructor: (you can't change the signature)
        // free any dynamically allocated memory
        ~Network();

        // Method to check if two users are friends (you can't change the signature)
        //   - user_id1: the ID of the first user
        //   - user_id2: the ID of the second user
        // Returns true if the two users are friends, false otherwise
        // If either user ID is invalid (i.e., not in the range of 0 to num_users-1),
        // the method should throw an exception
        bool is_friend(int user_id1, int user_id2);

        // Method to get the number of users (you can't change the signature)
        int get_num_users() const;

        // Method to get the number of connections (you can't change the signature)
        int get_num_connections() const;

        // ADD any necessary public methods
};
```

All the implementation of the methods of the class should be in a
separate file named `network.cpp`.  You should not put any implementation
in the header file `network.h`.

To work on this task you will develop your own test program. It can be
a simple program that creates an instance of the `Network` class and
calls the `is_friend` method with various user IDs to check if they are
friends.  You can also print the number of users and connections to
verify that the data was read correctly.  This program can be in a file 
named `main.cpp`.  We recommend that you develop your `main.cpp` using the
`catch2` testing framework, but it is not mandatory.  You can use any
testing framework you prefer.

To compile and link all source files into a binary, you can use `g++`
as follows:

```bash
$ g++ -std=c++11 main.cpp network.cpp -o prog
```

You can then run your program as follows:

```bash
$ ./prog filename.txt
```

where `filename.txt` is the name of the file containing the dataset
(e.g., `facebook-small.txt` or `facebook-combined.txt`).

## Task 2 (15 points)

You will add a public method to the `Network` class that computes the number
of friends of a given user.  The method should have the following
signature:

```cpp
int num_friends(int user_id);
```

If the user ID is invalid (i.e., not in the range of 0 to num_users-1),
the method should throw an exception.

### Task 3 (15 points)

You will add another public method to the `Network` class that computes the
number of users that are either friends or friends of friends of a given user.
The method should have the following signature:

```cpp
int num_friends_of_friends(int user_id);
```

If the user ID is invalid (i.e., not in the range of 0 to num_users-1),
the method should throw an exception.

## Task 4 (15 points)

Add a public method to the `Network` class that computes how many mutual
friends two users have.  The method should have the following signature:

```cpp
int num_mutual_friends(int user_id1, int user_id2);
```

If either user ID is invalid (i.e., not in the range of 0 to num_users-1),
the method should throw an exception. If the two user IDs are the same,
the method should return the number of friends of that user.

## Task 5 (15 points)

Add a public method to the `Network` class that computes the most popular user
in the network.  The most popular user is defined as the user with the
highest number of friends.  The method should have the following signature:

```cpp
int most_popular_user();
```

If there are multiple users with the same highest number of friends,
the method should return the user with the smallest user ID.

## Submission and grading

This assignment relies on automated evaluation.
Once you are finished, you **must** submit 
the files listed below via [Gradescope](https://www.gradescope.com/) 
to record your grade.

Use the exact filenames provided here:

    - `network.h`
    - `network.cpp`
    - `main.cpp`
    - `llm-disclaimer.txt`

The `llm-usage.txt` file should contain: the name of the LLM, 
if you used one, and a copy of the prompts you entered and the 
responses you received.  If you did not use an LLM, 
simply write "No LLM used".

> [!CAUTION]
> Remember, academic integrity is of utmost importance.  Any attempts at
> cheating or plagiarism will result in a forfeiture of credit.  Potential
> further actions include failing the class or referring the case for
> disciplinary measures.
