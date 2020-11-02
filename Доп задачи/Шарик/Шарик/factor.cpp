int factor(int x){
    int fact = 1;
    while (x > 1){
        fact *= x;
        x--;
    }
    return fact;
}

int rastonovka(int x, int y){
    int sum = factor(y) / (factor(x) * factor(y - x));
    return sum;
}
