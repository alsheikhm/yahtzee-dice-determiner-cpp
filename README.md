# yahtzee-dice-determiner-cpp
Yahtzee Dice Determiner

## Overview

Yahtzee Dice Determiner is a C++ program that evaluates a completed five-dice turn and determines the best possible Yahtzee-style result achieved by the player. The program asks the user to enter five dice values, stores the frequency of each roll, and then checks the roll against several possible dice combinations.

The program focuses on evaluating the final dice outcome rather than simulating the full reroll system. After all five valid dice values are entered, the program displays only the highest-ranking result the player achieved.

## Features

- Prompts the user to enter five dice values
- Accepts only valid dice rolls from 1 to 6
- Allows the user to quit early by entering `0`
- Uses a `map` to store each dice value and how many times it was rolled
- Detects major Yahtzee-style results
- Displays only the best result based on ranking order
- Includes input validation for out-of-range values

## Dice Frequency Evaluation Engine

The core of the program uses a `std::map<int, int>` to count how many times each dice value appears.

The key represents the dice roll value:

```cpp
1, 2, 3, 4, 5, or 6
```

The value represents how many times that number was rolled.

For example, if the user enters:

```text
2 2 2 5 5
```

The map would store the roll counts like this:

```text
2 -> 3
5 -> 2
```

This allows the program to recognize that the roll contains three of one value and two of another, which means the result is a full house.

## Result Detection

After all five dice values are entered, the program checks for each possible result using the stored roll counts.

The program can detect:

- Yahtzee / Five of a Kind
- Four of a Kind
- Full House
- Three of a Kind
- Large Straight
- Small Straight
- Nothing

The results are checked in ranking order, so only the best result is displayed.

## Result Ranking System

The program evaluates the final dice roll using the following priority order:

```text
1. Yahtzee / Five of a Kind
2. Four of a Kind
3. Full House
4. Three of a Kind
5. Large Straight
6. Small Straight
7. Nothing
```

This means that if a roll qualifies for multiple results, the strongest one is chosen.

For example, a roll like:

```text
1 2 3 4 5
```

could qualify as both a small straight and a large straight, but the program displays:

```text
Large Straight
```

because it is the better result.

## Example Output

```text
Enter a Number 1-6 or 0 to Exit: 2

Enter a Number 1-6 or 0 to Exit: 2

Enter a Number 1-6 or 0 to Exit: 2

Enter a Number 1-6 or 0 to Exit: 5

Enter a Number 1-6 or 0 to Exit: 5

Based on your turn, the best result you achieved was ...
Full House
```

## Key Concepts Demonstrated

- Maps with `std::map`
- Key/value pair storage
- Frequency counting
- User input validation
- Conditional logic
- Boolean flags
- Dice roll evaluation
- Ranking-based result selection
- Console input and output

## Design Highlights

- Uses a map to organize dice roll counts clearly
- Keeps the roll value as the key and the frequency as the value
- Validates each dice value before adding it to the map
- Allows the user to exit safely with `0`
- Uses boolean variables to track which results were achieved
- Checks results from strongest to weakest to ensure only the best result is printed
- Keeps the program simple, readable, and focused on the main dice-evaluation logic

## File Structure

```text
Yahtzee-Dice-Determiner/
├── main.cpp
└── README.md
```

## How to Run

1. Compile the program using a C++ compiler:

```bash
g++ main.cpp -o yahtzee_dice_determiner
```

2. Run the executable:

```bash
./yahtzee_dice_determiner
```

3. Enter five dice values between `1` and `6`.

4. Enter `0` at any time to exit the program early.

## Project Summary

This project demonstrates how a map can be used to count repeated values and evaluate patterns in a set of dice rolls. By storing each dice value with its frequency, the program can determine whether the player achieved a Yahtzee, full house, straight, or another dice result. The final output gives the user the best possible result from their turn.
