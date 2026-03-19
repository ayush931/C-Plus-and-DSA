/**
 * You have intercepted a secret message encoded as a string of numbers. The message is decoded via the following mapping:
 * "1" -> 'A'
 * "2" -> 'B'
 * "25" -> 'Y'
 * "26" -> 'Z'
 *
 * However, while decoding the message, you realize that there are many different ways you can decode the message because some codes are contained in other codes ("2" and "5" vs "25").
 *
 * For example, "11106" can be decoded into:
 *
 * "AAJF" with the grouping (1, 1, 10, 6)
 * "KJF" with the grouping (11, 10, 6)
 * The grouping (1, 11, 06) is invalid because "06" is not a valid code (only "6" is valid).
 * Note: there may be strings that are impossible to decode.
 *
 * Given a string s containing only digits, return the number of ways to decode it. If the entire string cannot be decoded in any valid way, return 0.
 *
 * The test cases are generated so that the answer fits in a 32-bit integer.
 *
 * Example 1:
 * Input: s = "12"
 * Output: 2
 * Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).
 *
 * Example 2:
 * Input: s = "226"
 * Output: 3
 * Explanation: "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
 *
 * Example 3:
 * Input: s = "06"
 * Output: 0
 * Explanation: "06" cannot be mapped to "F" because of the leading zero ("6" is different from "06"). In this case, the string is not a valid encoding, so return 0.
 *
 * Constraints:
 * 1 <= s.length <= 100
 * s contains only digits and may contain leading zero(s).
 */

class Solution {
public:
  vector<int> dp;
  // this function takes a string of digits and convert it to numbers
  int string_to_int(string s) {
    if (s.size() == 1)
      return s[0] - '0';                     // '9' - '0' = 9
    return (s[0] - '0') * 10 + (s[1] - '0'); // "26" -> ('2' - '0') * 10 + ('6' - '0') -> 2 * 10 + 6 -> 26
  };

  int f(string str, int idx) {
    // base case
    if (str[idx] == '0')
      return 0;
    if (idx >= str.size())
      return 0;
    if (idx == str.size() - 1) {
      if (str[idx] == '0')
        return 0;
      else
        return 1;
    }

    if (idx == str.size() - 2) {
      bool can_form_2_digits = string_to_int(str.substr(idx, 2)) <= 26;
      return can_form_2_digits + f(str, idx + 1);
    }

    if (dp[idx] != -1)
      return dp[idx];

    bool can_form_2_digits = string_to_int(str.substr(idx, 2)) <= 26;
    return dp[idx] = f(str, idx + 1) + ((can_form_2_digits) ? f(str, idx + 2) : 0);
  };

  int fbu(string str) {
    dp.clear();
    dp.resize(105, -1);
    int n = str.size();

    dp[n - 1] = (str[n - 1] == '0') ? 0 : 1;
    bool can_form = string_to_int(str.substr(n - 2, 2)) <= 26;
    if (str[n - 2] == '0')
      dp[n - 2] = 0;
    else
      dp[n - 2] = dp[n - 1] + (can_form);

    for (int i = n - 3; i >= 0; i--) {
      if (str[i] == '0') {
        dp[i] = 0;
        continue;
      }

      bool can_form_2_digits = string_to_int(str.substr(i, 2)) <= 26;
      dp[i] = dp[i + 1] + ((can_form_2_digits) ? dp[i + 2] : 0);
    }

    return dp[0];
  };

  int numDecodings(string s) {
    int n = s.size();
    if (n == 1) {
      if (s[n - 1] == '0')
        return 0;
      else
        return 1;
    }
    dp.clear();
    dp.resize(105, -1);
    return fbu(s);
  }
};