//  299. Bulls and Cows
//  
//  You are playing the following Bulls and Cows game with your friend: You write down a number and ask your friend to guess what the number is. Each time your friend makes a guess, you provide a hint that indicates how many digits in said guess match your secret number exactly in both digit and position (called "bulls") and how many digits match the secret number but locate in the wrong position (called "cows"). Your friend will use successive guesses and hints to eventually derive the secret number.
//
//  For example:
//  Secret number:  "1807"
//  Friend's guess: "7810"
//  Hint: 1 bull and 3 cows. (The bull is 8, the cows are 0, 1 and 7.)
//  Write a function to return a hint according to the secret number and friend's guess, use A to indicate the bulls and B to indicate the cows. In the above example, your function should return "1A3B". 
//  Please note that both secret number and friend's guess may contain duplicate digits, for example:
//
//  Secret number:  "1123"
//  Friend's guess: "0111"
//  In this case, the 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow, and your function should return "1A1B".
//  You may assume that the secret number and your friend's guess only contain digits, and their lengths are always equal.
//
//  Tags: Hash Table
//  
//  https://leetcode.com/problems/bulls-and-cows/    

#include <iostream>
#include <gtest/gtest.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> m;
        int a = 0, b = 0;

        for(int i = 0; i < secret.size(); i++){
            if(secret[i] == guess[i]) {
                a++;
            }else{
                m[secret[i]] ++;
            }
        }

        for(int i = 0; i< secret.size(); i++){
            if(secret[i] != guess[i] && m[guess[i]] > 0){
                b++;
                m[guess[i]]--;
            }
        }

        return to_string(a) + "A" + to_string(b) + "B";
    }
};

TEST(leetcode_299_bulls_and_cows, Basic)
{
    Solution *solution = new Solution();
    EXPECT_EQ("1A1B", solution->getHint("1123", "0111"));
    EXPECT_EQ("9A0B", solution->getHint("123456789", "123456789"));
    EXPECT_EQ("0A4B", solution->getHint("7151535801","4604986377"));
    EXPECT_EQ("3A17B", solution->getHint("00112233445566778899", "16872590340158679432"));
    EXPECT_EQ("3A17B", solution->getHint("00112233445566778899", "16872590340158679432"));
    EXPECT_EQ("2A39B", solution->getHint("93989817073226399421225583064242870001308363274756", "17347932826830156772850437376699905057641470419712"));

}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
