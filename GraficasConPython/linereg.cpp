#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#include <bits/stdc++.h>
using namespace std;

#define df(b, e) ((b) > (e))
#define fore(i, b, e) for (auto i = (b) - df(b, e); i != e - df(b, e); i += 1 - 2 * df(b, e))
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
#define f first
#define s second
#define pb push_back

typedef long long lli;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> ii;

template <class T>
struct rge { T b, e; };

template <class T>
rge<T> range(T i, T j) { return rge<T>{i, j}; }
template <class T> auto dud(T *x) -> decltype(cerr << *x, 0);
template <class T> char dud(...);

struct debug {
#ifdef LOCAL
  ~debug() { cerr << endl; }

  template <class T>
  typename enable_if<sizeof dud<T>(0) != 1, debug &>::type operator << (T i) {
    cerr << boolalpha << i;
    return *this;
  }

  template <class T>
  typename enable_if<sizeof dud<T>(0) == 1, debug &>::type operator << (T i) {
    return *this << range(begin(i), end(i));
  }

  template <class A, class B>
  debug & operator << (pair<A, B> d) {
    return *this << "(" << d.first << ", " << d.second << ")";
  }

  template <class T>
  debug & operator << (rge<T> d) {
    *this << "[";
    for (auto it = d.b; it != d.e; ++it)
      *this << ", " + 2 * (it == d.b) << *it;
    return *this << "]";
  }
#else
  template <class T> 
  debug & operator << (const T&) {
    return *this; 
  }
#endif
};

#define deb(...) " " << #__VA_ARGS__ ": " << (__VA_ARGS__) << " "
#define ln "(" << __LINE__ << ")"

#define sq(x) (x) * (x)

int main() {
  cin.tie(0)->sync_with_stdio(0), cout.tie(0);
  vector<double> x, y, xMx, yMy, xMx2, xMxyMx;
  x = {3, 8, 10, 11, 13, 16, 27, 30, 35, 37, 38, 44, 103, 142};
  y = {4, 7, 8, 8, 10, 11, 16, 26, 21, 9, 31, 30, 75, 90};
  int n = sz(x);
  double Mx = 0, My = 0;
  fore (i, 0, n)
    Mx += x[i] / n, My += y[i] / n;
  debug() << deb(Mx) deb(My);
  cout << "x - Mx\n";
  fore (i, 0, n) {
    xMx.pb(x[i] - Mx);
    cout << x[i] - Mx << '\n';
  }
  cout << "y - My\n";
  fore (i, 0, n) {
    yMy.pb(y[i] - My);
    cout << y[i] - My << '\n';
  }
  cout << "(x - Mx) ^ 2\n";
  fore (i, 0, n) {
    xMx2.pb(sq(xMx[i]));
    cout << sq(xMx[i]) << '\n';
  }
  cout << "(x - Mx)(y - My)\n";
  fore (i, 0, n) {
    xMxyMx.pb(xMx[i] * yMy[i]);
    cout << xMx[i] * yMy[i] << '\n';
  }
  double sxy = 0, sx2 = 0, m, b;
  fore (i, 0, n)
    sx2 += xMx2[i] / n, sxy += xMxyMx[i] / n;
  m = sxy / sx2;
  b = My - m * Mx; 
  debug() << deb(sxy) deb(sx2);
  debug() << setprecision(2) << fixed << "y = " << m << "x + " << b;

  return 0;
}
