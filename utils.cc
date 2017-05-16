
// Moves the alphabets 2 positions, keeps the numbers and special characters
void caesar_sipher(char s[]) {
    for (int i = 0; i < n; i++) {
        printf("%c", isAlpha(s[i]) ? s[i] + 2 % (s[i] < 90 ? 65 : 97): s[i]);
    }
}

// Condition: a > b
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
