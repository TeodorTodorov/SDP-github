#pragma once
class UnionFind
{
private:
	int* nodes;
	int length;
	void copy(UnionFind const & uf) {
		this->length = uf.length;
		if (this->nodes != nullptr)
		{
			delete[] this->nodes;
		}
		this->nodes = new int[length];
		for (int i = 0; i < length; i++)
		{
			this->nodes[i] = uf.nodes[i];
		}
	}
public:
	UnionFind(int n) {
		this->nodes = new int[n];
		this->length = n;
		for (int i = 0; i < length; i++)
		{
			this->nodes[i] = i;
		}
	}
	UnionFind(UnionFind const & uf) {
		copy(uf);
	}
	// podava referenciq - ne se podava novo kopie na obekta i const za da ne promenqme obekta, koito podavame
	UnionFind& operator = (UnionFind const &uf) {
		if (this != &uf)
		{
			copy(uf);
		}
	}
	void connect(int a, int b) {
		if (nodes[b] == b)
		{
			nodes[b] = a;
		}
		
		else {
			int tempSearch = nodes[b];
			nodes[b] = a;
			for (int i = 0; i < length; i++)
			{
				if (nodes[i] == tempSearch) {
					nodes[i] = a;
				}
			}
		}
	}
	bool checkConnectivity(int a, int b) {
		if (this->nodes[a] == this->nodes[b])
		{
			return true;
		}
		return false;
	}

	virtual ~UnionFind() {
		delete[] this->nodes;
	}
};

