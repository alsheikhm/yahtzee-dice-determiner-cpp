// Mohammed Al-Sheikh
// main.cpp

#include <iostream>
#include <map>

int main()
{
    // Map to store key (dice roll from user input) and value (number of time rolled)
    std::map<int, int> map;
    
    // Loop to prompt user to enter 5 valid numbers
    for(int i = 0; i < 5; ++i)
    {
        int value;
        
        // Prompt user to enter 1-6 inclusive or 0 to exit the program
        std::cout << "Enter a Number 1-6 or 0 to Exit: ";
        std::cin >> value;
        std::cout << std::endl;
        
        // If user input was 0, end program
        if(value == 0)
        {
            std::cout << "Exiting Program, Thanks for Playing!" << std::endl << std::endl;
            return 0;
        }
        
        // Check for valid input, must be 1-6 inclusive
        while(value < 1 || value > 6)
        {
            std::cout << "Invalid Input: Must be 1-6 to play or 0 to Exit, Try Again." << std::endl;
            std::cout << "Enter a Number 1-6 or 0 to Exit: ";
            std::cin >> value;
            std::cout << std::endl;
            
            if(value == 0)
            {
                std::cout << "Exiting Program, Thanks for Playing!" << std::endl << std::endl;
                return 0;
            }
        }
        
        // Increment value of the key from the user's input
        ++map[value];
    }
    
    // Initialize all possibilities as false; this is the order of best to worst results
    bool fiveKind = false;
    bool fourKind = false;
    bool fullHouse = false;
    bool threeKind = false;
    bool pair = false;
    bool largeStraight = false;
    bool smallStraight = false;
    
    // Check each possible input (1-6) to see how many times rolled, and set true to respective one
    for(int i = 1; i <= 6; ++i)
    {
        if(map[i] == 5)
        {
            fiveKind = true;
        }
        else if(map[i] == 4)
        {
            fourKind = true;
        }
        else if(map[i] == 3)
        {
            threeKind = true;
        }
        else if(map[i] == 2)
        {
            pair = true;
        }
    }
    
    // If user rolled three of a kind and a pair, set full house to true
    if(threeKind == true && pair == true)
    {
        fullHouse = true;
    }
    
    // If user rolled at least once a 1, 2, 3, 4, and 5 OR 2, 3, 4, 5, and 6, then set large straight to true
    if(map[1] > 0 && map[2] > 0 && map[3] > 0 && map[4] > 0 && map[5] > 0)
    {
        largeStraight = true;
    }
    else if(map[2] > 0 && map[3] > 0 && map[4] > 0 && map[5] > 0 && map[6] > 0)
    {
        largeStraight = true;
    }
    
    // If user rolled at least once a 1, 2, 3, and 4 OR 2, 3, 4, and 5, OR 3, 4, 5, and 6, then set small straight to true
    if(map[1] > 0 && map[2] > 0 && map[3] > 0 && map[4] > 0)
    {
        smallStraight = true;
    }
    else if(map[2] > 0 && map[3] > 0 && map[4] > 0 && map[5] > 0)
    {
        smallStraight = true;
    }
    else if(map[3] > 0 && map[4] > 0 && map[5] > 0 && map[6] > 0)
    {
        smallStraight = true;
    }
    
    std::cout << "Based on your turn, the best result you achieved was ..." << std::endl;
    
    // In order of best to worst result, only display output of the best of 7 results that were set as true
    if(fiveKind == true)
    {
        std::cout << "Yahtzee / Five of A Kind" << std::endl << std::endl;
    }
    else if(fourKind == true)
    {
        std::cout << "Four of A Kind" << std::endl << std::endl;
    }
    else if(fullHouse == true)
    {
        std::cout << "Full House" << std::endl << std::endl;
    }
    else if(threeKind == true)
    {
        std::cout << "Three of a kind" << std::endl << std::endl;
    }
    else if(largeStraight == true)
    {
        std::cout << "Large straight" << std::endl << std::endl;
    }
    else if(smallStraight == true)
    {
        std::cout << "Small straight" << std::endl << std::endl;
    }
    else
    {
        std::cout << "Nothing" << std::endl << std::endl;
    }
    
    return 0;
}
