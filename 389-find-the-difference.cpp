//  389. Find the Difference
//  
//  Given two strings s and t which consist of only lowercase letters.
//  String t is generated by random shuffling string s and then add one more letter at a random position.
//  Find the letter that was added in t.
//  Example:
//  Input:
//  s = "abcd"
//  t = "abcde"
//  Output:
//  e
//  Explanation:
//  'e' is the letter that was added.
//  Subscribe to see which companies asked this question
//  
//  Tags: Hash Table, Bit Manipulation
//  
//  https://leetcode.com/problems/find-the-difference/    

#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        char diff = 0;

        for(char c : s) diff ^= c;
        for(char c : t) diff ^= c;

        return diff;
    }
};

void judge(string s, string t, char expected){
    Solution solution;
    EXPECT_EQ(expected, solution.findTheDifference(s, t));
}

TEST(leetcode_389_find_the_difference, Basic)
{
    judge("abcd", "abced", 'e');
    judge("khqlxldhwmoonlgghrocbtaashtevjcgeygbalfwcdcuhqrfxikgzbwortfaubfirtpoprxmpeqziprarc",
          "rlprftrhpotmkbrxlhzwcoqvlfbcrbqpaeiqjtprihhgccailaoenbdgxzyesmgeowffchxwuaduragkotg",
          'e');
    judge("pkiraymxbpvqlszycybvhlkbhbyzsxljoaqlfclomjntegicnmnshkrnkdxnfutwfcdkngcvsldo",
          "lqkinsmlrkcubzfxojdncjtcbmsevhkyzlghonvipgnrksnctsfdbxamvohdnwyqblpydacflkxly",
         'd');
    judge("rimspsqhecdzsuvkqbfpsyjqwfrbtnunpetlijmducnduhqdwzocwpagtgdxsaoyxvwrkggukjrdjxzvpkzfomfp",
          "dptgrquslzkxcnkqfbddwjygoqwfsaopxfjbcnasmhzpmudmvuzsjuhgvkqtgskdftrbuwdcveinxpyowppjirrze",
          'b');
    judge("ymbgaraibkfmvocpizdydugvalagaivdbfsfbepeyccqfepzvtpyxtbadkhmwmoswrcxnargtlswqemafandgkmydtimuzvjwxvlfwlhvkrgcsithaqlcvrihrwqkpjdhgfgreqoxzfvhjzojhghfwbvpfzectwwhexthbsndovxejsntmjihchaotbgcysfdaojkjldprwyrnischrgmtvjcorypvopfmegizfkvudubnejzfqffvgdoxohuinkyygbdzmshvyqyhsozwvlhevfepdvafgkqpkmcsikfyxczcovrmwqxxbnhfzcjjcpgzjjfateajnnvlbwhyppdleahgaypxidkpwmfqwqyofwdqgxhjaxvyrzupfwesmxbjszolgwqvfiozofncbohduqgiswuiyddmwlwubetyaummenkdfptjczxemryuotrrymrfdxtrebpbjtpnuhsbnovhectpjhfhahbqrfbyxggobsweefcwxpqsspyssrmdhuelkkvyjxswjwofngpwfxvknkjviiavorwyfzlnktmfwxkvwkrwdcxjfzikdyswsuxegmhtnxjraqrdchaauazfhtklxsksbhwgjphgbasfnlwqwukprgvihntsyymdrfovaszjywuqygpvjtvlsvvqbvzsmgweiayhlubnbsitvfxawhfmfiatxvqrcwjshvovxknnxnyyfexqycrlyksderlqarqhkxyaqwlwoqcribumrqjtelhwdvaiysgjlvksrfvjlcaiwrirtkkxbwgicyhvakxgdjwnwmubkiazdjkfmotglclqndqjxethoutvjchjbkoasnnfbgrnycucfpeovruguzumgmgddqwjgdvaujhyqsqtoexmnfuluaqbxoofvotvfoiexbnprrxptchmlctzgqtkivsilwgwgvpidpvasurraqfkcmxhdapjrlrnkbklwkrvoaziznlpor",
          "qhxepbshlrhoecdaodgpousbzfcqjxulatciapuftffahhlmxbufgjuxstfjvljybfxnenlacmjqoymvamphpxnolwijwcecgwbcjhgdybfffwoygikvoecdggplfohemfypxfsvdrseyhmvkoovxhdvoavsqqbrsqrkqhbtmgwaurgisloqjixfwfvwtszcxwktkwesaxsmhsvlitegrlzkvfqoiiwxbzskzoewbkxtphapavbyvhzvgrrfriddnsrftfowhdanvhjvurhljmpxvpddxmzfgwwpkjrfgqptrmumoemhfpojnxzwlrxkcafvbhlwrapubhveattfifsmiounhqusvhywnxhwrgamgnesxmzliyzisqrwvkiyderyotxhwspqrrkeczjysfujvovsfcfouykcqyjoobfdgnlswfzjmyucaxuaslzwfnetekymrwbvponiaojdqnbmboldvvitamntwnyaeppjaohwkrisrlrgwcjqqgxeqerjrbapfzurcwxhcwzugcgnirkkrxdthtbmdqgvqxilllrsbwjhwqszrjtzyetwubdrlyakzxcveufvhqugyawvkivwonvmrgnchkzdysngqdibhkyboyftxcvvjoggecjsajbuqkjjxfvynrjsnvtfvgpgveycxidhhfauvjovmnbqgoxsafknluyimkczykwdgvqwlvvgdmufxdypwnajkncoynqticfetcdafvtqszuwfmrdggifokwmkgzuxnhncmnsstffqpqbplypapctctfhqpihavligbrutxmmygiyaklqtakdidvnvrjfteazeqmbgklrgrorudayokxptswwkcircwuhcavhdparjfkjypkyxhbgwxbkvpvrtzjaetahmxevmkhdfyidhrdeejapfbafwmdqjqszwnwzgclitdhlnkaiyldwkwwzvhyorgbysyjbxsspnjdewjxbhpsvj",
          't');
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
