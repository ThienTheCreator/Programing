//greatest common divisor Euclid's algorithm 
int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a%b);
}