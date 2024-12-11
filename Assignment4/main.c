//
//  main.c
//  C-course_assignment
//
//  Created by Eric Yang on 11/20/24.
//

#include <stdio.h>
#include <string.h>

int is_subsequence(const char *s, const char *t) {
    int s_len = (int)strlen(s);
    int t_len = (int)strlen(t);

    int s_index = 0;
    int t_index = 0;

    while (s_index < s_len && t_index < t_len) {
        if (s[s_index] == t[t_index]) {
            // 如果字符相同，那s的索引值加1
            s_index++;
        }
        // t 的索引值加1
        t_index++;
    }

    // 如果子's'字串全部可以在't'字串中匹配完成 then return 1
    return (s_index == s_len) ? 1 : 0;
}

int main(void) {
    // 輸入字串=1000，再加上一個終止符\0
    char s[1001], t[1001];
    printf("plz enter first string:");
    scanf("%s", s);
    printf("plz enter second string:");
    scanf("%s", t);

    int result = is_subsequence(s, t);
    printf("%d\n", result);

    return 0;
}
