#include <iostream>
#include <ctime>
#include <cmath>
#include <vector>

using namespace std;
double fak(unsigned long m) { if (m < 1) return 1; else return m * fak(m - 1); }



template<class T> T powq(T a, int k)

{
	T b = 1;

	for (; k; k >>= 1, a *= a) if (k & 1l) { b *= a; if (!k) break; }
	return b;

}

double comb(int n, int m) { return fak(m) / fak(n) / fak(m - n); }
void ExeFile(char*& n)
{
	int j, k = 0;

	for (; n[k]; k++); for (k--; k >= 0; --k) if (n[k] == '\\') break;
	for (j = 0; n[++k]; n[j++] = n[k]);
		n[j] = 0;

}

int main(int mn, char* nm[])
{
	double t, u,h, mx, sx, sx2, mx2, y, ind = 0;
	int x,n,N,i;
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	ExeFile(nm[0]);
	if (mn != 3) cerr << nm[0] << " n <->N \n<-> для вывода функции распределения\n"
		<< "иначе выводится плотность вероятности", exit(1); 
	/*p = atof(nm[1]); if (p > 1 || p < 0) cerr << "Oum6Ka p != 0..1!\n", exit(3);*/
	/*m = atof(nm[2]);*/ 
	n = atol(nm[1]); 
	N = atol(nm[2]); if (N < 0) N = -N, ind = 1;
	int* z = new int[N];
	double e = 1./N;
	cout << "Точность при моделироапнии e=" << e
		<< "- для ограничения бесконечного ряда составляющих" << endl;
	//for (j = s = 0, x = m; fabs(1 - s) > e; s += t, j++, x++) 
	//	t = 1/n;
	//cout << "Составляющие от x min=" << m << " до x_max=" << m + j - 1 << endl;
	vector<double> g(n), f(n); vector<int> a(n); // mac : :
	for (u = h = 0;(unsigned)h < g.size(); u = g[h++])
	{
		f[h] = 1./n, g[h] = f[h] + u;
	}

	for (mx2 = i = 0; i < N; i++)
	{
		t = double(rand()) / RAND_MAX;
		/*cout << t << endl;*/
		for (h = 0; h < g.size(); h++) if (t < g[h]) {
			a[h]++, mx2 += (z[i] = h + 1);
			break;

		}
	}
	mx2 /= N;
	//for (i = 0; i < n; i++)
	//{
	//	cout <<g[i]<<endl;
	//}
	for (sx2 = i = 0; i < N; i++) sx2 += (z[i] - mx2) * (z[i] - mx2); 
	sx2 /= N; 
	for (mx = i = 0; i < f.size(); i++) { 
		mx += double(1+i)*a[i] / N;
	}
	
	for (sx = i = 0; i < f.size(); i++) sx += double(1+i) * (1+i) * a[i] / N;
	sx -= mx * mx;
	if (ind)
	{
		for (y = h = 0, x = h; h < g.size(); h++, x++)
			y += a[h], cout << "p (" << x << ") : \t" << y << '\t' << y / double(N) << '\t' << g[h] << endl;
		for (y = h = 0, x = h; h < g.size(); h++, x++)
			y += a[h], cerr << x << '\t' << y / double(N) << '\t' << g[h] << endl;
	}
	else
	{
		for (h = 0, x = h; h < g.size(); h++, x++)
			cout << "p(" << x << "):\t" << a[h] << '\t' << a[h] / double(N) << '\t' << f[h] << endl;
		for (h = 0, x = h; h < g.size(); h++, x++)
			cerr << x << '\t' << a[h] / double(N) << '\t' << f[h] << endl;
	}
	cout << "m1=" << (n+1)/ 2. << "\tmx=" << mx << "\tmx2=" << mx2 << endl;
	cout << "mu2=" << (n*n-1)/12. << "\tsx=" << sx << "\tsx2=" << sx2 << endl << endl;
	delete[]z;
	return 0;
}
						
				