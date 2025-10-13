# Lab 7 - Recursion

# Overview

In this lab, you will design, implement and analyze recursive algorithms.

TODO: add explicit recursive decomposition process

## Learning Objectives

By the end of this lab, you should be able to:

1. Design decrease-by-constant and decrease-by-factor recursive algorithm to solve real-world problems.
2. Model the time complexity of decrease-by-constant and decrease-by-factor recursive algorithms with recurrence relations.
3. Implement decrease-by-constant and decrease-by-factor recursive algorithms.

## Grading

To receive full credit, you should:

1. Attend, participate and collaborate.
2. Make at least one submission to Gradescope.

> [!IMPORTANT]
> Effort is enough to receive full credit. You do not need to successfully complete any activities.

## Milestones

To achieve the lab objectives, you should:

1. Complete all activities listed under **Core Content**.

> [!NOTE]
> If you do not complete all activities listed under **Core Content** during the lab period, we recommend finishing them
> on your own. Subsequent labs, assignments and lectures will assume you have completed this lab's **Core Content**
> activities.

To leave early, you should:

1. Complete all activities listed under **Core Content**.
2. Complete all activities listed under **Extra Practice** or **Optional Advanced Topics**.

To maximize your learning, you should:

1. Complete all activities listed under **Core Content**.
2. Complete all activities listed under **Extra Practice**.
3. Attempt some activities listed under **Optional Advanced Topics**.

# Core Content

## Project Setup

1. Create a new project called `csc212-lab-07` in your IDE.
2. Download all files from [the lab handout folder](handout) into the `csc212-lab-07` project.

> [!NOTE]
> To download all files from the repository, navigate to the root of the repository, click on the green **Code** button
> and select **Download Zip**.`

## SRBOT Framework

The SRBOT framework is a general method for designing recursive algorithms. It consists of five steps:
1. **Subproblem Definition.** Give a function declaration with parameters, and precisely state the meaning of the function's return value. Typically, subproblems are defined over prefixes `A[:i]`, suffixes `A[i:]` or subarrays `A[i:j]` of an input array `A`.
2. **Recursive Relationship.** State a recursive relationship between subproblems, and one or more smaller subproblems. Justify the relationship in terms of the subproblem definition. 
3. **Base Cases.** State appropriate base case(s) for your recursive relationship. Justify the base cases in terms of the subproblem definition.
4. **Original Problem.** State the solution to the original problem in terms of the subproblem definition. Usually, this step involves invoking the subproblem once with appropriate parameters. 
5. **Time Analysis.** Model the time required to solve the original problem with a recurrence relation. Solve the recurrence.

### Reading

In this section, you will read an exemplar that using the SRBOT framework to design a recursive algorithm.

We want to design a recursive algorithm to compute `product(A)` (i.e. the product of all elements in `A`):

1. **Subproblem Definition.** We will use suffixes for the subproblem definition: `product(A, i)` is the product of all elements in `A[i:]`. Note that we could have used prefixes instead of suffixes.
2. **Recursive Relationship.** The product of all elements in the subarray `A[i:]` is the product of `A[i]` with the product of all elements in `A[i+1:]` (i.e. `product(A, i + 1`). Therefore, `product(A, i) = A[i] * product(A, i + 1)`.
3. **Base Cases.** The product of zero elements is one. Therefore, `product(A, n) = 1`, since `A[n:] = []`.
4. **Original Problem.** The product of all elements in `A` is `product(A, 0)`, since `A[0:] = A`.
5. **Time Analysis.** We can model the time complexity of `product` with the recurrence $T(n) = T(n - 1) + \Theta(1)$ where $T(0) = \Theta(1)$. After expanding $k$ times, $T(n) = T(n - k) + k\Theta(1)$. With $k = n$, $T(n) = T(0) + n\Theta(1) = \Theta(n)$.

## Playlist Period

Spotify allows users to create sequences of songs called **playlists**. Songs are played in sequential order until there are none left. Then, the playlist repeats, beginning again with the first song. The **period** of a playlist is the duration of time before a particular song repeats. Spotify displays the period of each playlist, so that users can select a playlist of appropriate duration (e.g. a two-hour playlist for a two-hour drive).

### Design

In this section, you will design a recursive algorithm to compute the period of a playlist using the SRBOT framework. If you spend more than 15-20 minutes on this section, look at the solution provided below and move on.

1. Read `playlist_period.h`.
2. Define subproblems and precisely state their meaning in words. Record your answer under **Subproblem Definition** in `playlist_period.md`.
3. Find a recursive relationship between subproblems. Record your answer under **Recursive Relationship** in `playlist_period.md`.
4. State base case(s) for your recursive relationship. Record your answer under **Base Cases** in `playlist_period.md`.
5. State the solution to the original problem using your subproblem definition. Record your answer under **Original Problem** in `playlist_period.md`.

<details>
<summary>Solution</summary>

1. N/a.
2. `playlist_period(songs, i)` is the period of the subarray `songs[i:]`.
3. `playlist_period(songs, i) = songs[i].duration + playlist_period(songs, i + 1)`. The duration of time before `songs[i]` repeats in playlist `songs[i:]` is the time to play song `song[i]` plus the time to play `songs[i+1:]`. The time to play `song[i]` is `songs[i].duration`. The time to play `songs[i+1:]` is the same as the time before `song[i+1:]` repeats in the playlist `songs[i+1:]`, which is `playlist_period(songs, i + 1)`.
4. `playlist_period(songs, n) = 0`. The period of the subarray `songs[n:] = []` is zero, since it contains no songs.
5. `playlist_period(playlist.songs, 0)`. To recurse, we must extract the sequence of songs from the playlist. Then, `songs[0:]` contains all songs, so `playlist_period(playlist.songs, 0)` is the period of the entire playlist.

</details>

> [!IMPORTANT]
> Submit `playlist_period.md` to Gradescope.

### Implementation

In this section, you will implement your recursive algorithm.

1. Complete `playlist_period.cpp`.
2. Build `test_playlist_period` from `playlist_period.cpp`, and `test_playlist_period.cpp`.
3. Run `test_playlist_period`. All tests should pass.

> [!IMPORTANT]
> Submit `playlist_period.cpp` to Gradescope.

### Theoretical Analysis

In this section, you will analyze your recursive algorithm. If you spend more than 5-10 minutes on this section, look at the solution provided below and move on.

1. State a recurrence relation $T(n)$ for the worst-case time complexity of your recursive algorithm. Record your answer under
   **Time Analysis** in `playlist_period.md`.
2. Solve the recurrence relation $T(n)$. What is the worst-case time complexity your recursive algorithm? Record your answer under
   **Time Analysis** in `playlist_period.md`.

<details>
<summary>Solution</summary>

1. $T(n) = T(n - 1) + \Theta(1)$ where $T(0) = \Theta(1)$.
2. After expanding $k$ times, $T(n) = T(n - k) + k\Theta(1)$. With $k = n$, $T(n) = T(0) + n\Theta(1) = \Theta(n)$.

</details>

> [!IMPORTANT]
> Submit `playlist_period.md` to Gradescope.

## Bug Bisect

GitHub allows developers to track code changes known as **commits**. After each commit, a collection of tests, known as a **test-suite**, is run to verify the code still works correctly. Ideally, as soon as a commit causes the test-suite to fail, the developers take notice and fix the bug. 

However, in large-scale projects where multiple developers commit many times per day and the test-suite takes a long time to run (tens of minutes), failing commits might not be identified until after several additional commits have taken place. Since the original bug was not fixed, all subsequent commits will also fail. Given a sequence of test-suite results where the test-suite passes until some commit and fails thereafter, GitHub allows developers to search for the first commit where the test-suite fails. This is the commit where the bug was introduced.

### Design

In this section, you will design a recursive algorithm to compute the first commit where the test-suite fails using the SRBOT framework. If you spend more than 15-20 minutes on this section, look at the solution provided below and move on.

1. Read `bug_bisect.h`.
2. Define subproblems and precisely state their meaning in words. Record your answer under **Subproblem Definition** in `bug_bisect.md`.
3. Find a recursive relationship between subproblems. Record your answer under **Recursive Relationship** in `bug_bisect.md`.
4. State base case(s) for your recursive relationship. Record your answer under **Base Cases** in `bug_bisect.md`.
5. State the solution to the original problem using your subproblem definition. Record your answer under **Original Problem** in `bug_bisect.md`.

<details>
<summary>Solution</summary>

1. N/a.
2. `bug_bisect(suite_results, left, right)` is the commit id of the first fail in the subarray `suite_results[left:right+1]`. The subarray must consist of zero or more passes followed by fails. There must be at least one fail. 
3. `bug_bisect(suite_results, left, right)` is `bug_bisect(suite_results, left, mid)` if `suite_results[mid].is_ok()` is `false` otherwise `bug_bisect(ok, mid + 1, right)`, where `mid = left + (right - left) / 2`.  If `suite_results[mid].is_ok()` is false, then the first fail must be at or before `mid`.  If `suite_results[mid].is_ok()` is `true`, the first fail must be after `mid`.
4. `bug_bisect(suite_results, index, index)` is `suite_results[index].commit_id`. The subarray is `suite_results[index:index+1] = [suite_results[index]]`. Since the subarray contains at least one fail, `suite_results[index]` must be a fail, so `suite_results[index].commit_id` is the commit id of the first fail.
5. `bug_bisect(suite_results, 0, n - 1)`.

</details>

> [!IMPORTANT]
> Submit `bug_bisect.md` to Gradescope.

### Implementation

In this section, you will implement your recursive algorithm.

1. Complete `bug_bisect.cpp`.
2. Build `test_bug_bisect` from `bug_bisect.cpp`, and `test_bug_bisect.cpp`.
3. Run `test_bug_bisect`. All tests should pass.

> [!IMPORTANT]
> Submit `bug_bisect.cpp` to Gradescope.

### Theoretical Analysis

In this section, you will analyze your recursive algorithm. If you spend more than 5-10 minutes on this section,
look at the solution provided below and move on.

1. State a recurrence relation $T(n)$ for the worst-case time complexity of your recursive algorithm. Record your answer under
   **Time Analysis** in `bug_bisect.md`.
2. Solve the recurrence relation $T(n)$. What is the worst-case time complexity of your recursive algorithm? Record your answer under
   **Time Analysis** in `bug_bisect.md`.

<details>
<summary>Solution</summary>

1. $T(n) = T(n/2) + \Theta(m)$, where $T(1) = \Theta(1)$, $n$ is the number of commits, and $m$ is the size of the test suite.
2. After expanding $k$ times, $T(n) = T(n/2^k) + k\Theta(m)$. With $k = \lg n$, $T(n) = T(1) + \Theta(m) \lg n = \Theta(m \lg n)$.

</details>

> [!IMPORTANT]
> Submit `bug_bisect.md` to Gradescope.

# Extra Practice

## Perfect Plunder

TOOD

### Design 

In this section, you will design a recursive algorithm to TODO using the SRBOT framework. If you spend more than 15-20 minutes on this section, look at the solution provided below and move on.

1. Read `perfect_plunder.h`.
2. Define subproblems and precisely state their meaning in words. Record your answer under **Subproblem Definition** in `perfect_plunder.md`.
3. Find a recursive relationship between subproblems. Record your answer under **Recursive Relationship** in `perfect_plunder.md`.
4. State base case(s) for your recursive relationship. Record your answer under **Base Cases** in `perfect_plunder.md`.
5. State the solution to the original problem using your subproblem definition. Record your answer under **Original Problem** in `perfect_plunder.md`.

> [!IMPORTANT]
> Submit `perfect_plunder.md` to Gradescope.

### Implementation

In this section, you will implement your recursive algorithm.

1. Complete `perfect_plunder.cpp`.
2. Build `test_perfect_plunder` from `perfect_plunder.cpp`, and `test_perfect_plunder.cpp`.
3. Run `test_perfect_plunder`. All tests should pass.

> [!IMPORTANT]
> Submit `perfect_plunder.cpp` to Gradescope.

### Theoretical Analysis

In this section, you will analyze your recursive algorithm. If you spend more than 5-10 minutes on this section,
look at the solution provided below and move on.

1. State a recurrence relation $T(n)$ for the worst-case time complexity of your recursive algorithm. Record your answer under
   **Time Analysis** in `perfect_plunder.md`.
2. Solve the recurrence relation $T(n)$. What is the worst-case time complexity of your recursive algorithm? Record your answer under
   **Time Analysis** in `perfect_plunder.md`.

> [!IMPORTANT]
> Submit `perfect_plunder.md` to Gradescope.

## Genetic Gap

TOOD

### Design

In this section, you will design a recursive algorithm to TODO using the SRBOT framework. If you spend more than 15-20 minutes on this section, look at the solution provided below and move on.

1. Read `genetic_gap.h`.
2. Define subproblems and precisely state their meaning in words. Record your answer under **Subproblem Definition** in `genetic_gap.md`.
3. Find a recursive relationship between subproblems. Record your answer under **Recursive Relationship** in `genetic_gap.md`.
4. State base case(s) for your recursive relationship. Record your answer under **Base Cases** in `genetic_gap.md`.
5. State the solution to the original problem using your subproblem definition. Record your answer under **Original Problem** in `genetic_gap.md`.

> [!IMPORTANT]
> Submit `genetic_gap.md` to Gradescope.

### Implementation

In this section, you will implement your recursive algorithm.

1. Complete `genetic_gap.cpp`.
2. Build `test_genetic_gap` from `genetic_gap.cpp`, and `test_genetic_gap.cpp`.
3. Run `test_genetic_gap`. All tests should pass.

> [!IMPORTANT]
> Submit `genetic_gap.cpp` to Gradescope.

### Theoretical Analysis

In this section, you will analyze your recursive algorithm. If you spend more than 5-10 minutes on this section,
look at the solution provided below and move on.

1. State a recurrence relation $T(n)$ for the worst-case time complexity of your recursive algorithm. Record your answer under
   **Time Analysis** in `genetic_gap.md`.
2. Solve the recurrence relation $T(n)$. What is the worst-case time complexity of your recursive algorithm? Record your answer under
   **Time Analysis** in `genetic_gap.md`.

> [!IMPORTANT]
> Submit `genetic_gap.md` to Gradescope.

# Optional Advanced Topics

## Roaming Roomba

TOOD

### Design

In this section, you will design a recursive algorithm to TODO using the SRBOT framework. If you spend more than 15-20 minutes on this section, look at the solution provided below and move on.

1. Read `roaming_roomba.h`.
2. Define subproblems and precisely state their meaning in words. Record your answer under **Subproblem Definition** in `roaming_roomba.md`.
3. Find a recursive relationship between subproblems. Record your answer under **Recursive Relationship** in `roaming_roomba.md`.
4. State base case(s) for your recursive relationship. Record your answer under **Base Cases** in `roaming_roomba.md`.
5. State the solution to the original problem using your subproblem definition. Record your answer under **Original Problem** in `roaming_roomba.md`.

> [!IMPORTANT]
> Submit `roaming_roomba.md` to Gradescope.

### Implementation

In this section, you will implement your recursive algorithm.

1. Complete `roaming_roomba.cpp`.
2. Build `test_roaming_roomba` from `roaming_roomba.cpp`, and `test_roaming_roomba.cpp`.
3. Run `test_roaming_roomba`. All tests should pass.

> [!IMPORTANT]
> Submit `roaming_roomba.cpp` to Gradescope.

### Theoretical Analysis

In this section, you will analyze your recursive algorithm. If you spend more than 5-10 minutes on this section,
look at the solution provided below and move on.

1. State a recurrence relation $T(n)$ for the worst-case time complexity of your recursive algorithm. Record your answer under
   **Time Analysis** in `roaming_roomba.md`.
2. Solve the recurrence relation $T(n)$. What is the worst-case time complexity of your recursive algorithm? Record your answer under
   **Time Analysis** in `roaming_roomba.md`.

> [!IMPORTANT]
> Submit `roaming_roomba.md` to Gradescope.

## Strategic Silicon

TOOD

### Design

In this section, you will design a recursive algorithm to TODO using the SRBOT framework. If you spend more than 15-20 minutes on this section, look at the solution provided below and move on.

1. Read `strategic_silicon.h`.
2. Define subproblems and precisely state their meaning in words. Record your answer under **Subproblem Definition** in `strategic_silicon.md`.
3. Find a recursive relationship between subproblems. Record your answer under **Recursive Relationship** in `strategic_silicon.md`.
4. State base case(s) for your recursive relationship. Record your answer under **Base Cases** in `strategic_silicon.md`.
5. State the solution to the original problem using your subproblem definition. Record your answer under **Original Problem** in `strategic_silicon.md`.

> [!IMPORTANT]
> Submit `strategic_silicon.md` to Gradescope.

### Implementation

In this section, you will implement your recursive algorithm.

1. Complete `strategic_silicon.cpp`.
2. Build `test_strategic_silicon` from `strategic_silicon.cpp`, and `test_strategic_silicon.cpp`.
3. Run `test_strategic_silicon`. All tests should pass.

> [!IMPORTANT]
> Submit `strategic_silicon.cpp` to Gradescope.

### Theoretical Analysis

In this section, you will analyze your recursive algorithm. If you spend more than 5-10 minutes on this section,
look at the solution provided below and move on.

1. State a recurrence relation $T(n)$ for the worst-case time complexity of your recursive algorithm. Record your answer under
   **Time Analysis** in `strategic_silicon.md`.
2. Solve the recurrence relation $T(n)$. What is the worst-case time complexity of your recursive algorithm? Record your answer under
   **Time Analysis** in `strategic_silicon.md`.

> [!IMPORTANT]
> Submit `strategic_silicon.md` to Gradescope.
