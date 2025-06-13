//
// Created by Alex on 2020/7/2.
//
int main(){
    int N, row = 0;
    char c;
    c >> N >> c;
    for (int i = 0; i < N; i++) {
        if ((2 * i * (i + 2) + 1) > N) {
            row = i - 1;
            break;
        }
    }
    return 0;
}

