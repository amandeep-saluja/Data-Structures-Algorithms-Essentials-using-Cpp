# Dynamic Programming

## Problem
* **Recursion Tree**
    - We will stuck in Overlapping subproblem.
* **Overlapping subproblem**
    - We are calculating the overlapping subproblems again and again, which will take O[2^{55}] time.

## Solution 
* **Memoization Tree**
    - We will store the subproblems in any Data structure and return the result when we need it. 
    - Two approaches: 
      --  Top Down DP
      -- Bottom Up DP

## Top Down DP (Recursion + Memoization)
In top down DP, we start building the big solution right way by explaining how you build it from smaller solutions.

## Bottom Up DP (Iterative + Memoization)
In Bottom Up DP, we start with small solutions and then use the small solutions to build larger solutions.