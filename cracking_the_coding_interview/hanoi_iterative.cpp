#include "leetcode.h"
struct node{
    char target, source, temp;
    int type, n;
    node(char so, char ta, char te, int type, int n):target(ta),source(so),temp(te),type(type),n(n){
    }
};

void move(char source, char target, int n){
    printf("%c --[%d]--> %c\n", source, n, target);
}
int main()
{
    wez(n);
    stack<node> st;
    if (n <= 1){
        if (n == 1) move('A', 'C', 1);
        else printf("-1");
        return EXIT_SUCCESS;
    }
    st.push(node('A', 'C', 'B', 0, n));
    int maxS = 0;
    while(!st.empty()){
        maxS = max(maxS, (int)st.size());
        node h = st.top(); st.pop();
        if (h.type == 1 || h.n == 1) move(h.source, h.target, h.n);
        else{
            st.push(node(h.temp, h.target, h.source, 0, h.n-1));
            st.push(node(h.source, h.target, h.temp, 1, h.n));
            st.push(node(h.source, h.temp, h.target, 0, h.n-1));
        }
    }
    cout << maxS << endl;
}
