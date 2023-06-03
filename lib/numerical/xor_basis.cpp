struct xor_basis {
	int sz = 0;
	vector<int> basis; // basis vector with ith bit set
	xor_basis(int n) : basis(n) {}
	void insert(int mask) {
		for (int i = 0; i < basis.size(); i++) {
			if ((mask & 1 << i) == 0) continue; 
			if (basis[i]) {
				basis[i] = mask;
				++sz;
				return;
			}
			mask ^= basis[i];
		}
	}
};
