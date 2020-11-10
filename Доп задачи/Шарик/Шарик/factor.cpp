int factor(int x){
    int fact = 1;
    while (x > 1){
        fact *= x;
        x--;
    }
    return fact;
}

int rastonovka(int x){
    int s = 1;
    int sum = factor(x) / factor(x - s);
    return sum;
}

int rectangle (int x, int y){
    int sum = ((x + 1)*(y + 1)*x*y)/4;
    return sum;
}
