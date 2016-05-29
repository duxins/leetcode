//  125. Valid Palindrome
//  
//  Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
//
//  For example,
//  "A man, a plan, a canal: Panama" is a palindrome.
//  "race a car" is not a palindrome.
//  Note:
//  Have you consider that the string might be empty? This is a good question to ask during an interview.
//  For the purpose of this problem, we define empty string as valid palindrome.
//
//  Tags: Two Pointers, String
//  
//  https://leetcode.com/problems/valid-palindrome/    

#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while(i < j){
            while(i < s.size() && !isalnum(s[i])){
                i++;
            }
            while(j >=0 && !isalnum(s[j])){
                j--;
            }

            if(i < j && tolower(s[i]) != tolower(s[j])){
                return false;
            }

            i++;
            j--;
        }
        return true;
    }
};

TEST(leetcode_125_valid_palindrome, Basic)
{
    Solution *solution = new Solution();
    EXPECT_TRUE(solution->isPalindrome("A man, a plan, a canal: Panama"));
    EXPECT_TRUE(solution->isPalindrome("A man\n a plan a canal\n -- Panama"));
    EXPECT_TRUE(solution->isPalindrome("Egad! Loretta has Adams as mad as a hatter. Old age!"));
    EXPECT_TRUE(solution->isPalindrome("\"Sirrah! Deliver deified desserts detartrated!\" stressed deified\n reviled Harris."));
    EXPECT_TRUE(solution->isPalindrome("Ud L?dPze8Z6?INK:2:V9jwp.;.;?nO?!9XqKiesU:7Y ;,82c:6w!YMn,\",? ,`!;E:b!lF!8,5kAtx;`qoH,aK?8K:gGT2Q!C826:ODM;qJs'sJq;MDO:628C!Q2TGg:K8?Ka,Hoq`;xtAk5,8!Fl!b:E;!` ?,\",nMY!w6:c28,; Y7:UseiKqX9!'On';.;.pwj9V:2:KNI?6Z8ezPd?L dU"));
    EXPECT_FALSE(solution->isPalindrome("race a car"));
    EXPECT_FALSE(solution->isPalindrome("QZrD2 7UL91z,i`O2ef:6e'2\"yP !:,U.:pX90PU3CXo'i!;3 `j 0?\"'hK8 ? BAjM2\"DBw?7!4R3?U2E8F2y!?3 R2!fw 6e!:0  ErCi98KM`,8`8648,mi3P0`,!5 E.?00J3A 52\"x8,tHy!'2!DLBbK'j!tt1C' 7`JPulW\"\"uRTbr\"',\",U`ZOW5'\"LMDQDMJ\"'5WOZ`U,\",'\"rbTRu\"\"WluPJ`7 'C1tt!j'KbBJD!2'!yHt,8x\"25 A3J00?.E 5!,`0P3im,8468`8,`MK89iCrE  0:!e6 wf!2R 3?!y2F8E2U?3R4!7?wBD\"2MjAB ? 8Kh'\"?0 j` 3;!i'oXC3UP09Xp:.U,:! Py\"2'e6:fe2O`i,z19LU7 2DrZQ"));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
