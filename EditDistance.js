/**
 * Calculate Edit Distance between two strings using Dynamic Programming
 * It takes two strings as parameters and returns an integer representing
 *  the number of edits (insert, remove, replace) necessary to match them
 * @param  string str
 * @param  string pat
 * @return int
 */
function editDist (str, pat) {
  const slen = str.length
  const plen = pat.length
  const dp = []
  for (let i = 0; i < slen; i++) {
    dp[i] = []
    for (let j = 0; j < plen; j++) {
      if (!i) dp[i][j] = j
      else if (!j) dp[i][j] = i
      else if (str[i - 1] === pat[j - 1]) dp[i][j] = dp[i - 1][j - 1]
      else dp[i][j] = 1 + Math.min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1])
    }
  }
  return dp[slen - 1][plen - 1]
}
