//Sieve of Eratosthenes from Competitive Programmer's Handbook

int sieve[];
for(int x = 2; x <= n; x++){
	if(sieve[x]) continue;
	for(int u = 2*x; u <= n; u += u){
		sieve[u] = x;
	}
}